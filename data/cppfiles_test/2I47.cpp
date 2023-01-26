#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int n, m, k, a[200200], s[200200], id[200200];
ll c[200200], pl[400400], ans;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) s[i] = (s[i - 1] + a[i]) % k;
  int p = s[n];
  if (!p) {
    for (int i = 1; i <= n; i++) c[s[i]] += m;
  } else {
    vector<int> v;
    set<int> st;
    for (int i = 0; i < k; i++) st.insert(i);
    while (!st.empty()) {
      int s = *st.begin();
      vector<int> v2;
      int u = s;
      while (1) {
        v2.push_back(u), st.erase(u);
        u = (u + p) % k;
        if (u == s) break;
      }
      for (int i = 0; i < v2.size(); i++)
        id[v2[i]] = v.size(), v.push_back(v2[i]);
      for (int i = 0; i < v2.size(); i++) v.push_back(v2[i]);
    }
    for (int i = 1; i <= n; i++) {
      int u = id[a[i] % k];
      pl[u]++, pl[u + m % k]--;
    }
    for (int i = 0; i < 2 * k; i++) {
      if (i) pl[i] += pl[i - 1];
      c[v[i]] += pl[i];
    }
    for (int i = 0; i < k; i++) c[i] += 1ll * m / k * i;
  }
  for (int i = 1; i <= n; i++) {
    c[s[i]]--;
    int x = (1ll * p * m % k + s[i]) % k;
    (ans += c[x]) %= mod;
    c[x]++;
  }
  (ans *= m) %= mod;
  if (1ll * p * m % k == 0) ans = (ans + 1) % mod;
  cout << ans;
}
