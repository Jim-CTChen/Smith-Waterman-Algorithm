#include <vector>
#include <iostream>

#include "definition.h"
#include "Mng.h"
#include "DS.h"

using namespace std;

ScoreMatrixMng::ScoreMatrixMng() {}

ScoreMatrixMng::~ScoreMatrixMng() {
  delete this->seq1;
  delete this->seq2;
  for (int i = 0; i < this->M; ++i) {
    delete [] this->score_matrix[i];
  }
  delete [] this->score_matrix;
}

void ScoreMatrixMng::init(int n, int m) {
  this->N = n;
  this->M = m;
  this->score_matrix = new ScoreMatrixGrid*[m];
  for (int i = 0; i < m; ++i) {
    this->score_matrix[i] = new ScoreMatrixGrid[n];
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      this->score_matrix[i][j].init(i, j);
    }
  }
}

void ScoreMatrixMng::printMatrix() {
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      printf("%4d",score_matrix[i][j]());
    }
    cout << endl;
  }
}

void ScoreMatrixMng::calculateScore(int x, int y) {
  // (x-1, y-1)
  int top_left = seq1[x] == seq2[y] ? 
    score_matrix[x-1][y-1]() + SUBSTITUTION_MATRIX_WEIGHT :
    score_matrix[x-1][y-1]() - SUBSTITUTION_MATRIX_WEIGHT;
  // (x, y-1)
}