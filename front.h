#ifndef FRONT_H
#define FRONT_H

#include <opencv2/opencv.hpp>


void FeatureExtraction(const cv::Mat& prev_image, 
                    const cv::Mat& curr_image,
                    std::vector<cv::KeyPoint>& keypoints1, 
                    cv::Mat& descriptor1, 
                    std::vector<cv::KeyPoint>& keypoints2, 
                    cv::Mat& descriptor2);

#endif // FRONT_H
