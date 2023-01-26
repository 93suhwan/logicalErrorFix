#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int mx = 0;
  bool one = false, two = false;
  unordered_set<int> S;
  for (int _ = (0); _ < (n); _++) {
    int tmp;
    cin >> tmp;
    S.insert(tmp);
    mx = max(mx, tmp);
    one |= tmp % 3 == 1;
    two |= tmp % 3 == 2;
  }
  if (mx % 3 == 0) {
    cout << mx / 3 + (one || two);
  } else if (mx % 3 == 1) {
    cout << mx / 3 + 1 +
                (two && (S.find(1) != S.end() || S.find(mx - 1) != S.end()));
  } else {
    cout << mx / 3 + 1 + one;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int _ = (0); _ < (t); _++) {
    solve();
    cout << "\n";
  }
}
