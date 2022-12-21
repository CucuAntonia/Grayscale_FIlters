#include "CppUnitTest.h"
#include "../../imageprocessingapp/Sources/Algorithms/Algorithms.h"
#include "../../imageprocessingapp/Sources/Utils/Utils.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace TesteImageProcessingApp
{
	


		TEST_CLASS(TesteImageProcessingApp)
		{
		public:


			TEST_METHOD(ValidInputImage_Averaging)
			{
				const cv::Mat inImage;
				cv::Mat outImage;
				Assert::AreEqual(false, Algo::Averaging(inImage, outImage));
			}

			TEST_METHOD(ValidNumberOfChannels_Averaging)
			{
		

				std::string image_path = "../Data/img.jpg";
				cv::Mat inImage = cv::imread(image_path, cv::IMREAD_COLOR);
				cv::Mat grayImage;
				cv::cvtColor(inImage, grayImage, cv::COLOR_BGR2GRAY);
				cv::Mat outImage;

				Assert::AreEqual(false, Algo::Averaging(grayImage, outImage));
			}

			TEST_METHOD(ValidOutputImage_Averaging)
			{
				std::string in_path = "../Data/img1.png";
				cv::Mat inImage = cv::imread(in_path, cv::IMREAD_COLOR);
				std::string out_path = "../Data/ValidOutputImage_Averaging_GT.png";
				cv::Mat outImage_expected = cv::imread(out_path, cv::IMREAD_GRAYSCALE);
				cv::Mat outImage_actual;
				Assert::AreEqual(true, Algo::Averaging(inImage, outImage_actual));
				Assert::AreEqual(true, Utils::GetDisimilarityMat(outImage_actual, outImage_expected));
			}
			TEST_METHOD(ValidInputImage_Luminance)
			{
				const cv::Mat inImage;
				cv::Mat outImage;
				Assert::AreEqual(false, Algo::Luminance(inImage, outImage));
			}

			TEST_METHOD(ValidNumberOfChannels_Luminance)
			{
				std::string image_path = "../Data/img.jpg";
				cv::Mat inImage = cv::imread(image_path, cv::IMREAD_COLOR);
				cv::Mat grayImage;
				cv::cvtColor(inImage, grayImage, cv::COLOR_BGR2GRAY);
				cv::Mat outImage;

				Assert::AreEqual(false, Algo::Luminance(grayImage, outImage));
			}

			TEST_METHOD(ValidOutputImage_Luminance)
			{
				std::string in_path = "../Data/img1.png";
				cv::Mat inImage = cv::imread(in_path, cv::IMREAD_COLOR);
				std::string out_path = "../Data/ValidOutputImage_Luminance_GT.png";
				cv::Mat outImage_expected = cv::imread(out_path, cv::IMREAD_GRAYSCALE);
				cv::Mat outImage_actual;
				Assert::AreEqual(true, Algo::Luminance(inImage, outImage_actual));
				Assert::AreEqual(true, Utils::GetDisimilarityMat(outImage_actual, outImage_expected));
			}

			TEST_METHOD(ValidInputImage_Desaturation)
			{
				const cv::Mat inImage;
				cv::Mat outImage;
				Assert::AreEqual(false, Algo::Desaturation(inImage, outImage));
			}

			TEST_METHOD(ValidNumberOfChannels_Desaturation)
			{
				std::string image_path = "../Data/img.jpg";
				cv::Mat inImage = cv::imread(image_path, cv::IMREAD_COLOR);
				cv::Mat grayImage;
				cv::cvtColor(inImage, grayImage, cv::COLOR_BGR2GRAY);
				cv::Mat outImage;

				Assert::AreEqual(false, Algo::Desaturation(grayImage, outImage));
			}

			TEST_METHOD(ValidOutputImage_Desaturation)
			{
				std::string in_path = "../Data/img1.png";
				cv::Mat inImage = cv::imread(in_path, cv::IMREAD_COLOR);
				std::string out_path = "../Data/ValidOutputImage_Desaturation_GT.png";
				cv::Mat outImage_expected = cv::imread(out_path, cv::IMREAD_GRAYSCALE);
				cv::Mat outImage_actual;
				Assert::AreEqual(true, Algo::Desaturation(inImage, outImage_actual));
				Assert::AreEqual(true, Utils::GetDisimilarityMat(outImage_actual, outImage_expected));
			}

			TEST_METHOD(ValidInputImage_Minimum_decomposition)
			{
				const cv::Mat inImage;
				cv::Mat outImage;
				Assert::AreEqual(false, Algo::Minimum_decomposition(inImage, outImage));
			}

			TEST_METHOD(ValidNumberOfChannels_Minimum_decomposition)
			{
				std::string image_path = "../Data/img.jpg";
				cv::Mat inImage = cv::imread(image_path, cv::IMREAD_COLOR);
				cv::Mat grayImage;
				cv::cvtColor(inImage, grayImage, cv::COLOR_BGR2GRAY);
				cv::Mat outImage;

				Assert::AreEqual(false, Algo::Minimum_decomposition(grayImage, outImage));
			}

			TEST_METHOD(ValidOutputImage_Minimum_decomposition)
			{
				std::string in_path = "../Data/img1.png";
				cv::Mat inImage = cv::imread(in_path, cv::IMREAD_COLOR);
				std::string out_path = "../Data/ValidOutputImage_Minimum_decomposition_GT.png";
				cv::Mat outImage_expected = cv::imread(out_path, cv::IMREAD_GRAYSCALE);
				cv::Mat outImage_actual;
				Assert::AreEqual(true, Algo::Minimum_decomposition(inImage, outImage_actual));
				Assert::AreEqual(true, Utils::GetDisimilarityMat(outImage_actual, outImage_expected));
			}


			TEST_METHOD(ValidInputImage_Maximum_decomposition)
			{
				const cv::Mat inImage;
				cv::Mat outImage;
				Assert::AreEqual(false, Algo::Maximum_decomposition(inImage, outImage));
			}

			TEST_METHOD(ValidNumberOfChannels_Maximum_decomposition)
			{
				std::string image_path = "../Data/img.jpg";
				cv::Mat inImage = cv::imread(image_path, cv::IMREAD_COLOR);
				cv::Mat grayImage;
				cv::cvtColor(inImage, grayImage, cv::COLOR_BGR2GRAY);
				cv::Mat outImage;

				Assert::AreEqual(false, Algo::Maximum_decomposition(grayImage, outImage));
			}

			TEST_METHOD(ValidOutputImage_Maximum_decomposition)
			{
				std::string in_path = "../Data/img1.png";
				cv::Mat inImage = cv::imread(in_path, cv::IMREAD_COLOR);
				std::string out_path = "../Data/ValidOutputImage_Maximum_decomposition_GT.png";
				cv::Mat outImage_expected = cv::imread(out_path, cv::IMREAD_GRAYSCALE);
				cv::Mat outImage_actual;
				Assert::AreEqual(true, Algo::Maximum_decomposition(inImage, outImage_actual));
				Assert::AreEqual(true, Utils::GetDisimilarityMat(outImage_actual, outImage_expected));

			}
			TEST_METHOD(ValidInputImage_Single_color_channel)
			{
				const cv::Mat inImage;
				cv::Mat outImage;
				Assert::AreEqual(false, Algo::Single_color_channel(inImage, outImage));
			}

			TEST_METHOD(ValidNumberOfChannels_Single_color_channel)
			{
				std::string image_path = "../Data/img.jpg";
				cv::Mat inImage = cv::imread(image_path, cv::IMREAD_COLOR);
				cv::Mat grayImage;
				cv::cvtColor(inImage, grayImage, cv::COLOR_BGR2GRAY);
				cv::Mat outImage;

				Assert::AreEqual(false, Algo::Single_color_channel(grayImage, outImage));
			}

			TEST_METHOD(ValidOutputImage_Single_color_channel_Blue)
			{
				std::string in_path = "../Data/img1.png";
				cv::Mat inImage = cv::imread(in_path, cv::IMREAD_COLOR);
				std::string out_path = "../Data/ValidOutputImage_Single_color_channel_Blue_GT.png";
				cv::Mat outImage_expected = cv::imread(out_path, cv::IMREAD_GRAYSCALE);
				cv::Mat outImage_actual;
				Assert::AreEqual(true, Algo::Single_color_channel(inImage, outImage_actual, Algo::ColorChannel::Blue));
				Assert::AreEqual(true, Utils::GetDisimilarityMat(outImage_actual, outImage_expected));
			}

			TEST_METHOD(ValidOutputImage_Single_color_channel_Green)
			{
				std::string in_path = "../Data/img1.png";
				cv::Mat inImage = cv::imread(in_path, cv::IMREAD_COLOR);
				std::string out_path = "../Data/ValidOutputImage_Single_color_channel_Green_GT.png";
				cv::Mat outImage_expected = cv::imread(out_path, cv::IMREAD_GRAYSCALE);
				cv::Mat outImage_actual;
				Assert::AreEqual(true, Algo::Single_color_channel(inImage, outImage_actual, Algo::ColorChannel::Green));
				Assert::AreEqual(true, Utils::GetDisimilarityMat(outImage_actual, outImage_expected));
			}
			TEST_METHOD(ValidOutputImage_Single_color_channel_Red)
			{
				std::string in_path = "../Data/img1.png";
				cv::Mat inImage = cv::imread(in_path, cv::IMREAD_COLOR);
				std::string out_path = "../Data/ValidOutputImage_Single_color_channel_Red_GT.png";
				cv::Mat outImage_expected = cv::imread(out_path, cv::IMREAD_GRAYSCALE);
				cv::Mat outImage_actual;
				Assert::AreEqual(true, Algo::Single_color_channel(inImage, outImage_actual, Algo::ColorChannel::Red));
				Assert::AreEqual(true, Utils::GetDisimilarityMat(outImage_actual, outImage_expected));
			}
			TEST_METHOD(ValidInputImage_Custom_gray_shades)
			{
				const cv::Mat inImage;
				cv::Mat outImage;
				Assert::AreEqual(false, Algo::Custom_gray_shades(inImage, outImage, 2));
			}

			TEST_METHOD(ValidNumberOfChannels_Custom_gray_shades)
			{
				std::string image_path = "../Data/img.jpg";
				cv::Mat inImage = cv::imread(image_path, cv::IMREAD_COLOR);
				cv::Mat grayImage;
				cv::cvtColor(inImage, grayImage, cv::COLOR_BGR2GRAY);
				cv::Mat outImage;

				Assert::AreEqual(false, Algo::Custom_gray_shades(grayImage, outImage, 2));
			}

			TEST_METHOD(ValidOutputImage_Custom_gray_shades)
			{
				std::string in_path = "../Data/img1.png";
				cv::Mat inImage = cv::imread(in_path, cv::IMREAD_COLOR);
				std::string out_path = "../Data/ValidOutputImage_Custom_gray_shades_GT.png";
				cv::Mat outImage_expected = cv::imread(out_path, cv::IMREAD_GRAYSCALE);
				cv::Mat outImage_actual;
				Assert::AreEqual(true, Algo::Custom_gray_shades(inImage, outImage_actual, 4));
				Assert::AreEqual(true, Utils::GetDisimilarityMat(outImage_actual, outImage_expected));
			}


			TEST_METHOD(ValidInputImage_Mat2QImage)
			{
				const cv::Mat inImage;
				QImage outImage;
				Assert::AreEqual(false, Utils::ConvertMat2QImage(inImage, outImage));
			}


			TEST_METHOD(ValidInputImage_QImage2Mat)
			{
				const QImage inImage;
				cv::Mat outImage;
				Assert::AreEqual(false, Utils::ConvertQImage2Mat(inImage, outImage));
			}

			TEST_METHOD(ValidOutputImage1Channel_Mat2QImage)
			{
				cv::Mat inImage(20, 20, CV_8UC1);
				QImage image_actual;
				QImage image_expected(20, 20, QImage::Format::Format_Grayscale8);
				Assert::AreEqual(true, Utils::ConvertMat2QImage(inImage, image_actual));
				Assert::AreEqual(true, Utils::VerifIfMatQImageAreSame(inImage, image_actual));
				Assert::AreEqual(true, Utils::GetDisimilarityQImage(image_actual, image_expected));

			}

			TEST_METHOD(ValidOutputImage3Channels_Mat2QImage)
			{
				cv::Mat inImage(20, 20, CV_8UC3);
				QImage image_actual;
				QImage image_expected(20, 20, QImage::Format::Format_RGB888);
				Assert::AreEqual(true, Utils::ConvertMat2QImage(inImage, image_actual));
				Assert::AreEqual(true, Utils::VerifIfMatQImageAreSame(inImage, image_actual));
				Assert::AreEqual(true, Utils::GetDisimilarityQImage(image_actual, image_expected));

			}

			TEST_METHOD(ValidOutputImageRGB888_QImage2Mat)
			{
				QImage inImage(20, 20, QImage::Format::Format_RGB888);
				cv::Mat image_actual;
				cv::Mat image_expected(20, 20, CV_8UC3);
				Assert::AreEqual(true, Utils::ConvertQImage2Mat(inImage, image_actual));
				Assert::AreEqual(true, Utils::VerifIfMatQImageAreSame(image_actual, inImage));
				Assert::AreEqual(true, Utils::GetDisimilarityMat(image_actual, image_expected));
			}

			TEST_METHOD(ValidOutputImageRGB32_QImage2Mat)
			{
				QImage inImage(20, 20, QImage::Format::Format_RGB32);
				cv::Mat image_actual;
				cv::Mat image_expected(20, 20, CV_8UC4);
				Assert::AreEqual(true, Utils::ConvertQImage2Mat(inImage, image_actual));
				Assert::AreEqual(true, Utils::VerifIfMatQImageAreSame(image_actual, inImage));
				Assert::AreEqual(true, Utils::GetDisimilarityMat(image_actual, image_expected));


			}

			TEST_METHOD(ValidOutputImageGrayscale8_QImage2Mat)
			{
				QImage inImage(20, 20, QImage::Format::Format_Grayscale8);
				cv::Mat image_actual;
				cv::Mat image_expected(20, 20, CV_8UC1);
				Assert::AreEqual(true, Utils::ConvertQImage2Mat(inImage, image_actual));
				Assert::AreEqual(true, Utils::VerifIfMatQImageAreSame(image_actual, inImage));
				Assert::AreEqual(true, Utils::GetDisimilarityMat(image_actual, image_expected));
			}
		};
	
}
