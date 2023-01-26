#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, k, i, count = 1, A[2000];
  cin >> t;
  for (i = 1; i < 1700; i++) {
    if (i % 3 == 0 || i % 10 == 3) {
      continue;
    } else {
      A[count] = i;
      count++;
    }
  }
  while (t--) {
    cin >> k;
    cout << A[k] << endl;
  }
}
