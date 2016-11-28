from flask import flash, redirect, render_template, url_for
from sqlalchemy.exc import IntegrityError

from app import app, db
from app.forms import AddGuestForm
from app.models import Guest
from app.util import flash_form_errors


# TODO: Add the proper methods for this route, then have this function render a
#       template containing the AddGuestForm and handle form submissions
@app.route('/guests/create', methods=[])
def add_guest():
    """
    """
    pass  # Remove this line
