#include <iostream>
#include <string>

#include "MataMvidia.h"
#include "Matrix.h"

int main() {
    // Testing the Matrix class

    // 1. Create a 3x3 matrix with initial value of 0
    std::cout << "Creating a 3x3 matrix with all values set to 0:" << std::endl;
    Matrix mat1(3, 3, 0);  // 3x3 matrix with all elements initialized to 0

    std::cout << "Matrix mat1:" << std::endl;
    std::cout << mat1 << std::endl;

    // 2. Modify some elements using operator()
    mat1(0, 0) = 1;
    mat1(0, 1) = 2;
    mat1(0, 2) = 3;
    mat1(1, 0) = 4;
    mat1(1, 1) = 5;
    mat1(1, 2) = 6;
    mat1(2, 0) = 7;
    mat1(2, 1) = 8;
    mat1(2, 2) = 9;

    std::cout << "Modified Matrix mat1:" << std::endl;
    std::cout << mat1 << std::endl;

    // 3. Testing the transpose function
    std::cout << "Transposing Matrix mat1:" << std::endl;
    Matrix transposedMat = mat1.transpose();
    std::cout << transposedMat << std::endl;

    // 4. Testing rotateClockwise() and rotateCounterClockwise()
    std::cout << "Rotating Matrix mat1 clockwise:" << std::endl;
    Matrix rotatedClockwise = mat1.rotateClockwise();
    std::cout << rotatedClockwise << std::endl;

    std::cout << "Rotating Matrix mat1 counterclockwise:" << std::endl;
    Matrix rotatedCounterClockwise = mat1.rotateCounterClockwise();
    std::cout << rotatedCounterClockwise << std::endl;

    // 5. Matrix scalar multiplication (mat1 * 2)
    Matrix mat2 = mat1 * 2;  // Multiply mat1 by 2
    std::cout << "Matrix mat1 * 2:" << std::endl;
    std::cout << mat2 << std::endl;

    // 6. Matrix addition (mat1 + mat2)
    Matrix mat3 = mat1 + mat2;  // Add mat1 and mat2
    std::cout << "Matrix mat1 + mat2:" << std::endl;
    std::cout << mat3 << std::endl;

    // 7. Matrix subtraction (mat2 - mat1)
    Matrix mat4 = mat2 - mat1;  // Subtract mat1 from mat2
    std::cout << "Matrix mat2 - mat1:" << std::endl;
    std::cout << mat4 << std::endl;

    // 8. Matrix multiplication (mat1 * mat2)
    Matrix mat5 = mat1 * mat2;  // Multiply mat1 and mat2
    std::cout << "Matrix mat1 * mat2:" << std::endl;
    std::cout << mat5 << std::endl;

    // 9. Testing equality operator (mat1 == mat2)
    if (mat1 == mat2) {
        std::cout << "Matrix mat1 is equal to mat2" << std::endl;
    } else {
        std::cout << "Matrix mat1 is not equal to mat2" << std::endl;
    }

    // 10. Matrix determinant calculation
    std::cout << "Determinant of mat1: " << Matrix::CalcDeterminant(mat1) << std::endl;

    // 11. Testing the Film class with Matrix frames
    std::cout << "\nCreating a film with 2 frames:" << std::endl;
    Matrix frames[2] = {Matrix(2, 2, 0), Matrix(2, 2, 1)};  // Film with 2 frames (2x2 matrices)

    // Set some frame values
    frames[0](0, 0) = 1; frames[0](0, 1) = 2;
    frames[0](1, 0) = 3; frames[0](1, 1) = 4;

    frames[1](0, 0) = 5; frames[1](0, 1) = 6;
    frames[1](1, 0) = 7; frames[1](1, 1) = 8;

    MataMvidia film("Action Movie", "John Doe", frames, 2);  // Create a Film object

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
