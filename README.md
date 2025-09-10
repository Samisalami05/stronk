# Stronk
The best string library for c

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

Adds a char buffer `b` with the lenght ´l´ to the string `s`.

Include: `<stronk.h>`

#### Returns:
Nothing

```c
void stronk_add(stronk* s, char* b, int l);
```

### stronk_add_cstr

Adds a null terminated char buffer ´b´ to the string `s`.

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
