#include <bits/stdc++.h>
using namespace std;
const int NR = 1e6 + 10;
const int mod = 998244353;
void Min(int& x, int y) { x = min(x, y); }
void Max(int& x, int y) { x = max(x, y); }
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int n, m, k;
int cnt[2][NR], now, all;
int ans[NR];
map<pair<int, int>, int> mp;
int a[NR], b[NR], op[NR];
int ksm(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * a * res % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  n = read(), m = read(), k = read();
  for (int i = 1; i <= k; i++) a[i] = read(), b[i] = read(), op[i] = read();
  now = n;
  for (int i = 1; i <= k; i++) {
    int x = a[i], y = b[i];
    if (op[i] == -1) {
      if (mp[make_pair(x, y)] != 0) {
        int t = mp[make_pair(x, y)];
        mp[make_pair(x, y)] = 0;
        if (t == -1) t = 0;
        if (!(y & 1)) t ^= 1;
        cnt[t][x]--;
        if (cnt[t][x] == 0 && cnt[t ^ 1][x] == 0)
          now++;
        else if (cnt[t][x] == 0 && cnt[t ^ 1][x])
          all--;
      }
    }
    if (op[i] == 0) {
      if (mp[make_pair(x, y)] != 0) {
        int t = mp[make_pair(x, y)];
        mp[make_pair(x, y)] = 0;
        if (t == -1) t = 0;
        if (!(y & 1)) t ^= 1;
        cnt[t][x]--;
        if (cnt[t][x] == 0 && cnt[t ^ 1][x] == 0)
          now++;
        else if (cnt[t][x] == 0 && cnt[t ^ 1][x])
          all--;
      }
      mp[make_pair(x, y)] = -1;
      int t = 0;
      if (!(y & 1)) t ^= 1;
      cnt[t][x]++;
      if (cnt[t][x] == 1 && cnt[t ^ 1][x] == 0)
        now--;
      else if (cnt[t][x] == 1 && cnt[t ^ 1][x])
        all++;
    }
    if (op[i] == 1) {
      if (mp[make_pair(x, y)] != 0) {
        int t = mp[make_pair(x, y)];
        mp[make_pair(x, y)] = 0;
        if (t == -1) t = 0;
        if (!(y & 1)) t ^= 1;
        cnt[t][x]--;
        if (cnt[t][x] == 0 && cnt[t ^ 1][x] == 0)
          now++;
        else if (cnt[t][x] == 0 && cnt[t ^ 1][x])
          all--;
      }
      mp[make_pair(x, y)] = 1;
      int t = 1;
      if (!(y & 1)) t ^= 1;
      cnt[t][x]++;
      if (cnt[t][x] == 1 && cnt[t ^ 1][x] == 0)
        now--;
      else if (cnt[t][x] == 1 && cnt[t ^ 1][x])
        all++;
    }
    ans[i] = (all) ? 0 : ksm(2, now);
  }
  now = m, all = 0;
  mp.clear();
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= k; i++) {
    int x = a[i], y = b[i];
    if (op[i] == -1) {
      if (mp[make_pair(x, y)] != 0) {
        int t = mp[make_pair(x, y)];
        mp[make_pair(x, y)] = 0;
        if (t == -1) t = 0;
        if (!(x & 1)) t ^= 1;
        cnt[t][y]--;
        if (cnt[t][y] == 0 && cnt[t ^ 1][y] == 0)
          now++;
        else if (cnt[t][y] == 0 && cnt[t ^ 1][y])
          all--;
      }
    }
    if (op[i] == 0) {
      if (mp[make_pair(x, y)] != 0) {
        int t = mp[make_pair(x, y)];
        mp[make_pair(x, y)] = 0;
        if (t == -1) t = 0;
        if (!(x & 1)) t ^= 1;
        cnt[t][y]--;
        if (cnt[t][y] == 0 && cnt[t ^ 1][y] == 0)
          now++;
        else if (cnt[t][y] == 0 && cnt[t ^ 1][y])
          all--;
      }
      mp[make_pair(x, y)] = -1;
      int t = 0;
      if (!(x & 1)) t ^= 1;
      cnt[t][y]++;
      if (cnt[t][y] == 1 && cnt[t ^ 1][y] == 0)
        now--;
      else if (cnt[t][y] == 1 && cnt[t ^ 1][y])
        all++;
    }
    if (op[i] == 1) {
      if (mp[make_pair(x, y)] != 0) {
        int t = mp[make_pair(x, y)];
        mp[make_pair(x, y)] = 0;
        if (t == -1) t = 0;
        if (!(x & 1)) t ^= 1;
        cnt[t][y]--;
        if (cnt[t][y] == 0 && cnt[t ^ 1][y] == 0)
          now++;
        else if (cnt[t][y] == 0 && cnt[t ^ 1][y])
          all--;
      }
      mp[make_pair(x, y)] = 1;
      int t = 1;
      if (!(x & 1)) t ^= 1;
      cnt[t][y]++;
      if (cnt[t][y] == 1 && cnt[t ^ 1][y] == 0)
        now--;
      else if (cnt[t][y] == 1 && cnt[t ^ 1][y])
        all++;
    }
    ans[i] = (ans[i] + ((all) ? 0 : ksm(2, now))) % mod;
  }
  mp.clear();
  int cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= k; i++) {
    int x = a[i], y = b[i];
    if (op[i] == -1) {
      if (mp[make_pair(x, y)]) {
        int t = (mp[make_pair(x, y)] == -1) ? 0 : 1;
        if (!(x & 1)) t ^= 1;
        if (!(y & 1)) t ^= 1;
        mp[make_pair(x, y)] = 0;
        if (t == 0)
          cnt1--;
        else
          cnt2--;
      }
    }
    if (op[i] == 0) {
      if (mp[make_pair(x, y)]) {
        int t = (mp[make_pair(x, y)] == -1) ? 0 : 1;
        if (!(x & 1)) t ^= 1;
        if (!(y & 1)) t ^= 1;
        mp[make_pair(x, y)] = 0;
        if (t == 0)
          cnt1--;
        else
          cnt2--;
      }
      int t = 0;
      if (!(x & 1)) t ^= 1;
      if (!(y & 1)) t ^= 1;
      mp[make_pair(x, y)] = -1;
      if (t == 0)
        cnt1++;
      else
        cnt2++;
    }
    if (op[i] == 1) {
      if (mp[make_pair(x, y)]) {
        int t = (mp[make_pair(x, y)] == -1) ? 0 : 1;
        if (!(x & 1)) t ^= 1;
        if (!(y & 1)) t ^= 1;
        mp[make_pair(x, y)] = 0;
        if (t == 0)
          cnt1--;
        else
          cnt2--;
      }
      int t = 1;
      if (!(x & 1)) t ^= 1;
      if (!(y & 1)) t ^= 1;
      mp[make_pair(x, y)] = 1;
      if (t == 0)
        cnt1++;
      else
        cnt2++;
    }
    if (!cnt1 && !cnt2)
      ans[i] -= 2;
    else if (!cnt1 || !cnt2)
      ans[i]--;
  }
  for (int i = 1; i <= k; i++) printf("%d\n", (ans[i] + mod) % mod);
  return 0;
}
