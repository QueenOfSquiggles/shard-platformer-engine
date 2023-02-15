#pragma once

#ifdef DEBUG
// creates additional memory and processing overhead to produce more meaningful error messages
#define JSON_DIAGNOSITCS
#endif
#include <string>
#include <fstream>

#include <nlohmann/json.hpp>
#include <toml++/toml.hpp>
#include "modules/logging/Log.hpp"

using json = nlohmann::json;

namespace io
{

    class Files
    {
        logging::Log ioLog = logging::Log("I/O");

    public:
        // File-String
        std::string fs_read(std::string filePath);
        bool fs_write(std::string filePath, std::string text);

        // JSON
        // See also: https://json.nlohmann.me/features/parsing/parse_exceptions/#exceptions
        json json_read(std::string filePath);
        bool json_write(std::string filePath, json obj);
    };
    
    static Files files;
}
