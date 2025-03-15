// 2장-1 reference.cpp
#include <stdio.h>
#include <stdlib.h>
//참조 변수(Reference)는 C++에서 추가된 기능이며, C 언어에는 없다 
int main (void){
    int num = 7;
    int &ref = num;
	//int &p;//오류, reference 변수는 항상 초기화해야 함
    //p = num; //안됨 
    printf("num = %d, ref = %d\n", num, ref);
    ref++; // 주소가 증가하는게 아니라 참조하는 변수의 값이 증가 
    printf("After ref++, num = %d, ref = %d\n", num, ref);//aliasing
    printf("&num = %p, &ref = %p\n\n", &num, &ref);
    system("pause");
	return 0;
}