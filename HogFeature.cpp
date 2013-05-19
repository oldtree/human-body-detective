
#include "HOGFeature.h"


const float PI = CV_PI;
const float MINIMUM = 0.000001;
const int cell=8;
const int block=2;
const int cell_bin=9;
 



void HOGDescription::calcalculateMatHogfeature(Mat &srcpic)
	{
		this->feature_mat = Mat(1,3780,CV_32FC1);
		this->width=64;
		this->height=128;
		calculateIntegralsMat(srcpic);
		float *feature_Ptr = this->feature_mat.ptr<float>(0);
		for (int i = 0; i <= height - cell * block ; i += cell)
		{
			for (int j = 0; j <= width - cell * block ; j += cell)
			{
				calculateBlockHogfeature(j, i, feature_Ptr,normalization);
				feature_Ptr += block * block * cell_bin;
			}
		}
		feature_Ptr=NULL;
		delete feature_Ptr;
		srcpic.release();
	}

void  HOGDescription::calculateIntegralsMat(Mat &srcpic)
{
	Mat img_gray(srcpic.size(),CV_8UC1);
	Mat dx;
	Mat dy;
	vector<Mat> bins;
	equalizeHist(srcpic,img_gray);
	/*filter2D(img_gray,dx,CV_32FC1,*(Mat_<float>(1,3)<<1,0,-1),Point(-1,-1),0.0,BORDER_REFLECT_101) ;
	filter2D(img_gray,dy,CV_32FC1,*(Mat_<float>(3,1)<<1,0,-1),Point(-1,-1),0.0,BORDER_REFLECT_101) ; */ 										 													
	Sobel(img_gray,dx,CV_32FC1,1,0,3);	 
	Sobel(img_gray,dy,CV_32FC1,0,1,3);	 	    
	for (int i = 0; i < 9 ; i++) {					 
		bins.push_back(Mat(img_gray.size(),CV_32FC1)) ;	
		integrals.push_back(Mat(img_gray.size(),CV_32FC1));
		bins[i].setTo(0);
		integrals[i].setTo(0);
	}
	float gradient;
	float magnitude;
	float* ptr_x;
	float* ptr_y;
	float** ptrs;
	for (int y = 0; y < height; y++) 
	{
		ptr_x =dx.ptr<float>(y);
		ptr_y =dy.ptr<float>(y);
		ptrs = (float**) malloc(9 * sizeof(float*));
		for (int i = 0; i < 9 ;i++)
		{
			ptrs[i] = (float*) (bins[i].ptr<float>(y));
		}

		for (int x = 0; x <width; x++)
		{
			if (ptr_x[x] == 0)
			{
				gradient = ((atan(ptr_y[x] /(ptr_x[x] + MINIMUM))) * (180/PI)) + 90;
			}
			else
			{
				gradient = ((atan(ptr_y[x] / ptr_x[x])) * (180 / PI)) + 90;
			}
			magnitude = sqrt((ptr_x[x] * ptr_x[x]) + (ptr_y[x] * ptr_y[x]));

			if (gradient <= 20) 
			{
				ptrs[0][x] = magnitude;
			}
			else if (gradient <=  40)
			{
				ptrs[1][x] = magnitude;
			}
			else if (gradient <=  60) 
			{
				ptrs[2][x] = magnitude;
			}
			else if (gradient <=  80)
			{
				ptrs[3][x] = magnitude;
			}
			else if (gradient <= 100)
			{
				ptrs[4][x] = magnitude;
			}
			else if (gradient <= 120)
			{
				ptrs[5][x] = magnitude;
			}
			else if (gradient <= 140){
				ptrs[6][x] = magnitude;
			}
			else if (gradient <= 160)
			{
				ptrs[7][x] = magnitude;
			}
			else 
			{
				ptrs[8][x] = magnitude;
			}
		}
	}
	dx.release();
	dy.release();
	img_gray.release();	
	ptr_x =NULL;
	ptr_y =NULL;
	ptrs =NULL;
	delete ptr_x;
	delete ptr_y;
	delete ptrs;
	for (int i = 0; i <9 ; i++){
		
		integral(bins[i], integrals[i]);
		bins[i].release();
	}
	bins.clear();
	return ;
};
void HOGDescription::calculateBlockHogfeature(int x_begin,int y_begin, float *feature_Ptr,bool normalization)
	{
		calculateRectHogfeature(Rect(x_begin,y_begin,8,8), feature_Ptr ,integrals);
		calculateRectHogfeature(Rect(x_begin+8,y_begin,8,8), feature_Ptr+9 ,integrals);
		calculateRectHogfeature(Rect(x_begin,y_begin+8,8,8), feature_Ptr +18,integrals);
		calculateRectHogfeature(Rect(x_begin+8,y_begin+8,8,8), feature_Ptr +27,integrals);

		if (normalization == true)
		{
			normL1(feature_Ptr);
		}
	}
void HOGDescription::calculateRectHogfeature(Rect cell, float *hogfeature_cell ,vector<Mat> &integrals)
{
		double a,b,c,d=0.0;
		
		for (int i = 0; i < 9 ; i++)
		{
			a = (integrals[i].ptr<double>(cell.y))[cell.x];
			b = (integrals[i].ptr<double>(cell.y + cell.height))[cell.x + cell.width];
			c = (integrals[i].ptr<double>(cell.y))[cell.x + cell.width];
			d = (integrals[i].ptr<double>(cell.y + cell.height))[cell.x];
			hogfeature_cell[i]=(a + b) - (c + d);
		}
} ;

vector<float> HOGDescription::getDetector()
{
	static const float detector[3780] = {0};
	return vector<float>(detector, detector + sizeof(detector)/sizeof(detector[0]));
};

void HOGDescription::normL1(float *block_feature_Ptr) 
{
	float total = 0;
	for (int i = 0; i < block * block * cell_bin; i++)
	{
		total += block_feature_Ptr[i];
	}
	total = (total < MINIMUM) ? MINIMUM : total; 
	for (int i = 0; i < block * block * cell_bin; i++)
	{
		block_feature_Ptr[i] /= total;
	}
} ;

void HOGDescription::normL2(float *block_feature_Ptr) 
{
	float total = 0;
	for (int i = 0; i < block * block * cell_bin; i++)
	{
		total += block_feature_Ptr[i] * block_feature_Ptr[i];
	}
	total = (total < MINIMUM) ? MINIMUM : total; 
	for (int i = 0; i < block * block * cell_bin; i++)
	{
		block_feature_Ptr[i] /= total;
	}
}  ;

void HOGDescription::normL2_hys(float *block_feature_Ptr) 
{
	float total = 0;
	normL2(block_feature_Ptr);
	for (int i = 0; i < block * block * cell_bin; i++)
	{
		block_feature_Ptr[i] = (block_feature_Ptr[i] > 0.2) ? 0.2 : block_feature_Ptr[i];
	}
	normL2(block_feature_Ptr);
} ;



