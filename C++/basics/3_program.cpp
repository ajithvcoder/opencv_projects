/*
Reading a image and finding ROI
------------------------------


Instructions to run the code
-----------------------------

> g++ 3_program.cpp -o app `pkg-config --cflags --libs opencv`
> ./app

*/



#include <opencv2/highgui.hpp>
#include "opencv2/core/core.hpp"

#include <iostream>
using namespace std;
using namespace cv;

int main(int argc,char** argv){

  Mat image;

  image = cv::imread("sample_two.jpeg",CV_LOAD_IMAGE_COLOR);
  if(!image.data){
      cout <<"could not open or find image"<< endl;
      return -1;
  }


  Mat D(image,Rect(50,50,100,100)); //using a rectangle
  // Rect(x,y,width,height)
  // from point 50,50 (x,y) 100 pixels to right and 100 pixels down are taken .



  namedWindow("Display window",cv::WINDOW_AUTOSIZE);
  imshow("Display window",D);

  waitKey(0);
  return 0;

}

// x,y,width,height
// x denotes from how much distance ROI of x start
// y denotes from how much distance ROI of y start
// width denotes how much width the picture should be
// height denotes how much height the picture should be