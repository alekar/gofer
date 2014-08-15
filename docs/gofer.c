.\" *** The original version of this man page was prepared by Gary Leavens.
.TH GOFER 1
.\" ***Local system maintainers should correct the following string def ***
.ds GL /usr/local/lib/Gofer
.SH NAME
gofer, gofc \- Gofer programming language interpreter and compiler

.SH SYNOPSIS
.B gofer

.B gofc [file] ...

.SH DESCRIPTION
Gofer is an interactive functional programming environment (i.e. an
interpreter) supporting a language based on the draft report for Haskell
version 1.2, including the following features:
.PD 0
.TP 10
  o  Lazy functional language features such as
lazy evaluation, higher order functions, pattern matching,
etc.
.TP
  o  Wide range of built-in types
with provision for defining new free
datatypes and type synonyms.
.TP
  o  Polymorphic type system
with provision for overloading based on
a system of type classes.
.TP
  o  Full Haskell 1.2 expression and pattern syntax
including lambda,
case, conditional and let expressions, list comprehensions, operator
sections, and wildcard, as and irrefutable patterns.
.TP
  o  Partial implementation of Haskell 1.2 I/O
enabling
the use of simple interactive programs and programs reading and writing
text files.
.TP
  o  Constructor classes and overloaded monad comprehensions.
.TP
  o  Simple minded compiler/translator gofc
with runtime system for
generation of standalone applications.
.TP
  o  Runs on PC compatible computers,
but also works on Sun and other workstations.
.PP 
Gofer is intended as an experimental language, particularly where type classes
are involved.  Gofer extends the Haskell type class system in several ways:
.TP
  o  Type classes with multiple parameters.
.TP
  o  Instances of type classes 
may be defined non-overlapping,
but otherwise arbitrary types.
.TP
  o  Predicates in contexts
may involve arbitrary type expressions,
not just type variables as in Haskell.
.TP
  o  Basic approach to dictionary construction is different,
based on the
approach described in a posting to the Haskell mailing list early in
Feburary 1991.  The resulting system ensures that all dictionaries are
constructed before evaluation begins, avoiding repeated construction
and enabling the shared evaluation of overloaded constants in
dictionaries.
.PP
The most significant features of Haskell not currently supported are:
modules, arrays, overloaded numeric constants, default declarations, derived
instances, contexts in datatype definitions.

.SH INTERPRETER
.PP
The Gofer interpreter is usually entered by giving the command `gofer'.
.PP
Most commands in Gofer take the form of a colon followed by one or more
characters which distinguish one command from another.  There  are  two
commands which are particularly worth remembering:
.TP
  o  :q  exits the  Gofer  interpreter.
On most systems, you can also
exit from Gofer by typing the end of  file  character (^D).
.TP
  o  :?  prints a list of all the commands,
which can be useful if you
forget the name of the command that you want to use.
.PP
Note that the interrupt key (^C on most systems) can  be  used  at  any
time whilst using Gofer to abandon the process of reading in a file  of
function definitions or the evaluation  of  an  expression.   When  the
interrupt key is detected, Gofer prints the string "{Interrupted!}" and
prints the "? " prompt so that further commands can be entered.

.SH COMPILER
.PP
Compiling a program with gofc is very much like starting up the Gofer
interpreter.  The compiler starts by reading the prelude and then
loads the script files specified by the command line.  These scripts
must contain a definition for the value main :: Dialogue which will be
the dialogue expression that is evaluated when the compiled program is
executed.
.PP
For example, if the file apr1.gs contains the simple program:
.RS
 main :: Dialogue
 main  = appendChan "stdout" "Hello, world\\n" exit done
.RE
then this can be compiled with the following command.
.RS
 gofc apr1.gs
.RE
The output is written to the file apr1.c -- i.e. the name obtained by
removing the .gs suffix and replacing it with a .c suffix.  Other
filename suffixes that are treated in a similar way are:
.RS
 .prj    .gp              for Gofer project files
 .prelude                 for Gofer prelude files
 .gof    .gs              for Gofer scripts
 .has    .hs              for Haskell scripts
 .lhs    .lit             for literate scripts
 .lgs    .verb
.RE
If no recognized suffix is found then the name of the output file is
obtained simply by appending the .c suffix to the input name.
Be careful; if you take an input
file called `prog' and compile it to `prog.c' using gofc, make sure
that you do not compile the C program in such a way that the output is
also called `prog' since this will overwrite your original source code!
For this reason, you should always using file extensions such as .gs
if you are using gofc.
.PP
If you run gofc with multiple script files, then the name of the output
file is based on the last script file to be loaded.  For example, the
command `gofc prog1.gs prog2.gs' produces an output file `prog2.c'.
.PP
The compiler gofc also works with project files,
using the name of the project file
to determine the name of the output file.  For example, the miniProlog
interpreter can be compiled using:
.RS
 gofc + miniProlog.prj
.RE
.PP
You can also specify Gofer command line options as part of the command
line used to run gofc.  Think of it like this; use exactly the same
command line to start Gofc as you would have done to start Gofer (ok,
replacing the command `gofer' with `gofc') so that you could start your
program immediately by evaluating the main expression.

.SH FILES
The files in \*(GL/lib contain various preludes and header files for
the Gofer compiler.

.SH "SEE ALSO"
Documentation about how to run the system is in the directory
.RS
 \*(GL/docs
.RE
For starters see the file ch03 in that directory.
See the file release.228 in that directory for more about the compiler.
.PP
sml(1)

.SH AUTHOR
Mark P. Jones

