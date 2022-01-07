<h1 align="center">
	ft_printf
</h1>

<p align="center">
	This project was made in accordance with the project of School 21 (Ecole 42).
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/haimasker/ft_printf?color=blue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/haimasker/ft_printf?color=blue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/haimasker/ft_printf?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/haimasker/ft_printf?color=blue" />
</p>

<h3 align="center">
	<a href="#preamble">Preamble</a>
	<span> · </span>
  <a href="#description">Description</a>
	<span> · </span>
	<a href="#installation">Installation and usage</a>
	<span> · </span>
	<a href="#testing">Testing</a>
</h3>

---

<a name="preamble"></a>
## Preamble

The purpose of this project is to recode printf function in c.

You can see the subject here: [`ft_printf`](en.subject.pdf).

Main requirements, rules and code style: [`Norm`](en_norm.pdf).

---

<a name="description"></a>
## Description

* The ``printf()`` function produce output according to a format as described below. <br>
The format string is a character string, beginning and ending in its initial shift state, if any. <br>
The format string is composed of zero or more directives: ordinary characters (not `%`), which <br>
are copied unchanged to the output stream; and conversion specifications, each of which results <br>
in fetching zero or more subsequent arguments.  Each conversion specification is introduced by <br>
the character `%`, and ends with a conversion specifier. In between there may be (in this order) <br>
zero or more flags, an optional minimum field width, an optional precision and an optional length modifier.

*  The overall syntax of a conversion specification is: <br>
``%[$][flags][width][.precision][length modifier]conversion``

### Mandatory part

ft_printf must process following type specifiers:

1. ``%c`` - single character

2. ``%s`` - string of characters

3. ``%p`` - pointer to void (in hexadecimal)

4. ``%d`` - decimal number

5. ``%i`` - integer number

6. ``%u`` - unsigned decimal number

7. ``%x`` - number in hexadecimal form (lowercase)

8. ``%X`` - number in hexadecimal form (uppercase)

9. ``%%`` - percent character

### Bonus part

ft_printf must manage following format specifiers (and any combinations of them):

1. ``-`` - left-justify within the given field width, right justification is the default;

2. ``0`` - left-pads the number with zeroes instead of spaces, where padding is specified;

3. ``.`` - precision (is used with numeric values):
  
4. ``#`` - adding prefix `0x` or `0X` for ``%x`` or ``%X`` type specifiers respectively;

5. ``+`` - adding sign (`+` or `-`) in dependency of output value. By default shows only `-` sign <br>
for negative values;

6. `` ``  (space) - adding space before positive output values. By default shows only `-` sign <br>
for negative values. Ignored if both `+` and ` ` flags are used.

* Also you can use width specifier (number) to define the field width. 

* Width and precision specifiers can be presented due to `*` character. <br>
In this case `*` should be printed in formatting string for ft_printf at required position instead of <br>
numeric value. At the same time value for `*` is passed as argument.
  
---

<a name="examples"></a>
## Examples



---

<a name="installation"></a>
## Installation and usage

Makefile compiles given functions into C static library file.

Compiler: `gcc`

Flags: `-Wall` `-Werror` `-Wextra`

<br>

* Go to the project folder:

```shell
$ cd 'path_to_libft'
```
* Then typo one of these command:

| Command         | Description                        |
| --------------- | ---------------------------------- |
| ``make``        | compiling mandatory part           |
| ``make bonus``  | compiling mandatory and bonus part |
| ``make clean``  | clearing all .o files              |
| ``make fclean`` | clearing all .o files and library  |

* To use compiled project in your code just include library header:

```c
#include "libft.h"
```

* While compiling your code add these flags:

```shell
-lft -L 'path_to_libft.a' -I 'path_to_libft.h'
```

---

<a name="testing"></a>
## Testing

* You can check code norm due to [norminette](https://github.com/42School/norminette).

* These are some testers for libft project:

	* [libftTester](https://github.com/Tripouille/libftTester)

	* [Libftest](https://github.com/jtoty/Libftest)

	* [libft-war-machine](https://github.com/y3ll0w42/libft-war-machine)
