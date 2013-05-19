
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/ml/ml.hpp>


#include <opencv2/opencv.hpp>
#include <string>
#include <cmath>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <omp.h>
using namespace std;
using namespace cv;


class HOGDescription
{
public:
	HOGDescription()
	{
		normalization=true;
		this->width = 0;
		this->height = 0;

	}
	~HOGDescription()
	{
		feature_mat.release();
		integrals.clear();
	}
	vector<float> getDetector();	
	void calculateIntegralsMat(Mat &input);
	void calculateRectHogfeature(Rect cell, float *hogfeature_cell ,vector<Mat> &integrals);
	void calcalculateMatHogfeature(Mat &input);
	void calculateBlockHogfeature(int x_begin,int y_begin, float *feature_Ptr,bool normalization);

	void normL1(float *block_feature_Ptr) ;
	void normL2(float *block_feature_Ptr) ;
	void normL2_hys(float *block_feature_Ptr) ;
public:
	Mat feature_mat;
	vector<Mat> integrals;
	bool normalization;
	int width;
	int height;
private:
};


