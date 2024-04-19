#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
#include "front.h"

using namespace std;

int main() {
    string video_path = "/home/wondong/code/cpp/sample_video.mp4";
    cv::VideoCapture cap(video_path);
    if (!cap.isOpened()){
        cout << "video is not founded !!" << endl;
        return -1;
    }

    int frameCount = cap.get(cv::CAP_PROP_FRAME_COUNT);
    cout << "count for the frames" << frameCount << endl;
    cap.set(cv::CAP_PROP_POS_FRAMES, 30);
    
    // define the frame matrix
    cv::Mat frame;
    cv::Mat prev_frame;
    
    //  define the index
    int count = 0;

    // define the feature extractor and matcher
    cv::Ptr<cv::FeatureDetector> detector = cv::ORB::create();

    while (true){
        cap >> frame;

        if (count > 0){
            
            // 1. keypoint extraction on each images
            std::vector<cv::KeyPoint> keypoints1, keypoints2;
            cv::Mat descriptor1, descriptor2;

            FeatureExtraction(frame, prev_frame, keypoints1, descriptor1, keypoints2, descriptor2);
            cout << "keypoints1 shape : " << keypoints1.size() << endl;
            cout << "keypoints2 shape : " << keypoints2.size() << endl;
        
            // // cv::Mat visualization;
            // cv::Mat visualization;
            // cv::hconcat(framekeypoints, prevkeypoints, visualization);
            // cv::imshow("visualization for the keypoint detection", visualization);


            if (cv::waitKey(1) == 'q'){
                break;
            }

        }

        if (frame.empty()){
            break;
        }
        
        // cv::imshow("test for the video!", frame);
        prev_frame = frame;
        count ++;

    }
    cap.release();
    return 0;
}