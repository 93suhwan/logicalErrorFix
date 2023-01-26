#include <bits/stdc++.h>
#pragma GCC optimize(2, 3, "Ofast")
using namespace std;
template <typename T1, typename T2>
void ckmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
void ckmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void print(T x, char let) {
  print(x), putchar(let);
}
mt19937 rng(1919810);
const int N = 1005;
vector<int> a, o, e;
int b[N], _[N], n;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    b[i] = _[i] = read();
    if (b[i] & 1)
      o.push_back(i);
    else
      e.push_back(i);
  }
  sort(_ + 1, _ + n + 1);
  for (int i = 2; i <= n; i++) {
    if (_[i - 1] == _[i]) {
      a.push_back(_[i] / 2);
      a.push_back((_[i] + 1) / 2);
      for (int j = 1; j <= n; j++) {
        if (j == i - 1 || j == i) continue;
        a.push_back(_[j] - a[0]);
      }
      puts("YES");
      for (auto v : a) printf("%d ", v);
      puts("");
      return 0;
    }
  }
  if ((int(e.size())) >= 3) {
    int x = b[e[0]], y = b[e[1]], z = b[e[2]];
    int sum = (x + y + z) / 2;
    a.push_back(sum - x);
    a.push_back(sum - y);
    a.push_back(sum - z);
    for (int i = 3; i <= (int(e.size())) - 1; i++) a.push_back(b[e[i]] - a[0]);
    for (int i = 0; i <= (int(o.size())) - 1; i++) a.push_back(b[o[i]] - a[0]);
    puts("YES");
    for (auto v : a) printf("%d ", v);
    puts("");
    return 0;
  }
  if ((int(o.size())) >= 2 && (int(e.size())) >= 1) {
    int x = b[o[0]], y = b[o[1]], z = b[e[0]];
    int sum = (x + y + z) / 2;
    a.push_back(sum - x);
    a.push_back(sum - y);
    a.push_back(sum - z);
    for (int i = 1; i <= (int(e.size())) - 1; i++) a.push_back(b[e[i]] - a[0]);
    for (int i = 2; i <= (int(o.size())) - 1; i++) a.push_back(b[o[i]] - a[0]);
    puts("YES");
    for (auto v : a) printf("%d ", v);
    puts("");
    return 0;
  }
  int len = (int(o.size()));
  vector<int> finda, findb;
  vector<int> vis(len);
  bool flag = false;
  for (int nums = min(40, len - 1); nums >= 2; nums--) {
    map<int, vector<int>> mp;
    int times = 30000;
    while (times--) {
      int t = nums;
      vector<int> chose;
      int csum = 0;
      while (t--) {
        int x;
        while (vis[x = rng() % len])
          ;
        vis[x] = 1;
        chose.push_back(x);
        csum += b[o[x]];
      }
      sort(chose.begin(), chose.end());
      for (auto v : chose) vis[v] = 0;
      if (mp.count(csum) && mp[csum] != chose) {
        finda = mp[csum];
        findb = chose;
        flag = true;
        goto end;
      }
      mp[csum] = chose;
    }
  }
end:;
  if (flag == false) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (auto v : finda) vis[v]++;
  for (auto v : findb) vis[v]++;
  vector<int> big, big1, big2;
  for (auto v : finda)
    if (vis[v] == 1) big1.push_back(v);
  for (auto v : findb)
    if (vis[v] == 1) big2.push_back(v);
  for (int i = 0; i < (int(big1.size())); i++)
    big.push_back(o[big1[i]]), big.push_back(o[big2[i]]);
  a.push_back(0);
  int las = 0;
  for (int i = 0; i < (int(big.size())) - 1; i++)
    a.push_back(las = b[big[i]] - las);
  for (int i = 0; i < (int(o.size())); i++)
    if (vis[i] != 1) a.push_back(b[o[i]]);
  for (auto v : e) a.push_back(b[e[v]]);
  for (auto v : a) printf("%d ", v);
  puts("");
  return 0;
}
