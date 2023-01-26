#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
const long long N = 2e5 + 5;
vector<pair<long long, long long>> G[N];
long long getMax(long long n) {
  long long color[n];
  memset(color, (-1), sizeof(color));
  long long ans = 0, cnt[2] = {};
  for (long long(i) = (0); (i) < (n); (i)++) {
    if (color[i] == -1) {
      color[i] = 0;
      memset(cnt, (0), sizeof(cnt));
      cnt[0]++;
      queue<long long> q;
      q.push(i);
      while (!q.empty()) {
        long long cur = q.front();
        q.pop();
        for (auto v : G[cur]) {
          if (color[v.first] == -1) {
            if (v.second)
              color[v.first] = 1 - color[cur];
            else
              color[v.first] = color[cur];
            q.push(v.first);
            cnt[color[v.first]]++;
          } else if (!(v.second ^ (color[v.first] == color[cur]))) {
            return -1;
          }
        }
      }
      ans += max(cnt[0], cnt[1]);
    }
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long T = 1;
  cin >> T;
  for (long long(t) = (1); (t) < (T + 1); (t)++) {
    long long n, m;
    cin >> n >> m;
    for (long long(i) = (0); (i) < (N); (i)++) G[i].clear();
    long long a, b;
    string s;
    for (long long(i) = (0); (i) < (m); (i)++) {
      cin >> a >> b >> s;
      if (s[0] == 'c') {
        G[a - 1].push_back({b - 1, 0});
        G[b - 1].push_back({a - 1, 0});
      } else {
        G[a - 1].push_back({b - 1, 1});
        G[b - 1].push_back({a - 1, 1});
      }
    }
    cout << getMax(n) << "\n";
  }
  return 0;
}
