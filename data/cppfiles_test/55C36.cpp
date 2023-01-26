#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
pair<int, int> seg[8 * N], lazy[8 * N];
void build(int l, int u, int i) {
  lazy[i] = {3 * N, -1};
  seg[i] = {0, -1};
  if (l == u) return;
  build(l, ((l + u) / 2), (i * 2 + 1));
  build(((l + u) / 2) + 1, u, (i * 2 + 2));
}
void lazup(int l, int u, int i) {
  if (lazy[i].first == 3 * N) return;
  seg[i] = min(seg[i], lazy[i]);
  if (l != u) {
    lazy[(i * 2 + 1)] = min(lazy[(i * 2 + 1)], lazy[i]);
    lazy[(i * 2 + 2)] = min(lazy[(i * 2 + 2)], lazy[i]);
  }
  lazy[i] = {3 * N, -1};
}
pair<int, int> query(int l, int u, int i, int ll, int uu) {
  lazup(l, u, i);
  if (l >= ll && u <= uu) {
    return seg[i];
  }
  if (l > uu || u < ll) return {3 * N, -1};
  return min(query(l, ((l + u) / 2), (i * 2 + 1), ll, uu),
             query(((l + u) / 2) + 1, u, (i * 2 + 2), ll, uu));
}
pair<int, int> update(int l, int u, int i, int ll, int uu, pair<int, int> &x) {
  lazup(l, u, i);
  if (l >= ll && u <= uu) {
    lazy[i] = x;
    lazup(l, u, i);
    return seg[i];
  }
  if (l > uu || u < ll) return seg[i];
  return seg[i] = min(update(l, ((l + u) / 2), (i * 2 + 1), ll, uu, x),
                      update(((l + u) / 2) + 1, u, (i * 2 + 2), ll, uu, x));
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> r[n];
  map<int, int> mp;
  set<int> s;
  for (int i = 0; i < m; i++) {
    int x, ll, rr;
    cin >> x >> ll >> rr;
    r[x - 1].push_back({ll, rr});
    s.insert(ll);
    s.insert(rr);
  }
  int c = 0;
  for (int x : s) {
    mp[x] = c++;
  }
  int oset = 0;
  int dp[n], prev[n];
  build(0, c - 1, 0);
  int ans = n, curr = -1;
  for (int i = 0; i < n; i++) {
    dp[i] = i;
    prev[i] = -1;
    for (pair<int, int> k : r[i]) {
      pair<int, int> lol = query(0, c - 1, 0, mp[k.first], mp[k.second]);
      if ((lol.first + oset) < dp[i]) {
        dp[i] = lol.first + oset;
        prev[i] = lol.second;
      }
    }
    pair<int, int> x = {dp[i] - (oset + 1), i};
    for (pair<int, int> k : r[i]) {
      update(0, c - 1, 0, mp[k.first], mp[k.second], x);
    }
    ans = min(ans, dp[i] + (n - i - 1));
    if (ans == (dp[i] + n - i - 1)) curr = i;
    oset++;
  }
  cout << ans << endl;
  int currind = n - 1;
  while (currind >= 0) {
    while (currind > curr) {
      cout << (currind + 1) << " ";
      currind--;
    }
    if (curr == -1)
      currind = -1;
    else {
      curr = prev[curr];
      currind--;
    }
  }
}
