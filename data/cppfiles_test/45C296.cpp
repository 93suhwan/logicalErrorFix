#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    int sm = 0;
    cin >> n;
    vector<bool> a(n);
    for (int i = 0; i < n; ++i) {
      int c;
      cin >> c;
      a[i] = c & 1;
      sm += a[i];
    }
    auto solve = [&]() {
      if (abs(n - sm * 2) >= 2) return -1;
      int out = INT_MAX;
      if (n - sm * 2 <= 0) {
        int pos = 0;
        int sm = 0;
        for (int i = 0; i < n; ++i)
          if (a[i]) {
            sm += abs(i - pos);
            pos += 2;
          }
        out = min(out, sm);
      }
      if (n - sm * 2 >= 0) {
        int pos = 0;
        int sm = 0;
        for (int i = 0; i < n; ++i)
          if (!a[i]) {
            sm += abs(i - pos);
            pos += 2;
          }
        out = min(out, sm);
      }
      return out;
    };
    cout << solve() << '\n';
  }
}
