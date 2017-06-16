Debug = 0

LDFLAGS = -lSDL2 -lpthread
CFLAGS = -Wall
INC_DIR = $(shell pkg-config --cflags sdl2)
EXEC = simple_cam

ifeq ($(Debug), 1)
CFLAGS += -g -DDEBUG
endif

.PHONY = all clean

all:$(EXEC)

$(EXEC): v4l2_driver.o main.c
	cc $^ $(CFLAGS) $(INC_DIR) $(LDFLAGS) -o $@ 

v4l2_driver.o:v4l2_driver.c
	cc $(CFLAGS) -o $@ -c $^

clean:
	rm *.o
	find -type f -executable -exec rm {} \;
