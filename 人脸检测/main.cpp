#include"fairypwq.h"

int main(){
	//打开视频文件
	cv::VideoCapture capture(0);
	//cv::VideoCapture capture("video.avi");
	//检查是否成功打开
	if(!capture.isOpened())
		return -1;
	//打开成功则获取帧速率
	double rate=capture.get(CV_CAP_PROP_FPS);
	bool stop(false);
	cv::Mat frame;//当前视频帧
	 
	cv::namedWindow("Extracted Frame");
	//每两帧之间根据当前帧速率延时，单位ms
	int delay=1000/rate;
	//std::cout<<delay<<std::endl;
	//对于视频中所有帧
	while(!stop){
		//如果还有下一帧，读取下一帧
		if(!capture.read(frame))
			break;
		cv::imshow("Extracted Frame",frame);
		//当读取视频时引入延时或按任意键停止；当使用摄像头时delay为负值,程序停留在此处,为使摄像头连续显示，这里应填入30
		if(cv::waitKey(delay)>=0)//有键按下返回按键值（正），达到延时后返回-1
			stop=true;
	}
	//关闭视频文件
	capture.release();
}