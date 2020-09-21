#include <vector>
#include <iostream>

#include "definition.h"
#include "util.h"
#include "Mng.h"
#include "DS.h"

using namespace std;



ScoreMatrixMng::ScoreMatrixMng(int type): function_type(type) {}

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
	this->score_matrix = new ScoreMatrixGrid*[m+1];
	for (int i = 0; i < m+1; ++i) {
		this->score_matrix[i] = new ScoreMatrixGrid[n+1];
	}
	for (int i = 0; i < m+1; ++i) {
		for (int j = 0; j < n+1; ++j) {
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

// void ScoreMatrixMng::calculateMatrix() {
// 	for (int i )
// }

void ScoreMatrixMng::calculateScore(int x, int y) {
	const int DIR_TOP_LEFT = 0;
	const int DIR_TOP = 1;
	const int DIR_LEFT = 2;
	const int DIR_ZERO = 3;
	int top_left_score = 0;
	int top_score = 0;
	int left_score = 0;
	// (x-1, y-1)
	top_left_score = seq1[x] == seq2[y] ? 
		score_matrix[x-1][y-1]() + SUBSTITUTION_MATRIX_WEIGHT :
		score_matrix[x-1][y-1]() - SUBSTITUTION_MATRIX_WEIGHT;
  	switch (function_type) {
		case GAP_PENALTY_TYPE_LINEAR:
			// (x, y-1)
			top_score = score_matrix[x][y-1] - GAP_PENALTY_OPENING;
			// (x-1, y)
			left_score = score_matrix[x-1][y] - GAP_PENALTY_OPENING;
			break;
		case GAP_PENALTY_TYPE_AFFINE:
			// TODO
			break;
		default:
			break;
	}
	vector<int> scores_candidates{ top_left_score, top_score, left_score, 0 }; 
	vector<int> result = maxValue(scores_candidates);
	score_matrix[x][y] = scores_candidates[result[0]];
	for (auto it = result.begin(); it != result.end(); it++) {
		switch (*it)
		{
			case DIR_TOP_LEFT:
				score_matrix[x][y].addParent(&score_matrix[x-1][y-1]);
				break;
			case DIR_TOP:
				score_matrix[x][y].addParent(&score_matrix[x][y-1]);
				break;
			case DIR_LEFT:
				score_matrix[x][y].addParent(&score_matrix[x-1][y]);
				break;
			default:
				break;
		}
	}
}
