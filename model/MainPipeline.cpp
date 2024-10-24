#include <iostream>
#include <vector>
#include <thread>

#include "MainPipeline.hpp"
#include "DefaultController.hpp"

MainPipeline::MainPipeline(std::vector<std::string> urls) {
    camera_url = urls;
    if(camera_url.size() == 1){
        camera_controller = new DefaultController(camera_url[0]);
    } else {
        // a gente ve depois
    }
}

void MainPipeline::startMainPipeline() {
    std::thread capture_thread(&DefaultController::startCapturing, this->camera_controller);
    capture_thread.join();

}
