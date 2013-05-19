#ifndef HOGGUI_H
#define HOGGUI_H

#include <QtGui/QDialog>
#include "ui_hoggui.h"
#include "HogFeature.h"

#include <iostream>
#include <QImage>


using namespace  std;
using namespace  Ui;


class HogGui : public QDialog
{
	Q_OBJECT

public:
	HogGui(QWidget *parent = 0, Qt::WFlags flags = 0);
	~HogGui();

private:
	Ui::HogGuiClass ui;
	string pic_path;
	string video_path;
	string xml_path;

	string postiveinfo;
	string negetiveinfo;
	string postive_pic_path;
	string negetive_pic_path;
	string save_path;
	string target_postive_pic_path;
	string target_negetive_pic_path;
	int read_and_write_total;
	int train_total;
	int positive_number;
	int negetive_number;
	QImage picture;
	float t;
	int people_detect;
public:
	void set_label_picture(string path,int pic_or_video);
public slots:
	void process_picture_detect();
	void process_video_detect();
	void process_picture_train();
	void process_picture();
	void load_path();
};
string trainfunc(string postive_info,string negetive_info,string postive_path,string nengtive_path,string save_path,int pic_tatal,int postive_num,int negetive_num);
int detectPic(string detect_pic_path);
int detectVideo(string detect_video_path);
void read_and_write(string postiveinfo,string negetiveinfo,string postive_pic_path,string negetive_pic_path,
	string target_postive_pic_path,string target_negetive_pic_path,int total);
Mat detect_func( Mat &img ,SVM &svm_pos,int &number);
QImage mat2qimage(const Mat& mat);
#endif // HOGGUI_H
