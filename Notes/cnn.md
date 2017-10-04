1. Unlike a regular Neural network, the layers of a ConvNet have neurons arranged in 3 dimensions: width, height and depth. 

2. Kinds of layers in CNNs:
	1. Input[32x32x3] : image input for eg: CIFAR10
	2. CONV layer will compute the output of neurons that are connected to local regiuons in the input, each computing a dot product between their weights and 
	a small region they are connected to in the input volume. This may result in volume such as [32x32x12] if we decided to use 12 filters. 
	3. RELU will apply an alementwise activation function such as max(0,x) thresholding at zero. This leaves the size of the volume unchanged (32x32x12)
	4. POOL layer will perform a downsampling operation along the spatial dimensions resulting in a volume such as (16x16x12)
	5. FULLY CONNECTED layer will compute the class scores resulting in vol size [1x1x10] where each of the 10 numbers correspond to a class score such as
	among the 10 categories of CIFAR. 

3. The layers are trained with gradient descent or batch gradient descent. 

4. Convolutional Layer: 
	1. SLide each filter across the width and height of the image and compute the dot products between entries of the filter and the input at the position.
	2. This produces a 2D activation map that gives responses of that filter at every spatial position. Intuitively, the network learns filters that activate whent they
	see some feature in the image.  
	3. Local connectivity: suppose the input volume has a size of 32x32x3, if the filter size is 5x5 then each neuron in the conv layer will have weights to a [5x5x3]
	region in the input volume for a total of 75 weights and 1 bias vector. 
	4. Spatial Arrangement: Three hyperparams control the size of the output volume: depth, stride and zero-padding. 
		1. Depth of the output volume is a hyperparam, it corresponds to the number of filters we would like to use, each learning to look for something different in the input. 
		2. Stride is with what we slide the filter. When the stride is 1 then we move the filters one pixel at a time. When the stride is 2 then the filters jump 2 pixels at a time.
		This will produce smaller output volumes. 
		3. The size of the zero padding is a hyper param. The nice feature of zero padding is that it will allow us to control the spatial size of the output volumes. 

5. We can compute the spatial size of the output volume as a function of the input volume size(W), the filter size (F) and the stride size (S) and the amount of zero padding(P) on the border.
The formula is (W-F+2P)/S+1. For eg for a 7x7 input and a 3x3 filter with a tride 1 and a pad 0 we would get a 5x5 output. 

6. Strides and zero padding are constrained using the above formula. The result of using the above formula must be an integer for the neurons to fit symmetrically. 

7. Parameter Sharing: We contraint the neurons in each depth slice to use the same weights and bias.  

8. BackProp: The backward pass for a convolution operation is alose a convolution but with spatially flipped filters. 

9. Dilated convolutions: introduce another hyperparam called dialation which corresponds to the spaces between each cell, called dialation. 

10. Pooling layer: insert pooling layer b/w successive conv layers. Function is to progressively reduce spatial size of the representation to reduce the amount of params and computation in the network. 
Most common kind of pooling layer is filter with size of 2x2 with stride 2 downsamples every depth slice in the input by 2 along both width and height. The depth dimension remains unchanged. 
Other pooling operations such as max pooling or average pooling work too. Max pooling  > average pooling. works better in practise. Seems likely that future architectures will feature very few to no pooling layers. 

11. ConvNet Architectures 
	1. Layer Patterns: The most common form of a ConvNet architecture stacks a few CONV-RELU layers, follows them with POOL and FC. We will also explicitly write the RELU activation function as a layer,
	which applies elementwise non linearity. 

	The most common architecture is as follows: INPUT -> [[CONV -> RELU]*N -> POOL?]*M -> [FC -> RELU]*K -> FC
	where * indicates repetition and the POOL? indicates an optional pooling layer. Moreover, N>=0(and N<=3, M>=0, K>=0 && K<=3). 

	2. In practise use whatever works best on ImageNet. "Don't be a hero"

12. Layer Sizing Patterns 
	1. The input layer shoudl be divisible by 2 many times. 
	2. The conv layers should be using small filters using a stride of 1 and crucially padding the input volume with zeros in such a way that the conv layer does not alter the spatial dimensions of the input. 
	P = (F-1)/2 preserves the input size. 
	3. The pool layers are in charge of downsampling the spatial dimensions of the input. 2x2 filters with a stride of 2 is the most common size. 
	4. Why use stride of 1 in conv? Smaller strides work better in practise with the CONV layers only transforming the input volume depth-wise. 
	5. Why use padding? In addition to the aforementioned benefit of keeping the spatial dimensions constant after CONV, doing this actually improves performance. Prevents the information of the borders
	from being washed away. 