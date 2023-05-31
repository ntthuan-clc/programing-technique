#include <iostream>
#include <cstdio>
#include<time.h> 
struct Circle {
    int x, y, r;
};

bool isCrossOver(Circle c1, Circle c2){
    float distance = sqrt((c1.x - c2.x)*(c1.x - c2.x) + (c1.y - c2.y)*(c1.y - c2.y));
    if(distance <= (c1.r + c2.r)){
        return true;
    }
    return false; 
}

int main() {
    srand(time(0));
    int n = rand() %100;
    Circle* cArr = new Circle[n];
    // fill the array with some example data
    for (int i = 0; i < n; i++) {
        cArr[i].x = rand() %100;
        cArr[i].y = rand() %100;
        cArr[i].r = rand() %100;
    }
    FILE* out = fopen("circles.bin", "wb"); // open file for writing in binary mode
    if (out == NULL) {
        std::cout << "Failed to open file" << std::endl;
        return 1;
    }
    fwrite(&n, sizeof(int), 1, out); // write the number of circles to the file
    fwrite(cArr, sizeof(Circle), n, out); // write the circles array to the file
    fclose(out); // close the file
    delete[] cArr; // free the dynamically allocated memory

    FILE* in = fopen("circles.bin", "rb"); // open file for reading in binary mode
    if (in == NULL) {
        std::cout << "Failed to open file" << std::endl;
        return 1;
    }

    fread(&n, sizeof(int), 1, in); // read the number of circles from the file
    cArr = new Circle[n];
    fread(cArr, sizeof(Circle), n, in); // read the circles array from the file
    fclose(in); // close the file
    // print out the data for demonstration purposes
    // std::cout << "n = " << n << std::endl;
    // for (int i = 0; i < n; i++) {
    //     std::cout << "Circle " << i + 1 << ": x = " << cArr[i].x << ", y = " << cArr[i].y << ", r = " << cArr[i].r << std::endl;
    // }

    for(int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++i) {
            if(isCrossOver(cArr[i], cArr[j])){
                std::cout << "C1: " << cArr[i].x << " " << cArr[i].y << " " << cArr[i].r << "\n";
                std::cout << "C2: " << cArr[j].x << " " << cArr[j].y << " " << cArr[j].r << "\n";
            }
        }
    }

    return 0;
}
