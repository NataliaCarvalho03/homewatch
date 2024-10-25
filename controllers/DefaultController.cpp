#include <iostream>
#include <string>
#include <unistd.h>

#include <opencv2/opencv.hpp>

#include "DefaultController.hpp"


DefaultController::DefaultController(std::string link){
    url = link;
}

int DefaultController::startCapturing() {
    cv::VideoCapture cap(url, cv::CAP_FFMPEG); 
    std::cout << "starting capture thread..." << std::endl;
    if (!cap.isOpened()) {
        std::cerr << "Error: Unable to open camera." << std::endl;
        std::cout << url << std::endl;
        return -1;
    }
    
    while (true){
        cv::Mat frame;
        cap >> frame;
        if (frame.empty()){
            break;
        }
        else {
            std::cout << "Frame captured..." << std::endl;
        }
        
        /*cv::namedWindow("Camera", cv::WINDOW_NORMAL);
        cv::resizeWindow("Camera", cv::Size(700, 300));
        cv::imshow("Camera",frame);
        if ( (char)27 == (char) cv::waitKey(1) ) break;*/
        
    }
    return 1;
}