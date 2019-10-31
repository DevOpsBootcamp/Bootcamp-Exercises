from flask_wtf import FlaskForm
from wtforms import StringField
from wtforms.validators import DataRequired, Optional


class AddGuestForm(FlaskForm):
    name = StringField('Guest Name', validators=[DataRequired()])
    message = StringField('Message', validators=[Optional()])
