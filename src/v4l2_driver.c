#include "v4l2_driver.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int IMAGE_WIDTH = 640;
int IMAGE_HEIGHT = 480;

int v4l2_open(char *device) {
  struct stat st;
  memset(&st, 0, sizeof(st));
  if (stat(device, &st) == -1) {
    perror("stat");
    return -1;
  }
  if (!S_ISCHR(st.st_mode)) {
    fprintf(stderr, "%s is no character device\n", device);
    return -1;
  } else
    printf("%s is a character device\n", device);
  return open(device, O_RDONLY);
}

int v4l2_close(int fd) { return close(fd); }
