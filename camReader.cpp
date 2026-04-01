//Include Libraries
//Include Libraries
#include<opencv2/opencv.hpp>
#include<iostream>


int main(){

    cv::VideoCapture cameraReader(0); //Creating the object that receives the camera

    if(!cameraReader.isOpened()){
        std::cout << "Error creating the cameraReader" << std::endl;
        return -1; 
    }

    cv::Mat matrixframe;    //matrix of pixels 

    while (true) {
        cameraReader >> matrixframe;
        if (matrixframe.empty()) break;

        cv::imshow("Webcam", matrixframe);

        if (cv::waitKey(10) == 27) {
            break;
        }
    }

    cameraReader.release();
    cv::destroyAllWindows();
    return 0;

}   