# Overfitting

머신러닝의 학습을 통해서 모델을 만들어 가는데 이 학습 데이터에 딱 맞는 모델을 만들어 실제 테스트 결과가 알많지 않는것을 도출하는 상황이다.

- Our model is very good with training data set (with memorization)
- Not good at test dataset or in real use

![](https://github.com/bongwon-suh/TIL/blob/master/img/0917/08.JPG?raw=true)



### Solutions for overfitting

1. More training data
2. Reduce the number of features
3. Regularization



### Regularization

가지고 있는 weight을 너무나 큰 값을 가지지 않도록 하는것

Cost function은 cost값을 최소화 시키는 것이였는데, 이 함수 뒤에 term을 추가를 해준뒤 W의 값이 작아질 수 있도록 하는것이다.

regularization strength가 0이 되면 이 값을 사용하지 않겠다는 의미

![](https://github.com/bongwon-suh/TIL/blob/master/img/0917/09.JPG?raw=true)

