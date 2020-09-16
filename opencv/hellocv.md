# Open CV

-  Open Source Computer Vision, 영상/동영상 처리에 사용 할 수 있는 오픈소스 라이브러리
- BSD 라이센스를 갖고 있으며 상용 소프트웨어에서도 사용 할 수 있다
- C++, C, PYTHON, JAVA와 같은 다양한 언어를 원하고 다양한 OS에서 사용 가능





# Hello CV

```c++
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;
int main() {

	Mat img = imread("lena.jpg");
	imshow("image", img);
	waitKey();

	imwrite("lenna.bmp", img);

	destroyAllWindows();

	return 0;
}
```

`imread("lena.jpg");` : imread() 함수는 filename 영상 파일을 불러와 Mat객체로 변환하여 반환

`waitKey()` 키보드 입력을 받는 용도로 사용

`imwrite("lenna.bmp", img);` Mat 객체에 저장되어 있는 영상 데이터를 파일로 저장하기 위해 사용하는 함수





