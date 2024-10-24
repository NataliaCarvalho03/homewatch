#ifndef DEFAULTCONTROLLER_H
#define DEFAULTCONTROLLER_H

#include <iostream>
#include <string>
#include <unistd.h>
#include <thread>


class DefaultController {
    public:
        std::string url;
        DefaultController(std::string link);
        int startCapturing();
        
};

#endif