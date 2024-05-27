#include <vector>

struct Pos {
    int i;
    int j;
};

enum Side { UP, DOWN, LEFT, RIGHT };

Side getSideWithSmallestValue(const std::vector<std::vector<int>>& matrix, const Pos& coord) {
    int minVal = INT_MAX;
    Side minSide = UP; // Por defecto, empezamos comparando con el lado superior

    // Comprobamos el lado superior
    if (coord.i > 0 && matrix[coord.i - 1][coord.j] != -1 && matrix[coord.i - 1][coord.j] < minVal) {
        minVal = matrix[coord.i - 1][coord.j];
        minSide = UP;
    }

    // Comprobamos el lado inferior
    if (coord.i < matrix.size() - 1 && matrix[coord.i + 1][coord.j] != -1 && matrix[coord.i + 1][coord.j] < minVal) {
        minVal = matrix[coord.i + 1][coord.j];
        minSide = DOWN;
    }

    // Comprobamos el lado izquierdo
    if (coord.j > 0 && matrix[coord.i][coord.j - 1] != -1 && matrix[coord.i][coord.j - 1] < minVal) {
        minVal = matrix[coord.i][coord.j - 1];
        minSide = LEFT;
    }

    // Comprobamos el lado derecho
    if (coord.j < matrix[0].size() - 1 && matrix[coord.i][coord.j + 1] != -1 && matrix[coord.i][coord.j + 1] < minVal) {
        minVal = matrix[coord.i][coord.j + 1];
        minSide = RIGHT;
    }

    return minSide;
}




-1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1

-1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1

-1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1

-1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1

-1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1

-1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1

-1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    

-1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1

-1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1

-1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1     3     2     1     0     1     2     3    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1

-1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1     3     2     1     2     3    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1

-1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1     3     2     3    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1

-1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1     3    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    

-1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1

-1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1    -1