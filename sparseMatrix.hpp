#ifndef SPARSEMATRIX_HPP
#define SPARSEMATRIX_HPP

//create struct to track coordinates and value of elements in sparse matrix
struct elementTriples {
    int row;
    int column;
    int value;

    elementTriples(int row, int column, int value) {
        this->row = row;
        this->column = column;
        this->value = value;
    }
    elementTriples() {
        this->row = 0;
        this->column = 0;
        this->value = 0;
    }

};

class sparseMatrix {
    private:
        int size;
        int width;
        int height;
        elementTriples* elementTriplesArray;

    public:
        //constuctors and deconstructors
        sparseMatrix(elementTriples* elementTriplesArray, int size, int width, int height);       

        //getters
        elementTriples* getElementTriples() { return this->elementTriplesArray; };        
        int getSize() { return this-> size; };
        int getWidth() { return this->width; };
        int getHeight() { return this->height; };

        //print functions
        void printElementTriples();
        void printMatrix();
};

#endif