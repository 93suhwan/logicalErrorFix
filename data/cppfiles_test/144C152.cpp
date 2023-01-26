#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int d4x[4] = {1, 0, -1, 0};
int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <class X, class Y>
bool minimize(X &x, const Y &y) {
  if (x > y) {
    x = y;
    return true;
  }
  return false;
}
template <class X, class Y>
bool maximize(X &x, const Y &y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}
const int MOD = 1e9 + 7;
template <class X, class Y>
void add(X &x, const Y &y) {
  x = (x + y);
  if (x >= MOD) x -= MOD;
}
template <class X, class Y>
void sub(X &x, const Y &y) {
  x = (x - y);
  if (x < 0) x += MOD;
}
const ll INF = 1e9;
const int N = 5e5 + 10;
int cnt[N];
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int each = n / m;
  int r = n % m;
  struct T {
    int index, c;
    bool operator<(const T &temp) const { return c > temp.c; };
  };
  priority_queue<T> q;
  for (int i = 1; i <= n; i++) {
    cnt[i] = 0;
    q.push({i, 0});
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= r; j++) {
      cout << each + 1 << " ";
      for (int t = 1; t <= each + 1; t++) {
        T curr = q.top();
        q.pop();
        cnt[curr.index]++;
        cout << curr.index << " ";
      }
      cout << '\n';
    }
    for (int j = r + 1; j <= m; j++) {
      cout << each << " ";
      for (int t = 1; t <= each; t++) {
        T curr = q.top();
        q.pop();
        cout << curr.index << " ";
      }
      cout << '\n';
    }
    for (int j = 1; j <= n; j++) q.push({j, cnt[j]});
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1, ddd = 0;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
