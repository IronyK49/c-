//4장_static_linkage.cpp
int g = 2017;//static duration, external linkage(다른 파일에 연결해서 사용가능)
static int s = 20;//static duration, internal linkage(이 파일에서만 사용가능)
const int c = 30;//const global 변수
void show();
int main() {
	show();
	show();
	return 0;
}
void show() {
	static int n = 0;//static duration, no linkage(필수, 처음 한번만 실행됨) 
	//...
	n++;
	return 0;
}