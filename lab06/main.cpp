#include <iostream>

int* findZeroRows(int** mat, int rows, int cols, int* zeroCount) {  // Исправлено на rows
    int* zeroRows = (int*)malloc(rows * sizeof(int));
    *zeroCount = 0;

    for (int i = 0; i < rows; i++) {  // Ищем строки с нулями, а не столбцы
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == 0) {
                zeroRows[*zeroCount] = i;  
                (*zeroCount)++;
                break;
            }
        }
    }
    if (*zeroCount > 0) {
        zeroRows = (int*)realloc(zeroRows, (*zeroCount) * sizeof(int));
    }
    else {
        free(zeroRows);
        zeroRows = nullptr;
    }

    return zeroRows;
}

void deleteZeroRows(int**& mat, int& rows, int cols, int* zeroRows, int zeroCount) {
    if (zeroCount == 0) return;

    int newRows = rows - zeroCount;
    int currentIndex = 0;

    // Сдвигаем строки без нулей в начало матрицы
    for (int i = 0; i < rows; i++) {
        bool isZeroRow = false;
        for (int k = 0; k < zeroCount; k++) {
            if (zeroRows[k] == i) {
                isZeroRow = true;
                break;
            }
        }
        if (isZeroRow == false) {
            // Сохраняем строку на новую позицию
            if (currentIndex != i) {
                for (int j = 0; j < cols; j++) {
                    mat[currentIndex][j] = mat[i][j];
                }
            }
            currentIndex++;
        }
    }

    //// Освобождаем удаленные строки 
    //for (int i = newRows; i < rows; i++) {
    //    free(mat[i]);
    //}

    // Изменяем размер массива указателей
    mat = (int**)realloc(mat, newRows * sizeof(int*));
    rows = newRows;
}

int main() {
    int** mat = (int**)malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i++) {
        mat[i] = (int*)malloc(2 * sizeof(int));
    }


    int A, B, C, D;

    do {
        std::cout << "Enter A: ";
        std::cin >> A;
        if (A < 0) std::cout << "Input error" << std::endl;
    } while (A < 0);

    do {
        std::cout << "Enter B: ";
        std::cin >> B;
        if (B < 0) std::cout << "Input error" << std::endl;
    } while (B < 0);

    std::cout << "Enter C: ";
    std::cin >> C;
    std::cout << "Enter D: ";
    std::cin >> D;

    mat[0][0] = A;
    mat[0][1] = B;
    mat[1][0] = C;
    mat[1][1] = D;

    int nr = 2 + A;
    int nc = 2 + B;

    // Расширяем матрицу
    mat = (int**)realloc(mat, nr * sizeof(int*));
    for (int i = 0; i < nr; i++) {
        if (i < 2) {
            mat[i] = (int*)realloc(mat[i], nc * sizeof(int));
        }
        else {
            mat[i] = (int*)malloc(nc * sizeof(int));
        }
    }

    // Заполняем расширенную часть 
    for (int i = nr-1; i >= 0; i--) {
        for (int j = nc-1; j >= 0; j--) {
            if (i >= A && j >= B) {
                mat[i][j] = mat[i - A][j - B];; 
            }
            else {
                mat[i][j] = i * C + j * D;  
            }
        }
    }

    std::cout << "Original matrix:" << std::endl;
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            std::cout << mat[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    int zeroCount;
    int* zeroRows = findZeroRows(mat, nr, nc, &zeroCount);


        deleteZeroRows(mat, nr, nc, zeroRows, zeroCount);

    std::cout << "Matrix after removing zero rows:" << std::endl;
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
    

    // освобождаем память
    if (zeroRows != nullptr) {
        free(zeroRows);
    }
    for (int i = 0; i < nr; i++) {
        free(mat[i]);
    }
    free(mat);

    int a1, b1;
    std::cout << "Enter A:" << std::endl;
    std::cin >> a1;
    std::cout << "Enter B:" << std::endl;
    std::cin >> b1;

    std::cout << "A: " << a1 << std::endl;
    std::cout << "B: " << b1 << std::endl;

    int* pa1 = new int(a1);
    int* pb1 = new int(b1);

    *pa1 *= 2;
    a1 = *pa1;
    std::cout << "New A: " << a1 << std::endl;

    int temp = *pa1;
    *pa1 = *pb1;
    *pb1 = temp;

    a1 = *pa1;
    b1 = *pb1;

    std::cout << "A: " << a1 << std::endl;
    std::cout << "B: " << b1 << std::endl;

    delete pa1;
    delete pb1;
    return 0;
}