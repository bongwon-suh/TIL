# Convolutional Neural Networks

![](https://github.com/bongwon-suh/TIL/blob/master/img/0922/01.JPG?raw=true)

CNN 아이디어는 고양이 실험에서 시작

고양이에게 그림을 보여줬더니, 뉴런들이 동시에 동작하는것이 아닌 특정 뉴런들만 동작

여기에 착안해서 입력을 나누어 받는것을 하게 됨



![](https://github.com/bongwon-suh/TIL/blob/master/img/0922/02.JPG?raw=true)

처음에 32x32x3의 컬러 이미지를 입력을 받을 때 이미지의 일부분(5x5x3)만 필터 처리를 함

필터가 하는 일은 한개의 값을 만들어냄

이렇게 똑같은 필터를 가지고 전체 이미지를 한번씩 훑게 됨

![](https://github.com/bongwon-suh/TIL/blob/master/img/0922/03.JPG?raw=true)

N x N 사이지의 이미지가 있고 필터 사이즈를 F x F 라 했을때  Output의 크기는 (n-f/stride)+1

stride는 몇 칸을 건너 띌건지에 대한 값이고, stride 값이 커질수록 output 사이즈가 작아지게 되면서  어떤 정보를 잃어버리게 된다고 할 수 있음

![](https://github.com/bongwon-suh/TIL/blob/master/img/0922/04.JPG?raw=true)

이런 정보 손실을 방지하기 위해서 padding 개념을 사용함

padding은 우선 테두리에다 0을 입력 만들어주게 되고 padding의 사용 이유로는,

1. 그림이 급격하게 작아지는것을 방지하기 위한것

2. 모서리를 인식하기 위함

7x7의 인풋이 있고 3x3의 필터를 사용한다고 했을 때, padding 적용시 output도 7x7이 됨

이처럼 패딩은 원래 입력의 이미자와 출력의 이미지가 같아지게끔 함

![](https://github.com/bongwon-suh/TIL/blob/master/img/0922/05.JPG?raw=true)

여러개의 필터를 중첩해서 사용하여 나온 아웃풋을 Convolution Layer

![](https://github.com/bongwon-suh/TIL/blob/master/img/0922/06.JPG?raw=true)

이렇게 여러개의 Convolution Layer 적용이 가능함