/*

Scanning a image
----------------

Instructions to run the code
-----------------------------

> g++ 5_program.cpp -o app `pkg-config --cflags --libs opencv`
> ./app sample_two.jpeg 20 [G]

*/



#include <bits/stdc++.h>
#include <opencv2/core.hpp>
#include <opencv2/core/utility.hpp>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>
#include <iostream>
#include <sstream>



using namespace std;
using namespace cv;


Mat& ScanimageAndReduceIterator(Mat& I,const uchar* table);

int main(int argc,char* argv[]){

    if (argc <3)
    {
        cout<< "Not enough parameters"<<endl;
        return -1;

    }
    Mat I,J;
    if(argc==4 && !strcmp(argv[3],"G"))
        I=imread(argv[1],IMREAD_GRAYSCALE);
    else
        I = imread(argv[1],IMREAD_COLOR);

    if(I.empty())
    {
        cout<<"The image"<<argv[1]<<"Could not be loaded"<<endl;
        return -1;

    }

    int divideWith=0;
    stringstream s;
    s<<argv[2];
    s>>divideWith;

    if (!s || !divideWith)
    {
        cout<<"Invalid number entered for dividing "<<endl;
        return -1;

    }

    //unsigned character
    uchar table[256];
    for(int i=0;i<256;++i)
        table[i]=(uchar)(divideWith * (i/divideWith));

    const int times=100;
    double t;

    t = (double)getTickCount();

    for(int i=0;i<times;++i)
    {
        cv::Mat clone_i=I.clone();
        J=ScanimageAndReduceIterator(clone_i,table);

    }
    t=1000*((double)getTickCount()-t)/getTickFrequency();
    t/=times;

    cout << "Time of reducing with the iterator (averaged for "
        << times << " runs): " << t << " milliseconds."<< endl;

}

Mat& ScanimageAndReduceIterator(Mat& I,const uchar* const table)
{
    CV_Assert(I.depth()==CV_8U);

    const int channels = I.channels();
    switch(channels)
    {
    case 1:
        {
            MatIterator_<uchar> it,end;
            for(it=I.begin<uchar>(),end=I.end<uchar>(); it!=end;++it)
                *it = table[*it];

            break;


        }
    case 3:
        {
            MatIterator_<Vec3b> it,end;
            for(it=I.begin<Vec3b>(), end = I.end<Vec3b>();it !=end;++it)
            {
                (*it)[0] = table[(*it)[0]];
                (*it)[1] = table[(*it)[1]];
                (*it)[2] = table[(*it)[2]];

            }


        }

    }
    return I;

}



























