import requests
from bs4 import BeautifulSoup

def crawl_web_page(url):
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 '
                      '(KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36'
    }
    try:
        response = requests.get(url, headers=headers)
        if response.status_code == 200:
            soup = BeautifulSoup(response.content, 'html.parser')
            data = soup.prettify()  # This formats the HTML content nicely

            # Print the data to console
            print(data)

            # Save the data to a file
            file_path = 'output.html'  # Define the local file path to store the data
            with open(file_path, 'w', encoding='utf-8') as file:
                file.write(data)
            print(f"Data saved to {file_path}")

        else:
            print(f"Failed to retrieve the page. Status code: {response.status_code}")
    except Exception as e:
        print(f"An error occurred: {e}")

# Specify the webpage to crawl
url = 'https://www.nytimes.com/section/business'
crawl_web_page(url)