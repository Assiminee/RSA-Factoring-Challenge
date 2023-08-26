#include <stdio.h>
#include <gmp.h>

int main() {
    const char *str = "1718944270642558716715";
    mpz_t num;
    mpz_init(num);

    if (mpz_set_str(num, str, 10) == 0) {
        gmp_printf("Value: %Zd\n", num);
    } else {
        printf("Conversion failed\n");
    }

    mpz_clear(num);
    return 0;
}
