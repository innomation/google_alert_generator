# generate_alerts.py
# A script to generate Google Alerts queries for a job search.

# --- 1. IMPORT YOUR LIST OF SITES ---
# The script now imports the career_sites list from your config_sites.py file.
try:
    from config_sites import career_sites
except ImportError:
    print("Error: Could not find config_sites.py.")
    print("Please make sure the file exists in the same directory and contains the 'career_sites' list.")
    exit()

# --- 2. ENHANCED QUERY TEMPLATES ---
# The 'site:' operator is now part of each template string.

# Management / Leadership Roles
mgmt_search_query = (
    'site:{url} ("Engineering" OR "SRE" OR "Site Reliability" OR "DevOps" OR "Platform" OR '
    '"Infrastructure" OR "Observability" OR "Production Platform") AND '
    '("Manager" OR "Lead" OR "Director")'
)

# Senior Individual Contributor (IC) Roles
senior_ic_search_query = (
    'site:{url} ("Lead" OR "Senior" OR "Staff" OR "Principal" OR "Distinguished" OR "Architect") AND '
    '("Engineer" OR "Cloud" OR "SRE" OR "Site Reliability" OR "DevOps" OR '
    '"Platform" OR "Infrastructure" OR "Systems" OR "Linux" OR '
    '"Production Engineer" OR "Core Services" OR "Backend")'
)

# Mid-Level & General IC Roles (filters out senior titles)
mid_ic_search_query = (
    'site:{url} ("Engineer" OR "Cloud" OR "SRE" OR "Site Reliability" OR "DevOps" OR '
    '"Platform" OR "Infrastructure" OR "Systems" OR "Linux" OR '
    '"Production Engineer" OR "Core Services" OR "Backend") '
    '-Senior -Staff -Principal -Lead -Architect'
)

# Key Technology Match (agnostic of seniority)
key_tech_search_query = (
    'site:{url} ("Kubernetes" OR "Docker" OR "Terraform" OR "Infrastructure as Code" OR "IaC" OR '
    '"CI/CD" OR "AWS" OR "GCP" OR "Azure" OR "Python" OR "Linux" OR "Prometheus" OR "Grafana" OR '
    '"OpenTelemetry" OR "Ansible" OR "Datadog" OR "GitOps")'
)

# --- 3. SCRIPT LOGIC TO GENERATE AND SAVE QUERIES ---

output_filename = "generated_google_alerts.txt"

try:
    with open(output_filename, "w") as f:
        print(f"Successfully opened {output_filename} for writing...")

        for company_name, url in career_sites:
            print(f"Generating queries for {company_name}...")

            f.write(f"# --- Queries for {company_name} ---\n")
            f.write(f"Management:\n {mgmt_search_query.format(url=url)}\n")
            f.write(f"Senior IC:\n {senior_ic_search_query.format(url=url)}\n")
            f.write(f"Mid-Level IC:\n {mid_ic_search_query.format(url=url)}\n")
            f.write(f"Key Tech:\n {key_tech_search_query.format(url=url)}\n")
            f.write("\n")

    print(f"\nSuccess! All queries have been written to {output_filename}")

except IOError as e:
    print(f"Error: Could not write to file {output_filename}. Reason: {e}")