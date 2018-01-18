#ifndef _V4l2_DRIVER__
#define _V4l2_DRIVER__

#include <inttypes.h>
#include <pthread.h>

#define BUF_NUM 4

extern int IMAGE_WIDTH;
extern int IMAGE_HEIGHT;

struct v4l2_ubuffer {
  void *start;
  unsigned int length;
};

extern struct v4l2_ubuffer *v4l2_ubuffers;

/* functions */
extern int v4l2_open(const char *device);
extern int v4l2_close(int fd);
extern int v4l2_querycap(int fd, const char *device);
extern int v4l2_sfmt(int fd, uint32_t pfmt);
extern int v4l2_gfmt(int fd);
extern int v4l2_mmap(int fd);
extern int v4l2_munmap();
extern int v4l2_sfps(int fd, int fps);
extern int v4l2_streamon(int fd);
extern int v4l2_streamoff(int fd);

#endif
