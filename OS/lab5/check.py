import openai_secret_manager
import requests

# Use openai_secret_manager to get the API key
secrets = openai_secret_manager.get_secrets("openai")
api_key = secrets["api_key"]

# Define the endpoint for the API
endpoint = "https://api.openai.com/v1/engines/davinci-codex/completions"

# Define the prompt for the API
prompt = (
    "Hello, how can I help you today?"
)

# Define the parameters for the API request
params = {
    "prompt": prompt,
    "max_tokens": 100,
    "temperature": 0.7,
}

# Send the API request and get the response
response = requests.post(
    endpoint,
    json=params,
    headers={"Authorization": f"Bearer {api_key}"}
)

# Print the response
print(response.json()["choices"][0]["text"])
