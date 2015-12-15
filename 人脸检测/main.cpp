#include"fairypwq.h"

int main(){
	//����Ƶ�ļ�
	cv::VideoCapture capture(0);
	//cv::VideoCapture capture("video.avi");
	//����Ƿ�ɹ���
	if(!capture.isOpened())
		return -1;
	//�򿪳ɹ����ȡ֡����
	double rate=capture.get(CV_CAP_PROP_FPS);
	bool stop(false);
	cv::Mat frame;//��ǰ��Ƶ֡
	 
	cv::namedWindow("Extracted Frame");
	//ÿ��֮֡����ݵ�ǰ֡������ʱ����λms
	int delay=1000/rate;
	//std::cout<<delay<<std::endl;
	//������Ƶ������֡
	while(!stop){
		//���������һ֡����ȡ��һ֡
		if(!capture.read(frame))
			break;
		cv::imshow("Extracted Frame",frame);
		//����ȡ��Ƶʱ������ʱ�������ֹͣ����ʹ������ͷʱdelayΪ��ֵ,����ͣ���ڴ˴�,Ϊʹ����ͷ������ʾ������Ӧ����30
		if(cv::waitKey(delay)>=0)//�м����·��ذ���ֵ���������ﵽ��ʱ�󷵻�-1
			stop=true;
	}
	//�ر���Ƶ�ļ�
	capture.release();
}