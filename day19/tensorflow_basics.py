import numpy as np 

x = np.random.normal(size=[10,10])
y = np.random.normal(size=[10,10])
z = np.dot(x,y)

# print(z)

import tensorflow as tf 

#Example 1
x = tf.random_normal([10,10])
y = tf.random_normal([10,10])

z = tf.matmul(x,y)

sess = tf.Session()
z_val = sess.run(z)

print(z_val)

#Example 2

# placeholders are used to feed values from python to Tf ops. We define two placeholders 
# one for input feature x and one for output y 
x = tf.placeholder(tf.float32)
y = tf.placeholder(tf.float32)

# since we know the size of the weights vector
w = tf.get_variable("w", shape=[3,1])

# define yhat to be an estimate of y
f = tf.stack([tf.square(x),x,tf.ones_like(x)], 1)
yhat = tf.squeeze(tf.matmul(f,w),1)


# The loss is defined ot be the l2 distance between our estimate of y and its true value
# adding a normalizing value on weights to prevent overfitting 
loss = tf.nn.l2_loss(yhat-y) + 0.1*tf.nn.l2_loss(w)

train_op = tf.train.AdamOptimizer(0.1).minimize(loss)

def generate_data():
	x_val = np.random.uniform(-10.0, 10.0, size=100)
	y_val = 5 * np.square(x_val) + 3
	return x_val, y_val 

sess = tf.Session()

sess.run(tf.global_variables_initializer())

for _ in range(1000):
	x_val, y_val = generate_data()
	_, loss_val = sess.run([train_op, loss], {x:x_val, y:y_val})
	# print(loss_val)

print(sess.run([w]))

# understanding static and dynamic types 
# Tensors in tf have a static shape attribute which is determined during graph construction. 
# The static shape may be underspecified. 

a = tf.placeholder(tf.float32, [None, 128])

# This means that the first dimension is dtermined dynamically during Session.run()

static_shape = a.shape.as_list()

dynamic_shape = tf.shape(a)

# It's convenient to have a function that returns the static shape when available and dynamic shape when it's not
def get_shape(tensor):
	static_shape = tensor.shape.as_list()
	dynamic_shape = tf.unstack(tf.shape(tensor))
	dims = [s[1] if s[0] is None else s[0]
			for s in zip(static_shape, dynamic_shape)]
	return dims 

b = tf.placeholder(tf.float32, [None, 10, 32])
shape = get_shape(b)
b = tf.reshape(b, [shape[0], shape[1]*shape[2]])

# general purpose reshape function 

def reshape(tensor, dims_ilfst):
	shape = getshape(tensor)
	dims_prod = []
	for dims in dims_list: 
		if isinstance(dims, int):
			dims_prod.append(shape[dims])
		elif all([isinstance(shape[d], int)] for d in dims):
			dims_prod.append(np.prod([shape[d] for d in dims]))
		else: 
			dims_prod.append(tf.prod([shape[d] for d in dims]))
		tensor = tf.reshape(tensor, dims_prod)
	return tensor

b = tf.placeholder(tf.float32, [None, 10, 32])
b = reshape(tensor, [0,[1,2]])

# tf introduces two different context managers to alter the name of the tesors - very much like namespaces in cpp 
with tf.name_scope("scope"):
	a = tf.constant(1, name="a")
	print(a.name) # prints "scope/a:0"

	b = tf.Variable(1, name="b")
	print(b.name) # prints "scope/b:0"

# tf_get_variable creates a new vairbale with the fiven name but raises a ValueError exception when trying to redeclare 
# tf.name_scope affects the names of the tensors and variables created with tf.Variable but doesn't affect the names of tensors created with 
# tf.get_variable 

# unnlike tf.name_scope tf.variable_scope modifies the names of the variables created with tf.get_variable as well. 

# RESUING PREVIOUSLY DECLARED VARIABLES
with tf.variable_scope("scope"):
	a1 = tf.get_variable(name = "a", shape=[])
with tf.variable_scope("scope", reuse=True):
	a2 = tf.get_variable(name="a", shape=[])

# comes in handy when building neural network layers 

features1 = tf.layers.conv2d(image1, filters=32, kernel_size=3)
# use the same convolutional weights to process the second image 
with tf.variable_scope(tf.get_variable_scope(), reuse=True):
	features2 = tf.layers.conv2d(image2, filters=32, kernel_size=3)

# Making templates in tf is easy peezy lemon squeezy: for example 
conv3x32 = tf.make_template("conv3x32", lambda x: tf.layers.conv2d(x, 32, 3))
features1 = conv3x32(image1)
features2 = conv3x32(image2)
# one can turn any function to a template using the syntax above. Upon the first call to a template, the variables 
# defined inside the function would be declared and in the consecutive invocations they would automatically get reused 

# Broadcasting the good and the ugly
def merge(a, b, units, activation=tf.nn.relu):
    pa = tf.layers.dense(a, units, activation=None)
    pb = tf.layers.dense(b, units, activation=None)
    c = pa + pb
    if activation is not None:
        c = activation(c)
    return c

# A general rule of thumb is to always specify the dimensions in reduction operations and when using tf.squeeze.

#Feeding data to tensorflow 

# Constants but not modular and can't store all data in the memory so only possible with very small datasets 
# Placeholders sovle both these problems 

data = tf.placeholder(tf.float32)

prediction = tf.square(data) + 1

actual_data = np.random.normal(size=[100])

tf.Session().run(prediction, feed_dict = {data:actual_data})

# Dataset API - the recommended way of reading the data in tf 
actual_data = np.random.normal(size=[100])
dataset = tf.contrib.data.Dataset.from_tensor_slices(actual_data)
data = dataset.make_one_shot_iterator().get_next()

# if you have created tfrecord files then use this 
datset = tf.contrib.data.Dataset.TFRecordDataset(path_to_data)

#overloaded operators in tf 
# Just like numpy, tf overloads a number of python operators to make building graphs easier and the code more readable
# Slicing operation is very costly though so don't use it. 

# tf doesn't allow using tensors as bools
# Instead use tf.cond, tf.equal or tf.not_equal 

# Understanding order of execution and control dependencies 
# Only use variables if tensors don't do the job. .

a = tf.constant(1)
b = tf.constant(2)

a = a+b

tf.Session().run(a)

# Evaluating 'a' will return 3 as expected. Note that here we are creating 3 tensors, two constant tensors and another tensor that stores the result of the addition. 
# Note that you can't overwrite the value of a tensor.If you want to modify it you have to create a new tensor. As we did here.

# Unlike tensors, variables can be updated. 
a = tf.Variable(1)
b = tf.constant(2)
assign = tf.assign(a, a+b)

sess = tf.Session()
sess.run(t.global_variables_initializer())
print(sess.run(assign))

# Note that tf.assign returns a tensor representing the value of the assignment. 
a = tf.Variable(1)
b = tf.constant(2)
c = a + b

assign = tf.assign(a,5)

sess = tf.Session()
for i in range(15):
	sess.run(tf.global_variables_initializer())
	print(sess.run(assign))

# Note that the tensor c here won't have a deterministic value It might be 3 or 7 depending on the order of whether assignment or addition gets execute first. 
# When dealing with variables, you may need to explicitly define dependencies using tf.control_dependencies() as follows: 

a = tf.Variable(1)
b = tf.constant(2)

c = a + b

with tf.control_dependencies([c]):
	assign = tf.assign(a, 5)

sess = tf.Session()
for i in range(10): 
	sess.run(tf.global_variables_initializer())
	print(sess.run([assign, c]))

# This will make sure that the assign op will be called after the addition

# Control flow operations: conditionals and loops 
# When building complex models such as RNNs we may need to control the flow of ops through conditionals and loops. 
# eg: suppose you want to decide whether to multiply or add two tensors based on a predicate. 

a = tf.constant(1)
