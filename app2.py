from flask import Flask

app = Flask(__name__)

@app.route('/')
def index():
    return 'Hello my name is Khanh<br/>my student ID is 4238064<br/>I am studying FSD'

if __name__ == '__main__':
    app.run(debug=True,host='0.0.0.0')


