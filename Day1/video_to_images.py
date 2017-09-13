import cv2

cap = cv2.VideoCapture('/path/to/video') #import video

count = 0
n = 360 #Number of frames to skip
while cap.isOpened():
    ret,frame = cap.read() # Read video frame
    cv2.imshow('Video Annotation',frame) 
    cv2.imwrite("frame%d.jpg" % count, frame) #Save every nth frame
    count = count + n
    if cv2.waitKey(10) & 0xFF == ord('q'):
        break


cap.release()
cap.destroyAllWindows()