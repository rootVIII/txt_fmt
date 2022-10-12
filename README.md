### Reformat a text file with a maximum line-length


- Compile project on Windows:  <pre><code>cl /Fe: txt_fmt.exe txt_fmt\\*.cpp</code></pre>

- Provide target file path and max line-length when executing:  <pre><code>text_format.exe file.txt 79</code></pre>

- A new file with a datestamp suffix will be created in the same location as the target file

- New lines will be preserved in the output file

- Lines in the resulting text file will not exceed the specified length

<pre><code>C:\Users\user1\Projects\txt_fmt>cat test.txt
Use the keyboard to select letters. Press down to submit a letter-guess; correct letters will appear within the green squares on the letter-board.

Study the unknown phrase after guessing a letter. Try to solve it in as few guesses as possible!

When you are sure of your answer, type it into the solution box and press enter to submit your answer.

C:\Users\user1\Projects\txt_fmt>
C:\Users\user1\Projects\txt_fmt>txt_fmt test.txt 48

C:\Users\user1\Projects\txt_fmt>cat test.txt.Wed_Oct_12_184000_2022
Use the keyboard to select letters. Press down
to submit a letter-guess; correct letters will
appear within the green squares on the
letter-board.

Study the unknown phrase after guessing a
letter. Try to solve it in as few guesses as
possible!

When you are sure of your answer, type it into
the solution box and press enter to submit your
answer.
</code></pre>