// #include <iostream>
// #include "Matrix.h"
// #include "MataMvidia.h"

// int main() {
//     // Test Matrix class
//     std::cout << "--- Testing Matrix Class ---\n";

//     // 1. Create and print matrices
//     Matrix mat1(3, 3, 1); // 3x3 matrix filled with 1
//     Matrix mat2(3, 3, 2); // 3x3 matrix filled with 2
//     std::cout << "Matrix mat1:\n" << mat1 << std::endl;
//     std::cout << "Matrix mat2:\n" << mat2 << std::endl;

//     // 2. Matrix addition, subtraction, and scalar multiplication
//     Matrix matSum = mat1 + mat2;
//     std::cout << "mat1 + mat2:\n" << matSum;
//     Matrix matDiff = mat2 - mat1;
//     std::cout << "mat2 - mat1:\n" << matDiff;
//     Matrix matScaled = mat1 * 5;
//     std::cout << "mat1 * 5:\n" << matScaled;

//     // 3. Matrix transpose and rotations
//     Matrix matTranspose = mat1.transpose();
//     std::cout << "Transpose of mat1:\n" << matTranspose;
//     Matrix matClockwise = mat1.rotateClockwise();
//     std::cout << "Clockwise rotation of mat1:\n" << matClockwise;
//     Matrix matCounterClockwise = mat1.rotateCounterClockwise();
//     std::cout << "Counter-clockwise rotation of mat1:\n" << matCounterClockwise;

//     // 4. Matrix comparison
//     std::cout << "mat1 == mat2: " << (mat1 == mat2 ? "True" : "False") << std::endl;
//     std::cout << "mat1 != mat2: " << (mat1 != mat2 ? "True" : "False") << std::endl;

//     // 5. Frobenius Norm
//     std::cout << "Frobenius norm of mat1: " << Matrix::CalcProbeniousNorm(mat1) << std::endl;

//     // 6. Determinant calculation (only for square matrices)
//     std::cout << "Determinant of mat1: " << Matrix::CalcDeterminant(mat1) << std::endl;

//     // Test MataMvidia class
//     std::cout << "\n--- Testing MataMvidia Class ---\n";

//     // 7. Create a film with frames
//     Matrix frames[2] = { Matrix(2, 2, 1), Matrix(2, 2, 2) };
//     MataMvidia film(2, "Matrix Adventure", "John Doe", frames);
//     std::cout << film << std::endl;

//     // 8. Add a new frame
//     film += Matrix(2, 2, 3);
//     std::cout << "After adding a new frame:\n" << film;

//     MataMvidia film("Action Movie", "John Doe", frames, 2);  // Create a Film object

//     // Output film information
//     std::cout << "Film name: Action Movie" << std::endl;
//     std::cout << "Author: John Doe" << std::endl;
//     std::cout << "Film length: " << 2 << " frames" << std::endl;
//     std::cout << "Frame 1:" << std::endl;
//     std::cout << frames[0] << std::endl;
//     std::cout << "Frame 2:" << std::endl;
//     std::cout << frames[1] << std::endl;

//     return 0;
// }
