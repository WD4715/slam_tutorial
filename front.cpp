#include "front.h"

void FeatureExtraction(const cv::Mat& prev_image,
                    const cv::Mat& curr_image,
                    std::vector<cv::KeyPoint>& keypoints1, 
                    cv::Mat& descriptor1, 
                    std::vector<cv::KeyPoint>& keypoints2,
                    cv::Mat& descriptor2,
                    std::vector<cv::DMatch>& goodMatches) {

    // 1. Feautre Extraction.
    cv::Ptr<cv::FeatureDetector> detector = cv::ORB::create();
    cv::Ptr<cv::DescriptorExtractor> extractor = cv::ORB::create();


    cv::Mat curr_gray, prev_gray;
    cv::cvtColor(curr_image, curr_gray, cv::COLOR_BGR2GRAY);
    cv::cvtColor(prev_image, prev_gray, cv::COLOR_BGR2GRAY);


    // ORB Feature extraction
    detector->detect(curr_gray, keypoints1);
    extractor->compute(curr_gray, keypoints1, descriptor1);
    detector->detect(prev_gray, keypoints2);
    extractor->compute(prev_gray, keypoints2, descriptor2);

    // // 2. Matching processing.
    cv::Ptr<cv::DescriptorMatcher> matcher  = cv::DescriptorMatcher::create ( "BruteForce-Hamming" );
    std::vector<cv::DMatch> matches;
    matcher->match ( descriptor1, descriptor2, matches );
    double min_dist=10000, max_dist=0;
    for (int i =0; i < descriptor1.rows; i++){
        double dist = matches[i].distance;

        if (dist < min_dist) min_dist = dist;
        if (dist > max_dist) max_dist = dist;
    }

    for (int i = 0; i < descriptor1.rows; i++){
        if (matches[i].distance <= cv::max(2*min_dist, 30.0)){
            goodMatches.push_back(matches[i]);
        }
    }
    
    
    // // 좋은 매칭 선택
    // std::cout << "About the matches size : " << matches.size() << std::endl;
    // for (size_t i = 0; i < matches.size(); ++i) {
    //     if (matches[i][0].distance < 0.75 * matches[i][1].distance) { // 거리가 가장 가까운 것이 두 번째로 가까운 것의 0.75배 이하인 경우
    //         goodMatches.push_back(matches[i][0]);
    //     }
    // }


}
