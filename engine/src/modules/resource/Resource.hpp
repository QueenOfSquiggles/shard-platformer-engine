#pragma once

#include <string>


class Resource
{
    //TODO - implement functions
public:
    std::string name;
    std::string filePath;

    Resource(std::string name, std::string filePath)
    {
        this->name = name;
        this->filePath = filePath;
    }

    virtual void serialize();
    virtual void deserialize();

};