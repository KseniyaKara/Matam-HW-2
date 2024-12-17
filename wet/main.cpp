#include <iostream>
#include <string>
#include "Matrix.h"
#include "MataMvdia.h"

int main() {
    // Testing the Matrix class

    std::cout << "Creating a 3x3 matrix with all values set to 1:" << std::endl;
    Matrix mat1(3, 3, 1);  // 3x3 matrix with all elements initialized to 1

    // Display the matrix using overloaded << operator
    std::cout << "Matrix mat1:" << std::endl;
    std::cout << mat1 << std::endl;

    // Modifying matrix elements using operator()
    mat1(1, 1) = 5;  // Set element at position (1, 1) to 5
    mat1(0, 2) = 7;  // Set element at position (0, 2) to 7

    std::cout << "Modified Matrix mat1:" << std::endl;
    std::cout << mat1 << std::endl;

    // Testing Matrix transpose
    std::cout << "Transposing Matrix mat1:" << std::endl;
    Matrix transposedMat = mat1.Transpose(mat1);
    std::cout << transposedMat << std::endl;

    // Testing matrix multiplication by a scalar
    Matrix mat2 = mat1 * 2;  // Multiply mat1 by 2
    std::cout << "Matrix mat1 * 2:" << std::endl;
    std::cout << mat2 << std::endl;

    // Testing matrix addition
    Matrix mat3 = mat1 + mat2;  // Add mat1 and mat2
    std::cout << "Matrix mat1 + mat2:" << std::endl;
    std::cout << mat3 << std::endl;

    // Testing matrix subtraction
    Matrix mat4 = mat2 - mat1;  // Subtract mat1 from mat2
    std::cout << "Matrix mat2 - mat1:" << std::endl;
    std::cout << mat4 << std::endl;

    // Testing equality operator
    if (mat1 == mat2) {
        std::cout << "Matrix mat1 is equal to mat2" << std::endl;
    } else {
        std::cout << "Matrix mat1 is not equal to mat2" << std::endl;
    }

    // Matrix determinant (if square matrix)
    std::cout << "Determinant of mat1: " << Matrix::CalcDeterminant(mat1) << std::endl;

    // Testing the Film class with Matrix frames

    std::cout << "\nCreating a film with 2 frames:" << std::endl;
    Matrix frames[2] = {Matrix(2, 2, 0), Matrix(2, 2, 1)};  // Film with 2 frames (2x2 matrices)

    // Set some frame values
    frames[0](0, 0) = 1; frames[0](0, 1) = 2;
    frames[0](1, 0) = 3; frames[0](1, 1) = 4;

    frames[1](0, 0) = 5; frames[1](0, 1) = 6;
    frames[1](1, 0) = 7; frames[1](1, 1) = 8;

    Film film("Action Movie", "John Doe", frames, 2);  // Create a Film object

    // Output film information
    std::cout << "Film name: Action Movie" << std::endl;
    std::cout << "Author: John Doe" << std::endl;
    std::cout << "Film length: " << 2 << " frames" << std::endl;
    std::cout << "Frame 1:" << std::endl;
    std::cout << frames[0] << std::endl;
    std::cout << "Frame 2:" << std::endl;
    std::cout << frames[1] << std::endl;

    return 0;
}
