#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vvi = vector<vector<int>>;
bool get_next(vector<int> &u) {
  int i = u.size() - 1;
  while (i >= 0 && u[i] == 1) {
    --i;
  }
  if (i < 0) {
    return false;
  }
  ++u[i];
  for (int j = i + 1; j < (int)u.size(); ++j) {
    u[j] = -1;
  }
  return true;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a) {
    cin >> e;
    e = abs(e);
  }
  sort(begin(a), end(a));
  if (find(begin(a), end(a), 0) != end(a)) {
    cout << "YES\n";
    return;
  }
  if (n == 1) {
    cout << "NO\n";
    return;
  }
  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i - 1]) {
      cout << "YES\n";
      return;
    }
  }
  vector<int> u(n, -1);
  do {
    int cnt_nonzero = 0;
    int s = 0;
    for (int i = 0; i < n; ++i) {
      s += u[i] * a[i];
      cnt_nonzero += (u[i] != 0);
    }
    if (cnt_nonzero > 0 && s == 0) {
      cout << "YES\n";
      return;
    }
  } while (get_next(u));
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
