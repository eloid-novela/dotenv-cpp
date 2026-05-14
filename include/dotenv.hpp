#pragma once

#include <string>
#include <unordered_map>

class dot_env 
{
public:
    bool load(const std::string& filepath);
    
    std::string get(const std::string& key) const;
    std::string get_or(const std::string& key, const std::string& default_value) const;

private:
    std::unordered_map<std::string, std::string> data;

    std::string trim(const std::string& str);
};