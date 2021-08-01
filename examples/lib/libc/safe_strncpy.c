#include <string.h>
char* safe_strncpy(char *dst, const char *src, size_t size)
{
    if (size == 0) {
        return dst;
    } else {
        size--;
        dst[size] = '\0';
        return strncpy(dst, src, size);
    }
}
