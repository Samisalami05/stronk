# Stronk
A string library for c.

## Getting started

### Installation
To install stronk on your system. Pull the repository and run the `install.sh` bash file.

### Usage
To include it in your c file, write:
```c
#include <stronk.h>
```

To compile it, add `-L. -lstronk` to your compile command.

## Interface

### stronk_init

Initiates a string.

Include: `<stronk.h>`

#### Returns:
The initialized string.

```c
stronk* stronk_init();
```

### stronk_deinit

Deinitializes a string by freeing up memory allocated by `stronk_init()`.

Include: `<stronk.h>`

#### Returns:
Nothing

```c
void stronk_deinit(stronk* s);
```

### stronk_add

Adds a char buffer `b` with the lenght `l` to the string `s`.

Include: `<stronk.h>`

#### Returns:
Nothing

```c
void stronk_add(stronk* s, char* b, int l);
```

### stronk_add_cstr

Adds a null terminated char buffer `b` to the string `s`.

Include: `<stronk.h`

#### Returns:
Nothing

```c
void stronk_add_cstr(stronk* s, char* b);
```

### stronk_get_temp_cstr

Returns the string `s` as a null terminated char buffer.

Include: `<stronk.h>`

#### Returns:
The char buffer.

#### Disclaimer:
The returned `char*` is not a copy which means it will be changed under runtime.

```c
char* stronk_get_temp_cstr(stronk* s);
```

### stronk_alloc_cstr

Returns the string `s` as a null terminated char buffer copy.

Include: `<stonk.h>`

#### Returns:
The allocated char buffer.

#### Disclaimer:
The returned char buffer needs to be freed after use.

```c
char* stronk_alloc_cstr(stronk* s);
```

### stronk_len

Returns the length of the string `s`.

Include: `<stronk.h>`

#### Returns:
The length.

```c
size_t stronk_len(stronk* s);
```

### stronk_reset

Clears a string `s` of its contents so that it can be reused. This can be much more performant than creating a new string because new memory does not have to be allocated.

Include: `<stronk.h>`

#### Returns:
Nothing

```c
void stronk_reset(stronk* s);
```

## Example

```c
#include <stdio.h>
#include <stronk.h>

int main() {
    // Initialize a string
	stronk* s = stronk_init();

    // Add a char buffer to the string
	stronk_add_cstr(s, "Example string");

    // Print string and length
	printf("%s\n", stronk_get_temp_cstr(s));
	printf("%ld\n", stronk_len(s));

    // Deinitialize the string
	stronk_deinit(s);
}
```

## Contributing
To contribute to strong, fork the repository and create a new branch with a fitting name. Thereafter create a pull request with your changes.

## Development environment
Stronk was developed in Ubuntu 22.04 LTS and compiled with GCC (GNU compiler collection).
