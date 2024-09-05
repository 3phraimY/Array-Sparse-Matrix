# include <iostream>
# include "sparseMatrix.hpp"

using namespace std;

int main() {

    int size, height, width;
    cout << "How many points would you like to plot in the matrix? > ";
    cin >> size;
    cout << "What is the height of the matrix? > ";
    cin >> height;
    if(height <= 0) {
        cout << "Error: Cannot have 0 or negative height";
        return 1;
    }
    cout << "What is the width of the matrix? > ";
    cin >> width;
    if(width <= 0) {
        cout << "Error: Cannot have 0 or negative width";
        return 1;
    }
    
    // create array of element triples of length size (2D array)
    elementTriples elementTriplesArray[size];

    // prompt user for location and values of points
    for(int i = 0; i < size; i++) { 
        cout << "Enter row position for point " << i + 1 << " > ";
        cin >> elementTriplesArray[i].row;
        if(elementTriplesArray[i].row > height || elementTriplesArray[i].row < 0) {
            cout << "Error: Row out of defined matrix";
            return 1;
        }

        cout << "Enter column position for point " << i + 1 << " > ";
        cin >> elementTriplesArray[i].column;
        if(elementTriplesArray[i].column > width || elementTriplesArray[i].column < 0) {
            cout << "Error: Column out of defined matrix";
            return 1;
        }

        cout << "Enter value for point " << i << " > ";
        cin >> elementTriplesArray[i].value;
        if(elementTriplesArray[i].value <= 0) {
            cout << "Error: Value cannot be 0 or negative";
            return 1;
        }
    }
    
    // create new sparse matrix given the provided data.
    sparseMatrix* userDefinedMatrix = new sparseMatrix(elementTriplesArray, size, width, height);

    cout << "================================================" << endl;
    userDefinedMatrix->printMatrix();
    cout << "================================================" << endl;
    userDefinedMatrix->printElementTriples();
    return 0;
}