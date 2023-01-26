#include <bits/stdc++.h>
using namespace std;
void solve(int a, int b, set<int>& ans) {
  int n = a + b;
  int F = n / 2;
  int S = n - F;
  int wa = max(0, F - a);
  int wb = max(0, S - b);
  int K = wa + wb;
  wa = F - wa;
  wb = S - wb;
  for (int i = 0; i <= min(wa, wb); i++) ans.insert(K + 2 * i);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    set<int> ans;
    solve(a, b, ans);
    solve(b, a, ans);
    cout << (int)ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
    cout << '\n';
  }
  return 0;
}
