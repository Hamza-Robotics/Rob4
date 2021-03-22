#pragma once
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/imgcodecs.hpp"
#include <iostream>
class ROBCV{
public:

	static void UtsoThreshold(cv::Mat inputarray, cv::Mat outputarray);
	static void Morpholizer(cv::Mat inputarray, cv::Mat outputarray, int structsize, int mode);
	
	static const int Morph_Erosion = 1;
	static const int Morph_dilation = 2;
	static const int Morph_Closing = 3;
	static const int Morph_Opening = 4;



private:
	static void morphing1d(int(&element)[3], int(&pic2d)[12], int type);
	static cv::Mat structmaker(int size);
	static void Dilation(cv::Mat inputarray, cv::Mat outputarray, int structsize);
	static void Erotion(cv::Mat inputarray, cv::Mat outputarray, int structsize);

};