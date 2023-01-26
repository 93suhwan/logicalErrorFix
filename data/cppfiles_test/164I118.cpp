#include <bits/stdc++.h>
long getbit(long first, long second) { return ((first >> second) & 1); }
using namespace std;
const long N = 2e5 + 5;
long cnt, n, k, l[N], r[N], h[N];
char c[N];
string s;
vector<long> so;
bool dd[N], Next[N];
void tao(long u, long pa) {
  h[u] = h[pa] + 1;
  if (l[u] != 0) tao(l[u], u);
  s += c[u];
  so.push_back(u);
  if (r[u] != 0) tao(r[u], u);
}
void dfs(long u, long last) {
  if (l[u] != 0) {
    if (Next[l[u]] && cnt + h[l[u]] - h[last] <= k) {
      dd[l[u]] = 1;
      cnt += h[l[u]] - h[last];
      last = u;
      dfs(l[u], l[u]);
    }
  }
  if (r[u] != 0) {
    if ((last == u || Next[u]) && cnt + h[u] - h[last] <= k) {
      dd[u] = 1;
      cnt += h[u] - h[last];
      dfs(r[u], u);
    }
  }
}
void dfs1(long u) {
  if (l[u] != 0) {
    dfs1(l[u]);
    dd[u] |= dd[l[u]];
  }
  if (r[u] != 0) {
    dfs1(r[u]);
    dd[u] |= dd[r[u]];
  }
}
void tao1(long u) {
  if (l[u] != 0) tao1(l[u]);
  if (dd[u])
    s += c[u], s += c[u];
  else
    s += c[u];
  if (r[u] != 0) tao1(r[u]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (long i = 1; i <= n; i++) cin >> c[i];
  for (long i = 1; i <= n; i++) cin >> l[i] >> r[i];
  s = "";
  tao(1, 0);
  for (long i = (long)s.size() - 1; i >= 0; i--)
    if (i == (long)s.size() - 1)
      Next[so[i]] = 0;
    else if (s[i] < s[i + 1])
      Next[so[i]] = 1;
    else if (s[i] == s[i + 1])
      Next[so[i]] = Next[so[i + 1]];
    else
      Next[so[i]] = 0;
  dfs(1, 0);
  dfs1(1);
  s = "";
  tao1(1);
  cout << s << '\n';
  return 0;
}
