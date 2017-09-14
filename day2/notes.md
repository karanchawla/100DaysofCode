1. Lenses introduce distortion - light rays bend too much or too little around the edges. 

2. Radial distortion: caused by light rays bending too much ro too little around the edges of the lense/ 

3. Tangential distortion: caused when camera lense is not properly aligned with the imaging plane/film. 

4. Distortion coefficients: k1,k2,p1,p2,k3

5. To undistort points opencv calculates r,
	where r = ||(x_corrected,y_corrected) - (x_c,y_c)||
where x_c,y_c is the distortion center. 

6. Radial distortion correction formula: 
x_corr = x(1 + k1*r^2 + k2*r^4 + k3*r^6)
y_corr = y(1 + k1*r^2 + k2*r^4 + k3*r^6)

7. Tangential distortion correction formula:
x_corr = x + [2*p1*x*y + p2*(r^2+2*x^2)]
y_corr = y + [p1*(r^2 + 2*y^2) + 2*p2*x*y]


8. 
```
ret, corners = cv2.findChessBoardCorners(gray, (8,6), None)
img = cv2.drawChessBoardCorners(img, (8,6), corners, ret)
ret, mtx, dist, rvecs, tvecs = cv2.calibrateCamera(objpoints, imgpoints, gray.shape[::-1])
dst = cv2.undistort(img, mtx, dist, None, mtx)
```

9. Retrieving image shape 
```
height, width = img[::-1]

or 

ht, width = img[:2]
```

10. Lane Curvature
	1. Detect lane lines using masking and thresholding techniques 
	2. Perform perspective transform to get birds' eye view of the lane
	3. Fit polynomial to lane line f(y) = ay^2 + by + c
	4. Extract curvature of lane lines using a mapping
	5. a gives the curvature, b gives you the heading and c gives you the position of the line based on how away it is from the very left of an image. 

11. `M = cv2.getPerspectiveTransform(src, dst)`
`warped cv2.warpPerspective(img, M, img_size, flags=cv2.INTER_LINEAR)`
img: image to transform 
M: perspective matrix
img_size: size we want the warped image to be 
flags: how to interpolate points
returns warped image 

12. Gradient threshold: Canny edge detection - gave us many edges we ended up discarding

13. Sobel operstor: way of taking derivative of the image in x or y direction. 
sobel operators with a kernel size of 3 -> can be any number >= 3. A larger kernel implies taking the gradient over a larger region of the image i.e. a smoother gradient. 

14. 
```
gray = cv2.cvtColor(im, cv2.COLOR_RGB2GRAY)
web