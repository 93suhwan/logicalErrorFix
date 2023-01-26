#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  long long max = 0;
  int j;
  for (int i = 0; i < n; i++) {
    if (v[i] >= max) {
      max = v[i];
      j = i;
    }
  }
  long long l = v[n - 1];
  map<int, int> m;
  if (l == max) {
    cout << 0 << "\n";
    return;
  }
  int big = 0, cnt = 0;
  for (int i = n - 1; i >= j + 1; i--) {
    if (v[i] > big) {
      big = v[i];
      cnt++;
    }
  }
  cout << cnt << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
