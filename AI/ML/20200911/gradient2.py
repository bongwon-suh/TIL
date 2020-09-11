import matplotlib.pyplot as plt
import tensorflow.compat.v1 as tf
tf.disable_v2_behavior()

X = [1,2,3]
Y = [1,2,3]

W = tf.Variable(-3.0)
hypothesis = X * W
cost = tf.reduce_mean(tf.square(hypothesis - Y))
optimizer = tf.train.GradientDescentOptimizer(learning_rate=0.1)
train = optimizer.minimize(cost)

sess = tf.Session()
sess.run(tf.global_variables_initializer())

W_val=[]
cost_val=[]

for step in range(100):
    print(step, sess.run(W))
    sess.run(train)
