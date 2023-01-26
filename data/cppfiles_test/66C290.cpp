#include <bits/stdc++.h>
using namespace std;
int main() {
  int testCases;
  cin >> testCases;
  while (testCases--) {
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++) {
      if (i % 3 == 0 || i % 10 == 3) {
        k++;
        continue;
      } else {
      }
    }
    cout << k << "\n";
  }
}
