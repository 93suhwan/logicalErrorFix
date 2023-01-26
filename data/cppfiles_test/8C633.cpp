#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  int input[10000];
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> input[i];
  }
  for (int i = 0; i < t; i++) {
    int c1 = 0;
    int c2 = 0;
    if (input[i] % 3 == 1) {
      c1 += 1;
    } else if (input[i] % 3 == 2) {
      c2 += 1;
    }
    c1 += input[i] / 3;
    c2 += input[i] / 3;
    cout << c1 << " " << c2 << "\n";
  }
  return 0;
}
