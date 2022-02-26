#include <iostream>
#include <vector>
#include <fstream>
#include <thread>
#include <string>

std::vector<std::vector<int>> matrixOne;
std::vector<std::vector<int>> matrixTwo;
std::vector<std::vector<int>> finalMatrix;

void matrixInput();
void matrixMultiplication();
void printMatrix();

int main() {
    matrixInput();
    matrixMultiplication();
    printMatrix();
    return 0;
}

void matrixMultiplication() {
    std::vector<int> row;
    int counter = 0;
    int newMatrix = 0;
    while (counter < matrixOne.size()) {
        for (int z = 0; z < matrixTwo[0].size(); z++) {
            for (int i = 0; i < matrixOne[0].size(); i++) {
                newMatrix = newMatrix + matrixOne[counter][i] * matrixTwo[i][z];
            }
            row.push_back(newMatrix);
            newMatrix = 0;
        }
        finalMatrix.push_back(row);
        row.clear();
        counter++;
    }

}

void printMatrix() {
    for (int i = 0; i < finalMatrix.size(); i ++) {
        for (int z = 0; z < finalMatrix[i].size(); z++) {
            std::cout << finalMatrix[i][z] << " ";
        }
        std::cout << std::endl;
    }
};

void matrixInput() {
    std::ifstream file;
    std::string fileName;
    int matrixSize[2];
    int matrixValues;
    std::vector<int> matrixRow;

    std::cin >> fileName;
    file.open(fileName);
    file >> matrixSize[0];
    file >> matrixSize[1];
    for (int i = 0; i < matrixSize[0]; i++) {
        for (int z = 0; z < matrixSize[1]; z++) {
            file >> matrixValues;
            matrixRow.push_back(matrixValues);
        }
        matrixOne.push_back(matrixRow);
        matrixRow.clear();
    }

    file >> matrixSize[0];
    file >> matrixSize[1];
    for (int i = 0; i < matrixSize[0]; i++) {
        for (int z = 0; z < matrixSize[1]; z++) {
            file >> matrixValues;
            matrixRow.push_back(matrixValues);
        }
        matrixTwo.push_back(matrixRow);
        matrixRow.clear();
    }
};
