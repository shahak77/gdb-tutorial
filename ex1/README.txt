Exercise 1: Basic Usage
Welcome! Today we will learn how to debug a program with gdb

Look at the file called main.cc. It contains a bug. Maybe you can spot it by
looking at the code but today we will find it using gdb.

Please read and perform each action before reading the following actions

1. compile the code by running the line 'g++ -g main.cc'. the -g flag adds debug
information to the executable that allows gdb connect lines from the executable
to code lines. If you want after the exercise you can try to compile without -g
and run gdb and see what happens

2. Run './a.out'

3. As you see, the program segfaults :(. Let's try opening it with gdb. Run the
command gdb a.out. It will open the gdb terminal. run the command 'run' or the
shorter version 'r' in order to run the executable inside gdb.

4. gdb now tells us that the program got SIGSEGV and the line that the program
got the SIGSEGV. Maybe this gives you enough information to find the bug but we
will try getting more information. press CTRL-x and then CTRL-a to enter TUI mode 
(Text User Interface). pressing CTRL-x CTRL-a again will exit from TUI mode to
normal mode. In TUI mode you can see the code section that you are in.

5. You can see now the line that caused the segfault. Let's understand what happened
by printing the current value of i. Run 'print i' or 'p i' to see the current
value of i.
If you've noticed, you can't use up and down to scroll through the command history
while in TUI mode. This is because up and down control the code view and not the
terminal. try using CTRL-p and CTRL-n instead.

6. Now that we've seen the value of i it is clear what the bug is. Let's fix it!
Now we will learn the most important command there is in gdb which is: how to exit gdb
Simply run 'quit' or 'q'
Fix the bug and re-compile and re-run the code and check that it works :)
