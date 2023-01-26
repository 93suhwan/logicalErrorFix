#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int n = N - 1; n >= 0; --n) {
      cin >> a[n];
    }
    int popped = 0;
    for (int i = 1; i <= N; ++i) {
      if (a[N - i] % (i + 1 - popped)) {
        a.pop_back();
        ++popped;
      } else {
        break;
      }
    }
    if (a.empty()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
