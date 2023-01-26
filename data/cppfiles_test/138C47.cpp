#include <bits/stdc++.h>
using namespace std;
long long get() {
  char c = getchar();
  long long x = 0LL;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    x *= 10LL;
    x += (c - '0');
    c = getchar();
  }
  return x;
}
string i_t_s(int x) {
  string t = "";
  while (x) {
    t += x % 10 + '0';
    x /= 10;
  }
  reverse(t.begin(), t.end());
  return t;
}
int s_t_i(string t) {
  int x = 0;
  for (int i = 0; i < (int)(t.size()); i++) {
    x = x * 10 + (t[i] - '0');
  }
  return x;
}
long long q_p(long long x, long long y) {
  long long res = 1;
  x %= 1000000007;
  while (y) {
    if (y % 2) {
      res = res * x;
      res %= 1000000007;
    }
    y /= 2;
    x = x * x;
    x %= 1000000007;
  }
  return res;
}
bool ok(int x, int y, int n, int m) {
  return (x >= 0 && x < n && y >= 0 && y < m);
}
bool isprime(int x) {
  if (x < 2) return false;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
int n, m, q;
long long a[400001], b[400001], c[400001];
struct wenti {
  long long k, id;
} p[400001];
bool cmp(wenti x, wenti y) { return x.k < y.k; }
int fa[400001];
int find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
}
long long prv[400001], cnt[400001], ans[400001];
set<pair<long long, pair<int, int> > > s;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);
  int r = 0, now = 0;
  for (int i = 0; i < n; i++) {
    while (r < m && b[r] < a[i]) {
      c[now++] = b[r++];
    }
    c[now] = a[i];
    cnt[now++] = 1;
  }
  while (r < m) c[now++] = b[r++];
  for (int i = 0; i < n + m; i++) fa[i] = i;
  prv[0] = c[0];
  for (int i = 1; i < n + m; i++) prv[i] = prv[i - 1] + c[i];
  for (int i = 0; i < n + m - 1; i++)
    s.insert(make_pair(c[i + 1] - c[i], make_pair(i, i + 1)));
  for (int i = 0; i < q; i++) {
    cin >> p[i].k;
    p[i].id = i;
  }
  sort(p, p + q, cmp);
  long long sum = 0;
  for (int i = 0; i < n; i++) sum += a[i];
  for (int i = 0; i < q; i++) {
    int add = p[i].k;
    while (!s.empty()) {
      pair<int, pair<int, int> > pp = *s.begin();
      if (pp.first <= add) {
        int x = pp.second.first, y = pp.second.second;
        x = find(x);
        y = find(y);
        fa[x] = y;
        if (cnt[x]) {
          sum -= prv[x] - prv[x - cnt[x]];
          sum -= prv[y] - prv[y - cnt[y]];
          cnt[y] += cnt[x];
          cnt[x] = 0;
          sum += prv[y] - prv[y - cnt[y]];
        }
        s.erase(s.begin());
      } else
        break;
    }
    ans[p[i].id] = sum;
  }
  for (int i = 0; i < q; i++) cout << ans[i] << "\n";
  return 0;
}
