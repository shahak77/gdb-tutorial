Exercise 3: Breakpoints, steps and watchpoints

In this exercise, the executables are trying to call many times to cyber functions
(that does cyber). Each cyber function has a value that if it is called with it
the function will cause itsumim! (this is expressed by turning the value of the
variable no_itsumim from 1 to 0). Your goal is to find and disable all the calls
to cyber functions that cause itsumim (we don't want to disable calls that don't
cause itsumim because we want to do as much cyber as possible).

Let's start by looking at main1.cc

As always, perform each step before reading the next.

1. compile it with the line 'g++ -g main1.cc cyber.o' and run './a.out'

2. As we see, we caused itsumim. Run a.out with gdb and enter TUI mode

3. The problem is that we don't know when no_itsumim turned into 0. Let's put a
breakpoint on the line that causes itsumim. A breakpoint on a line means that
each time the program reaches that line it will stop and let you run gdb commands
the line that we want to put a break-point on is line 5. Let's put a break-point
on that line by running 'break main1.cc:5' or 'b main1.cc:5'.

4. Now re-run the program (by running 'r')

5. As we see, the program stopped at the breakpoint. It's important to note that
the program stops before performing the line that has a breakpoint and not after.
Print the value of no_itsumim and i.

6. As we see, we need to pass on more lines to find the problematic call. In order
to continue the execution (until the next breakpoint), run 'continue' or 'c'.

7. Continue printing values and continuing until you find the problematic call

8. Fix main1.cc by skipping the problematic call. ensure that the cyber count
doesn't go below 9

You can see the breakpoints you have by running 'info break' or 'info b'. You
can delete a breakpoint by running 'delete num' where num is its number. You can
also disable and enable them with the commands 'disable num', 'enable num'. Disabled
breakpoints will not triggered but their position is still saved and they can be easily enabled

--------------------------------------------------------------------------------

Excellent! Now let's look at main2.cc

We have here many lines calling cyber2. We can put a breakpoint on each line but
it will be tedious. Instead we will put a breakpoint on the function cyber2.
To do that run in the gdb terminal 'break cyber2' or 'b cyber2'

Note that the breakpoint will put you inside the function cyber2. You will need
to go up in the stack to find the calling line (you can still print no_itsumim
while inside cyber2)

Here's another command that will come in handy to find the line. If you type
'display no_itsumim' (or any other expression) it will print its value every time
the execution has advanced. Each displayed expression has a number (the first is 1
and so on) and can be canceled by running 'undisplay number' where number is the
expression's number.

Use gdb to find the line causing itsumim and the comment it out. Make sure that
the cyber count doesn't go below 9

--------------------------------------------------------------------------------

Excellent! Now let's look at main3.cc

The more_cyber functions don't receive an argument. One of them always does
itsumim. We need to disable it.

This time we will have to put a breakpoint on each line because the functions are
different each line. instead we will step into and over the code

First, let's add a breakpoint when we start the program by running in the gdb
terminal 'b main'

Now, when we run the program it is going to print a lot of stuff and this will disrupt
the TUI gui. In order to prevent that, when we run the program, we will run the command
'r > /dev/null'. This will redirect the output of the program to /dev/null

Great, now that we ran the program we stopped at the beginning of main.

We now instead of continuing want to go step-by-step in the program. To do that we
will run 'step' or 's'. This will continue the program and will stop it on the
next line it runs. 

Start trying to find the problematic more_cyber function by performing a few steps
and then look at the next instruction

The problem by stepping into the next line is that we are entering the code of the
function nabaz which is irrelevant for the bug we're trying to find. Therefore we should
use 'next' or 'n' that steps over the next line. This means it will skip any function calls
that happen in this line and will go to the next line in this function (or the function
above it if none exist).

We should use next when we're on a more_cyber function or nabaz function and step
when we're on a cyber_batch.

Find the function that causes itsumim using next and step. don't forget to display no_itsumim.
If you went too far and want to go back, try running 'reverse-next' or 'rn' to undo a next
and 'reverse-step' or 'rs' to undo a step. These actions won't work on all
target environments though :(

As before, uncomment the problematic function and make sure the cyber count doesn't
go below 9.

More useful commands:
finish - continue running and stop at the end of the current function
stepi - like step but instead of doing one line from the source code, do one machine instruction
nexti - like next but instead of doing one line from the source code, do one machine instruction

--------------------------------------------------------------------------------

Now I'm going to tell you that all the hard work you did could be easily solved
by one command. You can add a breakpoint to an expression (say a variable).
Meaning that the program will stop when a write to that expression is performed.
Points like these are called watchpoints and the command for them is 'watch no_itsumim'.
Try to re-do one of the exercises with this command (you will fail to).

The reason you failed is because you were linked to an object file (cyber.o) that wasn't
compiled with the -g flag and gdb therefore couldn't tell when the value of no_itsumim
was changed.

There are two kind of watchpoints, hardware watchpoints and software watchpoints.
Hardware watchpoints stop at the machine instruction that caused the change
and therefore they won't slow down the execution. Hardware watchpoints don't work
well on global variables that were declared in other files.

Software watchpoints run a code after each source-code line that check if the value
was changed. We can tell gdb to put only software watchpoints by running
'set can-use-hw-watchpoints 0'. Note that this will make the execution really slow
so be patient. This is why under normal circumstances (where we don't need to watch globals)
we would much prefer using hardware watchpoints. Set the watchpoint only after
you loaded the program (put a breakpoint on the main function) because it will really
slow down the setup.

More useful commands:
rwatch - Set a watchpoint that will trigger if there was a read to the expression
awatch - Set a watchpoint that will trigger if there was a read or write to the expression

