#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 21, M = 4e7;
int n, a[N], pr[N];
bool Prime[N];
int p[N >> 3], tot;
void xxs(int x) {
  for (int i = (2); i <= (x); ++i) {
    if (!Prime[i]) p[++tot] = i, pr[i] = i;
    for (int j = 1; j <= tot && p[j] * i <= x; j++) {
      Prime[p[j] * i] = 1, pr[p[j] * i] = p[j];
      if (i % p[j] == 0) break;
    }
  }
}
int ns[N], tg[N];
void Add(int x, int L, int R, int l, int r, int W) {
  if (l <= L && R <= r) return tg[x] = min(tg[x], W), void();
  int mid = (L + R) >> 1;
  if (l <= mid) Add(x << 1, L, mid, l, r, W);
  if (r > mid) Add(x << 1 | 1, mid + 1, R, l, r, W);
}
void Push(int x, int L, int R) {
  if (L == R) return ns[L] = tg[x], void();
  int mid = (L + R) >> 1;
  tg[x << 1] = min(tg[x << 1], tg[x]);
  tg[x << 1 | 1] = min(tg[x << 1 | 1], tg[x]);
  Push(x << 1, L, mid);
  Push(x << 1 | 1, mid + 1, R);
}
vector<int> pos[N], c[N];
char s[N];
int Pr[M];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(tg, 0x3f, sizeof(tg));
  cin >> n;
  for (int i = (1); i <= (n); ++i) cin >> a[i];
  cin >> (s + 1);
  xxs(1000000);
  for (int i = (1); i <= (n); ++i) {
    int t = a[i];
    while (t > 1) {
      int r = pr[t], cnt = 0;
      while (t % r == 0) t /= r, cnt += 1;
      pos[r].push_back(i);
      if (s[i] == '*')
        c[r].push_back(cnt);
      else
        c[r].push_back(-cnt);
    }
  }
  memset(Pr, 0x3f, sizeof(Pr));
  for (int x = (1); x <= (1000000); ++x) {
    if (!((int)(pos[x]).size())) continue;
    int pn = ((int)(pos[x]).size());
    int sum = 2e7;
    for (int i = (pn - 1); i >= (0); --i) {
      int vr = pn - 1;
      Pr[sum] = min(Pr[sum], i - 1);
      sum += c[x][i];
      for (int t = (sum + 1); t <= (sum + 20); ++t) vr = min(vr, Pr[t]);
      if (vr < pn - 1)
        Add(1, 1, n, (i == 0 ? 1 : pos[x][i - 1] + 1), pos[x][i],
            pos[x][vr + 1] - 1);
    }
    sum = 2e7;
    for (int i = (pn - 1); i >= (0); --i) Pr[sum] = 1e9, sum += c[x][i];
  }
  Push(1, 1, n);
  long long ret = 0;
  for (int i = (1); i <= (n); ++i) ret += min(ns[i], n) - i + 1;
  cout << ret << '\n';
  return 0;
}
