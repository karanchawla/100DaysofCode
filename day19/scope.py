import tensorflow as tf 

with tf.name_scope("scope"):
	a = tf.constant(1, name="a")
	print(a.name) 

	b = tf.Variable(1, name="b")
	print(b.name) 

	c = tf.get_variable(name="c", shape=[])
	print(c.name)

'''
Output 
scope/a:0
scope/b:0
'''

with tf.variable_scope("scope"):
	a = tf.constant(1, name="a")
	print(a.name) 

	b = tf.Variable(1, name="b")
	print(b.name) 

	c = tf.get_variable(name="c", shape=[])
	print(c.name)