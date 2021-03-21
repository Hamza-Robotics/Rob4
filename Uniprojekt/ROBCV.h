#pragma once
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/imgcodecs.hpp"
#include <iostream>
class ROBCV
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/imgcodecs.hpp"
#include <iostream>

	
{
public:

	void UtsoThreshold(cv::Mat inputarray, cv::Mat outputarray);
	void Morpholizer(cv::Mat inputarray, cv::Mat outputarray, int structsize, int mode);


private:
	void morphing1d(int(&element)[3], int(&pic2d)[12], int type);

	cv::Mat structmaker(int size);
	void Dilation(cv::Mat inputarray, cv::Mat outputarray, int structsize);
	void Erotion(cv::Mat inputarray, cv::Mat outputarray, int structsize);

};