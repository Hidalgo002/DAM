#include <ctype.h>
#include <stdio.h>

int main() {
    char c = 'A';
    if (isupper(c)) {
        printf("Es una letra mayúscula.\n");
    }
    return 0;
}

