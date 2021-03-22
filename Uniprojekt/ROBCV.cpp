#include "ROBCV.h"


void ROBCV::UtsoThreshold(cv::Mat inputarray, cv::Mat outputarray) {
	int Histogram[256] = { 0 };
	float q1 = 0;
	float q2 = 0;
	float mean = 0;
	float var = 0;
	float ThreshVal = 0;
	float vartemp = 0;
	float sum = 0;
	float sumb = 0;

	int total = inputarray.cols * inputarray.rows;

	for (int x = 0; x < inputarray.cols; x++) {
		for (int y = 0; y < inputarray.rows; y++) {

			Histogram[inputarray.at<uchar>(cv::Point(x, y))] += 1;

		}
	}

	for (int i = 0; i < 255; i++) {

		sum = sum + i * Histogram[i];
	}

	for (int i = 0; i < 255; i++) {

		q1 = total - q2;

		if (q1 > 0 && q2 > 0) {
			mean = (sum - sumb) / q1;

			var = q1 * q2 * ((sumb / q2) - mean) * ((sumb / q2) - mean);


			if (vartemp < var) {
				vartemp = var;
				ThreshVal = i;
			}


		}

		q2 = q2 + Histogram[i];
		sumb = sumb + (i * Histogram[i]);
	}

	for (int x = 0; x < outputarray.cols; x++) {
		for (int y = 0; y < outputarray.rows; y++) {
			if (inputarray.at<uchar>(cv::Point(x, y)) > ThreshVal) {


				outputarray.at<uchar>(cv::Point(x, y)) = 255;
			}
			else {
				outputarray.at<uchar>(cv::Point(x, y)) = 0;
			}

		}

	}




}
// Testing på 1D
void ROBCV::morphing1d(int(&element)[3], int(&pic2d)[12], int type) {


	int N = (std::size(element) - 1) / 2;


	for (int i = 0; i < std::size(pic2d); i++) {

		if (i < N || i >((int)std::size(pic2d) - N)) {
			pic2d[i] = 0;


		}

		else {
			int temp = 0;

			for (int f = 0; f < std::size(element); f++) {
				if (pic2d[i + f] == element[f]) {
					temp++;

					if (temp == type) {


						pic2d[i] = 1;

						temp = 0;
					}

					else
					{
						pic2d[i] = 0;

					}
				}
			}
		}

	}

}
//Private
cv::Mat ROBCV::structmaker(int size) {
	cv::Mat kern = cv::Mat(size, size, CV_8U);
	for (int x = 0; x < kern.cols; x++) {
		for (int y = 0; y < kern.cols; y++) {
			kern.at<uchar>(cv::Point(x, y)) = 255;
		}
	}

	return kern;
}
//Private
void ROBCV::Dilation(cv::Mat inputarray, cv::Mat outputarray, int structsize) {
	cv::Mat StructingElement = structmaker(structsize);
	int Total = StructingElement.cols * StructingElement.rows;
	int temp = 0;

	for (int x = ((int)StructingElement.cols / 2); x < inputarray.cols - ((int)StructingElement.cols / 2); x++) {
		for (int y = ((int)StructingElement.rows / 2); y < inputarray.rows - ((int)StructingElement.rows / 2); y++) {
			for (int xi = 0; xi < (int)StructingElement.cols; xi++) {
				for (int yi = 0; yi < (int)StructingElement.rows; yi++) {
					if (StructingElement.at<uchar>(cv::Point(xi, yi)) == inputarray.at<uchar>(cv::Point(x + xi - 1, y + yi - 1))) {
						temp++;
					}



				}
			}

			if (temp > 1) {
				outputarray.at<uchar>(cv::Point(x, y)) = 225;
				temp = 0;
			}
			else {
				outputarray.at<uchar>(cv::Point(x, y)) = 0;
				temp = 0;

			}



		}

	}

}
//Private
void ROBCV::Erotion(cv::Mat inputarray, cv::Mat outputarray, int structsize) {
	cv::Mat StructingElement = structmaker(structsize);
	int Total = StructingElement.cols * StructingElement.rows;
	int temp = 0;

	for (int x = ((int)StructingElement.cols / 2); x < inputarray.cols - ((int)StructingElement.cols / 2); x++) {
		for (int y = ((int)StructingElement.rows / 2); y < inputarray.rows - ((int)StructingElement.rows / 2); y++) {
			for (int xi = 0; xi < (int)StructingElement.cols; xi++) {
				for (int yi = 0; yi < (int)StructingElement.rows; yi++) {
					if (StructingElement.at<uchar>(cv::Point(xi, yi)) == inputarray.at<uchar>(cv::Point(x + xi - 1, y + yi - 1))) {
						temp++;
					}



				}
			}

			if (temp == Total) {
				outputarray.at<uchar>(cv::Point(x, y)) = 225;
				temp = 0;
			}
			else {
				outputarray.at<uchar>(cv::Point(x, y)) = 0;
				temp = 0;

			}



		}

	}

}
//Public
void ROBCV::Morpholizer(cv::Mat inputarray, cv::Mat outputarray, int structsize, int mode) {
	if (mode == 1) {
		Erotion(inputarray, outputarray, structsize);
	}

	if (mode == 2) {

		Dilation(inputarray, outputarray, structsize);
	}

	if (mode == 3) {

		//DEC DILATION EROSION AND THAT MEANS CLOSING;
		Dilation(inputarray, outputarray, structsize);
		Erotion(inputarray, outputarray, structsize);

	}
	if (mode == 4) {
		//EDO EROTION DILATION AND THAT MEANS OPENING

		Erotion(inputarray, outputarray, structsize);
		Dilation(inputarray, outputarray, structsize);

	}
}


