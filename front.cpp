#include "front.h"
#include <opencv2/opencv.hpp>
#include <iostream>

void FeatureExtraction(const cv::Mat& prev_image,
                    const cv::Mat& curr_image,
                    std::vector<cv::KeyPoint>& keypoints1, 
                    cv::Mat& descriptor1, 
                    std::vector<cv::KeyPoint>& keypoints2, 
                    cv::Mat& descriptor2) {
    // // 여기에 FeatureExtraction 함수의 내용을 구현합니다.
    // // 이전에 작성한 코드를 여기에 추가하면 됩니다.
    // cv::Mat grayImage;
    // cv::cvtColor(inputImage, grayImage, cv::COLOR_RGB2GRAY);

    cv::Ptr<cv::FeatureDetector> detector = cv::ORB::create();
    cv::Ptr<cv::DescriptorExtractor> extractor = cv::ORB::create();

    // detector->detect(grayImage, keypoints);
    // extractor->compute(grayImage, keypoints, descriptors);


    cv::Mat curr_gray, prev_gray;
    cv::cvtColor(curr_image, curr_gray, cv::COLOR_BGR2GRAY);
    cv::cvtColor(prev_image, prev_gray, cv::COLOR_BGR2GRAY);

    detector->detect(curr_gray, keypoints1);
    extractor->compute(curr_gray, keypoints1, descriptor1);
    detector->detect(prev_gray, keypoints2);
    extractor->compute(prev_gray, keypoints2, descriptor2);
}
