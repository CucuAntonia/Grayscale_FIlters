#pragma once
#include <opencv2\opencv.hpp>  
#include <QApplication>
#include <QtGui>
#include <QLabel>

#ifdef UTILS_EXPORT
#define UTILS_API __declspec(dllexport)
#else
#define UTILS_API __declspec(dllimport)
#endif

namespace Utils
{
	///@brief   Function to convert a cv::Mat element to a QImage element
	///@details It returns true or false, depending on the conversion result.
	///@details https://doc.qt.io/qt-5/qimage.html#QImage-4
	///@return  bool
	///@param	const cv::Mat& src
	///@param	QImage& dest
	bool UTILS_API ConvertMat2QImage(const cv::Mat& src, QImage& dest);

	///@brief   Function to convert a QImage element to a cv::Mat element
	///@details It returns true or false, depending on the conversion result.
	///@details https://doc.qt.io/qt-5/qimage.html#QImage-4
	///@return  bool
	///@param	QImage& src
	///@param	const cv::Mat& dest
	bool UTILS_API ConvertQImage2Mat(const QImage& src, cv::Mat& dest);
}