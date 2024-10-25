#include <iostream>
#include <vector>
#include <thread>

#include "MainPipeline.hpp"
#include "DefaultController.hpp"
#include "YoloInference.hpp"

MainPipeline::MainPipeline(std::vector<std::string> urls) {
    camera_url = urls;
    if(camera_url.size() == 1){
        camera_controller = new DefaultController(camera_url[0]);
    } else {
        // a gente ve depois
    }
    inferenceWorker = new YoloInference("/home/orangepi/Documents/yolov4-tiny/yolov4-tiny.weights", 
                                        "/home/orangepi/Documents/yolov4-tiny/yolov4-tiny.cfg", 
                                        "/home/orangepi/Documents/yolov4-tiny/coco.names");

}

void MainPipeline::startMainPipeline() {
    std::thread capture_thread(&DefaultController::startCapturing, this->camera_controller);
    std::thread inferenceThread(&YoloInference::loadModel, this->inferenceWorker, false);
    inferenceThread.join();
    //capture_thread.join();

}
