/* LCM type definition class file
 * This file was automatically generated by lcm-gen
 * DO NOT MODIFY BY HAND!!!!
 */

package kinect.lcmtypes;
 
import java.io.*;
import java.nio.*;
import java.util.*;
import lcm.lcm.*;
 
public final class object_data_t implements lcm.lcm.LCMEncodable
{
    public long utime;
    public int id;
    public int num_cat;
    public kinect.lcmtypes.categorized_data_t cat_dat[];
    public double pos[];
    public double bbox[][];
 
    public object_data_t()
    {
        pos = new double[6];
        bbox = new double[2][3];
    }
 
    public static final long LCM_FINGERPRINT;
    public static final long LCM_FINGERPRINT_BASE = 0x2de0f14e30285d00L;
 
    static {
        LCM_FINGERPRINT = _hashRecursive(new ArrayList<Class>());
    }
 
    public static long _hashRecursive(ArrayList<Class> classes)
    {
        if (classes.contains(kinect.lcmtypes.object_data_t.class))
            return 0L;
 
        classes.add(kinect.lcmtypes.object_data_t.class);
        long hash = LCM_FINGERPRINT_BASE
             + kinect.lcmtypes.categorized_data_t._hashRecursive(classes)
            ;
        classes.remove(classes.size() - 1);
        return (hash<<1) + ((hash>>63)&1);
    }
 
    public void encode(DataOutput outs) throws IOException
    {
        outs.writeLong(LCM_FINGERPRINT);
        _encodeRecursive(outs);
    }
 
    public void _encodeRecursive(DataOutput outs) throws IOException
    {
        outs.writeLong(this.utime); 
 
        outs.writeInt(this.id); 
 
        outs.writeInt(this.num_cat); 
 
        for (int a = 0; a < this.num_cat; a++) {
            this.cat_dat[a]._encodeRecursive(outs); 
        }
 
        for (int a = 0; a < 6; a++) {
            outs.writeDouble(this.pos[a]); 
        }
 
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 3; b++) {
                outs.writeDouble(this.bbox[a][b]); 
            }
        }
 
    }
 
    public object_data_t(byte[] data) throws IOException
    {
        this(new LCMDataInputStream(data));
    }
 
    public object_data_t(DataInput ins) throws IOException
    {
        if (ins.readLong() != LCM_FINGERPRINT)
            throw new IOException("LCM Decode error: bad fingerprint");
 
        _decodeRecursive(ins);
    }
 
    public static kinect.lcmtypes.object_data_t _decodeRecursiveFactory(DataInput ins) throws IOException
    {
        kinect.lcmtypes.object_data_t o = new kinect.lcmtypes.object_data_t();
        o._decodeRecursive(ins);
        return o;
    }
 
    public void _decodeRecursive(DataInput ins) throws IOException
    {
        this.utime = ins.readLong();
 
        this.id = ins.readInt();
 
        this.num_cat = ins.readInt();
 
        this.cat_dat = new kinect.lcmtypes.categorized_data_t[(int) num_cat];
        for (int a = 0; a < this.num_cat; a++) {
            this.cat_dat[a] = kinect.lcmtypes.categorized_data_t._decodeRecursiveFactory(ins);
        }
 
        this.pos = new double[(int) 6];
        for (int a = 0; a < 6; a++) {
            this.pos[a] = ins.readDouble();
        }
 
        this.bbox = new double[(int) 2][(int) 3];
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 3; b++) {
                this.bbox[a][b] = ins.readDouble();
            }
        }
 
    }
 
    public kinect.lcmtypes.object_data_t copy()
    {
        kinect.lcmtypes.object_data_t outobj = new kinect.lcmtypes.object_data_t();
        outobj.utime = this.utime;
 
        outobj.id = this.id;
 
        outobj.num_cat = this.num_cat;
 
        outobj.cat_dat = new kinect.lcmtypes.categorized_data_t[(int) num_cat];
        for (int a = 0; a < this.num_cat; a++) {
            outobj.cat_dat[a] = this.cat_dat[a].copy();
        }
 
        outobj.pos = new double[(int) 6];
        System.arraycopy(this.pos, 0, outobj.pos, 0, 6); 
        outobj.bbox = new double[(int) 2][(int) 3];
        for (int a = 0; a < 2; a++) {
            System.arraycopy(this.bbox[a], 0, outobj.bbox[a], 0, 3);        }
 
        return outobj;
    }
 
}

