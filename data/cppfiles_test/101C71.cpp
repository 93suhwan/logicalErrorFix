#include <bits/stdc++.h>
const int N = 1e6 + 10;
const int M = 1e6;
using namespace std;
long long n, m, t, k;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
long long vertical[N], horizontal[N], sum = 0, v[N];
struct node {
  long long x, y;
} a[N];
long long cmp1(node x, node y) { return x.x < y.x; }
long long cmp2(node x, node y) { return x.y < y.y; }
long long ANS = 0;
signed main() {
  t = read();
  while (t--) {
    n = read(), m = read(), k = read();
    ANS = 0;
    for (long long i = 1; i <= n; i++) vertical[i] = read();
    for (long long i = 1; i <= m; i++) horizontal[i] = read();
    for (long long i = 1; i <= k; i++) {
      a[i].x = read(), a[i].y = read();
    }
    sort(a + 1, a + k + 1, cmp1);
    long long fst = 1;
    for (long long i = 1; i <= k; i) {
      set<long long> ans;
      ans.clear();
      while (a[i].x < vertical[fst] && i <= k) {
        ans.insert(a[i].y);
        sum++;
        v[a[i].y]++;
        i++;
      }
      while (a[i].x == vertical[fst]) i++;
      fst++;
      for (auto a : ans) {
        ANS += (v[a]) * (sum -= v[a]);
        v[a] = 0;
      }
    }
    fst = 1;
    sort(a + 1, a + k + 1, cmp2);
    for (long long i = 1; i <= k; i) {
      set<long long> ans;
      ans.clear();
      while (a[i].y < horizontal[fst] && i <= k) {
        ans.insert(a[i].x);
        v[a[i].x]++;
        i++;
        sum++;
      }
      while (a[i].y == horizontal[fst]) i++;
      fst++;
      for (auto a : ans) {
        ANS += (v[a]) * (sum -= v[a]);
        v[a] = 0;
      }
    }
    cout << ANS << endl;
  }
  return 0;
}
