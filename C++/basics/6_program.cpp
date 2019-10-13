/*

Applying a filter/kernel to a image
-----------------------------------

Instructions to run the code
-----------------------------

> g++ 6_program.cpp -o app `pkg-config --cflags --libs opencv`
> ./app sample_two.jpeg



*/



#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main(int argc,char* argv[])
{
    Mat src,dst0,dst1;
    const char* filename=argc>=2 ? argv[1]: "sample_two.jpeg.jpg";

    if(argc>=3 && !strcmp("G",argv[2]))
    {
        src=imread(filename,IMREAD_GRAYSCALE);
        cout<<"gray";
    }
    else
        src=imread(filename,IMREAD_COLOR);

    namedWindow("Input",WINDOW_AUTOSIZE);
    namedWindow("Output",WINDOW_AUTOSIZE);
    
    imshow("Input",src);

    Mat kernel=(Mat_<char>(3,3) << 0,-1,0,
                                    -1,5,-1,
                                    0,-1,0);

    filter2D(src,dst1,src.depth(),kernel);

    imshow("Output",dst1);
    waitKey();
    return 0;


}
