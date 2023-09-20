#ifndef MATRIX_H
#define MATRIX_H

#include <string>

void readMatrixSizeFromFile(size_t& width, size_t& height, const std::string& fileName);
void readMatrixFromFile(int* mat, size_t maxSize, const std::string& fileName);
void writeMatrixFromFile(const int* mat, size_t width, size_t height, const std::string& fileName);

#endif
