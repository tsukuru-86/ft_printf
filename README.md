*This project has been created as part of the 42 curriculum by tkomai.*

# ft_printf

## Purpose

This repository is prepared for a full-score ft_printf resubmission. It keeps
the mandatory implementation and the complete subject flag/width/precision
bonus implementation as separate Makefile targets.

## Description

This project reimplements the core behavior of the C standard library
`printf()` function. The resulting `libftprintf.a` library supports the
`cspdiuxX%` conversions and writes directly to standard output without using
the buffering system of the original `printf()`.

The bonus implementation also supports minimum field width, precision, and
the `-`, `0`, `#`, space, and `+` flags in their applicable conversions.

## Instructions

Build the mandatory implementation:

```sh
make
```

Build the bonus implementation:

```sh
make bonus
```

Both commands create `libftprintf.a` at the repository root. Link it with an
application that includes `includes/ft_printf.h`:

```sh
cc -Wall -Wextra -Werror main.c -Iincludes libftprintf.a
```

The other available Makefile rules are `clean`, `fclean`, and `re`.

## Testing

`test_bonus.c` is an optional local differential test program. It compares
the output and return value of `ft_printf()` with the system `printf()`.
It is included in this repository for development and verification, but it is
not part of the ft_printf assignment deliverables and must not be submitted
as the subject's required source files.

## Supported behavior

- `%c`: character
- `%s`: string
- `%p`: pointer in lowercase hexadecimal notation
- `%d`, `%i`: signed decimal integer
- `%u`: unsigned decimal integer
- `%x`, `%X`: lowercase or uppercase hexadecimal integer
- `%%`: percent sign
- Bonus: field width, precision, and the `-`, `0`, `#`, space, and `+` flags

## Algorithm and data structures

The mandatory implementation scans the format string once. When it finds a
conversion marker, it reads the matching variadic argument and sends it to a
small conversion-specific output function. Numbers are recursively emitted in
base 10 or base 16, so no heap allocation is required.

The bonus implementation first parses each conversion into a `t_pf_format`
structure. This structure records flags, width, precision, and the conversion
type. Numeric arguments are converted into a fixed-size stack buffer and
described by a `t_pf_number` structure containing the digits, prefix, zero
padding, and space padding. Separating parsing, formatting, and output makes
flag precedence explicit and avoids dynamic allocation and memory leaks.

## Resources

- `printf(3)` and `stdarg(3)` Linux manual pages
- ISO C documentation for variadic functions and formatted output
- The ft_printf Version 12.1 subject supplied with the project

AI was used to compare the existing implementation with the subject, design
the bonus parser and test matrix, review edge cases, and compare output and
return values against glibc `printf()` in a Linux environment. Every generated
path was compiled with the required warning flags and checked through direct
differential tests.
