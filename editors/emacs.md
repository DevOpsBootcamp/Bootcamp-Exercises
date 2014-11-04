Emacs
=====


Use `wget` to download the `data` file in this local directory:

```bash
$ wget https://github.com/DevOpsBootcamp/Bootcamp-Exercises/raw/master/editors/data
```

and then open the file in emacs:

```bash
$ emacs data
```

Starting with the cursor at the top of the file:

1. Press `C-space` to set a mark at the beginning of the file
2. Press `C-n` to move the cursor down a line
3. Keep moving the cursor down to the last line (it should still be in the first column)
4. Press `C-f` to move the cursor forward until it is on the 1 in `10.1.1.12:64857`. It should
   highlight everything up to the space before.
5. Press `C-x r k` to delete the highlighted rectangle. Notice that the rectangle deleted is slightly
   different from the shape that was highlighted: it deletes from the top to the bottom, and from the
   beginning of the line up to the space before `10.1.1.12` on all lines.
6. Press `M-x` and then type `replace-regexp` and hit enter. Type `10.1.1.12.` into the mini-buffer
7. Press enter, and then type `myhost:` into the minibuffer.
8. If you didn't move the cursor between steps 5 and 6, you'll notice you only replaced the last 
   `10.1.1.12`, and the other 15 ocurrences were **not** replaced. Press `M-<`
   to move to the beginning of the file.
9. Press `M-x` again, but this time follow it with `M-p`. You'll notice that
   `replace-regexp` appears in the mini-buffer. `M-p` places the last thing
   that was typed in the mini-buffer into the mini-buffer again.
10. Press enter, and you'll notice the mini-buffer now says
    `Replace regexp (default 10.1.1.12. -> myhost:)` Hit enter one more time to
    replace the rest of the ocurrences of `10.1.1.12`.
11. Press `M-x` and type `linum-mode` and hit enter. You should now see line
    numbers appear to the left of the lines.
12. Press `M-x` again and type `whitespace-mode`, and hit enter. You'll notice
    that lines now end with a greyed-out `$` and spaces between words are either
    `?` or ` `. Spaces at the end of lines after all other text will be
    highlighted in red, as well any lines that are > 79 characters long.
13. Remove all spaces at the end of lines (after TIME_WAIT or ESTABLISHED).
    These are the spaces highlighted in red.