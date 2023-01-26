#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> st(n);
  for (auto &i : st) cin >> i;
  auto isSolution = [&](int mini) -> bool {
    vector<int> heap = st;
    for (int i = n - 1; i > 1; i--) {
      if (heap[i] - mini < 0) return false;
      int transfer = (heap[i] - mini) / 3;
      if (heap[i] - mini > st[i]) transfer = st[i] / 3;
      heap[i - 1] += transfer;
      heap[i - 2] += transfer * 2;
    }
    return (heap[0] >= mini) && (heap[1] >= mini);
  };
  int l = 0, h = 1e9 + 1;
  while (l < h) {
    int m = l + (h - l + 1) / 2;
    if (isSolution(m))
      l = m;
    else
      h = m - 1;
  }
  cout << l << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
