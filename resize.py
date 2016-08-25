import glob
import os
from PIL import Image
import cv2

FILETYPES = ['test/1/*.jpg','test/1/*.jpeg','test/1/*.png']
Blurrness_Threshold = 100

def detectImageBlurrness(image):
     return cv2.Laplacian(image, cv2.CV_64F).var()

def convertImage2jpeg():
    for types in FILETYPES:
        openFiles = glob.glob(types)
        for files in openFiles:
            inFile = Image.open(files)
            fileName = os.path.splitext(files)[0]
            print(fileName)
            input_Image = cv2.imread(files)
            resized_image = cv2.resize(input_Image, (256, 256))
            Gray_Image = cv2.cvtColor(resized_image,cv2.COLOR_BGR2GRAY)
            blurness_Level = detectImageBlurrness(Gray_Image)

            if(blurness_Level < Blurrness_Threshold):
                print 'Image is not clear'
                print "image: %s  Blurness level: %s" % (files, blurness_Level)

                print "This image is dicarded"
                continue

             # gets filename


            outputFile = 'final_'+fileName + ".jpeg"
            cv2.imwrite(outputFile,resized_image)

    print "\n"
    return None


if __name__ == '__main__':
    print "########## Checking the Image blurrness and convert to .jpeg format from DATABASE ##########"

    convertImage2jpeg()

    print "########## End ############"


