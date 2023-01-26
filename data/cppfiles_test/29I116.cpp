#include <bits/stdc++.h>
#pragma GCC optimize "O3"
using namespace std;
const int INF = 1e9 + 7;
const int mod = 31607;
const int N = 2e5 + 7;
const int T = 1 << 20;
long long tree[T + T];
long long ile[T + T];
pair<long long, int> suma(int pocz, int kon) {
  pocz += T;
  kon += T;
  pair<long long, int> ret = {tree[pocz], ile[pocz]};
  if (pocz != kon) {
    ret.first += tree[kon];
    ret.second += ile[kon];
  }
  while (pocz >> 1 != kon >> 1) {
    if (pocz % 2 == 0) {
      ret.first += tree[pocz + 1];
      ret.second += ile[pocz + 1];
    }
    if (kon & 1) {
      ret.first += tree[kon - 1];
      ret.second += ile[kon - 1];
    }
    pocz >>= 1;
    kon >>= 1;
  }
  return ret;
}
void ustaw(int poz, long long val, int il = 1) {
  poz += T;
  tree[poz] = val;
  ile[poz] = il;
  poz >>= 1;
  while (poz) {
    tree[poz] = tree[poz + poz] + tree[poz + poz + 1];
    ile[poz] = ile[poz + poz] + ile[poz + poz + 1];
    poz >>= 1;
  }
}
long long ans[N];
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int> > input;
  vector<int> tab(n);
  for (int i = 0; i < n; i++) {
    cin >> tab[i];
    input.push_back({tab[i], i});
  }
  sort(input.begin(), input.end());
  set<pair<long long, int> > secik;
  for (auto& [val, id] : input) {
    ans[id] = suma(0, id).first;
    ustaw(id, val);
  }
  reverse(input.begin(), input.end());
  for (int i = 0; i < T + T; i++) ile[i] = tree[i] = 0;
  for (auto& [val, id] : input) {
    ans[id] += 1ll * suma(0, id).second * val;
    ustaw(id, val);
  }
  for (int i = 0; i < T + T; i++) ile[i] = tree[i] = 0;
  int prev_val = -1;
  int ile_wszyscy = 0;
  for (auto& [val, id] : input) {
    if (prev_val != -1) {
      ile_wszyscy += (prev_val - val);
      while ((int)secik.size()) {
        auto pom = *secik.begin();
        if (pom.first - ile_wszyscy <= 0) {
          secik.erase(pom);
          int ile_razy = tab[pom.second] / val;
          int nast = tab[pom.second] / (ile_razy + 1);
          secik.insert({val - nast + ile_wszyscy, pom.second});
          ustaw(pom.second, tab[pom.second], ile_razy);
        } else
          break;
      }
    }
    pair<long long, int> pom = suma(0, id);
    ans[id] += pom.first - 1ll * pom.second * val;
    ustaw(id, val, 1);
    secik.insert({val - val / 2 + ile_wszyscy, id});
    prev_val = val;
  }
  secik.clear();
  reverse(input.begin(), input.end());
  for (int i = 0; i < T + T; i++) tree[i] = ile[i] = 0;
  prev_val = -1;
  ile_wszyscy = 0;
  for (auto& [val, id] : input) {
    auto drzewo = suma(0, id);
    ans[id] += val * drzewo.second - drzewo.first;
    if (prev_val != -1) {
      ile_wszyscy += val - prev_val;
      while ((int)secik.size()) {
        auto pom = *secik.begin();
        if (pom.first - ile_wszyscy <= 0) {
          secik.erase(pom);
          int kiedy = tab[pom.second] - val % tab[pom.second];
          secik.insert({kiedy + ile_wszyscy, pom.second});
          ustaw(pom.second, tab[pom.second] * (val / tab[pom.second]));
        } else
          break;
      }
    }
    secik.insert({val + ile_wszyscy, id});
    ustaw(id, val);
    prev_val = val;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
    ans[i + 1] += ans[i];
  }
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test = 1;
  for (int i = 0; i < test; i++) solve();
}
