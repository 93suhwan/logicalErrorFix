#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 5, INF = 0x3f3f3f3f, MOD = 998244353;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
set<pair<int, int>, greater<pair<int, int>>> arr;
int n;
void func(int l, int r) {
  if (arr.find({l, r}) != arr.end())
    arr.erase({l, r});
  else
    return;
  if (l == r) {
    cout << l << " " << r << " " << l << endl;
    return;
  }
  pair<int, int> pl = *arr.upper_bound({l, r});
  if (pl.first == l) {
    cout << l << " " << r << " " << pl.second + 1 << endl;
    func(pl.first, pl.second);
    if (pl.second + 2 < n) func(pl.second + 2, n);
  } else {
    cout << l << " " << r << " " << l << endl;
    func(l + 1, r);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int cases;
  cin >> cases;
  while (cases--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int l, r;
      cin >> l >> r;
      arr.insert({l, r});
    }
    func(1, n);
    cout << endl;
  }
  return 0;
}
