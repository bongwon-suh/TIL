# RNN

### Sequence Data

우리가 사용하는 데이터들은 시퀀스 데이터들이 많은데, 그 중 한 예로,자연어 처리가 있다.

하나의 단어만 이해해서는 문맥을 이해하지 못하는데, 이전의 말했던 단어들을 이해 한 후 문맥 이해를 할 수 있게 된다 이것이 sequence data의 한 예이다.

기존 뉴럴 네트워크 시스템에서는 x라는 입력이 있으면 y출력하게 되는데 이 경우에 sequence data를 처리하기 용이하지 못하다.

이전의 했던 연산이 다음에 연산에 영향을 미쳐야하는데, 그래서 해보자고 한것이 아래와 같은 그림이다.

![](https://github.com/bongwon-suh/TIL/blob/master/img/0926/01.JPG?raw=true)

현재 state가 미래의 state에 영향을 미치게 된다.

즉, 어떤 시점에서의 연산이 이전의 연산을 영향을 받게 된다.

![](https://github.com/bongwon-suh/TIL/blob/master/img/0926/02.JPG?raw=true)





### Vanilla Recurrent Neural Network

![](https://github.com/bongwon-suh/TIL/blob/master/img/0926/03.JPG?raw=true)

입력에 대한 각각의 weight값을 만들어준 다음 tanh로 새로운 h값과 y값 출력을 하게 된다.



### RNN applications

- Language Modeling
- Speech Recognition
- Machine Translation
- Converstation Modeling / Question Answering
- Image/Video Captioning
- Image/Music/Dance Generation



![](https://github.com/bongwon-suh/TIL/blob/master/img/0926/04.JPG?raw=true)