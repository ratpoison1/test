# Library Management System

## Book Management System for Undergraduate

This is only for the Book and Undergraduate.

class list:

* member(undergraduate)
* resource(book)
* input
* library
---
member:

	has member list ins the input.dat

	save information about book name, restricted date, and deadline.

resource:

	has resource(book) lists in the input.dat

	save information about book name, who borrowed.

input:

	has input lists splited into useful format.

library:

	implement whole program and methods.
---
input format:

YY/MM/DD	[resource type] [resource name] [operation] [member type] [member name]

---
resource type : Book

operation : B, R

member type : Undergraduate

---
output format:

[op#] [return code] [description]
