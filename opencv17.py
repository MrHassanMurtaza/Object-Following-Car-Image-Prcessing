import numpy as np
import cv2
import serial

ser = serial.Serial('COM10', 9600)

# multiple cascades: https://github.com/Itseez/opencv/tree/master/data/haarcascades

#https://github.com/Itseez/opencv/blob/master/data/haarcascades/haarcascade_frontalface_default.xml
##face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
face_cascade = cv2.CascadeClassifier('haarcascade_fullbody.xml')


#https://github.com/Itseez/opencv/blob/master/data/haarcascades/haarcascade_eye.xml
##eye_cascade = cv2.CascadeClassifier('haarcascade_fullbody.xml')

cap = cv2.VideoCapture(1)
counter = 0
prevHeight = 320
while True:
    
    ret, img = cap.read()
    width, height, channels = img.shape
   # print height
    
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray)

    for (x,y,w,h) in faces:
        if h > prevHeight:
            prevHeight = h
        cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)
        if x+w > ((width/4)*3):
            ser.write(str(3));
        elif x < width/4:
            ser.write(str(2));

        if h < prevHeight:
            ser.write(str(1));
            prevHeight = h
        if h < 250:
            ser.write(str(1));
            
##        roi_gray = gray[y:y+h, x:x+w]
##        roi_color = img[y:y+h, x:x+w]
##        
##        eyes = eye_cascade.detectMultiScale(roi_gray)
##        for (ex,ey,ew,eh) in eyes:
##            cv2.rectangle(roi_color,(ex,ey),(ex+ew,ey+eh),(0,255,0),2)

    cv2.imshow('img',img)
    k = cv2.waitKey(30) & 0xff
    if k == 27:
        break

cap.release()
cv2.destroyAllWindows()
