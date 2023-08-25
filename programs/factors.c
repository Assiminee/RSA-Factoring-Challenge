#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* fact3(int num) {
    int* factors = (int*)malloc(2 * sizeof(int));
    int sqrt_num = (int)sqrt(abs(num));

    if (num % 2 == 0) {
        factors[0] = num / 2;
        factors[1] = 2;
        return factors;
    }

    for (int i = 3; i <= sqrt_num; i++) {
        if (i == sqrt_num && num % sqrt_num != 0) {
            factors[0] = num;
            factors[1] = 1;
            return factors;
        }
        if (num % i == 0) {
            factors[0] = num / i;
            factors[1] = i;
            return factors;
        }
    }

    return factors;
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        char* input_filename = argv[1];
        FILE* f = fopen(input_filename, "r");
        if (f) {
            int x;
            while (fscanf(f, "%d", &x) != EOF) {
                int* factors = fact3(x);
                printf("%d=%d*%d\n", x, factors[0], factors[1]);
                free(factors);
            }
            fclose(f);
        } else {
            printf("Error: Can't open file %s\n", input_filename);
        }
    } else {
        printf("Usage: factors <file>\n");
    }

    return 0;
}

