#include <iostream>
#include <cstdlib>

int* findZeroColumns(int** mat, int row, int col, int* zeroCount) {
    // Находим столбцы с нулями
    int* zeroCols = (int*)std::malloc(col * sizeof(int));
    *zeroCount = 0;

    for (int j = 0; j < col; j++) {
        for (int i = 0; i < row; i++) {
            if (mat[i][j] == 0) {
                zeroCols[*zeroCount] = j;
                (*zeroCount)++;
                break;
            }
        }
    }

    if (*zeroCount > 0) {
        zeroCols = (int*)std::realloc(zeroCols, (*zeroCount) * sizeof(int));
    }
    else {
        std::free(zeroCols);
        zeroCols = nullptr;
    }

    return zeroCols;
}

void moveZeroColumnsToEnd(int** mat, int row, int col, int* zeroCols, int zeroCount) {
    if (zeroCount == 0) return;

    // Переставляем столбцы с нулями в конец
    for (int i = 0; i < row; i++) {
        int nonZeroIndex = 0;

        // Сначала копируем все столбцы без нулей
        for (int j = 0; j < col; j++) {
            bool isZeroCol = false;
            for (int k = 0; k < zeroCount; k++) {
                if (j == zeroCols[k]) {
                    isZeroCol = true;
                    break;
                }
            }
            if (!isZeroCol) {
                mat[i][nonZeroIndex] = mat[i][j];
                nonZeroIndex++;
            }
        }

        // Затем копируем столбцы с нулями
        for (int j = 0; j < col; j++) {
            bool isZeroCol = false;
            for (int k = 0; k < zeroCount; k++) {
                if (j == zeroCols[k]) {
                    isZeroCol = true;
                    break;
                }
            }
            if (isZeroCol) {
                mat[i][nonZeroIndex] = mat[i][j];
                nonZeroIndex++;
            }
        }
    }
}

int main() {
    int** mat = (int**)std::malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i++) {
        mat[i] = (int*)std::malloc(2 * sizeof(int));
    }

    // заполняем
    int A, B, C, D;

    do {
        std::cout << "enter A: ";
        std::cin >> A;
        if (A < 0) std::cout << "error! A must be >= 0\n";
    } while (A < 0);

    do {
        std::cout << "enter B: ";
        std::cin >> B;
        if (B < 0) std::cout << "error! B must be >= 0\n";
    } while (B < 0);

    std::cout << "enter C: ";
    std::cin >> C;
    std::cout << "enter D: ";
    std::cin >> D;

    mat[0][0] = A;
    mat[0][1] = B;
    mat[1][0] = C;
    mat[1][1] = D;

    int nr = 2 + A;
    int nc = 2 + B;

    // Расширяем матрицу
    mat = (int**)std::realloc(mat, nr * sizeof(int*));
    for (int i = 0; i < nr; i++) {
        if (i < 2) {
            mat[i] = (int*)std::realloc(mat[i], nc * sizeof(int));
        }
        else {
            mat[i] = (int*)std::malloc(nc * sizeof(int));
        }
    }

    // Заполняем расширенную часть
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            if (i < 2 && j < 2) continue;
            mat[i][j] = (i - 1) * C + (j - 1) * D;
        }
    }

    std::cout << "original matrix:\n";
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Находим столбцы с нулями
    int zeroCount;
    int* zeroCols = findZeroColumns(mat, nr, nc, &zeroCount);

    if (zeroCount > 0) {
        std::cout << "columns with zeros: ";
        for (int i = 0; i < zeroCount; i++) {
            std::cout << zeroCols[i] << " ";
        }
        std::cout << std::endl;

        // Переставляем столбцы с нулями в конец
        moveZeroColumnsToEnd(mat, nr, nc, zeroCols, zeroCount);

        std::cout << "matrix after moving zero columns to end:\n";
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                std::cout << mat[i][j] << " ";
            }
            std::cout << std::endl;
        }

        // Удаляем столбцы с нулями (обрезаем матрицу)
        int newCols = nc - zeroCount;
        for (int i = 0; i < nr; i++) {
            mat[i] = (int*)std::realloc(mat[i], newCols * sizeof(int));
        }
        nc = newCols;
    }
    else {
        std::cout << "no columns with zeros found" << std::endl;
    }

    std::cout << "final matrix:\n";
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // освобождаем память
    if (zeroCols != nullptr) {
        std::free(zeroCols);
    }
    for (int i = 0; i < nr; i++) {
        std::free(mat[i]);
    }
    std::free(mat);

    // Пункт 2

    float a, b;
    std::cout << "enter a and b: ";
    std::cin >> a >> b;

    float* pA = new float(a);
    float* pB = new float(b);

    *pA *= 3;

    std::cout << "after a*3: a=" << *pA << " b=" << *pB << std::endl;

    float tmp = *pA;
    *pA = *pB;
    *pB = tmp;

    std::cout << "after swap: a=" << *pA << " b=" << *pB << std::endl;

    delete pA;
    delete pB;

    return 0;
}