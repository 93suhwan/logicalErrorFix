#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int ndigit;
  int digit;
  int number;
  string supp;
  int out;
  int module;
  int output;
  getline(cin, supp);
  n = stoi(supp);
  for (int i = 0; i < n; i++) {
    getline(cin, supp);
    ndigit = stoi(supp);
    getline(cin, supp);
    output = 0;
    module = 10;
    for (int j = 0; j < ndigit; j++) {
      number = (supp[supp.length() - 1 - j]) - '0';
      if (j == 0) {
        digit = number;
        if (digit != 0) {
          output = digit;
        }
      } else {
        digit = number;
        if (digit != 0) {
          output += (digit + 1);
        }
      }
    }
    cout << output;
    cout << "\n";
  }
  return 0;
}
