#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void *
vdlopen(const char *filename, int flag) {
    void *dl_handle;
    dl_handle = dlopen(filename, RTLD_LAZY);
    if (!dl_handle) {
        printf("Load %s library, error: %s\n", filename, dlerror());
        exit(EXIT_FAILURE);
    } else {
        printf("Load %s library, success!\n", filename);
    }
    return dl_handle;
}

void *
vdlsym(void *handle, const char *symbol) {
    double (*func)(double); /* Yep ... this is only for double */
    func = dlsym(handle, symbol);
    if (!func) {
        printf("Load %s symbol, error: %s\n", symbol, dlerror());
        exit(EXIT_FAILURE);
    } else {
        printf("Load %s symbol, success!\n", symbol);
    }
    return func;
}

int
vdlclose(void *handle) {
    int i;
    i = dlclose(handle);
    if (i) {
        printf("Unload error %i: %s\n", i, dlerror());
        exit(EXIT_FAILURE);
    } else {
        printf("Unload, success!\n");
    }
    return i;
}

int
main()
{
    double x, y;
    x = 60.0;
    char *lib = "libm.so";
    char *method = "sin";
    void *dl_handle;
    double (*func)(double);
    dl_handle = vdlopen(lib, RTLD_LAZY);
    func = vdlsym(dl_handle, method);
    y = (*func)(x * 3.141592 / 180.0);
    printf("angle = %f degree, sin(angle) = %f\n", x, y);
    vdlclose(dl_handle);
    exit(0);
}

