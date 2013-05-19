#include "hoggui.h"
#include <QByteArray>
Mat terminal_temp;
float time_cost;
SVM pos_svm;
int sys_width=600;
int sys_height=400;

HogGui::HogGui(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
{
	ui.setupUi(this);
	this->t = 0.0;
	this->people_detect = 0;
	xml_path="E:/sample/resultfinnal1.xml";
	if (!xml_path.empty())
	{
		pos_svm.load(xml_path.c_str());
	}
	QObject::connect(ui.pic_pushButton,SIGNAL(clicked()),this,SLOT(process_picture_detect()));
	QObject::connect(ui.video_pushButton,SIGNAL(clicked()),this,SLOT(process_video_detect()));
	QObject::connect(ui.create_pushButton,SIGNAL(clicked()),this,SLOT(process_picture()));
	QObject::connect(ui.trainpushButton,SIGNAL(clicked()),this,SLOT(process_picture_train()));
	QObject::connect(ui.load_pushButton,SIGNAL(clicked()),this,SLOT(load_path()));
}

HogGui::~HogGui()
{

}

void HogGui::process_picture_detect()
{
	int num=0;
	ui.video_pushButton->setDisabled(false);
	ui.video_path_lineEdit->setDisabled(false); 
	num=detectPic(pic_path);
	ui.lcdNumber->display(num);
	ui.time_lcdNumber->display(time_cost);
	picture=mat2qimage(terminal_temp);
	ui.show_label->setPixmap(QPixmap::fromImage(picture));
};
void HogGui::process_video_detect()
{
	this->ui.pic_pushButton->setDisabled(false);
	this->ui.pic_path_lineEdit->setDisabled(false);
	float t=0.0;
	int people_number=0;
	Mat img;
	int img_count=0;
	VideoCapture cap(video_path.c_str());
	if (!cap.isOpened())
	{
		time_cost=0;
		people_number=0;
		return ;
	}
	while (1)
	{
		cap>>img; 
		terminal_temp.release();
		if (img.empty())
		{
			break;
		}
		img_count++;
		if (img_count>16)
		{
			img_count++;
			time_cost=0;
			t = (float)getTickCount();
			terminal_temp=detect_func(img,pos_svm,people_number);
			t = (float)getTickCount() - t;
			time_cost=t;
			picture=mat2qimage(terminal_temp);
			ui.show_label->setPixmap(QPixmap::fromImage(picture));
		}
		imshow("video",img);
		waitKey(1);
		img.release();
	}; 
	return;
	
};
void HogGui::process_picture_train()
{
	postiveinfo.clear();
	negetiveinfo.clear();
	postive_pic_path.clear();
	negetive_pic_path.clear();
	save_path.clear();
	train_total = 0;
	positive_number = 0;
	negetive_number = 0;

	postiveinfo=ui.postive_infolineEdit->text().toStdString();
	negetiveinfo=ui.nengtive_pathlineEdit->text().toStdString();
	postive_pic_path=ui.postive_infolineEdit->text().toStdString();
	negetive_pic_path=ui.nengtive_pathlineEdit->text().toStdString();
	save_path=ui.save_pathlineEdit->text().toStdString();
	train_total=ui.pic_tatallineEdit->text().toInt();
	positive_number=ui.postive_numlineEdit->text().toInt();
	negetive_number=ui.negetive_numlineEdit->text().toInt();

	trainfunc(postiveinfo,negetiveinfo,postive_pic_path,negetive_pic_path,save_path,
		train_total,positive_number,negetive_number);
}
void HogGui::process_picture()
{
	postiveinfo.clear();
	negetiveinfo.clear();
	postive_pic_path.clear();
	negetive_pic_path.clear();
	target_postive_pic_path.clear();
	target_negetive_pic_path.clear();
	read_and_write_total = 0;

	postiveinfo=ui.postive_infolineEdit->text().toStdString();
	negetiveinfo=ui.nengtive_pathlineEdit->text().toStdString();
	postive_pic_path=ui.postive_infolineEdit->text().toStdString();
	negetive_pic_path=ui.nengtive_pathlineEdit->text().toStdString();
	target_postive_pic_path=ui.target_postive_pic_path_lineEdit->text().toStdString();
	target_negetive_pic_path=ui.target_negetive_pic_path_lineEdit->text().toStdString();

	read_and_write_total=ui.total_lineEdit->text().toInt();

	read_and_write(postiveinfo,negetiveinfo,postive_pic_path,negetive_pic_path,
		target_postive_pic_path,target_negetive_pic_path,read_and_write_total);
}
void HogGui::set_label_picture(string path,int pic_or_video)
{
	QImage src_pic;
	if (pic_or_video==1)
	{
		src_pic=QImage(path.c_str());
		this->ui.show_label->setPixmap(QPixmap::fromImage(src_pic));
	}
	if (pic_or_video==2)
	{
		src_pic=QImage(path.c_str());
	}

}
void  HogGui::load_path()
	{
		string path_temp;
		this->pic_path=this->ui.pic_path_lineEdit->text().toStdString();
		this->video_path=this->ui.video_path_lineEdit->text().toStdString();
		path_temp=this->ui.xml_lineEdit->text().toStdString();
		if (!pic_path.empty()&&video_path.empty())
		{ 
			this->ui.video_pushButton->setDisabled(true);
			this->ui.video_path_lineEdit->setDisabled(true); 
			set_label_picture(pic_path,1);
		}
		else if (pic_path.empty()&&!video_path.empty())
		{
			this->ui.pic_pushButton->setDisabled(true);
			this->ui.pic_path_lineEdit->setDisabled(true);
			set_label_picture(video_path,2);
		}
		if ((!path_temp.empty())&&(path_temp!=xml_path))
		{
			xml_path=path_temp;
			pos_svm.load(xml_path.c_str());
		}
	}

QImage mat2qimage(const Mat& mat) {
	int cvIndex;
	int cvLineStart;
	Mat rgb=mat.clone();
	IplImage *	cvimage=&rgb.operator IplImage();


	QImage image=QImage(cvimage->width, cvimage->height, QImage::Format_RGB888);
	cvIndex = 0; cvLineStart = 0;
	for (int y = 0; y < cvimage->height; y++) {
		unsigned char red,green,blue;
		cvIndex = cvLineStart;
		for (int x = 0; x < cvimage->width; x++) {
			red = cvimage->imageData[cvIndex+2];
			green = cvimage->imageData[cvIndex+1];
			blue = cvimage->imageData[cvIndex+0];

			image.setPixel(x,y,qRgb(red,green,blue));
			cvIndex += 3;
		}
		cvLineStart += cvimage->widthStep;                        
	}
	
	return image;   
}



//////////////////////////////////////////////////////////////////////////
string trainfunc(string postive_info,string negetive_info,string postive_path,string nengtive_path,string save_path,
	int pic_tatal,int postive_num,int negetive_num)
{
	SVM svm;
	int size = pic_tatal;
	Mat feature_vec_mat= Mat(size,3780,CV_32FC1);
	Mat res_mat= Mat(size,1,CV_32FC1);
	feature_vec_mat.setTo(0);
	res_mat.setTo(0);
	if (postive_info.empty())		  
	{
		return "please check your  positive picture .txt info ";
	}
	if (negetive_info.empty())
	{
		return "please check your  negetive_info picture .txt info ";
	}
	if (postive_path.empty())
	{
		return "please check your  positive picture path set .is that correct? ";
	}
	if (nengtive_path.empty())
	{
		return "please check your  nengtive_path picture set .is that correct? ";
	}
	if (save_path.empty())
	{
		return "please check your  result save path .is that correct? ";
	}
	if ((pic_tatal==0)||(postive_num==0)||(negetive_num))
	{
		return "please check your picture number set.is that correct? ";
	}
	ifstream readfile(postive_info,ios::in);//ifstream readfile("E:/sample/pos1/pos.txt",ios::in);
	ifstream readfile1(negetive_info,ios::in);//ifstream readfile1("E:/sample/neg1/neg.txt",ios::in);

	string src_pos_filename=postive_path;
	string src_neg_filename=nengtive_path;
	int feature_vec_length = 3780;

	for(int i=0;i<postive_num;i++)								  
	{
		char filename[100];
		string pos_path=src_pos_filename;
		readfile.getline(filename,100);				    
		string path(filename);
		pos_path.append(path);
		Mat img;

		img = imread(pos_path,0);
		cv::Ptr<HOGDescription> h=new HOGDescription;
		h->calcalculateMatHogfeature(img);
		float *pd = h->feature_mat.ptr<float>(0);
		for (int m = 0; m < feature_vec_length; m++)
		{
			CV_MAT_ELEM(feature_vec_mat.operator CvMat(), float, i, m ) = *pd;
			pd++;
		}
		CV_MAT_ELEM(res_mat.operator CvMat(),float,i,0) = 1;
		img.release();
	}
	for(int i=0;i<negetive_num;i++)
	{
		char filename[100];
		Mat img;
		string neg_path=src_neg_filename;
		readfile1.getline(filename,100);
		string path(filename);
		neg_path.append(path);

		img = imread(neg_path,0);
		cv::Ptr<HOGDescription> h=new HOGDescription;
		h->calcalculateMatHogfeature(img);

		float *temp =h->feature_mat.ptr<float>(0);
		float *temp1 = feature_vec_mat.ptr<float>(i+postive_num);
		for (int m = 0; m < feature_vec_length; m++)
		{
			(*temp1)=(*temp);
			temp++;
			temp1++;
		}
		CV_MAT_ELEM(res_mat.operator CvMat(),float,i+postive_num,0) =-1;
		img.release();
	}

	CvTermCriteria criteria;
	criteria = cvTermCriteria(CV_TERMCRIT_EPS,1000,FLT_EPSILON); 
	svm.train(feature_vec_mat,res_mat,Mat(),Mat(),CvSVMParams(CvSVM::C_SVC,CvSVM::RBF,10.0,0.09,1.0,10.0,0.5,1.0,NULL,criteria));
	svm.save(save_path.c_str());
	feature_vec_mat.release();
	res_mat.release();

	return "successful done!";
};


int detectPic(string detect_pic_path)
{
	
	float t=0.0;
	int people_number=0;
	
	Mat img=imread(detect_pic_path,1);
	if (img.empty())
	{
		time_cost=0;
		people_number=0;
		return 0;
	}
	while ((img.cols>sys_width)||(img.rows>sys_height))
	{
		pyrDown(img,img);
	}

	t = (float)getTickCount();
	time_cost=t;
	terminal_temp.release();
	terminal_temp=detect_func(img,pos_svm,people_number);
	t = (float)getTickCount() - t;
	img.release();
	return people_number;
}
int detectVideo(string detect_video_path)
{

	float t=0.0;
	int people_number=0;
	Mat img;
	int img_count=0;
	VideoCapture cap(detect_video_path.c_str());
	if (!cap.isOpened())
	{
		time_cost=0;
		people_number=0;
		return 0;
	}

	do
	{
		cap>>img; 
		if (img_count<16)
		{
			img_count++;
			continue;
		}
		terminal_temp.release();
		time_cost=0;
		t = (float)getTickCount();
		terminal_temp=detect_func(img,pos_svm,people_number);
		t = (float)getTickCount() - t;
		time_cost=t;
		img.release();
	}while (img.empty()); 
	return 0;
}
void read_and_write(string postiveinfo,string negetiveinfo,string postive_pic_path,string negetive_pic_path,
	string target_postive_pic_path,string target_negetive_pic_path,int total=10000)
{
	Mat img_source;
	Mat img_target;

	bool pos_or_neg=true;
	ifstream pos_readfile("E:/INRIAPerson/70X134H96/Test/pos/pos.txt",ios::in);
	ifstream neg_readfile("E:/INRIAPerson/Train/neg/neg.txt",ios::in); 

	string src_pos_filename="E:/INRIAPerson/70X134H96/Test/pos/";
	string src_neg_filename="E:/INRIAPerson/Train/neg/";

	string target_pos_filename="E:/sample/pos1/";
	string target_neg_filename="E:/sample/neg1/";

	for(int i=0;i<total;i++)								  
	{
		char filename[100];
		string src_path=src_neg_filename;
		string target_path=target_pos_filename;
		neg_readfile.getline(filename,100);
		if (filename[0]=='#')
		{
			std::cout<<"file read to the end!"<<std::endl;
			break;
		}
		string path(filename);
		src_path.append(path);
		target_path.append(path);
		img_source = imread(src_path,1);

		//////////////////////////////////////////////////////////////////////////
		int width=img_source.cols;
		int height=img_source.rows;
		int channel= img_source.channels();

		img_target.create(Size(64,128),CV_8UC3);
		img_target.setTo(0);
		for (int i = 10; i < 128+10; i++)
		{
#pragma omp parallel for
			for (int j = 10; j < 64+10; j++)
			{
				for (int n=0;n<channel;n++)
				{
					img_target.at<Vec3b>(i-10,j-10)[n]=img_source.at<Vec3b>(i,j)[n];
				}
			}
		}
		imwrite(target_path,img_target);
	}
	system("pause");
};
Mat detect_func(Mat &src, SVM &svm_pos,int &num)
{
	Mat img=src.clone();
	Mat test;
	Mat test1;
	pyrDown(img,test);
	pyrDown(test,test1);
	vector<Mat>	img_list1;
	vector<std::pair<int,Point> >result_list1;
	vector<Mat>	img_list2;
	vector<std::pair<int,Point> >result_list2;
	vector<Mat>	img_list3;
	vector<std::pair<int,Point> >result_list3;
	
#pragma omp parallel for
	for (int i=0;i<3;i++)
	{
		if (i==0)
		{
			img=img;
			int width=img.cols;
			int height=img.rows;

			if ((width<=64)&&(height<=128))
			{ 
				Mat temp(128,64,CV_8UC3);
				temp.setTo(0);
				for (int j = 0; j < height; j++)
				{	
					for (int i = 0; i < width; i++)
					{
						temp.at<Vec3b>(j,i)=img.at<Vec3b>(j,i);
					}
				}
				cvtColor(temp,temp,CV_RGB2GRAY);
				img_list1.push_back(temp);
				temp.release();
				result_list1.push_back(pair<int,Point>(0,Point(0,0)));
			}
			else
			{
				for (int h=0;h<height-128;h+=32)
				{
					for (int w=0;w<width-64;w+=32)
					{
						Mat temp(128,64,CV_8UC3);
						temp.setTo(0);
#pragma omp parallel for
						for (int j = h; j < 128+h; j++)
						{	
							for (int i = w; i < 64+w; i++)
							{
								temp.at<Vec3b>(j-h,i-w)=img.at<Vec3b>(j,i);
							}
						}
						cvtColor(temp,temp,CV_RGB2GRAY);
						img_list1.push_back(temp);
						temp.release();
						result_list1.push_back(pair<int,Point>(0,Point(w,h)));
					}
				}
			}

		}
		else if (i==1)
		{
			int width=test.cols;
			int height=test.rows;

			if ((width<=64)&&(height<=128))
			{ 
				Mat temp(128,64,CV_8UC3);
				temp.setTo(0);
				for (int j = 0; j < height; j++)
				{	
					for (int i = 0; i < width; i++)
					{
						temp.at<Vec3b>(j,i)=test.at<Vec3b>(j,i);
					}
				}
				cvtColor(temp,temp,CV_RGB2GRAY);
				img_list2.push_back(temp);
				temp.release();
				result_list2.push_back(pair<int,Point>(0,Point(0,0)));
			}
			else
			{
				for (int h=0;h<height-128;h+=32)
				{
					for (int w=0;w<width-64;w+=32)
					{
						Mat temp(128,64,CV_8UC3);
						temp.setTo(0);
#pragma omp parallel for
						for (int j = h; j < 128+h; j++)
						{	
							for (int i = w; i < 64+w; i++)
							{
								temp.at<Vec3b>(j-h,i-w)=test.at<Vec3b>(j,i);
							}
						}
						cvtColor(temp,temp,CV_RGB2GRAY);
						img_list2.push_back(temp);
						temp.release();
						result_list2.push_back(pair<int,Point>(0,Point(w,h)));
					}
				}
			}

		}
		else if (i==2)
		{
			int width=test1.cols;
			int height=test1.rows;

			if ((width<=64)&&(height<=128))
			{ 
				Mat temp(128,64,CV_8UC3);
				temp.setTo(0);
				for (int j = 0; j < height; j++)
				{	
					for (int i = 0; i < width; i++)
					{
						temp.at<Vec3b>(j,i)=test1.at<Vec3b>(j,i);
					}
				}
				cvtColor(temp,temp,CV_RGB2GRAY);
				img_list3.push_back(temp);
				temp.release();
				result_list3.push_back(pair<int,Point>(0,Point(0,0)));
			}
			else
			{
				for (int h=0;h<height-128;h+=32)
				{
					for (int w=0;w<width-64;w+=32)
					{
						Mat temp(128,64,CV_8UC3);
						temp.setTo(0);
#pragma omp parallel for
						for (int j = h; j < 128+h; j++)
						{	
							for (int i = w; i < 64+w; i++)
							{
								temp.at<Vec3b>(j-h,i-w)=test1.at<Vec3b>(j,i);
							}
						}
						cvtColor(temp,temp,CV_RGB2GRAY);
						img_list3.push_back(temp);
						temp.release();
						result_list3.push_back(pair<int,Point>(0,Point(w,h)));
					}
				}
			}
		}
	}
	vector<Rect> found, found_filtered;	
	vector<Rect> found_test, found_filtered_test;	
	int i,j=0;
#pragma omp parallel for
  	for (int i=0;i<img_list1.size();i++)
	{
		cv::Ptr<HOGDescription> h=new HOGDescription;
		h->calcalculateMatHogfeature(img_list1[i]);				  
		float pos=0;
		pos=svm_pos.predict(h->feature_mat);
 		if ((pos==1))
		{
			result_list1[i].first=1;
			found.push_back(Rect(result_list1[i].second.x,result_list1[i].second.y,64,128));
		}
	}
	for(i = 0; i < found.size(); i++ )
	{
		Rect r = found[i];
		for(j = 0; j < found.size(); j++ )
			if( j != i && (r & found[j]) ==r)
				break;
		if( j == found.size() )
			found_filtered.push_back(r);
	}

	for(i = 0; i < found_filtered.size(); i++ )
	{
		Rect r = found_filtered[i];
		r.x += cvRound(r.width*0.1);
		r.width = cvRound(r.width*0.8);
		r.y += cvRound(r.height*0.1);
		r.height = cvRound(r.height*0.8);
		//rectangle(img, r.tl(), r.br(), cv::Scalar(0,255,0), 2);
		found_test.push_back(r);
		num++;
	}
	found.clear();
	found_filtered.clear();

#pragma omp parallel for
	for (int i=0;i<img_list2.size();i++)
	{
		cv::Ptr<HOGDescription> h=new HOGDescription;
		h->calcalculateMatHogfeature(img_list2[i]);				  
		float pos=0;
		pos=svm_pos.predict(h->feature_mat);
		if ((pos==1))
		{
			result_list2[i].first=1;
			found.push_back(Rect(result_list2[i].second.x,result_list2[i].second.y,64,128));
		}
	}
	for(i = 0; i < found.size(); i++ )
	{
		Rect r = found[i];
		for(j = 0; j < found.size(); j++ )
			if( j != i && (r & found[j]) ==r)
				break;
		if( j == found.size() )
			found_filtered.push_back(r);
	}

	for(i = 0; i < found_filtered.size(); i++ )
	{
		Rect r = found_filtered[i];
		r.x += cvRound(r.width*0.1);
		r.width = cvRound(r.width*0.8);
		r.y += cvRound(r.height*0.1);
		r.height = cvRound(r.height*0.8);
		//rectangle(test, r.tl(), r.br(), cv::Scalar(0,255,0), 2);
		found_test.push_back(Rect(r.x*img.cols/test.cols,r.y*img.rows/test.rows,r.width+64,r.height+128));
		num++;
	}
	found.clear();
	found_filtered.clear();
#pragma omp parallel for
	for (int i=0;i<img_list3.size();i++)
	{
		cv::Ptr<HOGDescription> h=new HOGDescription;
		h->calcalculateMatHogfeature(img_list3[i]);				  
		float pos=0;
		pos=svm_pos.predict(h->feature_mat);
		if ((pos==1))
		{
			result_list3[i].first=1;
			found.push_back(Rect(result_list3[i].second.x,result_list3[i].second.y,64,128));
		}
	}
	for(i = 0; i < found.size(); i++ )
	{
		Rect r = found[i];
		for(j = 0; j < found.size(); j++ )
			if( j != i && (r & found[j]) ==r)
				break;
		if( j == found.size() )
			found_filtered.push_back(r);
	}

	for(i = 0; i < found_filtered.size(); i++ )
	{
		Rect r = found_filtered[i];
		r.x += cvRound(r.width*0.1);
		r.width = cvRound(r.width*0.8);
		r.y += cvRound(r.height*0.1);
		r.height = cvRound(r.height*0.8);
		//rectangle(test1, r.tl(), r.br(), cv::Scalar(0,255,0), 2);
		found_test.push_back(Rect(r.x*img.cols/test1.cols,r.y*img.rows/test1.rows,r.width+64,r.height+128));
		num++;
	}
	found.clear();
	found_filtered.clear();
	for(i = 0; i < found_test.size(); i++ )
	{
		Rect r = found_test[i];
		for(j = 0; j < found_test.size(); j++ )
			if( j != i && (r & found_test[j]) ==r)
				break;
		if( j == found_test.size() )
			found_filtered_test.push_back(r);
	}

	for(i = 0; i < found_filtered_test.size(); i++ )
	{
		Rect r = found_filtered_test[i];
		r.x += cvRound(r.width*0.1);
		r.width = cvRound(r.width*0.8);
		r.y += cvRound(r.height*0.1);
		r.height = cvRound(r.height*0.8);
		rectangle(img, r.tl(), r.br(), cv::Scalar(0,255,0), 2);
	}

	//imshow("img",img);
	//waitKey(0);
	img_list1.clear();
	result_list1.clear();
	img_list2.clear();
	result_list2.clear();
	img_list3.clear();
	result_list3.clear();
	


	return img ;
}