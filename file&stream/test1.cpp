#include <stdio.h>

struct circle {
    int x, y, r;
};

int main() {
    int n = 3; // number of circles
    struct circle circles[n]; // array of circles
    FILE* fp = fopen("circles.bin", "rb"); // open file for reading in binary mode
    if (fp == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
    fread(circles, sizeof(circles), 1, fp); // read the circles array from the file
    for (int i = 0; i < n; i++) {
        printf("x = %d, y = %d, r = %d\n", circles[i].x, circles[i].y, circles[i].r); // print the values of x, y, and r for each circle
    }
    fclose(fp); // close the file
    return 0;
}
