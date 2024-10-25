
#ifndef MAINPIPELINE_H
#define MAINPIPELINE_H

#include <iostream>
#include <vector>
#include <thread>

#include "DefaultController.hpp"
#include "YoloInference.hpp"


class MainPipeline {
    public:
        std::vector<std::string> camera_url;
        DefaultController *camera_controller;
        YoloInference *inferenceWorker;
        //std::thread inferecence;
        MainPipeline(std::vector<std::string> urls);
        void startMainPipeline();
};

#endif