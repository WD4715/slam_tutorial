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


    cv::VideoWriter writer("/home/wondong/code/cpp/output.mp4", cv::VideoWriter::fourcc('M','P','4','V'), 25, cv::Size(1280, cap.get(cv::CAP_PROP_FRAME_HEIGHT)));

    while (true){
        cap >> frame;

        if (count > 0){
            
            // 1. keypoint extraction on each images
            std::vector<cv::KeyPoint> keypoints1, keypoints2;
            // std::vector<cv::Point2f> keypoints1, keypoints2;
                    
            cv::Mat descriptor1, descriptor2;
            std::vector<cv::DMatch> goodMatches; 

            FeatureExtraction(frame, prev_frame, keypoints1, descriptor1, 
                            keypoints2, descriptor2, goodMatches);
            
            // // 결과 출력
            cv::Mat imgMatches;                   
            drawMatches ( frame, keypoints1, prev_frame, keypoints2, goodMatches, imgMatches );
            cv::imshow("visualization for the feautre matching ", imgMatches);
            
            // Video save
            writer.write(imgMatches);
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
    writer.release();
    return 0;
}