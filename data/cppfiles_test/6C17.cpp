#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, mod = 1e9 + 7;
int n, a[N], phi[N], cnt[N];
vector<int> d[N];
void init() {
  for (int i = 1; i < (N); ++i) {
    phi[i] = i;
  }
  for (int i = 2; i < (N); ++i) {
    if (phi[i] == i) {
      for (int j = i; j < N; j += i) {
        phi[j] -= phi[j] / i;
      }
    }
  }
  for (int i = 1; i < (N); ++i) {
    for (int j = i; j < N; j += i) {
      d[j].push_back(i);
    }
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  init();
  cin >> n;
  for (int i = 1; i < (n + 1); ++i) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int x = 1; x < (n + 1); ++x) {
    for (int i = x; i <= n; i += x) {
      for (const int j : d[a[i]]) {
        ++cnt[j];
      }
    }
    for (int i = x; i <= n; i += x) {
      for (const int j : d[a[i]]) {
        if (cnt[j]) {
          ans = (ans +
                 phi[x] * 1ll * phi[j] % mod * cnt[j] % mod * cnt[j] % mod) %
                mod;
          cnt[j] = 0;
        }
      }
    }
  }
  cout << ans << '\n';
}
