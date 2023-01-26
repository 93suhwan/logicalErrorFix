#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    cin >> N;
    bool possible = false;
    vector<int> a(N);
    for (int n = 0; n < N; ++n) {
      cin >> a[n];
      if (n > 0 && a[n - 1] >= a[n]) {
        possible = true;
      }
    }
    if (N % 2 == 0) {
      possible = true;
    }
    if (possible) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
