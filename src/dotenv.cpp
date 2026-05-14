#include "../include/dotenv.hpp"
#include <fstream>

bool dot_env::load(const std::string& filepath=".env") 
{
    std::ifstream file(filepath);
    if (!file.is_open()) return false;

    std::string line;

    while (std::getline(file, line)) 
    {
        line = trim(line);

        if (line.empty() || line[0] == '#')
            continue;

        auto pos = line.find('=');
        if (pos == std::string::npos)
            continue;

        std::string key = trim(line.substr(0, pos));
        std::string value = trim(line.substr(pos + 1));

        data[key] = value;
    }

    return true;
}

std::string dot_env::get(const std::string& key) const 
{
    auto it = data.find(key);
    if (it == data.end()) return "";
    return it->second;
}

std::string dot_env::get_or(const std::string& key, const std::string& default_value) const 
{
    auto it = data.find(key);
    if (it == data.end()) return default_value;
    return it->second;
}

std::string dot_env::trim(const std::string& str) 
{
    auto start = str.begin();
    while (start != str.end() && std::isspace(*start)) start++;

    auto end = str.end();
    do 
    {
        end--;
    } 
    while (std::distance(start, end) > 0 && std::isspace(*end));

    return std::string(start, end + 1);
}