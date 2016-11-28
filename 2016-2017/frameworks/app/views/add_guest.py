from flask import flash, redirect, render_template, url_for
from sqlalchemy.exc import IntegrityError

from app import app, db
from app.forms import AddGuestForm
from app.models import Guest
from app.util import flash_form_errors


@app.route('/guests/create', methods=['GET', 'POST'])
def add_guest():
    form = AddGuestForm()

    if form.validate_on_submit():
        name = form.name.data
        message = form.message.data

        guest = Guest(name, message)

        try:
            db.session.add(guest)
            db.session.commit()

        except IntegrityError as e:
            flash('Guest with name "{}" already exists!'.format(name))
            return redirect(url_for('add_guest'))

        flash('Guest "{}" successfully added'.format(name))
        return redirect(url_for('index'))

    flash_form_errors(form)

    return render_template('add_guest.html', form=form)
