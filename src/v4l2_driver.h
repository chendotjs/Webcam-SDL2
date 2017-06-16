#ifndef _V4l2_DRIVER__
#define _V4l2_DRIVER__

extern int IMAGE_WIDTH;
extern int IMAGE_HEIGHT;

struct v4l2_buffer {
  void *start;
  unsigned int length;
};

extern struct v4l2_buffer *v4l2_buffers;

/* functions */
int v4l2_open(char *device);
int v4l2_close(int fd);

#endif
