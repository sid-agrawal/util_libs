#pragma once

#include <stdio.h>
#include <string.h>

typedef struct {
    const char *key;
    const char *value;
} KeyValuePair;

// Function to write JSON data to a buffer
void json_write(char *buf, size_t buf_size, KeyValuePair *pairs, 
                size_t num_pairs);
