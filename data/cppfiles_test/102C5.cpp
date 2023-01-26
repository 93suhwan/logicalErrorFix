#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int k, A, h, m;
int a[1000] = {}, b[161616] = {}, cnt, f[10100], d[151515] = {},
    ans[111111] = {};
unordered_map<int, int> mp;
int fpw(int x, int k, int p) {
  int ret = 1;
  while (k) {
    if (k & 1) ret = 1ll * ret * x % p;
    x = 1ll * x * x % p;
    k >>= 1;
  }
  return ret;
}
int add(int x, int y) { return (x += y) >= mod ? x - mod : x; }
int Sum[1000100];
int solve(vector<int> &c, int len) {
  int sum = 0;
  for (int i = 1; i <= 2 * len; i++) {
    if (i & 1)
      sum = add(sum, 1ll * i * f[c[(i + 1) / 2]] % mod);
    else
      sum = add(sum, 1ll * i * f[a[k]] % mod);
  }
  if (!mp[add(sum, mod - h)]) return 0;
  int st = mp[add(sum, mod - h)] - 1;
  for (int i = 0; i < cnt; i++) {
    if (st >> i & 1) {
      Sum[d[i]]++;
    }
  }
  for (int i = 1; i <= len; i++) ans[i * 2 - 1] = c[i], ans[i * 2] = a[k];
  for (int i = 1; i <= len; i++) {
    if (Sum[c[i]]) {
      swap(ans[i * 2 - 1], ans[i * 2]);
      Sum[c[i]]--;
    }
  }
  return 1;
}
int check(vector<int> &c) {
  for (int i = k - 1; i >= 0; i--) {
    int p = (1 << (k - i));
    if (i == 0) p = (1 << (k - 1));
    if (c.size() - 1 < p) return 1;
    for (int l = 1, r = p; r < c.size(); l = r + 1, r += p) {
      int cnt = 0;
      for (int j = l; j <= r; j++) {
        if (c[j] == a[i]) {
          cnt++;
        }
      }
      if (cnt != 1) return 0;
    }
  }
  return 1;
}
void dfs(vector<int> &siz, vector<int> &c, int pos) {
  if (pos == m + 1) {
    if (!check(c)) return;
    if (solve(c, m)) {
      for (int i = 1; i <= 2 * m; i++) {
        printf("%d ", ans[i]);
      }
      exit(0);
    } else
      return;
  }
  for (int i = 0; i <= k - 1; i++) {
    if (siz[i]) {
      siz[i]--;
      c.push_back(a[i]);
      dfs(siz, c, pos + 1);
      c.pop_back();
      siz[i]++;
    }
  }
}
vector<int> siz;
int main() {
  mp.rehash((1 << 16) + 5);
  cin >> k >> A >> h;
  siz.resize(k + 1);
  m = (1 << (k - 1));
  if (k == 0) {
    if (h == A) {
      puts("1");
    } else
      puts("-1");
    return 0;
  }
  a[0] = 1;
  for (int i = 1; i <= k; i++) {
    a[i] = (1 << (i - 1)) + 1;
  }
  for (int i = 0; i <= (1 << (k - 1)) + 10; i++) f[i] = fpw(A, i, mod);
  b[cnt++] = add(f[a[k]], mod - f[1]);
  d[cnt - 1] = 1;
  for (int i = 1; i <= k - 1; i++) {
    for (int j = 1; j <= a[i] - 1; j++) {
      b[cnt++] = add(f[a[k]], mod - f[a[i]]);
      d[cnt - 1] = a[i];
    }
  }
  siz[0] = 1;
  for (int i = 1; i <= k - 1; i++) {
    siz[i] = (1 << (i - 1));
  }
  for (int j = 0; j < (1 << cnt); j++) {
    int sum = 0;
    for (int i = 0; i < cnt; i++) {
      if (j >> i & 1) {
        sum = add(sum, b[i]);
      }
    }
    mp[sum] = j + 1;
  }
  vector<int> c;
  c.clear();
  c.push_back(0);
  dfs(siz, c, 1);
  puts("-1");
  return 0;
}
