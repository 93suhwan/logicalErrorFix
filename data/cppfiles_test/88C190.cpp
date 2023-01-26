#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
long long t, n, m, ans[305][305], bit[305];
pair<long long, long long> a[100005];
vector<long long> g[100005];
map<long long, long long> viz;
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first == b.first) {
    return a.second > b.second;
  } else
    return a.first < b.first;
}
long long change1(long long pos) {
  pos--;
  long long x = pos / m;
  return x + 1;
}
long long change2(long long pos) {
  long long x = pos % m;
  if (x == 0) {
    x = m;
  }
  return x;
}
void update(long long pos, long long val) {
  for (; pos <= m; pos += pos & (-pos)) {
    bit[pos] += val;
  }
}
long long query(long long pos) {
  long long rs = 0;
  for (; pos; pos -= pos & (-pos)) {
    rs += bit[pos];
  }
  return rs;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    viz.clear();
    vector<long long> compres;
    for (long long i = 1; i <= n * m; i++) {
      cin >> a[i].first;
      compres.push_back(a[i].first);
      a[i].second = i;
    }
    sort(compres.begin(), compres.end());
    long long indx = 0;
    for (long long i = 0; i < compres.size(); i++) {
      if (i == 0 || compres[i] != compres[i - 1]) {
        viz[compres[i]] = ++indx;
      }
    }
    for (long long i = 1; i <= n * m; i++) {
      a[i].first = viz[a[i].first];
    }
    sort(a + 1, a + n * m + 1, cmp);
    for (long long i = 1; i <= n * m; i++) {
      g[a[i].first].push_back(a[i].second);
    }
    for (long long i = 1; i <= n * m; i++) {
      ans[change1(i)][change2(i)] = a[i].first;
    }
    for (long long i = 1; i <= n; i++) {
      for (long long j = m; j >= 1; j--) {
        long long x = ans[i][j];
        ans[i][j] = g[x].back();
        g[x].pop_back();
      }
    }
    long long res = 0;
    for (long long i = 1; i <= n; i++) {
      map<long long, long long> mm;
      vector<long long> v;
      for (long long j = 1; j <= m; j++) {
        v.push_back(ans[i][j]);
      }
      sort(v.begin(), v.end());
      for (long long j = 0; j < v.size(); j++) {
        mm[v[j]] = j + 1;
      }
      for (long long j = 1; j <= m; j++) {
        ans[i][j] = mm[ans[i][j]];
      }
    }
    for (long long i = 1; i <= n; i++) {
      for (long long j = 0; j <= m; j++) {
        bit[j] = 0;
      }
      for (long long j = 1; j <= m; j++) {
        res += query(ans[i][j]);
        update(ans[i][j], 1ll);
      }
    }
    cout << res << '\n';
  }
}
