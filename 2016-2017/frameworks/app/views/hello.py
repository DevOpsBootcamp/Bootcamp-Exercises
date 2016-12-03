from app import app

@app.route('/hello/<name>')
def hello(name):
    print("hello")
    return 'Hello %s!!' % name
