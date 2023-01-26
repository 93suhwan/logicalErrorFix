#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int T, N;
int A[maxn];
void solve() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];
  if (A[1] == 1) {
    cout << N + 1 << " ";
    for (int i = 1; i <= N; i++) cout << i << " ";
    cout << "\n";
    return;
  }
  bool oke = false;
  vector<int> res;
  for (int i = 1; i <= N; i++) {
    if (A[i] == 0 && A[i + 1] == 1 && !oke) {
      res.push_back(i);
      res.push_back(N + 1);
      oke = true;
    } else
      res.push_back(i);
  }
  if (!oke)
    cout << -1 << "\n";
  else {
    for (auto e : res) cout << e << " ";
    cout << "\n";
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
