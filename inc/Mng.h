#ifndef MNG_H
#define MNG_H

#include <utility>
#include <vector>

class ScoreMatrixGrid;

class ScoreMatrixMng {
	public:
		ScoreMatrixMng(int);
		~ScoreMatrixMng();
		void init(int, int);
		void setSeq1 (char* seq) { seq1 = seq; }
		void setSeq2 (char* seq) { seq2 = seq; }
		char* getSeq1() { return seq1; }
		char* getSeq2() { return seq2; }  
		void printMatrix();
		void calculateMatrix();
		void traceBack();
		int calculateScore(int, int);
		int N = 0; // first seq, x-dir
		int M = 0; // second seq, y-dir
		int function_type;
	private:
		ScoreMatrixGrid** score_matrix = 0;
		vector<pair<int, int>> max_index;
		char* seq1 = 0;
		char* seq2 = 0;
		
};



#endif // MNG_H