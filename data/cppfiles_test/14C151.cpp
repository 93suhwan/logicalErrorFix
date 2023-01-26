#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int ac = 0;
  int bc = 0;
  int cc = 0;
  for (auto ss : s) {
    if (ss == 'A')
      ac++;
    else if (ss == 'B')
      bc++;
    else
      cc++;
  }
  int v = min(ac, bc);
  ac -= v;
  bc -= v;
  int g = min(bc, cc);
  bc -= g;
  cc -= g;
  if (ac > 0 || bc > 0 || cc > 0) {
    cout << "NO\n";
  } else
    cout << "YES\n";
}
void solve2() {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  vector<vector<int>> res;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = a.size() - 1; i >= 0; i--) {
    int mv = a[i];
    int mi = i;
    for (int j = i - 1; j >= 0; j--) {
      if (mv < a[j]) {
        mv = a[j];
        mi = j;
      }
    }
    int l = mi;
    int r = i;
    if (l == r) continue;
    res.push_back({l, r, 0});
    for (int j = mi; j < r; j++) {
      a[j] = a[j + 1];
    }
    a[r] = mv;
  }
  cout << res.size() << "\n";
  for (auto r : res) {
    for (auto rr : r) {
      cout << rr + 1 << " ";
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve2();
  }
  return 0;
}
