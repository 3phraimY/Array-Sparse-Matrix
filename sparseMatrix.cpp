#include "sparseMatrix.hpp"

#include <iostream>

// constructor
sparseMatrix::sparseMatrix(elementTriples* elementTriplesArray, int size, int width, int height) {
    this->elementTriplesArray = elementTriplesArray;
    this->size = size;
    this->width = width;
    this->height = height;
}

void sparseMatrix::printElementTriples() {
    std::cout << "Element Index    Element Row    Element Column    Element Value" << std::endl;
    for(int i = 0; i < this->size; i++)
    {
        std::cout << "      " << i << "                " << this->elementTriplesArray[i].row << "                " << this->elementTriplesArray[i].column << "                "<< this->elementTriplesArray[i].value << std::endl;
    }
    return;
}

/*
    Prints one element at a time, begining at row 1 column 1
    Progresses across the column stopping at each element to check for a matching element coordinate for the current location
    After the row is printed, moves to the next row below
*/
void sparseMatrix::printMatrix() {
    for(int currentRow = 1; currentRow < this->height + 1; currentRow++)
    {
        for(int currentColumn = 1; currentColumn < this->width + 1; currentColumn++)
        {
            //iterating through the array of element triples
            for(int i = 0; i < this->size; i++)
            {
                //checks current coordinates for a match in the element triples array
                elementTriples currentElementTriple = this->elementTriplesArray[i];
                if(currentElementTriple.row == currentRow && currentElementTriple.column == currentColumn)
                {
                    std::cout << currentElementTriple.value << " ";
                    break;
                }
                else if(i == this->size -1)
                {
                    std::cout << "0 ";
                }
            }
        }
        std:: cout << std::endl;
    }        
}