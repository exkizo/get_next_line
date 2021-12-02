# get_next_line
```c
  char *get_next_line(int fd);
```
<div><p>The goal of this project is to create a function that reads a file descriptor and returns a line.</p>
<ul>
  <li>Calling your function get_next_line in a loop will then allow you to read the text
available on the file descriptor one line at a time until the end of it.</li>
  <li>Your function should return the line that has just been read. If there is nothing else to read or if an error has occurred it should return NULL.</li>
  <li>Make sure that your function behaves well when it reads from a file and when it reads from the standard input.</li>
  <li>libft is not allowed for this project. You must add a get_next_line_utils.c file which will contain the functions that are needed for your get_next_line to work.</li>
 </ul></div>
 
## Compilation
  For the evaluation your program will be compiled in this way:
  ```bash
  cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c.
  ```
  Which will be used as the buffer size for the read calls in your get_next_line. This value will be modified by your evaluators and by the moulinette.
  
 <div><ul>
  <li>Your read must use the BUFFER_SIZE defined during compilation to read from a file or from stdin. This value will be modified during the evaluation for testing purposes.</li>
  <li>In the header file get_next_line.h you must have at least the prototype of the function get_next_line.</li>
  <li>lseek is not an allowed function. File reading must be done only once.</li>
  <li>We consider that get_next_line has undefined behavior if, between two calls, the same file descriptor switches to a different file before reading everything from the first fd.</li>
  <li>Finally we consider that get_next_line has undefined behavior when reading from a binary file. However, if you wish, you can make this behavior coherent.</li>
  <li>Global variables are forbidden.</li>
  <li>Important: The returned line should include the ’\n’, except if you have reached the end of file and there is no ’\n’.</li>
  </ul></div>

## Bonus Part
The project get_next_line is straightforward and leaves very little room for bonuses, but we are sure that you have a lot of imagination. If you have aced the mandatory part, then by all means, complete this bonus part to go further. Just to be clear, no bonuses will be taken into consideration if the mandatory part isn’t perfect.Turn-in all 3 mandatory files ending by _bonus.[c\h] for this part.
<div>
  <ul>
  <li>To succeed get_next_line with a single static variable.</li>
    <li>To be able to manage multiple file descriptors with your get_next_line. For example, if the file descriptors 3, 4 and 5 are accessible for reading, then you can call get_next_line once on 3, once on 4, once again on 3 then once on 5 etc. without losing the reading thread on each of the descriptors.</li>
  </ul>
</div>
