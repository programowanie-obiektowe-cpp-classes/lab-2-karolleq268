#include <iostream>

#pragma once

#include "Resource.hpp"

class ResourceManager 
{
private:
    Resource* resource; 

public:
    ResourceManager() : resource(new Resource()) 
    {
        std::cout << "ResourceManager created\n";
    }

    ~ResourceManager() 
    {
        delete resource;
        std::cout << "ResourceManager destroyed\n";
    }

    ResourceManager(const ResourceManager& other)
        : resource(new Resource(*other.resource)) 
    {
        std::cout << "ResourceManager copied\n";
    }

    ResourceManager& operator=(const ResourceManager& other) 
    {
        if (this != &other) 
        {
            delete resource;
            resource = new Resource(*other.resource);
            std::cout << "ResourceManager copy-assigned\n";
        }
        return *this;
    }

    double get() 
    {
        return (*resource).get();
    }
};
