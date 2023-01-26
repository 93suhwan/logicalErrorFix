#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
long long int arr[2][1000015];
long long int root(long long int n, long long int c) {
  if (n != arr[c][n]) arr[c][n] = root(arr[c][n], c);
  return arr[c][n];
}
void solve() {
  long long int v = 0, e = 0, i = 0, a = 0, b = 0, c = 0, d = 0, k = 0, t = 0,
                m = 20000000000000000, n = 0, q = 0, j = 0, r = 0, l = 0,
                sum = 0, pdt = 1;
  cin >> v;
  for (i = 0; i <= v; i++) {
    arr[0][i] = i;
    arr[1][i] = i;
  }
  cin >> n >> m;
  while (n--) {
    cin >> c >> d;
    l = root(c, 0);
    r = root(d, 0);
    arr[0][l] = r;
  }
  while (m--) {
    cin >> c >> d;
    l = root(c, 1);
    r = root(d, 1);
    arr[1][l] = r;
  }
  vector<pair<long long int, long long int> > ans;
  for (i = 1; i <= v; i++) {
    l = root(1, 0);
    r = root(1, 1);
    c = root(i, 0);
    d = root(i, 1);
    if (c != l && d != r) {
      ans.push_back({1, i});
      arr[0][c] = l;
      arr[1][d] = r;
    }
  }
  stack<long long int> zero, one;
  for (i = 1; i <= v; i++) {
    l = root(1, 0);
    r = root(1, 1);
    c = root(i, 0);
    d = root(i, 1);
    if (l != c) zero.push(i);
    arr[0][c] = l;
    if (r != d) one.push(i);
    arr[1][d] = r;
    if (!zero.empty() && !one.empty()) {
      ans.push_back({zero.top(), one.top()});
      zero.pop();
      one.pop();
    }
  }
  cout << ans.size() << endl;
  for (auto j : ans) {
    cout << j.first << " " << j.second << endl;
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
