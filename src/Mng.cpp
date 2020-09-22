#include <vector>
#include <iostream>
#include <utility>

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
	for (int i = 0; i < M+1; ++i) {
		if (i == 0) printf("        ");
		else printf("%4c",seq1[i-1]);
	}
	cout << endl;
	for (int i = 0; i < M+1; ++i) {
		if (i == 0) printf("    ");
		else printf("%4c", seq2[i-1]);
		for (int j = 0; j < N+1; ++j) {
			printf("%4d", score_matrix[i][j]());
		}
		cout << endl;
	}
}


int ScoreMatrixMng::calculateScore(int x, int y) {
	const int DIR_TOP_LEFT = 0;
	const int DIR_TOP = 1;
	const int DIR_LEFT = 2;
	const int DIR_ZERO = 3;
	int top_left_score = 0;
	int top_score = 0;
	int left_score = 0;
	// (x-1, y-1)
	top_left_score = seq1[y-1] == seq2[x-1] ? 
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
	return scores_candidates[result[0]];
}

void ScoreMatrixMng::calculateMatrix() {
	max_index.clear();
	int max_value = 0;
	for (int i = 1; i < M+1; ++i) {
		for (int j = 1; j < N+1; ++j) {
			int result = calculateScore(i, j);
			if (result > max_value) {
				max_index.clear();
				max_index.push_back(pair<int, int>(i, j));
				max_value = result;
			} else if (result == max_value) {
				max_index.push_back(pair<int, int>(i, j));
			}
		}
	}
	// cout << "index of max score: " << endl;
	// for (auto it : max_index) {
	// 	cout << "(" << it.first << ", " << it.second << ")" << endl;
	// }
}

void ScoreMatrixMng::traceBack() {
	
}