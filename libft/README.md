# Libft

**Libft** is a custom C library that reimplements essential functions from the C standard library and adds useful utility functions for string, memory, and character manipulation. It serves as a foundational toolset for future projects, promoting understanding of low-level programming and memory management.

## Features

- **Character checks** - ft_is/
    - **`ft_isalpha`** : _Checks for an alphabetic character._
    - **`ft_isdigit`** : _Checks for a digit (0 through 9)._
    - **`ft_isalnum`** : _Checks for an alphanumeric character._
    - **`ft_isascii`** : _Checks whether 'c' is a 7-bit unsigned char value that fits into the ASCII character set._
    - **`ft_isprint`** : _Checks for any printable character including space._
    - **`ft_islower`** : _Checks for a lowercase letter._
    - **`ft_isupper`** : _Checks for an uppercase letter._

- **Conversions** - ft_to/
    - **`ft_itoa`** : _Converts an integer to a string._
    - **`ft_atoi`** : _Converts the initial portion of the string pointed to by 'nptr' to int, ignoring leading whitespace and handling optional signs._
    - **`ft_atol`** : _Converts a string to a signed long integer._
    - **`ft_atoll`** : _Converts a string to a signed long long integer._
    - **`ft_toupper`** : _Converts the letter 'c' to uppercase, if possible._
    - **`ft_tolower`** : _Converts the letter 'c' to lowercase, if possible._
    - **`ft_strtoll`** : _Custom implementation of strtoll, converts a string to a signed long long integer, handling optional base, white spaces, signs, and overflow._

- **Memory management** - ft_mem/
    - **`ft_bzero`** : _Sets the first 'n' bytes of the area starting at 's' to zero (bytes containing char '\0')._
    - **`ft_calloc`** : _Allocates memory for an array of 'nelem' elements of size 'elsize' each and returns a pointer to the allocated memory. The memory is set to zero._
    - **`ft_memset`** : _Fills the first 'n' bytes of the memory area pointed to by 's' with the constant byte 'c'._
    - **`ft_memcpy`** : _Copies 'n' bytes from memory area 'src' to memory area 'dest'. The memory areas must not overlap._
    - **`ft_memccpy`** : _Copies no more than 'n' bytes from memory area 'src' to memory area 'dest', stopping when the character 'c' is found._
    - **`ft_memmove`** : _Copies 'n' bytes from memory area 'src' to memory area 'dest'. The memory areas may overlap._
    - **`ft_memchr`** : _Scans the initial 'n' bytes of the memory area pointed to by 's' for the first instance of 'c'._
    - **`ft_memrchr`** : _Searches backwards for the first instance of 'c' in the 'n' bytes pointed to by 's'._
    - **`ft_memcmp`** : _Compares the first 'n' bytes of the memory areas 's1' and 's2'._
    - **`ft_memdel`** : _Frees a pointer and sets it to NULL._

- **Strings** - ft_str/
    - **`ft_strchr`** : _Returns a pointer to the first occurrence of the character 'c' in the string 'str'._
    - **`ft_strrchr`** : _Returns a pointer to the last occurrence of the character 'c' in the string 'str'._
    - **`ft_strnstr`** : _Locates the first occurrence of the null-terminated string 'needle' in 'haystack', searching at most 'n' characters._
    - **`ft_strdup`** : _Returns a pointer to a new string which is a duplicate of the string 's'._
    - **`ft_substr`** : _Returns a substring from 's', starting at index 'start' and of maximum size 'len'._
    - **`ft_strjoin`** : _Concatenates 's1' and 's2' into a new string._
    - **`ft_strtrim`** : _Trims characters from 'set' from the beginning and end of 's1'._
    - **`ft_strmapi`** : _Applies the function 'f' to each character of 's', returning a new resulting string._
    - **`ft_split`** : _Splits 's' into an array of strings using 'c' as the delimiter._
    - **`ft_split_quotes`** : _Splits 's' into an array of strings using delimiters, respecting quoted substrings._
    - **`ft_strlen`** : _Calculates the length of the string 'str'._
    - **`ft_strnlen`** : _Calculates the length of 's', up to a maximum of 'maxlen' bytes._
    - **`ft_strlcpy`** : _Copies up to 'size - 1' characters from 'src' to 'dst', NUL-terminating the result._
    - **`ft_strlcat`** : _Appends 'src' to string 'dst' of size 'size', guaranteeing NUL-termination._

- **Lists** - ft_lst/
    - **`ft_lstnew`** : _Allocates and returns a new list element. The 'content' is initialized with the given value; 'next' is set to NULL._
    - **`ft_lstlast`** : _Returns the last element of the list._
    - **`ft_lstmap`** : _Iterates through 'lst', applies function 'f' to each content, and creates a new list with the results. If needed, 'del' is used to clean up._
    - **`ft_lstadd_front`** : _Adds the element 'new' at the beginning of the list._
    - **`ft_lstadd_back`** : _Adds the element 'new' at the end of the list._
    - **`ft_lstdelone`** : _Frees the memory of an element's content using 'del' and frees the element itself._
    - **`ft_lstclear`** : _Deletes and frees an entire list, using 'del' on each element, then frees the list._
    - **`ft_lstiter`** : _Iterates the list and applies function 'f' to the content of each element._
    - **`ft_lstsize`** : _Counts the number of elements in a list._

- **File I/O** - ft_gnl/
    - **`get_next_line`** : _Reads a line from the given file descriptor, returning it as a string._

- **Formatted output** - ft_printf/
    - **`ft_printf`** : _Custom implementation of printf, formatted output conversion and printing to standard output._
    - **`ft_dprintf`** : _Custom implementation of dprintf, formatted output conversion and printing to the given file descriptor._

- **Output functions** - ft_put/
    - **`ft_putchar_fd`** : _Outputs the character 'c' to the given file descriptor._
    - **`ft_putstr_fd`** : _Outputs the string 's' to the given file descriptor._
    - **`ft_putnstr_fd`** : _Outputs up to 'len' characters of the string 's' to the given file descriptor._
    - **`ft_putendl_fd`** : _Outputs the string 's' followed by a newline to the given file descriptor._
    - **`ft_putnbr_fd`** : _Outputs the integer 'n' to the given file descriptor._

## Tech Stack

- **C** – Core language
- **Makefile** – For easy build and management

## Usage

1. Clone the repository:

```bash
git clone git@github.com:Felipp3san/42-libft.git libft
cd libft
```

2. Compile the library:

```bash
make
```

- This will create `libft.a`.
- Include in other projects by adding:

```make
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) $(MAKEFLAGS) all
```

and compile flags:

```bash
-I./libft/include -L./libft -lft
```

## Compilation

- Build the executable:

```bash
make
```

- Remove object files:

```bash
make clean
```

- Remove all binaries and rebuild:

```bash
make fclean
make
```

## Testing

Tested with custom scripts and frameworks such as:

- [libftTester](https://github.com/Tripouille/libftTester)
- [Libftest](https://github.com/jtoty/Libftest)
- [libft-unit-test](https://github.com/alelievr/libft-unit-test)

## License

Educational project under 42 School academic policy.
