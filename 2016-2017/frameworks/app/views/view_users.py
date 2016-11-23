from flask import render_template

from app import app
from app.models import User

# TODO: Have this function render a template that contains the list of users
#       in the database
@app.route('/users', methods=['GET'])
def view_users():
    """
    """
    pass  # Remove this line
