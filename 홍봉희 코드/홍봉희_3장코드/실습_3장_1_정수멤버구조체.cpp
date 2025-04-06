#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <windows.h>

struct Rectangle {
    int leftBottomX;
    int leftBottomY;
    int width;
    int height;
};

/*
typedef struct Rectangle {
    int leftBottomX;
    int leftBottomY;
    int width;
    int height;
} Rectangle;
*/
//기본적인 C 언어 문법에서는 struct Rectangle를 반드시 써야
int compareRectangles(const struct Rectangle* a, const struct Rectangle* b) {
    return (a->leftBottomX - b->leftBottomX);
}
void showRectangle(struct Rectangle r) { // 파라미터를 받을때 함수의 타입에 맞는지 중요 
    printf("[%d, %d, %d, %d]\n", r.leftBottomX, r.leftBottomY, r.width, r.height);
}
void showRectangles(char* message, struct Rectangle* rectangles[], int numRectangles) {

}
void swap(struct Rectangle* rect[], int i, int j) {

}
void selectionSortRectangles(struct Rectangle* rectangles[], int numRectangles) { // selection sort for문 2번 
    // int compareRectangles(const Student* b);를 사용한 정렬
    // void swap(Rectangle * rect[], int i, int j) 사용
}

int main(void) {
    SetConsoleOutputCP(CP_UTF8);//한글깨지는 문제 해결하기 위해 사용 
    const int numRectangles = 5;
    struct Rectangle r1 = { 3, 5, 10, 15 };
    struct Rectangle r2 = { 3, 5, 10, 12 };
    struct Rectangle r3 = { 3, 5, 6, 10 };
    struct Rectangle r4 = { 3, 5, 7, 8 };
    struct Rectangle r5 = { 3, 3, 9, 14 };
    struct Rectangle* rectangles[numRectangles] = { &r1,&r2,&r3,&r4,&r5 }; // array of pointer, &: 참조변수(중요)

    showRectangles("정렬전:", rectangles, numRectangles);

    selectionSortRectangles(rectangles, numRectangles);

    showRectangles("정렬후:", rectangles, numRectangles);

    system("pause");
    return 0;
}