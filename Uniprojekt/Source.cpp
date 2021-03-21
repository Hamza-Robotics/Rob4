#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/imgcodecs.hpp"
#include <iostream>

#include "ROBCV.h"


using namespace std;
//Public 

ROBCV rss; 

void main() {
	
	cv::Mat Out1 = cv::imread("C:\\Users\\Xamza\\Documents\\Uni\\4 semester\\Robot Perception og Robot Sensing\\BilledeFiler\\tools-black.jpg",cv::IMREAD_GRAYSCALE);
	//Mat Img2 = Mat(Img.rows, Img.cols, CV_8U);

	//Mat Out1= Mat(Img.rows, Img.cols, CV_8U);
	cv::Mat Out2 = cv::Mat(Out1.rows, Out1.cols, CV_8U);

	rss.UtsoThreshold(Out1, Out1);
	//Morpholizer(Out1, Out2, 3, 4);
	//imshow("Mig", Out2);

	cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	morphologyEx(Out1, Out2, cv::MORPH_CLOSE, element);
	imshow("OpenCV", Out2);


	cv::waitKey(0);
}
