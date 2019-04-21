/*

Basic Operations
----------------

Instructions to run the code
-----------------------------

> g++ 4_program.cpp -o app `pkg-config --cflags --libs opencv`
> ./app


CV_[The number of bits per item][Signed or Unsigned][Type Prefix]C[The channel number]

Reference:
http://ninghang.blogspot.com/2012/11/list-of-mat-type-in-opencv.html
change the variables

*/


#include "opencv2/core.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void help()
{
    cout<<"program is executed"<<endl;


}

int main(int,char**)
{
    help();
    Mat M(2,2,CV_8UC3,Scalar(0,0,255));
    cout<<"M="<<endl<<" "<<M<<endl<<endl;

    M.create(4,4,CV_8UC3);
    cout<< "M" <<endl<<" "<<M<<endl<<endl;


    Mat E=Mat::eye(4,4,CV_64F);
    cout<<E<<endl;

    Mat O = Mat::ones(2,2,CV_32F);
    cout<<"0="<<endl<<" "<<O<<endl<<endl;

    Mat Z=Mat::zeros(3,3,CV_8UC1);
    cout<<"Z="<<Z<<endl;

    Mat C=(Mat_<double>(3,3)<<0,-1,0,-1,5,-1,0,-1,0);
    cout<<"C ="<<C<<endl;

//method to use ifdef and run a loop
#define CV_CXX11 1


#ifdef CV_CXX11
    C=(Mat_<double>({0,-1,0,-1,5,-1,0,-1,0}).reshape(3));
    cout<<"C ="<<endl<<C<<endl;
#endif


    Mat RowClone = C.row(1).clone();
    cout<<"RowClone ="<<endl<<RowClone<<endl;

    Mat R=Mat(3,2,CV_8UC3);
    randu(R,Scalar::all(0),Scalar::all(255));

    Point2f P(5,1);
    cout<<"Point (2D) = "<<P<<endl<<endl;

    Point3f P3f(2,6,7);
    cout<<"Point (3D)"<<P3f<<endl<<endl;

    vector<float> v;
    v.push_back((float)CV_PI);
    v.push_back(2);
    cout<<Mat(v)<<endl;

    vector<Point2f> vPoints(20);
    for (size_t i=0;i<vPoints.size();++i)
        vPoints[i]=Point2f((float)(i*5),(float)(i%7));

    cout<<"A vector of 2D points"<<vPoints<<endl;

}


























