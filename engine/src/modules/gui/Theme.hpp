#pragma once

#include <string>
#include <unordered_map>
#include <raylib.h>

using namespace std;

namespace gui
{
    class Theme
    {
        
        unordered_map<string, Color> themeProperties;

    public:
        void addProperty(string key, Color value)
        {
            themeProperties.insert(pair<string, Color>(key, value));
        }

        Color getProperty(string key, Color defaultValue)
        {
            auto loc = themeProperties.find(key);
            if (loc == themeProperties.end()) return defaultValue;
            return loc->second;
        }

        unordered_map<string, Color>::iterator itrBegin() { return themeProperties.begin(); }
        unordered_map<string, Color>::iterator itrEnd() { return themeProperties.end(); }
    };


}