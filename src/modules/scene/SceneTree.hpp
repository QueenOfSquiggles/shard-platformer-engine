#pragma once

#include "GameObject.hpp"
#include <vector>

class SceneTree
{
    struct Element
    {
        GameObject* game_object;
        Element* parent;
        std::vector<Element*> children;         
    };

    Element* root;

};