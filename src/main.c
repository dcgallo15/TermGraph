#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// TODO: ensure this doesn't compile each time `make` is run!
#include "../res/tuibox.h"

// NOTE: these must be divisible by 2
#define WIDTH 32
#define HEIGHT 32

static char data[WIDTH * HEIGHT];

void setData(char c) {
	// TODO: make this more efficent
	for(size_t i = 0; i < WIDTH * HEIGHT; ++i) {
		data[i] = c;
	}
}

void outputData(void) {
	// Print line by line
	// TODO: Make adjustments since thhe height of a character is around 2x width of a character
	for(size_t i = 0; i < HEIGHT; i++) {
		fwrite(data + (i * WIDTH) * sizeof(char), sizeof(char), WIDTH, stdout);
		fputc('\n', stdout);
	}
}

void scaleDataForConsoleSize(void) {
    for(size_t y = 0; y < HEIGHT + 1; ++y) {
        for(size_t x = 0; x < WIDTH; ++x) {
            if (data[y*WIDTH + x] == '*' && data[(y+1)*WIDTH + x] == '*') {
                data[(y)*WIDTH + x] = '*';
            } else if (data[(y+1)*WIDTH + x] == '*') {
                data[(y)*WIDTH + x] = '_';
            } else if (data[(y)*WIDTH + x] == '*' && data[(y+1)*WIDTH + x] != '*') {
                data[(y)*WIDTH + x] = '^';
            }
        }
    }
}

// 32x32 grid
// (0,0) is (16, 16)
// NOTE: will need to change to floating point co-ords at some point

void circleExample(double r) {
	for(int y = 0; y < HEIGHT; ++y) {
		for(int x = 0; x < WIDTH; ++x) {
			// Can change these depending on the centering
			int transformX = x - (WIDTH / 2);
			int transformY = y - (HEIGHT / 2);
            // use <= for filled in circle
			if(pow(transformX, 2) + (pow(transformY, 2)) <= pow(r, 2)) {
                data[y*WIDTH + x] = '*';
            }
        }
	}
}

// TODO: fix direction of parabolaExample
void parabolaExample(void) {
	for(int y = 0; y < HEIGHT; ++y) {
		for(int x = 0; x < WIDTH; ++x) {
			// Can change these depending on the centering
			int transformX = x - (WIDTH / 2);
			int transformY = y - (HEIGHT / 2);
			if(pow(transformX, 2) == transformY) {
                data[y*WIDTH + x] = '*';
            }
        }
	}
}

void drawYLine(int m, int c) {
	for(int y = 0; y < HEIGHT; ++y) {
		for(int x = 0; x < WIDTH; ++x) {
			// Can change these depending on the centering
			int transformX = x - (WIDTH / 2);
			int transformY = y - (HEIGHT / 2);
			if(m*transformX + c == transformY) {
                data[y*WIDTH + x] = '*';
            }
        }
    }
}

void drawXLine(int m, int c) {
	for(int y = 0; y < HEIGHT; ++y) {
		for(int x = 0; x < WIDTH; ++x) {
			// Can change these depending on the centering
			int transformX = x - (WIDTH / 2);
			int transformY = y - (HEIGHT / 2);
			if(transformX == transformY*m + c) {
                data[y*WIDTH + x] = '*';
            }
        }
    }
}
void drawAxes(void) {
    drawYLine(0, 0);
    drawXLine(0, 0);
}

int main(void) {
	setData(' ');
	//circleExample(4);
    parabolaExample();
    //drawAxes();
    scaleDataForConsoleSize();
    outputData();
	return 0;
}
