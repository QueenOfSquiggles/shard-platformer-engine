/**
 * @file GuiElement.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui/raygui.h>

#include <set>

/// @brief the namespace for all GUI related components
namespace gui
{
    /// @brief The parent class for all GUIElements
    class GuiElement 
    {
    protected:
        enum SizeFlag
        {
            EXPAND, SHRINK
        };
        
        Vector2 min_size = (Vector2){16.0f, 16.0f};
        SizeFlag size_flag = SizeFlag::EXPAND;
        bool visible = false;
        std::set<GuiElement*> child_elements;

        /// @brief virtual function for drawing the specific GUI element. Uses raygui calls to draw with specified bounds to create a responsive UI
        /// @param bounds the boundaries of this element provided by the parent. This allows containers to control the size of child elements. 
        virtual void draw_gui_element(Rectangle bounds);

    public:
        /// @brief adds an element as a child of this element. 
        /// @param element the element to be added
        void add_child(GuiElement* element);

        /// @brief draws this element as the root, which draws all child elements
        void draw_root();
    };
}