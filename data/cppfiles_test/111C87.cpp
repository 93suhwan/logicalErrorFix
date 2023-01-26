#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int num;
    cin >> num;
    for (int i = 1; i <= num; i++) {
      int v1 = num, temp = num;
      while (v1 > 0) {
        for (int k = 1; k <= i && v1 > 0; k++) {
          cout << "(";
          v1 = v1 - 1;
        }
        cout << ")";
        temp = temp - 1;
      }
      for (int l = 0; l < num; l++) {
      }
      for (int j = 1; j <= temp; j++) {
        cout << ")";
      }
      cout << "\n";
    }
    t--;
  }
}
