#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
#include <string>

#include "DS.h"
#include "Mng.h"
#include "definition.h"
#include "util.h"

using namespace std;

ScoreMatrixMng Manager(GAP_PENALTY_TYPE_LINEAR);

int main()
{
  string input1, input2;
  char* seq1 = 0;
  char* seq2 = 0;
  int N = 0; // seq1 length
  int M = 0; // seq2 length
  cout << "Please enter 2 nuclieic acid sequence." << endl;
  cout << "Seperate each two adjacent nucleic acid with space." << endl;
  cout << "Press Enter after first sequence." << endl;
  cin >> input1 >> input2;
  N = input1.length();
  M = input2.length();
  seq1 = new char[N];
  seq2 = new char[M];
  strcpy(seq1, input1.c_str());
  strcpy(seq2, input2.c_str());
  Manager.init(N, M);
  Manager.setSeq1(seq1);
  Manager.setSeq2(seq2);
  // Manager.printMatrix();
}