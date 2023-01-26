#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << '\n';
  err(++it, args...);
}
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const ll INF = 1000000007;
const int V = 200005;
int cnt[V];
int a[V];
int color[V];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i) cin >> a[i], --a[i], ++cnt[a[i]];
    int C = 0;
    for (int i = 0; i < n; ++i)
      if (0 < cnt[i] && cnt[i] < k) C += cnt[i];
    C %= k;
    int ans = 0;
    int c = -1;
    memset(color, 0, sizeof(color));
    for (int i = 0; i < n; ++i) {
      if (cnt[a[i]] >= k) {
        if (color[a[i]] == k) {
          cout << 0 << ' ';
          continue;
        }
        cout << ++color[a[i]] << ' ';
      } else {
        if (C) {
          --C;
          cout << 0 << ' ';
          continue;
        }
        cout << ((++c) % k) + 1 << ' ';
      }
    }
    cout << '\n';
  }
  return 0;
}
