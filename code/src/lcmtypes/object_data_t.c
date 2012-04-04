/** THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
 * BY HAND!!
 *
 * Generated by lcm-gen
 **/

#include <string.h>
#include "object_data_t.h"

static int __object_data_t_hash_computed;
static int64_t __object_data_t_hash;

int64_t __object_data_t_hash_recursive(const __lcm_hash_ptr *p)
{
    const __lcm_hash_ptr *fp;
    for (fp = p; fp != NULL; fp = fp->parent)
        if (fp->v == __object_data_t_get_hash)
            return 0;

    const __lcm_hash_ptr cp = { p, (void*)__object_data_t_get_hash };
    (void) cp;

    int64_t hash = 0x2de0f14e30285d00LL
         + __int64_t_hash_recursive(&cp)
         + __int32_t_hash_recursive(&cp)
         + __int32_t_hash_recursive(&cp)
         + __categorized_data_t_hash_recursive(&cp)
         + __double_hash_recursive(&cp)
         + __double_hash_recursive(&cp)
        ;

    return (hash<<1) + ((hash>>63)&1);
}

int64_t __object_data_t_get_hash(void)
{
    if (!__object_data_t_hash_computed) {
        __object_data_t_hash = __object_data_t_hash_recursive(NULL);
        __object_data_t_hash_computed = 1;
    }

    return __object_data_t_hash;
}

int __object_data_t_encode_array(void *buf, int offset, int maxlen, const object_data_t *p, int elements)
{
    int pos = 0, thislen, element;

    for (element = 0; element < elements; element++) {

        thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].utime), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].id), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].num_cat), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __categorized_data_t_encode_array(buf, offset + pos, maxlen - pos, p[element].cat_dat, p[element].num_cat);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __double_encode_array(buf, offset + pos, maxlen - pos, p[element].pos, 6);
        if (thislen < 0) return thislen; else pos += thislen;

        { int a;
        for (a = 0; a < 2; a++) {
            thislen = __double_encode_array(buf, offset + pos, maxlen - pos, p[element].bbox[a], 3);
            if (thislen < 0) return thislen; else pos += thislen;
        }
        }

    }
    return pos;
}

int object_data_t_encode(void *buf, int offset, int maxlen, const object_data_t *p)
{
    int pos = 0, thislen;
    int64_t hash = __object_data_t_get_hash();

    thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    thislen = __object_data_t_encode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int __object_data_t_encoded_array_size(const object_data_t *p, int elements)
{
    int size = 0, element;
    for (element = 0; element < elements; element++) {

        size += __int64_t_encoded_array_size(&(p[element].utime), 1);

        size += __int32_t_encoded_array_size(&(p[element].id), 1);

        size += __int32_t_encoded_array_size(&(p[element].num_cat), 1);

        size += __categorized_data_t_encoded_array_size(p[element].cat_dat, p[element].num_cat);

        size += __double_encoded_array_size(p[element].pos, 6);

        { int a;
        for (a = 0; a < 2; a++) {
            size += __double_encoded_array_size(p[element].bbox[a], 3);
        }
        }

    }
    return size;
}

int object_data_t_encoded_size(const object_data_t *p)
{
    return 8 + __object_data_t_encoded_array_size(p, 1);
}

int __object_data_t_decode_array(const void *buf, int offset, int maxlen, object_data_t *p, int elements)
{
    int pos = 0, thislen, element;

    for (element = 0; element < elements; element++) {

        thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].utime), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].id), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].num_cat), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].cat_dat = (categorized_data_t*) lcm_malloc(sizeof(categorized_data_t) * p[element].num_cat);
        thislen = __categorized_data_t_decode_array(buf, offset + pos, maxlen - pos, p[element].cat_dat, p[element].num_cat);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __double_decode_array(buf, offset + pos, maxlen - pos, p[element].pos, 6);
        if (thislen < 0) return thislen; else pos += thislen;

        { int a;
        for (a = 0; a < 2; a++) {
            thislen = __double_decode_array(buf, offset + pos, maxlen - pos, p[element].bbox[a], 3);
            if (thislen < 0) return thislen; else pos += thislen;
        }
        }

    }
    return pos;
}

int __object_data_t_decode_array_cleanup(object_data_t *p, int elements)
{
    int element;
    for (element = 0; element < elements; element++) {

        __int64_t_decode_array_cleanup(&(p[element].utime), 1);

        __int32_t_decode_array_cleanup(&(p[element].id), 1);

        __int32_t_decode_array_cleanup(&(p[element].num_cat), 1);

        __categorized_data_t_decode_array_cleanup(p[element].cat_dat, p[element].num_cat);
        if (p[element].cat_dat) free(p[element].cat_dat);

        __double_decode_array_cleanup(p[element].pos, 6);

        { int a;
        for (a = 0; a < 2; a++) {
            __double_decode_array_cleanup(p[element].bbox[a], 3);
        }
        }

    }
    return 0;
}

int object_data_t_decode(const void *buf, int offset, int maxlen, object_data_t *p)
{
    int pos = 0, thislen;
    int64_t hash = __object_data_t_get_hash();

    int64_t this_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &this_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (this_hash != hash) return -1;

    thislen = __object_data_t_decode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int object_data_t_decode_cleanup(object_data_t *p)
{
    return __object_data_t_decode_array_cleanup(p, 1);
}

int __object_data_t_clone_array(const object_data_t *p, object_data_t *q, int elements)
{
    int element;
    for (element = 0; element < elements; element++) {

        __int64_t_clone_array(&(p[element].utime), &(q[element].utime), 1);

        __int32_t_clone_array(&(p[element].id), &(q[element].id), 1);

        __int32_t_clone_array(&(p[element].num_cat), &(q[element].num_cat), 1);

        q[element].cat_dat = (categorized_data_t*) lcm_malloc(sizeof(categorized_data_t) * q[element].num_cat);
        __categorized_data_t_clone_array(p[element].cat_dat, q[element].cat_dat, p[element].num_cat);

        __double_clone_array(p[element].pos, q[element].pos, 6);

        { int a;
        for (a = 0; a < 2; a++) {
            __double_clone_array(p[element].bbox[a], q[element].bbox[a], 3);
        }
        }

    }
    return 0;
}

object_data_t *object_data_t_copy(const object_data_t *p)
{
    object_data_t *q = (object_data_t*) malloc(sizeof(object_data_t));
    __object_data_t_clone_array(p, q, 1);
    return q;
}

void object_data_t_destroy(object_data_t *p)
{
    __object_data_t_decode_array_cleanup(p, 1);
    free(p);
}

int object_data_t_publish(lcm_t *lc, const char *channel, const object_data_t *p)
{
      int max_data_size = object_data_t_encoded_size (p);
      uint8_t *buf = (uint8_t*) malloc (max_data_size);
      if (!buf) return -1;
      int data_size = object_data_t_encode (buf, 0, max_data_size, p);
      if (data_size < 0) {
          free (buf);
          return data_size;
      }
      int status = lcm_publish (lc, channel, buf, data_size);
      free (buf);
      return status;
}

struct _object_data_t_subscription_t {
    object_data_t_handler_t user_handler;
    void *userdata;
    lcm_subscription_t *lc_h;
};
static
void object_data_t_handler_stub (const lcm_recv_buf_t *rbuf,
                            const char *channel, void *userdata)
{
    int status;
    object_data_t p;
    memset(&p, 0, sizeof(object_data_t));
    status = object_data_t_decode (rbuf->data, 0, rbuf->data_size, &p);
    if (status < 0) {
        fprintf (stderr, "error %d decoding object_data_t!!!\n", status);
        return;
    }

    object_data_t_subscription_t *h = (object_data_t_subscription_t*) userdata;
    h->user_handler (rbuf, channel, &p, h->userdata);

    object_data_t_decode_cleanup (&p);
}

object_data_t_subscription_t* object_data_t_subscribe (lcm_t *lcm,
                    const char *channel,
                    object_data_t_handler_t f, void *userdata)
{
    object_data_t_subscription_t *n = (object_data_t_subscription_t*)
                       malloc(sizeof(object_data_t_subscription_t));
    n->user_handler = f;
    n->userdata = userdata;
    n->lc_h = lcm_subscribe (lcm, channel,
                                 object_data_t_handler_stub, n);
    if (n->lc_h == NULL) {
        fprintf (stderr,"couldn't reg object_data_t LCM handler!\n");
        free (n);
        return NULL;
    }
    return n;
}

int object_data_t_subscription_set_queue_capacity (object_data_t_subscription_t* subs,
                              int num_messages)
{
    return lcm_subscription_set_queue_capacity (subs->lc_h, num_messages);
}

int object_data_t_unsubscribe(lcm_t *lcm, object_data_t_subscription_t* hid)
{
    int status = lcm_unsubscribe (lcm, hid->lc_h);
    if (0 != status) {
        fprintf(stderr,
           "couldn't unsubscribe object_data_t_handler %p!\n", hid);
        return -1;
    }
    free (hid);
    return 0;
}

