// 2��-1 reference.cpp
#include <stdio.h>
#include <stdlib.h>
//���� ����(Reference)�� C++���� �߰��� ����̸�, C ���� ���� 
int main (void){
    int num = 7;
    int &ref = num;
	//int &p;//����, reference ������ �׻� �ʱ�ȭ�ؾ� ��
    //p = num; //�ȵ� 
    printf("num = %d, ref = %d\n", num, ref);
    ref++; // �ּҰ� �����ϴ°� �ƴ϶� �����ϴ� ������ ���� ���� 
    printf("After ref++, num = %d, ref = %d\n", num, ref);//aliasing
    printf("&num = %p, &ref = %p\n\n", &num, &ref);
    system("pause");
	return 0;
}