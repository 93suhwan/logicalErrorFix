#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF = 1e100;
const double EPS = 1e-9;
const double PI = acos(-1);
void solve() {
  int n;
  cin >> n;
  vector<int> ar(n);
  bool bo = true;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    bo &= ar[i] & 1 ^ i;
  }
  if (!bo) {
    cout << -1 << '\n';
    return;
  }
  int a, b;
  vector<int> res;
  for (int i = n; i > 1; i -= 2) {
    for (int j = 0; j < i; j++) {
      if (ar[j] == i) a = j + 1;
      if (ar[j] == i - 1) b = j + 1;
    }
    if (a == i && b == i - 1) {
      continue;
    }
    if (a != 1) {
      res.push_back(a);
      reverse(ar.begin(), ar.begin() + a);
      for (int j = 0; j < i; j++)
        if (ar[j] == i - 1) b = j + 1;
    }
    if (b != 2) {
      res.push_back(b - 1);
      reverse(ar.begin(), ar.begin() + b - 1);
      res.push_back(b + 1);
      reverse(ar.begin(), ar.begin() + b + 1);
      res.push_back(3);
      reverse(ar.begin(), ar.begin() + 3);
    }
    res.push_back(i);
    reverse((ar).begin(), (ar).end());
  }
  cout << res.size() << '\n';
  for (int x : res) cout << x << ' ';
  if (res.size()) cout << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
