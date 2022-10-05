#include "IO.hpp"
using namespace std;

namespace io
{
    // Files-String
    string Files::fs_read(string filePath)
    {
        ifstream input(filePath);
        if (!input)
        {
            ioLog.warn("IO Problem: failed to create ifstream");
            return "";
        }
        string data;
        while(input)
        {
            string line;
            std::getline(input, line);
            data += line + "\n";
        }
        ioLog.debug("Read data from :" + filePath);
        return data;
    }

    bool Files::fs_write(string filePath, string text)
    {
        ofstream output(filePath);
        if (!output)
        {
            ioLog.warn("IO Problem: failed to create ofstream");
            return false;
        }
        ioLog.debug("Writing data to :" + filePath);
        output << text;
        output.close();
        return true;
    }

    // JSON
    json Files::json_read(string filePath)
    {
        string raw = fs_read(filePath);
        try{
            json j = json::parse(raw, nullptr, true, true); // hardcoded to allow comments. I want engine to be permissive
            return j;
        }catch(json::parse_error& e)
        {
            string formattedMsg = string(TextFormat("Error reading json file at %s;\n\t%s", filePath.c_str(), e.what()));
            ioLog.err(formattedMsg);
        }
        return NULL;
    }

    bool Files::json_write(string filePath, json obj)
    {
        return fs_write(filePath, obj.dump());
    }

}