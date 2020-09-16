#ifndef DS_H
#define DS_H

#include <iostream>
#include <vector>

class ScoreMatrixGrid {
  public:
    ScoreMatrixGrid();
    ~ScoreMatrixGrid();
    int operator() () { return score; }
    int operator + (int x) { return (score += x); }
    int operator - (int x) { return (score -= x); }
    int score = 0;
    int x;
    int y;
    
  private:
    vector <ScoreMatrixGrid*> parents;
};


#endif // DS_H