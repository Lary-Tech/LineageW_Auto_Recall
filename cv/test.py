import cv2
import numpy as np
from matplotlib import pyplot as plt
 
img = cv2.imread("./image/21-44-03-201_2022-03-13_neokubski_Image.jpg")  
img2 = img.copy()
template = cv2.imread("./image/21-44-03-201-red_plot.png")  
w = template.shape[1]
h = template.shape[0]
 
# All the 6 methods for comparison in a list
methods = ['cv2.TM_CCOEFF', 'cv2.TM_CCOEFF_NORMED', 'cv2.TM_CCORR',
            'cv2.TM_CCORR_NORMED', 'cv2.TM_SQDIFF', 'cv2.TM_SQDIFF_NORMED']
 
for meth in methods:
    img = img2.copy()
    method = eval(meth)
 
    # Apply template Matching
    res = cv2.matchTemplate(img,template,method)
    min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(res)
 
    # If the method is TM_SQDIFF or TM_SQDIFF_NORMED, take minimum
    if method in [cv2.TM_SQDIFF, cv2.TM_SQDIFF_NORMED]:
        top_left = min_loc
    else:
        top_left = max_loc
    bottom_right = (top_left[0] + w, top_left[1] + h)
 
    cv2.rectangle(img,top_left, bottom_right, 255, 2)
 
    cv2.imshow('g',res)
    #plt.title('Matching Result'), plt.xticks([]), plt.yticks([])
    cv2.imshow('i', img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    