/*

Reading a image
----------------

Instructions to run the code
-----------------------------

> g++ 2_program.cpp -o app `pkg-config --cflags --libs opencv`
> ./app

*/



#include <opencv2/highgui.hpp>
#include "opencv2/core/core.hpp"
#include <iostream>


//name space
using namespace std;
using namespace cv;



int main(int argc,char** argv){

  cv::Mat image;
  image = cv::imread("sample_two.jpeg",CV_LOAD_IMAGE_COLOR);
  if(!image.data){
      std::cout<<"could not open or find image"<<std::endl;
      return -1;
  }


  cv::namedWindow("Display window",cv::WINDOW_AUTOSIZE);
  cv::imshow("Display window",image);

  cv::waitKey(0);
  return 0;

}

// x,y,width,height
// x denotes from how much distance ROI of x start
// y denotes from how much distance ROI of y start
// width denotes how much width the picture should be
// height denotes how much height the picture should be