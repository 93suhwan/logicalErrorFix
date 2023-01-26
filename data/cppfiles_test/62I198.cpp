#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const long long inf = 1000000000000000000;
void solve() {
  int n;
  cin >> n;
  vector<int> pos;
  set<int> chk;
  int one = -1;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[i] = x;
    chk.insert(x);
    if (x == 0) {
      pos.push_back(i);
    } else if (x == 1) {
      one = i;
    }
  }
  bool f = 0;
  int ans = -1;
  for (auto u : pos) {
    if (chk.find(u + 1) != chk.end()) {
      f = 1;
      ans = u;
      break;
    }
  }
  if (one != -1) {
    cout << n + 1 << ' ';
    for (int i = 1; i <= n; i++) {
      cout << i << ' ';
    }
    cout << '\n';
  } else if (a[n] == 0) {
    for (int i = 1; i <= n; i++) cout << i << ' ';
    cout << n + 1 << '\n';
  } else if (f) {
    for (int i = 1; i <= ans; i++) {
      cout << i << ' ';
    }
    cout << n + 1 << ' ';
    for (int i = ans + 1; i <= n; i++) {
      cout << i << ' ';
    }
    cout << '\n';
  } else
    cout << -1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) solve();
}
