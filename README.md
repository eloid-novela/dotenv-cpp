# dotenv-cpp

A lightweight C++ library for loading environment variables from `.env` files.

## Overview

`dotenv-cpp` is a simple and efficient library designed to load configuration from `.env` files into C++ applications. It helps developers manage environment-based settings in a clean and structured way.

It supports basic key-value parsing, comments, and safe retrieval of values with fallback defaults.

---

## Features

- Load `.env` files easily
- Key-value parsing (`KEY=VALUE`)
- Ignore comments and empty lines
- Safe retrieval with default values
- Simple and minimal API
- Unit tested with GoogleTest

---

## Installation

Clone the repository:

```bash
git clone https://github.com/eloid-novela/dotenv-cpp.git
cd dotenv-cpp
````

Build with CMake:

```bash
mkdir build
cd build
cmake ..
make
```

---

## Usage

### Example `.env` file

```env
DB_HOST=localhost
DB_PORT=5432
DEBUG=true
```

### Example code

```cpp
#include <iostream>
#include "dotenv.hpp"

int main() 
{
    dot_env env;

    if (!env.load(".env")) 
    {
        std::cerr << "Failed to load .env file" << std::endl;
        return 1;
    }

    std::cout << env.get("DB_HOST") << std::endl;
    std::cout << env.get_or("PORT", "8080") << std::endl;

    return 0;
}
```

---

## Running Tests

This project uses **GoogleTest**.

Build and run tests:

```bash
mkdir build
cd build
cmake ..
make
ctest
```

Or run directly:

```bash
./dotenv_tests
```

---

## Project Structure

```
dotenv-cpp/
├── include/
│   └── dotenv.hpp
├── src/
│   └── dotenv.cpp
├── tests/
│   ├── test_dotenv.cpp
├── CMakeLists.txt
└── README.md
```

---

## Future Improvements

* Support for quoted values (`"hello world"`)
* Variable interpolation (`${VAR}`)
* Type-safe getters (`get_int`, `get_bool`)
* Header-only version
* Cross-platform enhancements
* Packaging for vcpkg / Conan

---

## Contributing

Contributions are welcome! Feel free to fork the project and submit pull requests.

---
