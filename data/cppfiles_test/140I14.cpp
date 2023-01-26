#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int sqrCount = 1;
    int cubCount = 1;
    int count = 0;
    while (pow(sqrCount, 2) <= n) {
      sqrCount++;
      count++;
    }
    while (pow(cubCount, 3) <= n) {
      cubCount++;
      count++;
    }
    cout << count - 1 << endl;
  }
  return 0;
}
