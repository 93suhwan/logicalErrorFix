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
int b[N];
void solve(int tCase) {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<array<int, 3>> vec;
  for (int i = 1; i <= n; ++i) {
    int k = i;
    for (int j = i + 1; j <= n; ++j) {
      if (a[k] > a[j]) k = j;
    }
    int d = k - i;
    if (d == 0) continue;
    vector<int> v;
    for (int j = k; j <= n; ++j) {
      v.push_back(a[j]);
    }
    for (int j = i; j < k; ++j) {
      v.push_back(a[j]);
    }
    for (int j = i; j <= n; ++j) {
      a[j] = v[j - i];
    }
    vec.push_back({i, n, d});
  }
  cout << vec.size() << '\n';
  for (auto arr : vec) {
    cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';
  }
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
