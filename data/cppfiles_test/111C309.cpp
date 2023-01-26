#include <bits/stdc++.h>
using namespace std;
void problem() {
  int testcases;
  cin >> testcases;
  while (testcases--) {
    int number;
    cin >> number;
    string siva = "";
    for (int i = 0; i < number; i++) {
      siva += "()";
    }
    int l = 2 * number;
    cout << siva << "\n";
    for (int i = 1; i < number; i++) {
      char t = siva[i];
      siva[i] = siva[l - i - 1];
      siva[l - i - 1] = t;
      cout << siva << "\n";
    }
  }
}
int main() { problem(); }
