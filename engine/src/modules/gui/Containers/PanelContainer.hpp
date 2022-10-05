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
        Color panelColour = WHITE;
        Color fontColour = BLACK;
        Padding padding = (Padding){10, 10, 10, 10};
        virtual void draw() override;
        virtual void addElement(GuiElement *element) override;
    };
}