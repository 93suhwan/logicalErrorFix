#include <bits/stdc++.h>
using namespace std;
template <class T, class K>
ostream &operator<<(ostream &cout, pair<T, K> a) {
  cout << a.first << ' ' << a.second;
  return cout;
}
template <class T>
void show(vector<T> &a) {
  cerr << "[ ";
  for (int ij = 0; ij < (int)a.size(); ij++) {
    cerr << a[ij] << " ";
  }
  cerr << "]\n";
}
template <class T>
void show(T a) {
  cerr << a << '\n';
}
template <typename... T>
void show(T... args) {
  ((cerr << args << ' '), ...);
  cerr << '\n';
}
template <class T>
void read(vector<T> &a) {
  for (auto &x : a) {
    cin >> x;
  }
}
template <class T>
void read(T &a) {
  cin >> a;
}
void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  vector<pair<int, int>> id(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    id[i] = {p[i], i};
  }
  sort(id.begin(), id.end());
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') cnt++;
  }
  int zero = 1, one = cnt + 1;
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    if (s[id[i].second] == '0') {
      ans[id[i].second] = zero++;
    } else {
      ans[id[i].second] = one++;
    }
  }
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
}
int32_t main(int32_t argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << '\n';
}
