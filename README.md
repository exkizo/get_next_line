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
Turn-in all 3 mandatory files ending by _bonus.[c\h] for this part.
<div>
  <ul>
  <li>To succeed get_next_line with the bonus you need to use just one static variable.</li>
    <li>Also you need to be able to manage multiple file descriptors with your get_next_line. For example, if the file descriptors 3, 4 and 5 are accessible for reading, then you can call get_next_line once on 3, once on 4, once again on 3 then once on 5 etc. without losing the reading thread on each of the descriptors.</li>
  </ul>
</div>

## How do the code works
  My version of get_next_line function works with 3 main functions and some utility functions to help the program. To handle with the multiple file descriptors problems it was created an array of pointers witch each element is contais the address of a pointer to a string.
### Main functions:
* [`read_line`](get_next_line/get_next_line_utils.c) -this fuction reads into the buffer [BUFFER_SIZE] bytes and checks if it was readed at least one line(if there is a '/n'). While there is less than a line read, it joins to the preview interation using ```ft_strjoin```
 when it was readed more at least one line, the fuction will them free the buffer and return.
 
 * [`get_line`](get_next_line/get_next_line.c) -this function iterates the returned string from ```read_line``` and looks for a '/n'(end of a line) and return a line.
 
 *  [`get_line`](get_next_line/get_next_line.c) -this function iterates the returned string from ```read_line``` and returns the string after the '/n' (end of the line) so it can be used on the next time the function ```get_next_line``` is called.
  
