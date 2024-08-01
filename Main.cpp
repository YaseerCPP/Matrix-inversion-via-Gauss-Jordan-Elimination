#include <iostream>
#include <vector>
#include <iomanip>

// Function to perform Gauss-Jordan Elimination
bool gaussJordanElimination(std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();
    std::vector<std::vector<double>> inverse(n, std::vector<double>(n, 0.0));

    // Initialize the inverse matrix as the identity matrix
    for (int i = 0; i < n; ++i) {
        inverse[i][i] = 1.0;
    }

    for (int i = 0; i < n; ++i) {
        // Find the pivot element
        double pivot = matrix[i][i];
        if (pivot == 0.0) {
            return false; // Singular matrix, cannot be inverted
        }

        // Normalize the pivot row
        for (int j = 0; j < n; ++j) {
            matrix[i][j] /= pivot;
            inverse[i][j] /= pivot;
        }

        // Eliminate the pivot column from other rows
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j < n; ++j) {
                    matrix[k][j] -= factor * matrix[i][j];
                    inverse[k][j] -= factor * inverse[i][j];
                }
            }
        }
    }

    // Replace the original matrix with its inverse
    matrix = inverse;
    return true;
}

// Function to print the matrix
void printMatrix(const std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(10) << std::setprecision(4) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Example matrix (3x3)
    std::vector<std::vector<double>> matrix = {
        {4, 7, 2},
        {3, 6, 1},
        {2, 5, 3}
    };

    std::cout << "Original Matrix:" << std::endl;
    printMatrix(matrix);

    if (gaussJordanElimination(matrix)) {
        std::cout << "Inverse Matrix:" << std::endl;
        printMatrix(matrix);
    } else {
        std::cout << "Matrix is singular and cannot be inverted." << std::endl;
    }

    return 0;
}
