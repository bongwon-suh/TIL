# 히스토그램

히스토그램이란 영상의 픽셀 값 분포를 그래프 형태로 표현하는것

그레이스케일의 경우, 픽셀의 갯수를 구하고, 이를 막대 그래프로 표현함으로써 히스토그램을 구할 수 있다.

히스토그램 그래프에서 가로축을 히스토그램의 빈(bin)이라 하고, 일반적으로 그레이스케일 영상에서는

256개의 빈을 갖는다.

OpenCV에서 히스토그램을 구하려면 `calcHist()` 함수를 사용한다.



```c++
void calcHist(const Mat* images, int nimages, const int* channels, InputArray mask,
              OutputArray hist, int dims, const int* histSize, const float** ranges,
              bool uniform=true, bool accumulate=false);
```

- images : 입력 영상의 배열 또는 입력 영상의 주소. 영상이 배열인 경우 영상의 크기와 깊이는 같아야함
- nimages : 입력 영상 갯수
- channels : 히스토그램을 구할 채널을 나타내는 정수형 배열
- mask : 마스크 영상. 입력 영상과 크기가 같은 8비트 배열이여 한다. 마스크 행렬의 원소 값이 0이 아닌
               좌표의 픽셀만 히스토그램 계산에 사용된다. mask 인자에 Mat() 또는 noArray()를 지정하면
               입력 영상 전체에 대한 히스토 그램을 구함
- hist : 출력 히스토그램 CV_32F 깊이를 사용하는 dims 차원의 행렬
- dims  : 출력 히스토그램의 차원 수
- histSize : 각 차원의 히스토그램 배열 크기를 나타내는 배열
- ranges : 각 차원의 히스토그램 범위. 등간격 히스토그램(uniform=true), ranges[i]는 각 차원의
                 최솟값과 최댓값으로 구성된 배열이고 범위를 나타냄
                 비등간격 히스토그램이면 ranges[i] 는 각각의 구역을 나타내는 histSize[i]+1개의 원소 배열 
- uniform : 히스토그램 빕ㅁ의 간격이 균등한지를 나타내는 플래그
- accumulate : 누적 플래그. true이면 hist배열을 초기화하지 않고 누적하여 히스토그램을 계산



