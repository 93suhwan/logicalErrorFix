#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int score = 0;
  int ar[2 * k];
  int j = 2 * k - 1;
  int i = n - 1;
  while (j >= 0) {
    ar[j] = v[i];
    i--;
    j--;
  }
  for (int i = 0; i < k; i++) {
    int add = ar[i] / ar[i + k];
    score += add;
  }
  for (int j = 0; j < n - (2 * k); j++) {
    score += v[j];
  }
  cout << score << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int _t;
  cin >> _t;
  while (_t--) solve();
}
