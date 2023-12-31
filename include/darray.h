#ifndef SNAKE_DARRAY_H
#define SNAKE_DARRAY_H

#include <stddef.h>

#define DARRAY_DEFAULT_CAPACITY 1
#define DARRAY_RESIZE_FACTOR 2

enum { DARRAY_CAPACITY,
       DARRAY_LENGTH,
       DARRAY_STRIDE,
       DARRAY_FIELD_LENGTH };

void *_darray_create(size_t length, size_t stride);
void _darray_destroy(void *array);

size_t _darray_field_get(void *array, size_t field);
void _darray_field_set(void *array, size_t field, size_t value);

void *_darray_resize(void *array);

void *_darray_push(void *array, const void *value_ptr);
void _darray_pop(void *array, void *out_value);

void *_darray_insert_at(void *array, size_t index, const void *value_ptr);
void _darray_pop_at(void *array, size_t index, void *out_value);

#define darray_create(type) _darray_create(DARRAY_DEFAULT_CAPACITY, sizeof(type))

#define darray_reserve(type, capacity) _darray_create(capacity, sizeof(type))

#define darray_destroy(array) _darray_destroy(array)

#define darray_push(array, value)           \
    {                                       \
        typeof(value) temp = value;         \
        array = _darray_push(array, &temp); \
    }

#define darray_pop(array, out_value) _darray_pop(array, out_value)

#define darray_insert_at(array, index, value)   \
    {                                           \
        typeof(value) temp = value;             \
        _darray_insert_at(array, index, &temp); \
    }

#define darray_pop_at(array, index, out_value) _darray_pop_at(array, index, out_value)

#define darray_clear(array) _darray_field_set(array, DARRAY_LENGTH, 0);

#define darray_capacity(array) _darray_field_get(array, DARRAY_CAPACITY)

#define darray_length(array) _darray_field_get(array, DARRAY_LENGTH)

#define darray_stride(array) _darray_field_get(array, DARRAY_STRIDE)

#endif// SNAKE_DARRAY_H
