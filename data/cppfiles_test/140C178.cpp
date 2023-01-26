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
    int mark = 1;
    while (pow(sqrCount, 2) <= n) {
      sqrCount++;
      count++;
    }
    while (pow(cubCount, 3) <= n) {
      if (pow(mark, 2) == cubCount) {
        mark++;
      } else {
        count++;
      }
      cubCount++;
    }
    cout << count << endl;
  }
  return 0;
}
