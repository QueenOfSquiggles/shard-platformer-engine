#pragma once

#include "PanelContainer.hpp"

namespace gui {

    class VBoxContainer : public PanelContainer
    {
    public:
        VBoxContainer(string m_name) : PanelContainer(m_name){}
        
        int separation = 10;
        virtual void draw(Rectangle elementBounds, Theme* parentTheme) override;


    };
}