#include <iostream>
#include <opencv2/opencv.hpp>

#include "YoloInference.hpp"

YoloInference::YoloInference(std::string modelPath, std::string cfgPath, std::string classesPath){
    this->modelPath = modelPath;
    this->cfgPath = cfgPath;
    this->classesPath = classesPath;

}

void YoloInference::loadModel(bool isCuda=false) {
    cv::dnn::Net result = cv::dnn::readNetFromDarknet(this->cfgPath, this->modelPath);
    if (isCuda) {
        std::cout << "Attempty to use CUDA\n";
        result.setPreferableBackend(cv::dnn::DNN_BACKEND_CUDA);
        result.setPreferableTarget(cv::dnn::DNN_TARGET_CUDA_FP16);
    } else {
        std::cout << "Running on CPU\n";
        result.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
        result.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);
    }
    this->model = result;
    std::cout << "Model loaded successfully..." << std::endl;
}

