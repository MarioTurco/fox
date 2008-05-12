#include <stdio.h>
#include "matrix.h"

int main() {
    matrix_type **A, **B, **C;
    int correct;

    A = matrix_new_from_file(2, 3, "data_matrix_test/A");
    B = matrix_new_from_file(3, 4, "data_matrix_test/B");
    C = matrix_new(2, 4);

    if (A == NULL || B == NULL) {
        printf("Error reading files\n");
        return -1;
    }

    /* C esta inicializada en cero */

    printf("A =\n");
    matrix_print(stdout, A, 2, 3);
    printf("B =\n");
    matrix_print(stdout, B, 3, 4);
    printf("C before =\n");
    matrix_print(stdout, C, 2, 4);

    matrix_multiply_and_add(A, B, C, 2, 3, 4);

    printf("C after =\n");
    matrix_print(stdout, C, 2, 4);

    correct = C[0][0] == -26 && C[0][1] ==   9 && C[0][2] ==   7 && C[0][3] == -14 &&
              C[1][0] ==  29 && C[1][1] ==  -7 && C[1][2] == -14 && C[1][3] ==  10;

    matrix_free(A);
    matrix_free(B);
    matrix_free(C);

    if (correct) {
        printf("Test passed\n");
        return 0;
    } else {
        printf("Test failed\n");
        return -1;
    }
}

