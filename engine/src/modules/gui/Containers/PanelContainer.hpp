#pragma once
#include "Container.hpp"
#include "../Label.hpp"

namespace gui
{
    class PanelContainer : public Container
    {
    public:
        PanelContainer(string m_name) : Container(m_name) {
            panelLabel = Label(m_name);
        }
        Label panelLabel = Label("_");
        Padding padding = (Padding){30, 30, 30, 30};
        virtual void draw(Rectangle elementBounds, Theme* parentTheme) override;
    };
}