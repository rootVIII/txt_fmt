### Reformat a text file with a maximum line-length


- Compile project on Windows:  <pre><code>cl /Fe: text_format.exe text_format\\*.cpp</code></pre>

- Provide target file path and max line-length when executing:  <pre><code>text_format.exe file.txt 79</code></pre>

- A new file with a datestamp suffix will be created in the same location as the target file

- New lines will be preserved in the output file

- Lines in the resulting text file will not exceed the specified length
