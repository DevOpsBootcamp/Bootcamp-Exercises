from flask import render_template

from app import app
from app.models import Guest

@app.route('/guests', methods=['GET'])
def view_guests():
    guests = Guest.query.all()

    return render_template('view_guests.html', guests=guests)
