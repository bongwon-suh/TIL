# Neural Net for XOR

XOR은 하나의 모델로는 불가능하다고 증명이 됐고, 다수의 모델을 이용하여 XOR문제에 대해 풀이가 가능해 졌다고 한다.

![](https://github.com/bongwon-suh/TIL/blob/master/img/0920/01.JPG?raw=true)



### Backpropagation

Foward로 진행하여 얻은 값과 실제 값을 비교하여 얻은 error, 즉 cost를 통해 다시 뒤로 돌아가는 과정을 통해 설정값을 다시 알아내겠다는 개념

![](https://github.com/bongwon-suh/TIL/blob/master/img/0920/02.JPG?raw=true)

뒤에서 부터 하나씩 순서대로 계산해가면서 w와 b값을 구하는 과정



```python
import numpy as np
import tensorflow.compat.v1 as tf
tf.disable_v2_behavior()

x_data = np.array([[0, 0], [0, 1], [1, 0], [1, 1]], dtype=np.float32)
y_data = np.array([[0], [1], [1], [0]], dtype=np.float32)
X = tf.placeholder(tf.float32)
Y = tf.placeholder(tf.float32)

W1 = tf.Variable(tf.random_normal([2, 2]), name='weight1')
b1 = tf.Variable(tf.random_normal([2]), name='bias1')
layer1 = tf.sigmoid(tf.matmul(X, W1) + b1)

W2 = tf.Variable(tf.random_normal([2, 1]), name='weight2')
b2 = tf.Variable(tf.random_normal([1]), name='bias2')
hypothesis = tf.sigmoid(tf.matmul(layer1, W2) + b2)

# cost/loss function
cost = -tf.reduce_mean(Y * tf.log(hypothesis) + (1 - Y) * tf.log(1 - hypothesis))
train = tf.train.GradientDescentOptimizer(learning_rate=0.1).minimize(cost)
# Accuracy computation
# True if hypothesis>0.5 else False
predicted = tf.cast(hypothesis > 0.5, dtype=tf.float32)
accuracy = tf.reduce_mean(tf.cast(tf.equal(predicted, Y), dtype=tf.float32))
# Launch graph
with tf.Session() as sess:
   # Initialize TensorFlow variables
   sess.run(tf.global_variables_initializer())
   for step in range(10001):
       sess.run(train, feed_dict={X: x_data, Y: y_data})
       if step % 100 == 0:
           print(step, sess.run(cost, feed_dict={X: x_data, Y: y_data}), sess.run([W1, W2]))

   # Accuracy report
   h, c, a = sess.run([hypothesis, predicted, accuracy],
                      feed_dict={X: x_data, Y: y_data})
   print("\nHypothesis: ", h, "\nCorrect: ", c, "\nAccuracy: ", a)

```

