#ifndef DS_H
#define DS_H

#include <iostream>
#include <vector>

using namespace std;

class ScoreMatrixGrid {
  public:
    ScoreMatrixGrid();
    ~ScoreMatrixGrid();
    void init(int, int);
    int operator() () { return score; }
    int operator + (int x) { return (score += x); }
    int operator - (int x) { return (score -= x); }
    int score = 0;
    int X;
    int Y;
    
  private:
    vector <ScoreMatrixGrid*> parents;
};


#endif // DS_H