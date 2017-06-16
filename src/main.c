#include "v4l2_driver.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_help() {
  printf("Usage: simple_cam <width> <height> (/dev/video#)\n");
}

int main(int argc, char const *argv[]) {
  char *device = "/dev/video0";

  if (argc < 2) {
    print_help();
    exit(0);
  }

  if (argc == 3) {
    IMAGE_WIDTH = atoi(argv[1]);
    IMAGE_HEIGHT = atoi(argv[2]);
  }

  if (argc > 3) {
    device = argv[3];
  }

  int video_fildes = v4l2_open(device);
  if (video_fildes == -1) {
    fprintf(stderr, "can't open %s\n", device);
    exit(-1);
  }

exit_:
  if (v4l2_close(video_fildes) == -1) {
    perror("close");
  };
  return 0;
}
