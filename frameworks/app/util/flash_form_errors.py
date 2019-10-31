def flash_form_errors(form):
    for field, errors in form.errors.items():
        for error in errors:
            flash("{} {}", field.label.text, error)
