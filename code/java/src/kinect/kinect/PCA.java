package kinect.kinect;


import java.awt.Color;
import java.awt.Rectangle;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

import javax.imageio.ImageIO;

import april.jmat.LinAlg;

public class PCA {
	public static boolean isValidPixel(Color c){
		return c.getRed() > 1 || c.getGreen() > 1 || c.getBlue() > 1;
	}
	
	public static double[] getMean(ArrayList<int[]> pixels){
		// compute the mean
    	int n = pixels.size();
    	double[] mean = new double[]{0,0};
    	for(int[] pixel : pixels){
    		mean[0] += pixel[0];
    		mean[1] += pixel[1];
    	}
    	
    	mean[0] /= n;
    	mean[1] /= n;
    	return mean;
	}
	
	public static double[][] getCov(ArrayList<int[]> pixels, double[] mean){
		// compute the covariance
    	int n = pixels.size();
    	double[][] B = new double[2][n];
    	double[][] Bt = new double[n][2];
    	for(int i = 0; i < 2; i++){
    		for(int j = 0; j < n; j++){
    			B[i][j] = pixels.get(j)[i] - mean[i];
    			Bt[j][i] = B[i][j];
    		}
    	}
    	double[][] cov = LinAlg.matrixAB(B, Bt);
    	return LinAlg.scale(cov, 1.0/n);
	}
	
	public static double[] getPrincipleEigenvector(double[][] cov){
		double a = cov[0][0];
		double b = cov[0][1];
		double c = cov[1][0];
		double d = cov[1][1];
		double t = a + d; //trace
		double det = a*d - b*c; //determinant
		
		// eigenvalue
		double lambda = t/2 + Math.sqrt(t*t/4-det);
		
		// eigenvector
		double[] v = new double[2];
		if(c != 0){
			v[0] = lambda-d;
			v[1] = c;
		} else if(b != 0){
			v[0] = b;
			v[1] = lambda-a;
		} else {
			v[0] = 1;
			v[1] = 0;
		}
		
		LinAlg.normalizeEquals(v);
		return v;
	}
	
	public static ArrayList<int[]> getPixels(BufferedImage img){
		ArrayList<int[]> pixels = new ArrayList<int[]>();
	    for(int i = 0; i < img.getWidth(); i++){
	    	for(int j = 0; j < img.getHeight(); j++){
	    		Color c = new Color(img.getRGB(i, j));
	    		if(isValidPixel(c)){
	    			pixels.add(new int[]{i, j});
	    		}
	    	}
	    }
	    return pixels;
	}
	
	public static double[] projectOntoVector(ArrayList<int[]> pixels, double[] mean, double[] v){
		double min = Double.MAX_VALUE;
		double max = Double.MIN_VALUE;
		for(int[] pixel : pixels){
			double proj = (pixel[0]-mean[0])*v[0] + (pixel[1]-mean[1])*v[1];
			min = (proj < min ? proj : min);
			max = (proj > max ? proj : max);
		}
		
		return new double[]{min, max};
	}
	
	public static double getFeature(BufferedImage img, double[] start, double[] dir){
		final double increment = .5;
		double x = start[0];
		double y = start[1];
		double dist = 0;
		
		
		Rectangle bounds = new Rectangle(0, 0, img.getWidth(), img.getHeight());
		
		int xi = (int)x;
		int yi = (int)y;
		while(bounds.contains(xi, yi)){
			for(int i = 0; i < 2; i++){
				for(int j = 0; j < 2; j++){
					if(bounds.contains(xi+i, yi+j)){
						Color color = new Color(img.getRGB(xi + i, yi + j));
						if(isValidPixel(color)){
							return dist;
						}
					}
				}
			}
			
			x += dir[0] * increment;
			y += dir[1] * increment;
			dist += increment;
			xi = (int)x;
			yi = (int)y;
		}

		return 0;
	}
	
	public static double[] getFeatures(BufferedImage img, int numFeatures){
		// Directions are with right being +v1 and up being +v2
		
	    ArrayList<int[]> pixels = getPixels(img);
	    if(pixels.size() == 0){
	    	return null;
	    }
		double[] mean = getMean(pixels);
    	double[][] cov = getCov(pixels, mean);
    	
    	double[] v1 = getPrincipleEigenvector(cov);
	    double[] v2 = new double[]{-v1[1], v1[0]}; // perpendicular vector

		// project the pixels onto each axis (get OBB limits from mean)
	    double[] proj1 = projectOntoVector(pixels, mean, v1);
	    double[] proj2 = projectOntoVector(pixels, mean, v2);
	    
	    // left center of the OBB
	    double[] leftCenter = new double[2];
	    leftCenter[0] = mean[0] + proj1[0]*v1[0];
	    leftCenter[1] = mean[1] + proj1[0]*v1[1];
	    
	    double[] features = new double[2*numFeatures];
	    int f = 0;
	    for(int i = 0; i < 2; i++){
	    	// Start at bottom-left or top-left
	    	double[] start = new double[2];
	    	start[0] = leftCenter[0] + proj2[i]*v2[0]; 
	    	start[1] = leftCenter[1] + proj2[i]*v2[1];
	    	
	    	// Direction is either up or down
	    	double[] dir = LinAlg.scale(v2, (i == 0 ? 1 : -1));
	    	
	    	// Pick points evenly along the line
	    	for(float perc = .05f; perc <= .95; perc += .92f/(numFeatures-1)){
	    		double[] pt = new double[2];
	    		pt[0] = start[0] + perc*(proj1[1] - proj1[0])*v1[0];
	    		pt[1] = start[1] + perc*(proj1[1] - proj1[0])*v1[1];
	    		features[f++] = getFeature(img, pt, dir)/(proj2[1] - proj2[0]);
	    	}
	    }

    	return features;
	}
	
	public static void main(String args[])
    {
		BufferedImage img = null;
		try {
		    img = ImageIO.read(new File("simple_tri.png"));		    
		    getFeatures(img, 20);
		} catch (IOException e) {
		}
    }
}
