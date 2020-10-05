# 영상의 필터링

영상의 필터링은 마스크(mask)라 부르는 작은 크기의 행렬을 이용한다.

필터링 연산의 결과는 마스크 행렬의 모양과 원소 값에 의해 결정된다.

마스크를 이용한 필터링은 입력 영상의 모든 픽셀 위로 마스크 행렬을 이동시키면서 마스크 연산을 수행하는 방식으로 이루어진다.

마스크 연산이란 마스크 행렬의 모든 원소에 대하여 마스크 행렬 원소 값과 같은 위치에 있는 입력 영상 픽셀 값을 서로 곱한 후, 그 결과를 모두 더하는 연산이다. 3x3 마스크 행렬에 대한 수식으로 나타내면 다음과 같다.

![](https://github.com/bongwon-suh/TIL/blob/master/img/1005/03.JPG?raw=true)

![](https://github.com/bongwon-suh/TIL/blob/master/img/1005/04.JPG?raw=true)

영상의 가장자리 픽셀에는 수식을 그대로 적용하기 어렵기 때문에 OpenCV에서 영상의 필터링을 수행할 때, 영상의 가장자리 픽셀을 확장하여 가상의 픽셀을 만든다.



OpenCV에서 필터 마스크를 사용하는 일반적인 필터링은 `filter2D()`함수를 이용한다.

```c++
void filter2D(InputArray src, OutputArray dst, int ddepth, InputArray kernel,
              Point anchor=Point(-1,-1), double delta=0, int borderType=BORDER_DEFAULT)
```

- src : 입력 영상
- dst : 출력 영상
- ddepth : 결과 영상의 깊이
- kernel : 필터링 커널
- anchor : 고정점 좌표
- delta : 필터링 연산 후 추가적으로 더할 값
- borderType : 가장자리 픽셀 확장방식



### 엠보싱 필터링

엠보싱 필터링은 직물이나 종이 금속판 등에 올록볼록한 형태로 만든 객체의 윤곽 또는 무늬로 만드는 필터링

입력 영상에서 필셀 값 변화가 적은 평탄한 영역은 회색으로 설정하고, 객체의 경계 부분은 좀 더 밝거나 어둡게 설정하면 된다.



