import numpy as np
import cv2
import os

ps = ['21-44-03-201_2022-03-13_neokubski_Image.jpg', 
      '22-02-50-086_2022-03-13_neokubski_Image.jpg', 
      '22-03-22-133_2022-03-16_neokubski_Image.jpg',
      '22-09-05-656_2022-03-14_neokubski_Image.jpg',
      '23-49-24-037_2022-03-15_neokubski_Image.jpg',
      '22-59-13-501_2022-03-13_neokubski_Image.jpg']

for i in range(6):
    image = './image/' + ps[i]
    savefile = './res/1.png'
    # image = os.listdir(image_file)
    save_image = os.path.join(savefile, image)

    #设定颜色HSV范围，假定为红色
    redLower = np.array([38, 30, 140])
    redUpper = np.array([91, 67, 160])

    #设定颜色HSV范围，假定为红色
    greenLower = np.array([50, 150, 100])
    greenUpper = np.array([155, 255, 250])

    #读取图像
    img = cv2.imread(image)

    #去除颜色范围外的其余颜色
    mask = cv2.inRange(img, redLower, redUpper)
    #去除颜色范围外的其余颜色
    mask2 = cv2.inRange(img, greenLower, greenUpper)

    # 二值化操作
    ret, binary = cv2.threshold(mask, 0, 255, cv2.THRESH_BINARY)
    # 二值化操作
    ret2, binary2 = cv2.threshold(mask2, 0, 255, cv2.THRESH_BINARY)

    #膨胀操作，因为是对线条进行提取定位，所以腐蚀可能会造成更大间隔的断点，将线条切断，因此仅做膨胀操作
    kernel = np.ones((5, 5), np.uint8)
    dilation = cv2.dilate(binary, kernel, iterations=1)

    #膨胀操作，因为是对线条进行提取定位，所以腐蚀可能会造成更大间隔的断点，将线条切断，因此仅做膨胀操作
    kernel = np.ones((5, 5), np.uint8)
    dilation2 = cv2.dilate(binary2, kernel, iterations=2)

    #获取图像轮廓坐标，其中contours为坐标值，此处只检测外形轮廓
    contours, hierarchy = cv2.findContours(dilation, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    #获取图像轮廓坐标，其中contours为坐标值，此处只检测外形轮廓
    contours2, hierarchy2 = cv2.findContours(dilation2, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)


    cv2.imshow('image', img)
    cv2.imshow('dia', dilation2)
    cv2.waitKey(0)

    if len(contours) > 0:
        #cv2.boundingRect()返回轮廓矩阵的坐标值，四个值为x, y, w, h， 其中x, y为左上角坐标，w,h为矩阵的宽和高
        boxes1 = [cv2.boundingRect(c) for c in contours]
        boxes2 = [cv2.boundingRect(c) for c in contours2]

        #   for box in boxes1:
        #     x, y, w, h = box
        #     if w > 16 or h > 16 or w < 5 or h < 5 or h - w > 1 or w - h > 1:
        #         continue

        #     cv2.destroyAllWindows()
        #     #绘制矩形框对轮廓进行定位
        #     cv2.rectangle(img, (x, y), (x+w, y+h), (255, 0, 0), 2)
        # 	#将绘制的图像保存并展示
        #     cv2.imwrite(save_image, img)
        #     cv2.imshow('image', img)

        #   for box in boxes2:
        #     x, y, w, h = box
        #     if w > 37 or h > 37 or w < 18 or h < 18 or h - w > 3 or w - h > 3:
        #         continue

        #     cv2.destroyAllWindows()
        #     #绘制矩形框对轮廓进行定位
        #     cv2.rectangle(img, (x, y), (x+w, y+h), (0, 255, 0), 2)
        # 	#将绘制的图像保存并展示
        #     cv2.imwrite(save_image, img)
        cv2.imshow('image', img)

        for box in boxes2:
            x, y, w, h = box
            if w > 33 or h > 33 or w < 18 or h < 18 or h - w > 3 or w - h > 3:
                continue
            
            flag = 0
            for redbox in boxes1:
                X, Y, W, H = redbox
                if X + W >= x and X + W <= x+w and Y + H >= y and Y + H <= y + h and W <=10 and H <= 10 and (x >= 300 or y >= 300):
                    print(x, " ", y)
                    flag = 1
                    break
                else:
                    flag = 0

            if flag == 0:
                continue

            cv2.destroyAllWindows()
            #绘制矩形框对轮廓进行定位
            cv2.rectangle(img, (x, y), (x+w, y+h), (0, 0, 255), 2)
            #将绘制的图像保存并展示
            cv2.imwrite(save_image, img)
            cv2.imshow('image', img)
            


        cv2.waitKey(0)
        cv2.destroyAllWindows()
