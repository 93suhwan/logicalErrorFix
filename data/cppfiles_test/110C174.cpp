#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 5e5 + 10;
const long long MOD = 998244353;
const long long MAXnum = 2e5;
const long double eps = 1e-8;
const long double inf = 1e20;
const long double PI = acos(-1);
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
inline void print(long long x) {
  if (x < 0) putchar('-'), x = x;
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
struct Edge {
  long long to, w, next;
} edges[MAXN];
long long head[MAXN], cnt = 0;
void add(long long u, long long v, long long w) {
  edges[++cnt].w = w;
  edges[cnt].to = v;
  edges[cnt].next = head[u];
  head[u] = cnt;
}
long long ind[MAXN];
priority_queue<long long, vector<long long>, greater<long long> > que, que2;
long long temp[MAXN];
void solve() {
  while (!que.empty()) que.pop();
  while (!que2.empty()) que2.pop();
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    ind[i] = 0;
    head[i] = 0;
  }
  cnt = 0;
  for (long long i = 1; i <= n; i++) {
    long long k = 0;
    cin >> k;
    for (long long j = 0; j < k; j++) cin >> temp[j];
    sort(temp, temp + k);
    for (long long j = 0; j < k; j++) {
      long long v = temp[j];
      add(v, i, 1);
      ind[i]++;
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (ind[i] == 0) {
      que.push(i);
    }
  }
  long long cntt = 0, now = 0, ans = 1;
  while (!que.empty() || !que2.empty()) {
    if (que.empty()) {
      while (!que2.empty()) {
        long long x = que2.top();
        que2.pop();
        que.push(x);
      }
      ans++;
    }
    long long x = que.top();
    que.pop();
    now = x;
    cntt++;
    for (long long i = head[x]; i; i = edges[i].next) {
      long long v = edges[i].to;
      ind[v]--;
      if (ind[v] == 0) {
        if (v > now)
          que.push(v);
        else
          que2.push(v);
      }
    }
  }
  if (cntt != n) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
