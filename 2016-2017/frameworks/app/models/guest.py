from app import db

class Guest(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(80), unique=True)
    message = db.Column(db.String(255))

    def __init__(self, name, message):
        self.name = name
        self.message = message

    def __repr__(self):
        return '<User {}>'.format(self.name)
