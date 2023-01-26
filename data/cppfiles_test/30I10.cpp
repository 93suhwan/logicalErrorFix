#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline void chkmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
inline void chkmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int Mod = 1000000007;
int sum(int a, int b) { return (a + b >= Mod ? a + b - Mod : a + b); }
int mul(int a, int b) { return ((ll)a * b) % Mod; }
int powm(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
int inv(int a) { return powm(a, Mod - 2); }
const int MAXN = 150228;
int n, q;
int a[MAXN];
int parent[1000229];
vector<int> who[1000228];
bool bad[1000228];
bool good[1000229];
vector<int> z[1000228];
int findset(int a) {
  if (parent[a] == a) {
    return a;
  }
  return parent[a] = findset(parent[a]);
}
void merge(int a, int b) {
  a = findset(a);
  b = findset(b);
  if (a == b) {
    return;
  }
  good[a] |= good[b];
  parent[b] = a;
}
int rep[1000229];
vector<int> goode[1000229];
void solve() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    who[a[i]].push_back(a[i]);
  }
  for (int i = 2; i <= 1000001; i++) {
    parent[i] = i;
    good[i] = (i % 2) == 0;
  }
  for (int i = 2; i <= 1000001; i++) {
    if (bad[i]) {
      continue;
    }
    z[i].push_back(i);
    for (int j = 2 * i; j <= 1000001; j += i) {
      z[j].push_back(i);
      bad[j] = true;
    }
  }
  for (int i = 2; i <= 1000001; i++) {
    if (bad[i]) {
      continue;
    }
    int a = -1;
    if (!who[i].empty()) {
      a = who[i][0];
    }
    for (int j = 2 * i; j <= 1000001; j += i) {
      if (!who[j].empty()) {
        if (a == -1) {
          a = who[j][0];
        } else {
          merge(a, who[j][0]);
        }
      }
    }
  }
  for (int i = 2; i <= 1000001; i++) {
    if (!bad[i]) {
      rep[i] = -1;
      for (int j = i; j <= 1000001; j += i) {
        if (!who[j].empty()) {
          rep[i] = findset(who[j][0]);
          break;
        }
      }
    }
  }
  for (int i = 2; i <= 1000001; i++) {
    if (who[i].empty()) {
      continue;
    }
    for (auto x : z[i + 1]) {
      if (rep[x] != -1) {
        goode[rep[x]].push_back(findset(i));
        goode[findset(i)].push_back(rep[x]);
      }
    }
  }
  for (int i = 2; i <= 1000001; i++) {
    sort((goode[i]).begin(), (goode[i]).end());
  }
  for (int it = 0; it < q; it++) {
    int s, t;
    cin >> s >> t;
    s--, t--;
    s = a[s];
    t = a[t];
    s = findset(s);
    t = findset(t);
    if (s == t) {
      cout << 0 << '\n';
      continue;
    }
    if (good[s] || good[t]) {
      cout << 1 << '\n';
      continue;
    }
    {
      auto fk = lower_bound((goode[s]).begin(), (goode[s]).end(), t) -
                goode[s].begin();
      if (fk != (int)(goode[s]).size() && goode[s][fk] == t) {
        cout << 1 << '\n';
        continue;
      }
    }
    swap(s, t);
    {
      auto fk = lower_bound((goode[s]).begin(), (goode[s]).end(), t) -
                goode[s].begin();
      if (fk != (int)(goode[s]).size() && goode[s][fk] == t) {
        cout << 1 << '\n';
        continue;
      }
    }
    cout << 2 << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
