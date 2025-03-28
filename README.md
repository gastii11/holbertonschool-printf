
# _printf Holberton School

In this project we create our own version of the printf () function of the C language.


## Documentation

What does this function do?

_printf.c
In this project we create our own version of the printf () function of the C language.

Description
What does this function do?

'_printf' is a personalized function inspired by ‘printf’ of the standard library of C. Its objective is to print formatted text in the standard output (‘ stdout’), supporting basic specifiers such as '%C', '%S', '%D', '%', '%%' and handling of invalid specifiers.

In this project we will learn to understand the internal functioning of ‘printf’ and the management of variable arguments in C.

## Characteristics
Main characteristics
- Specifiers supported:
 - '%c': Print a character.
 - '%s': Print a character chain.
 - '%d' or'%i': Print an integer with a 12 -basis sign.
 - '%%': Print the '%'.
 - Invalid specifiers: Print '%' followed by the unrecognized character (eg: '%#' → '#').

Extreme Case Management:
 - Negative integers, zero and `int_min`.
 - Empty chains ("") and null pointers
 (Print "(null)").
## Compilation Flowchart
Visit:
https://lucid.app/lucidchart/03a8c694-2268-4bcc-b3bb-e5f84352e187/edit?invitationId=inv_9924b8c6-8e23-4d32-9136-5f84cc8d473a&page=0_0#
## Deployment
Requirements
- C compiler (e.g., GCC).
- C standard library ('stdarg.h', 'stdio.h', 'limits.h').

## Structure
_printf/

├── _printf.c -Main _printf() function

├── _printf.h -Header with definitions and structures

├── main.h -Function prototypes and includes

├── ayudas.c -Auxiliary functions (_putchar, _strlen)

├── caracter.c -Handling %c

├── cadena.c -Handling %s

├── enteros.c -Handling %d and %i

├── porcentaje.c -Handling %%

├── invalido.c -Handling invalid specifiers

└── main.c -Handles test cases

## Build

Clone the repository or download the files:
https://github.com/gastii11/holbertonschool-printf.git
## Usage Manual

##Compilation

Compile all the '.c' files together. Example using GCC:

gcc -Wall -Wextra -Werror -pedantic *.c -o my_printf

##Functionality

The '_printf' function prints formatted text according to specifiers. It supports:

* %c: Character

* %s: String of text

* %%: '%' symbol

* %d/%i: Integers (base 10)

##Basic syntax:

int _printf(const char *format, ...);

##Usage Examples

#include "main.h"

int main(void) {

_printf("Hello %s! Age: %d%%. Char: %c\n", "World", 25, 'A');

// Output: Hello World! Age: 25%. Char: A

return 0;

}

##Valid Specifiers

Specifier | Output | Example

--- | --- | ---

%c | Individual character | _printf("%c", 'A') → A

%s | String of characters | _printf("%s", "Hello") → Hello

%% | Literal percent symbol | _printf("%%") → %

%d or %i | Signed integer (base 10) | _printf("%d", -123) → -123

##Return Values

Returns the number of characters printed (excluding the final null byte).

##Returns -1 in error cases:

* If `format` is `NULL`

* If only `%` is passed without a specifier (e.g., `_printf("%")`)

##Known Limitations

* Does not support width/precision modifiers (e.g., `%5d`, `%.3f`).

* Does not support advanced conversions:

* Pointers (%p)

* Hexadecimal/octal numbers (%x, %o)

* Unsigned numbers (%u)

* Handling of `INT_MIN` in integers uses a hardcoded string due to conversion limitations.

## Behavior with Special Cases

Case | Output

--- | ---

_printf(NULL) | Returns -1

_printf("%") | Returns -1

_printf("%k") | Prints %k

_printf("%s", NULL) | Prints (null)

##Extending the Project

To add new specifiers:

* Create a handler function (e.g., `handle_hexadecimal`).

* Add it to the `handle` table in `_printf.c`:

static const FormatHandler handle[] = {

...

{'x', handle_hexadecimal}, // New specifier

};

##Debugging Tips

Common errors:

* Forgetting to initialize `va_list` with `va_start`.

* Not handling the character counter correctly.

#3Tests:

// Verify the return value

int len = _printf("Test: %d", 42);

assert(len == 7); // "Test: 42" has 7 characters

This manual covers the basic usage and structure of the project.
## Authors

Gastón Dominguez - [@gastii11](https://github.com/gastii11)

Emanuel Romero - [@padredemellis](https://github.com/padredemellis)



