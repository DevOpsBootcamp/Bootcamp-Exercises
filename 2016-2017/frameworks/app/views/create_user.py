from flask import flash, redirect, render_template, url_for
from sqlalchemy.exc import IntegrityError

from app import app, db
from app.forms import CreateUserForm
from app.models import User
from app.util import flash_form_errors


# TODO: Add the proper methods for this route, then have this function render a
#       template containing the CreateUserForm and handle form submissions
@app.route('/users/create', methods=[])
def create_user():
    """
    """
    pass  # Remove this line
