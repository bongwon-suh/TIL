# Softmax Regression

### Multinomial Classification

- 결과 값이 2개 이상으로 분류가 되는것

- 예제

  - 공부시간, 수업 참석일에 대한 성적

  ![](https://github.com/bongwon-suh/TIL/blob/master/img/0915_07.jpg?raw=true)

  ![](https://github.com/bongwon-suh/TIL/blob/master/img/0915_08.jpg?raw=true)

  - 위 표와 그래프에서 보듯 3가지의 Binary Classification을 찾을 수 있다.

    1. A or not
    2. B or not
    3. C or not

    이 3가지 경우를 하나의 수식으로 나타내면,
    $$
    \begin{pmatrix} W_{A1} & W_{A2} & W_{A3}\\ W_{B1} & W_{B2} & W_{B3}\\ W_{C1} & W_{C2} & W_{C3} \end{pmatrix} \begin{pmatrix} X_{1}\\ X_{2}\\ X_{3} \end{pmatrix} = \begin{pmatrix} \overline{Y_{A}}\\ \overline{Y_{B}}\\ \overline{Y_{C}} \end{pmatrix}
    $$

### 

예를들어 어떤 값을 연산한 결과 아래와 같은 값을 얻었다고 했을 때,
$$
\begin{pmatrix} W_{A1} & W_{A2} & W_{A3}\\ W_{B1} & W_{B2} & W_{B3}\\ W_{C1} & W_{C2} & W_{C3} \end{pmatrix} \begin{pmatrix} X_{1}\\ X_{2}\\ X_{3} \end{pmatrix} = \begin{pmatrix} 2.0\\ 1.0\\ 0.1 \end{pmatrix}
$$
2.0이 가장 큰 값으로 어떤 값은 A라고 예측할 수 있지만 sigmoid함수를 사용하여 0~1 사이의 값을 받아 분류 할 수 있다. 그리고 0~1사이의 값으로 확률(p) 값으로 바꿀것이다.

이때 필요 한것이 Softmax함수이다.

![](https://github.com/bongwon-suh/TIL/blob/master/img/0915_09.jpg?raw=true)

Softmax 함수를 사용하여 확률이 나오게 되면 이를 One-HOT encoding을 이용하요 제일 큰 값을 1로 나머지를 0으로 바꿔주면 된다.



### Cross-entropy cost function

$$
D(S, L)=-\sum_{i}^{}L_{i}log(S_{i})
$$

$$
Loss=\frac{1}{n}\sum_{i}^{}(S(WX+b),L_{i})
$$



```python
import tensorflow.compat.v1 as tf
tf.disable_v2_behavior()

x_data = [[1,2,1,1,],[2,1,3,2],[3,1,3,4],[4,1,5,5],[1,7,5,5],[1,2,5,6],[1,6,6,6],[1,7,7,7]]
y_data = [[0,0,1],[0,0,1],[0,0,1],[0,1,0],[0,1,0],[0,1,0],[0,0,1],[0,0,1]]

X = tf.placeholder(tf.float32, shape=[None, 4])
Y = tf.placeholder(tf.float32, shape=[None, 3])
nb_classes = 3

W = tf.Variable(tf.random_normal([4, nb_classes]), name='weight')
b = tf.Variable(tf.random_normal([nb_classes]), name='bias')

hypothesis = tf.nn.softmax(tf.matmul(X, W)+b)

cost = tf.reduce_mean(-tf.reduce_sum(Y*tf.log(hypothesis), axis=1))
optimizer = tf.train.GradientDescentOptimizer(learning_rate=0.1).minimize(cost)

with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())

    for step in range(2001):
        sess.run(optimizer, feed_dict={X: x_data, Y:y_data})
        if step % 200 == 0:
            print(step, sess.run(cost, feed_dict={X: x_data, Y: y_data}))

    a = sess.run(hypothesis, feed_dict={X: [[1,11,7,9]]})
    print(a, sess.run(tf.arg_max(a,1)))
```

