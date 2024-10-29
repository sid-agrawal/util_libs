#include <stdio.h>
#include <string.h>
#include <utils/json.h>


// Function to write JSON data to a buffer
void json_write(char *buf, size_t buf_size, KeyValuePair *pairs, size_t num_pairs) {
    size_t offset = 0;
    offset += snprintf(buf + offset, buf_size - offset, "{");

    for (size_t i = 0; i < num_pairs; ++i) {
        offset += snprintf(buf + offset, buf_size - offset, "\"%s\": \"%s\"", pairs[i].key, pairs[i].value);
        if (i < num_pairs - 1) {
            offset += snprintf(buf + offset, buf_size - offset, ", ");
        }
    }

    snprintf(buf + offset, buf_size - offset, "}");
}

/* Example
 *
 *
 int main() {
    char buffer[256];
    KeyValuePair pairs[] = {
        {"name", "John Doe"},
        {"age", "30"},
        {"email", "john.doe@example.com"}
    };
    size_t num_pairs = sizeof(pairs) / sizeof(pairs[0]);

    json_write(buffer, sizeof(buffer), pairs, num_pairs);
    printf("JSON Data: %s\n", buffer);

    return 0;
}
*/
