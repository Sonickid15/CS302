#include <iostream>
#include <vector>
#include <fstream>
#include <thread>
#include <string>
 
std::vector<std::vector<int>> matrixOne;
std::vector<std::vector<int>> matrixTwo;
std::vector<std::vector<int>> finalMatrix;

void matrixInput();
void matrixMultiplication(int, int);
void printMatrix();

int main() {
    std::vector<std::thread> threadPool;
    int r = 0;
    int c = 0;
    int maxThreads = std::thread::hardware_concurrency();
    
    matrixInput();

    finalMatrix.resize(matrixOne.size(), std::vector<int>(matrixTwo[0].size(),0));

    for (int z = 0; z < finalMatrix.size(); z++) {
            for (int i = 0; i < finalMatrix[0].size(); i++) {
            threadPool.push_back(std::thread(matrixMultiplication, z, i));
            if (threadPool.size() % maxThreads == 0) {
                for (int j = 0; j < threadPool.size(); j++){ 
                    threadPool[j].join();
                }
                threadPool.clear();
            }
        }
    }
    printMatrix();

    for (int i = 0; i < threadPool.size(); i++){ 
        threadPool[i].join();          
    }

    return 0;
}

void matrixMultiplication(int r, int c) {
    int matrixNum = 0;
    for (int z = 0; z < matrixOne[0].size(); z++) {
        matrixNum = matrixNum + matrixOne[r][z] * matrixTwo[z][c];
    }
    finalMatrix[r][c] = matrixNum;
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
    std::cout << "Enter filename: ";
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
