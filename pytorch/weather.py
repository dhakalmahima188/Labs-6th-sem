import requests
from bs4 import BeautifulSoup

city = input("Enter your City Name ")
search = "Weather in {}".format(city)
url=f"https://www.google.com/search?&q={search}"

r =requests.get(url)
htmlContent = r.content 
#print(htmlContent)


soup = BeautifulSoup(htmlContent,'html.parser')
#print(soup.prettify)

temp = soup.find("div", class_='BNeawe').text

print("Temperature in " + city + " is " + temp +".")