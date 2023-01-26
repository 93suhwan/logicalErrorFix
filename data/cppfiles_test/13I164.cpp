#include <bits/stdc++.h>
using namespace std;
bool res(string s) {
  bool res;
  int sumA = 0;
  int sumB = 0;
  int sumC = 0;
  for (int i = 0; i < s.size(); i++) {
    switch (s[i]) {
      case 'A':
        sumA++;
        break;
      case 'B':
        sumB++;
        break;
      case 'C':
        sumC++;
        break;
    }
  }
  return (sumB == (sumA + sumC));
}
int main() {
  int numOfInp = 0;
  cin >> numOfInp;
  string* inputs = new string[numOfInp];
  for (int i = 0; i < numOfInp; i++) {
    getline(cin, inputs[i]);
  }
  for (int i = 0; i < numOfInp; i++) {
    if (res(inputs[i]))
      cout << "YES";
    else
      cout << "NO";
  }
  return 0;
}
