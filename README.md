This README outlines what each document within the holbertonschool-printf directory does.

The task is to create a printf function that follows the rules of the standard printf.

The first tasks requests that _printf produces an output based on the format.


FILE DESCRIPTIONS

_printf.c		Main _printf function. Parses the format string, matches specifiers, and calls handlers.
conversion_func.c	Contains functions responsible for converting values (e.g., characters, strings, integers).
handler_func.c		Contains the handler functions used by _printf to execute the correct conversion.
main.h			Header file conttaining all prototypes, structs, and macros shared across the project.
man_3_printf.3		Manual page documenting _printf, its usage, and supported format specifiers.


REQUIREMENTS

Allowed editors: vi, vim, emacs

All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89

All your files should end with a new line

A README.md file, at the root of the folder of the project is mandatory

Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl

You are not allowed to use global variables

No more than 5 functions per file

The prototypes of all your functions should be included in your header file called main.h

Don't forget to push your header file

All your header files should be include guarded




FORMAT SPECIFIERS

%c	Character
%s	String
%%	Percent sign
%d	Signed integer
%i	Signed integer



Author:

Lachie King - NOV 2025