from flask import render_template

from app import app
from app.models import Guest

# TODO: Have this function render a template that contains the list of guests
#       in the database
@app.route('/guests', methods=['GET'])
def view_guests():
    """
    """
    pass  # Remove this line
