#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize(2)
using namespace std;
inline long long read() {
  char c = getchar();
  long long first = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar())
    first = (first << 1) + (first << 3) + (c ^ 48);
  if (f) first = -first;
  return first;
}
const long long all = (1ll << 45) - 1;
long long n, k, vis[45], F[45];
map<long long, long long> t;
vector<long long> s[15];
signed main() {
  n = read(), k = read();
  s[1].push_back(0);
  F[0] = 0;
  for (long long i = n; i >= 1; i--) F[i] = F[i - 1] + (1 << (i - 1));
  sort(F, F + n + 1);
  if (n == 1) return puts("ACCEPTED"), 0;
  for (long long w = 1; w <= k; w++) {
    long long p = read();
    vector<long long> v;
    long long cnt = 0;
    t.clear();
    for (long long i = 1; i <= p; i++) {
      long long first = read();
      if (!vis[first]) vis[first] = 1, cnt++;
      v.push_back(first);
    }
    for (const long long &first : s[w]) {
      long long res = 0, X = first;
      for (long long i = 0; i < v.size(); i++)
        if (first & (1ll << (v[i] - 1))) res++, X &= all ^ (1ll << (v[i] - 1));
      for (long long i = v.size() - res; i < v.size(); i++)
        X |= (1ll << (v[i] - 1));
      s[w + 1].push_back(X);
      for (long long i = (long long)(v.size()) - res - 1, k = 1; k <= cnt;
           k++, i--) {
        X |= (1ll << (v[i] - 1));
        s[w + 1].push_back(X);
      }
    }
  }
  long long f = 0;
  for (long long i = 1; i <= n; i++)
    if (!vis[i]) f = 1;
  for (const long long &first : s[k + 1]) {
    long long tl = 0, tr = n, p;
    while (tl <= tr) {
      long long Mid = (tl + tr) >> 1;
      if (F[Mid] >= first)
        p = Mid, tr = Mid - 1;
      else
        tl = Mid + 1;
    }
    if (F[p] != first) f = 0;
  }
  if (f)
    puts("REJECTED");
  else
    puts("ACCEPTED");
  return 0;
}
