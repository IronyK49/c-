//4��_static_linkage.cpp
int g = 2017;//static duration, external linkage(�ٸ� ���Ͽ� �����ؼ� ��밡��)
static int s = 20;//static duration, internal linkage(�� ���Ͽ����� ��밡��)
const int c = 30;//const global ����
void show();
int main() {
	show();
	show();
	return 0;
}
void show() {
	static int n = 0;//static duration, no linkage(�ʼ�, ó�� �ѹ��� �����) 
	//...
	n++;
	return 0;
}