Vim
===


Use `wget` to download the `data` file in this local directory:

```bash
$ wget https://github.com/DevOpsBootcamp/Bootcamp-Exercises/raw/master/editors/data
```

and then open the file in vim:

```bash
$ vim data
```

Starting with the cursor at the top of the file:

1. Press `C-v` to begin a Visual Block
2. Press `j` to move the cursor down to the last line
3. Press `l` to move the cursor to the space before `10.1.1.12`.
4. Press `x` to delete the highlighted rectangle.
5. Type `:%s/10.1.1.12./myhost:/` and hit enter to change the first
   occurrence of `10.1.1.12.` to `myhost:` on every line.
6. Type `:set number` and hit enter to add line numbers.
7. Type `:match ExtraWhitespace /\s\+$\| \+\ze\t/` and hit enter to highlight
   extra whitespace at the end of lines.
8. Remove extra whitespace from the lines that have it.
