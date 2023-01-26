#include <bits/stdc++.h>
using namespace std;
void err() { cout << endl; }
template <class T, class... Ts>
void err(T arg, Ts &...args) {
  cout << arg << ' ';
  err(args...);
}
const int N = 2e5 + 10;
const long long mod = 1e9 + 7;
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
long long rng(long long l, long long r) {
  uniform_int_distribution<long long> uni(l, r);
  return uni(mt);
}
int a[N];
void solve(int tCase) {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  vector<int> add, sub;
  string s;
  cin >> s;
  for (int i = 1; i <= n; ++i) {
    if (s[i - 1] == 'R') {
      add.push_back(a[i]);
    } else {
      sub.push_back(a[i]);
    }
  }
  std::sort(add.begin(), add.end(), greater<int>());
  std::sort(sub.begin(), sub.end());
  bool f = true;
  for (int i = 1; i <= sub.size(); ++i) {
    if (sub[i - 1] < i) f = false;
  }
  for (int i = 1; i <= add.size(); ++i) {
    if (add[i - 1] > n - i + 1) f = false;
  }
  if (f)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve(t);
  }
  return 0;
}
