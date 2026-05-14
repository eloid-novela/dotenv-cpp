#include <iostream>
#include "../include/dotenv.hpp"

int main() 
{
    dot_env env;

    if (!env.load(".env.example")) 
    {
        std::cout << "Failed to load .env\n";
        return 1;
    }

    std::cout << env.get("DB_HOST") << std::endl;
    std::cout << env.get_or("PORT", "8080") << std::endl;
    std::cout << env.get("API_KEY") << std::endl;

}