from flask import Flask, render_template
import random

app = Flask(__name__)

# Function to check if a year is a leap year
def is_leap_year(year):
    if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
        return True
    else:
        return False

# Route to generate a random year and check if it's leap
@app.route('/')
def generate_random_year():
    random_year = random.randint(0, 2021)
    leap_status = is_leap_year(random_year)
    return f"The random year generated is {random_year}, which {leap_status} a leap year."

if __name__ == '__main__':
    app.run(debug=True,host='0.0.0.0')
        
