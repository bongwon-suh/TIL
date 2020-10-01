# 영상의 밝기 조절

영상의 전체적인 밝기를 조절하여 밝거나 어두운 영상을 만드는 일

영상의 밝기 조절을 위해서는 입력 영상의 모든 필셀에 일정 값을 더하거나 빼는 작업을 수행하게 된다.

![](https://github.com/bongwon-suh/TIL/blob/master/img/1001/01.jpg?raw=true)

src는 입력 영상,  dst는 출력 영상, n은 조절할 밝기

행렬의 원소 값을 설정할 때, 자료형이 갖는 값의 범위를 벗어나는 경우 자료형의 조지솟값 또는 최댓값으로 원소 값을 설정하는 연산을 `포화연산`이라고 부르고 다음과 같은 수식으로 표현 가능하다.

![](https://github.com/bongwon-suh/TIL/blob/master/img/1001/02.jpg?raw=true)



그러므로 실제 밝기 조절을 구현할 때에는 포화연산을 함께 고려한 수식을 사용한다.

![](https://github.com/bongwon-suh/TIL/blob/master/img/1001/03.png?raw=true)



```c++
void brightness2() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image Load failed" << endl;
		return;
	}

	Mat dst(src.rows, src.cols, src.type());

	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			dst.at<uchar>(j, i) = src.at<uchar>(j, i) + 100;
		}
	}

	imshow("src", src);
	imshow("dst", dst);
	waitKey();

	destroyAllWindows();
}
```

위 코드는 영상의 모든 픽셀 값에 100을 더하게 되는 코드인데,

매우 밝은 영역과 어두운 영역이 비정상적으로 섞여 있는데, 포화연산을 수행하지 않았기 떄문이다.

unsigned char 자료형은 1바이트 메모리 공간을 사용하는데 256을 대입할 경우 0으로 변환되어 저장되는 

문제가 발생하게 된다.

이런 포화 연산을 수행하는 캐스팅 함수를 지원한다.



```c++
template<> inline
uchar saturate_cast<uchar>( int V);
```

- 반환값 : 0~255 사이의 정수



