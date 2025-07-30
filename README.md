# Google Alerts Query Generator

A powerful command-line tool to automate the creation of highly specific Google Alerts queries, designed for power users, researchers, and job seekers who need to monitor the web with precision.

### **Why This Project?**

Google Alerts is an invaluable tool for monitoring the web, but managing dozens or even hundreds of highly specific alerts through the web interface is a tedious, manual process. This project solves that problem by allowing you to:

- Centrally manage a list of target websites in a simple configuration file.
- Define powerful query templates for different search criteria (e.g., management roles, senior engineers, specific technologies).
- Instantly generate hundreds of ready-to-use query strings with a single command.

This tool was born from the need to create a sophisticated, automated job search system but is flexible enough for any large-scale monitoring task.

### **Features**

- Bulk Query Generation: Create hundreds of precise Google Alerts queries in seconds.
- Template-Driven: Easily define and reuse query structures for different needs.
- Centralized Configuration: Manage your entire list of target websites from a single, clean configuration file.
- Multi-Language Support: Choose between a flexible Python script or a high-performance, standalone C++ executable.
- Included Job Search Catalog: Comes pre-loaded with query templates tailored for Systems Engineering, SRE, DevOps, and Platform Engineering roles in the tech and gaming industries.

## **Getting Started**

Choose the version that best fits your workflow. Both versions use the same logic and produce the same output.
Prerequisites

For the Python version: Python 3.7+

For the C++ version: A C++20 compatible compiler (e.g., GCC 10+, Clang 12+, MSVC v19.29+) and CMake (v3.20+).

## **Installation & Setup**

Clone the repository:

    git clone [https://github.com/your-username/google-alert-generator.git](https://github.com/your-username/google-alert-generator.git)
    cd google-alert-generator

Configure your target sites:

- If using the C++ version, open sites.txt and add your target URLs in the format CompanyName,URL.
- If using the Python version, open config_sites.py and edit the career_sites list.

## **How to Use**

##### Python Version

Simply run the script from your terminal:

    python generate_alerts.py

##### *C++ Version (using CMake)*

Create a build directory:

    mkdir build
    cd build

Configure and build the project:

    cmake ..
    cmake --build .

Run the executable:

    ./generate_alerts

After running either version, a file named generated_google_alerts.txt will be created in the root directory. This file contains all your queries, neatly organized and ready to be copied and pasted into google.com/alerts.

## **Customization**

The power of this tool comes from its configuration files.

    config_sites.py / sites.txt: This is where you define your master list of companies and career page URLs. This is the main file you will edit.

    generate_alerts.py / generate_alerts.cpp: You can edit the query template strings within the main script files to change the keywords, add new query types, or tailor the search logic to your specific needs.

## **Contributing**

Contributions are welcome! If you have ideas for new features, query enhancements, or bug fixes, please feel free to open an issue or submit a pull request.

## **License**

This project is licensed under the MIT License - see the [LICENSE.md]() file for details.
