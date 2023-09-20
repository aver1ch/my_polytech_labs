#include "task.h"
#include "matrix.h"
#include <bubblesort.h>

#include <iostream>
#include <fstream>
#include <algorithm>

int countColumnWithDuplicates(const int* matrix, size_t width, size_t height)
{
  int* column = new int[height];
  int colsWithDuplcates = 0;
  for (size_t col = 0; col < width; ++col) {
    for (size_t row = 0; row < height; ++row) {
      column[row] = matrix[row * width + col];
    }
    bubbleSort(column, column + height);
    for (size_t i = 1; i < height; ++i) {
      if (column[i] == column[i - 1]) {
        ++colsWithDuplcates;
        break;
      }
    }
  }
  delete[] column;
  return colsWithDuplcates;
}

int findMinSecondaryDiagonal(const int* matrix, size_t width, size_t height)
{
  int minSum = matrix[0];
  for (size_t y = 1; y < height - 1; ++y) {
    int sumOfDiagonal = 0;
    for (size_t x = 0, yy = y + 1; yy > 0; ++x, --yy) {
      sumOfDiagonal += matrix[(yy - 1) * width + x];
    }
    minSum = std::min(minSum, sumOfDiagonal);
  }
  for (size_t x = 1; x < width; ++x) {
    int sumOfDiagonal = 0;
    for (size_t y = height - 1, xx = x; xx < width; --y, ++xx) {
      sumOfDiagonal += matrix[y * width + xx];
    }
    minSum = std::min(minSum, sumOfDiagonal);
  }
  return minSum;
}

void writeResult(int result, const std::string& fileName)
{
  std::ofstream os(fileName);
  os << result;
  if (!os) {
    throw std::runtime_error("Can't write matrix to the file");
  }
}

void performTask(const Parameters& parameters)
{
  size_t width = 0;
  size_t height = 0;
  readMatrixSizeFromFile(width, height, parameters.inputFileName);
  if (!width || !height) {
    return;
  }
  const size_t matrixArea = width * height;
  if (parameters.task == Parameters::Task::First) {
    const size_t MaxMatrixArea = 1000;
    if (matrixArea > MaxMatrixArea) {
      throw std::runtime_error("Matrix in file greater than MAX_SIZE");
    }
    int matrixData[MaxMatrixArea];
    readMatrixFromFile(matrixData, matrixArea, parameters.inputFileName);
    writeResult(countColumnWithDuplicates(matrixData, width, height), parameters.outputFileName);
  }
  if (parameters.task == Parameters::Task::Second) {
    int* matrixData = new int[matrixArea];
    try {
      readMatrixFromFile(matrixData, matrixArea, parameters.inputFileName);
      writeResult(findMinSecondaryDiagonal(matrixData, width, height), parameters.outputFileName);
    } catch (const std::exception& e) {
      delete [] matrixData;
      throw;
    }
    delete[] matrixData;
  }
}
