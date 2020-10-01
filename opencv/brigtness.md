# 영상의 밝기 조절

영상의 전체적인 밝기를 조절하여 밝거나 어두운 영상을 만드는 일

영상의 밝기 조절을 위해서는 입력 영상의 모든 필셀에 일정 값을 더하거나 빼는 작업을 수행하게 된다.

![](https://github.com/bongwon-suh/TIL/blob/master/img/1001/01.jpg?raw=true)

src는 입력 영상,  dst는 출력 영상, n은 조절할 밝기

행렬의 원소 값을 설정할 때, 자료형이 갖는 값의 범위를 벗어나는 경우 자료형의 조지솟값 또는 최댓값으로 원소 값을 설정하는 연산을 `포화연산`이라고 부르고 다음과 같은 수식으로 표현 가능하다.

![](https://github.com/bongwon-suh/TIL/blob/master/img/1001/02.jpg?raw=true)



그러므로 실제 밝기 조절을 구현할 때에는 포화연산을 함께 고려한 수식을 사용한다.

![](https://github.com/bongwon-suh/TIL/blob/master/img/1001/03.png?raw=true)

