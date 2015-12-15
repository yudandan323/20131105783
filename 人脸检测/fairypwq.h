#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;

void startCount(double &time){
	time=static_cast<double>(cv::getTickCount());
}
void endCount(double &time){
	time=static_cast<double>(cv::getTickCount())-time;
	time/=cv::getTickFrequency();
	std::cout<<time<<std::endl;
}

//显示一张图片
void show1im(std::string name,cv::Mat image1){
	cv::namedWindow(name);
	cv::imshow(name,image1);
}
//显示两张图片
void show2im(std::string name1,cv::Mat image1,std::string name2,cv::Mat image2){
	cv::namedWindow(name1);
	cv::imshow(name1,image1);
	cv::namedWindow(name2);
	cv::imshow(name2,image2);
}
//显示三张图片
void show3im(std::string name1,cv::Mat image1,std::string name2,
	cv::Mat image2,std::string name3,cv::Mat image3){
	cv::namedWindow(name1);
	cv::imshow(name1,image1);
	cv::namedWindow(name2);
	cv::imshow(name2,image2);
	cv::namedWindow(name3);
	cv::imshow(name3,image3);
}