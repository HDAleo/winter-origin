#include <opencv2/opencv.hpp>  
#include <iostream>  
  
cv::Mat gamma_correction(const cv::Mat& src, double gamma) {  

    cv::Mat dst;  
    dst.create(src.size(), src.type());  
  
    for (int y = 0; y < src.rows; y++) {  
        for (int x = 0; x < src.cols; x++) {  
            for (int c = 0; c < src.channels(); c++) {  
                double pixel_value = static_cast<double>(src.at<cv::Vec3b>(y, x)[c]);  
                pixel_value = std::pow(pixel_value / 255.0, gamma) * 255.0;  
                pixel_value = std::min(std::max(pixel_value, 0.0), 255.0);
                dst.at<cv::Vec3b>(y, x)[c] = static_cast<uchar>(pixel_value);  
            }  
        }  
    }  
  
    return dst;  
}  
  
int main() {  

    cv::Mat image = cv::imread("pic1.png", cv::IMREAD_COLOR);  
  
    if (image.empty()) {  
        std::cerr << "Error" << std::endl;  
        return -1;  
    }  
  
    double gamma = 2.0;
    cv::Mat gamma_corrected_image = gamma_correction(image, gamma);  
  
    cv::imshow("Gamma Corrected Image1", gamma_corrected_image);  
  
    cv::waitKey(0);  
  
    return 0;  
}