// #include "Matrix.h"
// #include "MataMvidia.h"
// #include <iostream>

// using namespace std;

// void testMatrixOperations() {
//     cout << "--- Testing Matrix Operations ---" << endl;
    
//     // Creating matrices
//     Matrix m1(2, 2, 1); // 2x2 matrix filled with 1s
//     Matrix m2(2, 2, 2); // 2x2 matrix filled with 2s

//     cout << "Matrix m1:\n" << m1;
//     cout << "Matrix m2:\n" << m2;

//     // Addition
//     Matrix m3 = m1 + m2;
//     cout << "m1 + m2:\n" << m3;

//     // Scalar multiplication
//     Matrix m4 = m1 * 3;
//     cout << "m1 * 3:\n" << m4;

//     // Unary minus
//     Matrix m5 = -m2;
//     cout << "-m2:\n" << m5;

//     // Transpose
//     Matrix m6 = m2.transpose();
//     cout << "Transpose of m2:\n" << m6;

//     // Rotations
//     cout << "Rotate m2 clockwise:\n" << m2.rotateClockwise();
//     cout << "Rotate m2 counter-clockwise:\n" << m2.rotateCounterClockwise();

//     // Equality check
//     Matrix m7(2, 2, 2);
//     if (m2 == m7)
//         cout << "m2 and m7 are equal!" << endl;
//     else
//         cout << "m2 and m7 are NOT equal!" << endl;

//     cout << "--- End of Matrix Operations ---\n" << endl;
// }

// void testMataMvidiaOperations() {
//     cout << "--- Testing MataMvidia Operations ---" << endl;

//     Matrix frame1(2, 2);
//     Matrix frame2(2, 2);
//     frame1(0, 0) = 1; frame1(0, 1) = 2;
//     frame1(1, 0) = 3; frame1(1, 1) = 4;

//     frame2(0, 0) = 5; frame2(0, 1) = 6;
//     frame2(1, 0) = 7; frame2(1, 1) = 8;

//     Matrix array[] = {frame1, frame2};

//     MataMvidia movie("MataMatrix", "Baraa Egbaria", array, 2);
//     cout << movie << endl;

//     // Adding a new frame
//     Matrix newFrame(2, 2, 9);
//     movie += newFrame;
//     cout << "After adding a new frame:\n" << movie;

//     // Combining movies
//     MataMvidia movie2 = movie + movie;
//     cout << "Combined Movie:\n" << movie2;

//     cout << "--- End of MataMvidia Operations ---\n" << endl;
// }

// int main() {
//     // Run tests
//     testMatrixOperations();
//     testMataMvidiaOperations();
    
//     return 0;
// }
