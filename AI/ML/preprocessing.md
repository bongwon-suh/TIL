# Preprocessing

Gradient 알고리즘을 위한 데이터(x)의 전처리

![](https://github.com/bongwon-suh/TIL/blob/master/img/0917/05.JPG?raw=true)

2차원 데이터에서 x2 데이터들의 차이가 크기 때문에 다음과 같은 타원형 모영의 그래프가 그려 질 수 있다.  이러한 경우 잘못된 그래프가 그려 질 수 있다.

이런 경우를 방지하기 위해 일반화 과정을 거쳐야 한다.



### Regularization

![](https://github.com/bongwon-suh/TIL/blob/master/img/0917/06.JPG?raw=true)

일반화 과정에는 크게 2가지 방법이 있다.

1. Zero-centered data : 데이터의 중심이 0으로 가도록 함
2. Normalized data : 데이터가 범위 안에 항상 들어가도록 함

![](https://github.com/bongwon-suh/TIL/blob/master/img/0917/07.JPG?raw=true)