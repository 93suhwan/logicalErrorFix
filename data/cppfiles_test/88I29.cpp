#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
const long long oo = 1e18 + 7, mod = 1e9 + 7;
long long n, m, a[N];
vector<long long> vc;
struct cmp {
  bool operator()(const pair<long long, long long>& a,
                  const pair<long long, long long>& b) {
    if (a.first != b.first)
      return a.first > b.first;
    else
      return a.second < b.second;
  }
};
set<pair<long long, long long>, cmp> see[N], see2[N];
map<long long, long long> mp;
long long bit[305][305];
void init() {
  vc.clear();
  for (long long i = 1; i <= n * m; i++) {
    see[i].clear();
    see2[i].clear();
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) bit[i][j] = 0;
  }
  mp.clear();
}
void upd(long long id, long long pos) {
  for (; pos <= m; pos += pos & -pos) bit[id][pos]++;
}
long long get(long long id, long long pos) {
  long long ans = 0;
  for (; pos; pos -= pos & -pos) ans += bit[id][pos];
  return ans;
}
void process() {
  cin >> n >> m;
  init();
  for (long long i = 1; i <= n * m; i++) {
    long long x;
    cin >> x;
    a[i] = x;
    vc.push_back(x);
  }
  sort(vc.begin(), vc.end());
  long long cnt = 1;
  for (long long i = 1; i <= n * m; i++) {
    see[cnt].insert({((i - 1) % m) + 1, ((i - 1) / m) + 1});
    if ((i == n * m) || vc[i] != vc[i - 1]) {
      mp[vc[i - 1]] = cnt;
      cnt++;
    }
  }
  cnt--;
  for (long long i = 1; i <= cnt; i++) {
    long long mx = -1;
    for (auto it : see[i]) mx = max(mx, it.second);
    for (auto it : see[i]) {
      if (it.second == mx) {
        see2[i].insert(it);
      }
    }
    for (auto it : see2[i]) see[i].erase(it);
  }
  long long ans = 0;
  for (long long i = 1; i <= n * m; i++) {
    pair<long long, long long> temp;
    if (see[mp[a[i]]].size()) {
      temp = (*see[mp[a[i]]].begin());
      see[mp[a[i]]].erase(temp);
    } else {
      temp = (*see2[mp[a[i]]].begin());
      see2[mp[a[i]]].erase(temp);
    }
    ans += get(temp.second, temp.first - 1);
    upd(temp.second, temp.first);
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  long long t;
  cin >> t;
  while (t--) process();
}
