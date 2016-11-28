from flask_wtf import FlaskForm
from wtforms import StringField
from wtforms.validators import DataRequired


class CreateUserForm(FlaskForm):
    name = StringField('User Name', validators=[DataRequired()])
