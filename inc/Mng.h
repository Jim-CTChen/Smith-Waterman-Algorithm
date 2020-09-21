#ifndef MNG_H
#define MNG_H


class ScoreMatrixGrid;

class ScoreMatrixMng {
	public:
		enum Direction {
			TOP_LEFT = 0,
			TOP = 1,
			LEFT = 2,
			ZERO = 3,
			last
		};
		enum PenaltyFunction {
			LINEAR,
			AFFINE
		};
		ScoreMatrixMng(int);
		~ScoreMatrixMng();
		void init(int, int);
		void setSeq1 (char* seq) { seq1 = seq; }
		void setSeq2 (char* seq) { seq2 = seq; }
		char* getSeq1() { return seq1; }
		char* getSeq2() { return seq2; }  
		void printMatrix();
		void calculateMatrix();
		void calculateScore(int, int);
		int N = 0; // first seq, x-dir
		int M = 0; // second seq, y-dir
		int function_type;
	private:
		ScoreMatrixGrid** score_matrix = 0;
		char* seq1 = 0;
		char* seq2 = 0;
};



#endif // MNG_H