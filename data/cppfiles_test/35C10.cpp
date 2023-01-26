#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int v[N], prime[N], cntp;
inline void init(int n) {
  for (int i = 2; i <= n; i++) {
    if (v[i] == 0) v[i] = i, prime[++cntp] = i;
    for (int j = 1; j <= cntp; j++) {
      if (prime[j] > v[i] || prime[j] > n / i) break;
      v[i * prime[j]] = prime[j];
    }
  }
}
int a[N], n, L[N];
char b[N];
vector<int> pos[N];
vector<pair<int, int>> stk;
inline void add(int i, int x) {
  while (x > 1) pos[v[x]].push_back(i), x /= v[x];
}
inline void del(int i, int x) {
  while (x > 1) {
    if (pos[v[x]].empty()) return L[i] = 0, void();
    L[i] = min(L[i], pos[v[x]].back());
    pos[v[x]].pop_back(), x /= v[x];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  init(*max_element(a + 1, a + 1 + n));
  iota(L + 1, L + 1 + n, 1), cin >> (b + 1);
  for (int i = 1; i <= n; i++) b[i] == '*' ? add(i, a[i]) : del(i, a[i]);
  long long ans = 0;
  for (int i = n; i >= 1; i--) {
    if (!L[i]) {
      stk.clear();
      continue;
    }
    int cnt = 1;
    while (!stk.empty() && stk.back().first >= L[i])
      cnt += stk.back().second, stk.pop_back();
    stk.emplace_back(L[i], cnt);
    if (L[i] == i) ans += cnt;
  }
  cout << ans << "\n";
  return 0;
}
