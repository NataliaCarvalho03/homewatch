#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "MainPipeline.hpp"


int main(int argc, char* argv[]){
    std::string cameraURL = std::string("rtsp://192.168.100.213:554/live/0/MAIN");
    std::vector<std::string> cameras;
    cameras.push_back(cameraURL);
    MainPipeline mainPipeline(cameras);
    mainPipeline.startMainPipeline();
    return 0;
}