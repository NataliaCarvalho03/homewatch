#ifndef YOLOINFERENCE_H
#define YOLOINFERENCE_H

#include <iostream>
#include <opencv2/opencv.hpp>

class YoloInference {
    public:
        std::string modelPath;
        std::string cfgPath;
        std::string classesPath;
        cv::dnn::Net model;
        YoloInference(std::string modelPath, std::string cfgPath, std::string classesPath);
        void loadModel(bool isCuda);
};

#endif