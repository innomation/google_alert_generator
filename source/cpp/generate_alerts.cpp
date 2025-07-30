#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility> // For std::pair
#include <sstream> // For std::stringstream
#include <format>  // For std::format (C++20)

// A structure to hold company information, clearer than std::pair
struct SiteInfo {
    std::string name;
    std::string url;
};

// Function to load sites from the configuration file
std::vector<SiteInfo> load_sites(const std::string& filename) {
    std::vector<SiteInfo> sites;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return sites; // Return empty vector
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, url;

        // Split the line by the first comma
        if (std::getline(ss, name, ',') && std::getline(ss, url)) {
            sites.push_back({name, url});
        }
    }
    return sites;
}

int main() {
    // --- 1. LOAD SITES FROM CONFIGURATION FILE ---
    auto career_sites = load_sites("sites.txt");
    if (career_sites.empty()) {
        return 1; // Exit if the file could not be read or was empty
    }

    // --- 2. QUERY TEMPLATES ---
    // Using C++ raw string literals R"()" for clean multi-line strings
    const std::string mgmt_search_query = R"(site:{} ("Engineering" OR "SRE" OR "Site Reliability" OR "DevOps" OR "Platform" OR "Infrastructure" OR "Observability" OR "Production Platform") AND ("Manager" OR "Lead" OR "Director" OR "Head of" OR "VP"))";
    const std::string senior_ic_search_query = R"(site:{} ("Lead" OR "Senior" OR "Staff" OR "Principal" OR "Distinguished" OR "Architect") AND ("Engineer" OR "Cloud" OR "SRE" OR "Site Reliability" OR "DevOps" OR "Platform" OR "Infrastructure" OR "Systems" OR "Linux" OR "Production Engineer" OR "Core Services" OR "Backend" OR "Systems Design"))";
    const std::string mid_ic_search_query = R"(site:{} ("Engineer" OR "SRE" OR "DevOps" OR "Platform" OR "Backend" OR "Production Engineer" OR "Core Services" OR "Software Engineer" OR "Cloud Engineer") -Senior -Staff -Principal -Lead -Architect)";
    const std::string key_tech_search_query = R"(site:{} ("Kubernetes" OR "Docker" OR "Terraform" OR "Infrastructure as Code" OR "IaC" OR "CI/CD" OR "AWS" OR "GCP" OR "Azure" OR "Python" OR "Linux" OR "Prometheus" OR "Grafana" OR "OpenTelemetry" OR "Ansible" OR "Datadog" OR "GitOps"))";

    // --- 3. GENERATE AND SAVE QUERIES ---
    const std::string output_filename = "generated_google_alerts.txt";
    std::ofstream output_file(output_filename);

    if (!output_file.is_open()) {
        std::cerr << "Error: Could not write to file " << output_filename << std::endl;
        return 1;
    }

    std::cout << "Successfully opened " << output_filename << " for writing..." << std::endl;

    for (const auto& site : career_sites) {
        std::cout << "Generating queries for " << site.name << "..." << std::endl;

        output_file << "# --- Queries for " << site.name << " ---\n";
        output_file << "Management:\n" << std::format(mgmt_search_query, site.url) << "\n\n";
        output_file << "Senior IC:\n" << std::format(senior_ic_search_query, site.url) << "\n\n";
        output_file << "Mid-Level IC:\n" << std::format(mid_ic_search_query, site.url) << "\n\n";
        output_file << "Key Tech:\n" << std::format(key_tech_search_query, site.url) << "\n\n";
    }

    std::cout << "\nSuccess! All queries have been written to " << output_filename << std::endl;

    return 0;
}