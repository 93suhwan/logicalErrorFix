#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline", "no-stack-protector", "unroll-loops")
using namespace std;
namespace io {
const int SIZE = (1 << 21) + 1;
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c,
                                       qu[55];
int f, qr;
inline void flush() {
  fwrite(obuf, 1, oS - obuf, stdout);
  oS = obuf;
}
inline void putc(char x) {
  *oS++ = x;
  if (oS == oT) flush();
}
template <class I>
inline void gi(I &x) {
  for (c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    ;
  for (x = 0; c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    x = (x << 1) + (x << 3) + (c & 15);
}
inline void gs(char *s, int n) {
  while (s[1] != '*' && s[1] != '/')
    s[1] = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                        (iS == iT ? EOF : *iS++))
                     : *iS++);
  for (int i = 2; i <= n; i++)
    s[i] = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                        (iS == iT ? EOF : *iS++))
                     : *iS++);
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_flusher_;
}  // namespace io
const int N = 1000005;
int val[N << 2], a[N], ans[N];
char s[N];
void update(int root, int l, int r, int L, int R, int t) {
  if (r < L || l > R) return;
  if (L <= l && r <= R) {
    val[root] = min(val[root], t);
    return;
  }
  update(root << 1, l, ((l + r) >> 1), L, R, t);
  update((root << 1) | 1, ((l + r) >> 1) + 1, r, L, R, t);
}
void pushdown(int root, int l, int r) {
  if (l == r) {
    ans[l] = val[root];
    return;
  }
  val[root << 1] = min(val[root << 1], val[root]);
  val[(root << 1) | 1] = min(val[(root << 1) | 1], val[root]);
  pushdown(root << 1, l, ((l + r) >> 1));
  pushdown((root << 1) | 1, ((l + r) >> 1) + 1, r);
}
int p[N], v[N], tot = 0;
bool notp[N];
void getp() {
  for (int i = 2; i <= 1000000; i++) {
    if (!notp[i]) p[++tot] = i, v[i] = i;
    for (int j = 1; i * p[j] <= 1000000 && j <= tot; j++) {
      notp[i * p[j]] = true, v[i * p[j]] = p[j];
      if (i % p[j] == 0) break;
    }
  }
}
vector<pair<int, int> > num[N];
int mn[20][N], sum[N], Log[N];
void buildST(int x) {
  int m = num[x].size();
  for (int i = 1; i <= m; i++)
    sum[i] = num[x][i - 1].first, sum[i] += sum[i - 1];
  for (int i = 1; i <= m; i++) mn[0][i] = num[x][i - 1].first;
  for (int j = 1; j <= Log[m]; j++)
    for (int i = 1; i + (1 << j) - 1 <= m; i++)
      mn[j][i] = min(mn[j - 1][i], sum[i + (1 << (j - 1)) - 1] - sum[i - 1] +
                                       mn[j - 1][i + (1 << (j - 1))]);
}
int main() {
  memset(val, 0x3f, sizeof(val));
  int n;
  scanf("%d", &n);
  getp();
  for (int i = 2; i <= n; i++) Log[i] = Log[i >> 1] + 1;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    while (a[i] != 1) {
      int t = v[a[i]], c = 0;
      while (a[i] % t == 0) a[i] /= t, c++;
      num[t].emplace_back(make_pair(s[i] == '*' ? c : -c, i));
    }
  }
  for (int i = 2; i <= 1000000; i++)
    if (num[i].size()) {
      buildST(i);
      int m = num[i].size();
      for (int j = 1; j <= m; j++) {
        int pos = j, add = 0, ed, lst;
        for (int k = Log[m]; k >= 0; k--)
          if (pos + (1 << k) - 1 <= m && add + mn[k][pos] >= 0)
            add += sum[pos + (1 << k) - 1] - sum[pos - 1], pos += (1 << k);
        if (pos - 1 == m)
          ed = n;
        else
          ed = num[i][pos - 1].second - 1;
        if (j == 1)
          lst = 1;
        else
          lst = num[i][j - 2].second + 1;
        update(1, 1, n, lst, num[i][j - 1].second, ed);
      }
    }
  pushdown(1, 1, n);
  long long Ans = 0;
  for (int i = 1; i <= n; i++)
    if (s[i] == '/' && a[i] != 1)
      continue;
    else
      Ans += min(n, ans[i]) - i + 1;
  printf("%lld", Ans);
  return 0;
}
