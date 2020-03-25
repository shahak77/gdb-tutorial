Exercise 2: Stack Navigation and exceptions.

Look at the file called main.cc
The function generate_map always generate the same map that has as keys every number
from 0 to 9 except 1 number. Your goal is to find out which number is it. You
only have the function's object file.

If you recall, the 'at' method gets the value of a given key and throws an exception
if it doesn't exist

As always, perform each step before reading the next.

1. compile the code by running the line 'g++ -g main.cc generate_map.o'

2. Run './a.out' and see that an exception is thrown

3. Run 'gdb a.out' and run the executable by running 'r'

4. Enter TUI mode (by pressing CTRL-x CTRL-a)

5. As you can see, we are in a place in the code that we don't have its source file.
But that's ok, because we can go up in the stack until we reach our own code.
Run the command 'up'. It will go up in the call stack and present to you the file you're
currently at. Keep running 'up' until you reach main.cc (that's our code).
Note that if you simply press enter it will perform the same action you did last time.

6. Now you're at the line with the call to at() that caused the exception. Find
the secret number by printing i (you can instead print m if you prefer)

7. Note that while going up the stack, we had to pass a lot of frames that handle the
termination of the program once the exception was thrown. We can instead tell gdb
to stop the program when an exception is thrown. This is also useful if you're
debugging an exception that is later caught.
Run 'catch throw' and then re-run the program by running 'r' (you can do this in
TUI mode or you can return to normal mode). Now as you see the stack is much shorter

8. Fix main.cc by running 'continue' in the loop when the key is the problematic value

