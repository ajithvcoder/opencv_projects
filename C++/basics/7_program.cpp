
/*

Applying a brightness to a image
-----------------------------------

Instructions to run the code
-----------------------------

> g++ 7_program.cpp -o app `pkg-config --cflags --libs opencv`
> ./app lion.jpg


*/




#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

#include <cv.h>
#include <highgui.h>
#include <iostream>

using namespace cv;
using namespace std;

double alpha;
int beta;

int main(int argc,char** argv)
{
    Mat image=imread(argv[1]);
    Mat new_image=Mat::zeros(image.size(),image.type());

    cout<<"Enter alpha value [1.0-3.0]:";
    cin>>alpha;
    cout<<"Enter beta value [0-100]:";
    cin>>beta;


    image.convertTo(new_image,-1,alpha,beta);
/*
instead of image.convertTO you can below loop

    for(int y=0;y<image.rows;y++)
        { for( int x=0;x<image.cols;x++)
            {
                for(int c=0;c<3;c++)
                    {
                        new_image.at<Vec3b>(y,x)[c]=saturate_cast<uchar>(alpha*(image.at<Vec3b>(y,x)[c]) + beta);
                    }

            }


        }
*/

    imshow("Orginal Image",image);
    imshow("New Image",new_image);


    waitKey();
    return 0;

}

