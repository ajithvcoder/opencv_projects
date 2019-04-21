/*

Getting arguments
-----------------

Instructions to run the code
-----------------------------

> g++ 1_program.cpp -o app `pkg-config --cflags --libs opencv`
> ./app water air

*/

#include <opencv2/highgui.hpp>
#include "opencv2/core/core.hpp"

#include <iostream>
using namespace std;
using namespace cv;

int main(int argc,char** argv){



  printf("argc = %d\n",argc);
  printf("argv = %s\n",argv[0]);
  printf("argv = %s\n",argv[1]);
  printf("argv = %s\n",argv[2]);

  printf("printing in a for loop \n");

  for(int i=0;i<argc;++i){

    printf("%s\n",argv[i]);
  }

  return 0;

}

