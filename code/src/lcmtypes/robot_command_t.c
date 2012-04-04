/** THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
 * BY HAND!!
 *
 * Generated by lcm-gen
 **/

#include <string.h>
#include "robot_command_t.h"

static int __robot_command_t_hash_computed;
static int64_t __robot_command_t_hash;

int64_t __robot_command_t_hash_recursive(const __lcm_hash_ptr *p)
{
    const __lcm_hash_ptr *fp;
    for (fp = p; fp != NULL; fp = fp->parent)
        if (fp->v == __robot_command_t_get_hash)
            return 0;

    const __lcm_hash_ptr cp = { p, (void*)__robot_command_t_get_hash };
    (void) cp;

    int64_t hash = 0x27beb0b89a7b051bLL
         + __int64_t_hash_recursive(&cp)
         + __boolean_hash_recursive(&cp)
         + __double_hash_recursive(&cp)
         + __string_hash_recursive(&cp)
        ;

    return (hash<<1) + ((hash>>63)&1);
}

int64_t __robot_command_t_get_hash(void)
{
    if (!__robot_command_t_hash_computed) {
        __robot_command_t_hash = __robot_command_t_hash_recursive(NULL);
        __robot_command_t_hash_computed = 1;
    }

    return __robot_command_t_hash;
}

int __robot_command_t_encode_array(void *buf, int offset, int maxlen, const robot_command_t *p, int elements)
{
    int pos = 0, thislen, element;

    for (element = 0; element < elements; element++) {

        thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].utime), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __boolean_encode_array(buf, offset + pos, maxlen - pos, &(p[element].updateDest), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __double_encode_array(buf, offset + pos, maxlen - pos, p[element].dest, 6);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __string_encode_array(buf, offset + pos, maxlen - pos, &(p[element].action), 1);
        if (thislen < 0) return thislen; else pos += thislen;

    }
    return pos;
}

int robot_command_t_encode(void *buf, int offset, int maxlen, const robot_command_t *p)
{
    int pos = 0, thislen;
    int64_t hash = __robot_command_t_get_hash();

    thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    thislen = __robot_command_t_encode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int __robot_command_t_encoded_array_size(const robot_command_t *p, int elements)
{
    int size = 0, element;
    for (element = 0; element < elements; element++) {

        size += __int64_t_encoded_array_size(&(p[element].utime), 1);

        size += __boolean_encoded_array_size(&(p[element].updateDest), 1);

        size += __double_encoded_array_size(p[element].dest, 6);

        size += __string_encoded_array_size(&(p[element].action), 1);

    }
    return size;
}

int robot_command_t_encoded_size(const robot_command_t *p)
{
    return 8 + __robot_command_t_encoded_array_size(p, 1);
}

int __robot_command_t_decode_array(const void *buf, int offset, int maxlen, robot_command_t *p, int elements)
{
    int pos = 0, thislen, element;

    for (element = 0; element < elements; element++) {

        thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].utime), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __boolean_decode_array(buf, offset + pos, maxlen - pos, &(p[element].updateDest), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __double_decode_array(buf, offset + pos, maxlen - pos, p[element].dest, 6);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __string_decode_array(buf, offset + pos, maxlen - pos, &(p[element].action), 1);
        if (thislen < 0) return thislen; else pos += thislen;

    }
    return pos;
}

int __robot_command_t_decode_array_cleanup(robot_command_t *p, int elements)
{
    int element;
    for (element = 0; element < elements; element++) {

        __int64_t_decode_array_cleanup(&(p[element].utime), 1);

        __boolean_decode_array_cleanup(&(p[element].updateDest), 1);

        __double_decode_array_cleanup(p[element].dest, 6);

        __string_decode_array_cleanup(&(p[element].action), 1);

    }
    return 0;
}

int robot_command_t_decode(const void *buf, int offset, int maxlen, robot_command_t *p)
{
    int pos = 0, thislen;
    int64_t hash = __robot_command_t_get_hash();

    int64_t this_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &this_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (this_hash != hash) return -1;

    thislen = __robot_command_t_decode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int robot_command_t_decode_cleanup(robot_command_t *p)
{
    return __robot_command_t_decode_array_cleanup(p, 1);
}

int __robot_command_t_clone_array(const robot_command_t *p, robot_command_t *q, int elements)
{
    int element;
    for (element = 0; element < elements; element++) {

        __int64_t_clone_array(&(p[element].utime), &(q[element].utime), 1);

        __boolean_clone_array(&(p[element].updateDest), &(q[element].updateDest), 1);

        __double_clone_array(p[element].dest, q[element].dest, 6);

        __string_clone_array(&(p[element].action), &(q[element].action), 1);

    }
    return 0;
}

robot_command_t *robot_command_t_copy(const robot_command_t *p)
{
    robot_command_t *q = (robot_command_t*) malloc(sizeof(robot_command_t));
    __robot_command_t_clone_array(p, q, 1);
    return q;
}

void robot_command_t_destroy(robot_command_t *p)
{
    __robot_command_t_decode_array_cleanup(p, 1);
    free(p);
}

int robot_command_t_publish(lcm_t *lc, const char *channel, const robot_command_t *p)
{
      int max_data_size = robot_command_t_encoded_size (p);
      uint8_t *buf = (uint8_t*) malloc (max_data_size);
      if (!buf) return -1;
      int data_size = robot_command_t_encode (buf, 0, max_data_size, p);
      if (data_size < 0) {
          free (buf);
          return data_size;
      }
      int status = lcm_publish (lc, channel, buf, data_size);
      free (buf);
      return status;
}

struct _robot_command_t_subscription_t {
    robot_command_t_handler_t user_handler;
    void *userdata;
    lcm_subscription_t *lc_h;
};
static
void robot_command_t_handler_stub (const lcm_recv_buf_t *rbuf,
                            const char *channel, void *userdata)
{
    int status;
    robot_command_t p;
    memset(&p, 0, sizeof(robot_command_t));
    status = robot_command_t_decode (rbuf->data, 0, rbuf->data_size, &p);
    if (status < 0) {
        fprintf (stderr, "error %d decoding robot_command_t!!!\n", status);
        return;
    }

    robot_command_t_subscription_t *h = (robot_command_t_subscription_t*) userdata;
    h->user_handler (rbuf, channel, &p, h->userdata);

    robot_command_t_decode_cleanup (&p);
}

robot_command_t_subscription_t* robot_command_t_subscribe (lcm_t *lcm,
                    const char *channel,
                    robot_command_t_handler_t f, void *userdata)
{
    robot_command_t_subscription_t *n = (robot_command_t_subscription_t*)
                       malloc(sizeof(robot_command_t_subscription_t));
    n->user_handler = f;
    n->userdata = userdata;
    n->lc_h = lcm_subscribe (lcm, channel,
                                 robot_command_t_handler_stub, n);
    if (n->lc_h == NULL) {
        fprintf (stderr,"couldn't reg robot_command_t LCM handler!\n");
        free (n);
        return NULL;
    }
    return n;
}

int robot_command_t_subscription_set_queue_capacity (robot_command_t_subscription_t* subs,
                              int num_messages)
{
    return lcm_subscription_set_queue_capacity (subs->lc_h, num_messages);
}

int robot_command_t_unsubscribe(lcm_t *lcm, robot_command_t_subscription_t* hid)
{
    int status = lcm_unsubscribe (lcm, hid->lc_h);
    if (0 != status) {
        fprintf(stderr,
           "couldn't unsubscribe robot_command_t_handler %p!\n", hid);
        return -1;
    }
    free (hid);
    return 0;
}

