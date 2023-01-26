#include <bits/stdc++.h>
using namespace std;
long long int dx[] = {0, 1, 0, -1};
long long int dy[] = {1, 0, -1, 0};
long long int dxx[] = {0, 1, 0, -1, 1, 1, -1, -1};
long long int dyy[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int mxx = 600005;
unordered_map<int, int> mp;
int bit[mxx];
long long int dp[mxx][2];
long long int inf = 5e15 + 2;
long long int savemin[mxx];
long long int savemax[mxx];
void add(int n) {
  while (n <= 600000) {
    bit[n] += 1;
    n += n & -n;
  }
}
int run(int n) {
  int sum = 0;
  while (n > 0) {
    sum += bit[n];
    n -= n & -n;
  }
  return sum;
}
void solve() {
  int n;
  int m;
  scanf("%d%d", &n, &m);
  mp.clear();
  for (int i = 1; i <= n + 2 * m + 2; i++) {
    bit[i] = 0;
    dp[i][0] = dp[i][1] = inf;
  }
  long long int a, b;
  vector<long long int> points, v;
  vector<pair<long long int, long long int> > seg, fseg;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a);
    v.push_back(a);
    points.push_back(a);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%lld%lld", &a, &b);
    v.push_back(a);
    v.push_back(b);
    seg.push_back({a, b});
  }
  sort(v.begin(), v.end());
  int sum = 0;
  for (auto it : v) {
    if (mp[it] == 0) mp[it] = ++sum;
  }
  for (auto it : points) {
    add(mp[it]);
  }
  sort(seg.begin(), seg.end());
  for (auto it : seg) {
    int x = mp[it.first] - 1;
    int y = mp[it.second];
    if (run(y) - run(x) == 0) {
      fseg.push_back({it});
    }
  }
  points.push_back(-inf);
  points.push_back(inf);
  sort(points.begin(), points.end());
  int sz = points.size();
  int N = fseg.size();
  int start = 0;
  long long int ans = inf;
  dp[0][1] = dp[0][1] = 0ll;
  for (int i = 1; i < sz; i++) {
    vector<pair<long long int, long long int> > st;
    while (start < N) {
      pair<long long int, long long int> x = fseg[start];
      if (x.first < points[i] and x.first > points[i - 1] and
          x.second < points[i]) {
        st.push_back(x);
      } else
        break;
      start++;
    }
    reverse(st.begin(), st.end());
    long long int Mxx = points[i];
    for (int ttt = 0; ttt < st.size(); ttt++) {
      long long int coast = st[ttt].first - points[i - 1];
      long long int x = min(dp[i - 1][0] + coast * 2, coast + dp[i - 1][1]);
      dp[i][0] = min(dp[i][0], x);
      dp[i][1] = min(dp[i][1], x + points[i] - Mxx);
      Mxx = min(Mxx, st[ttt].second);
    }
    long long int x = points[i] - Mxx + min(dp[i - 1][0], dp[i - 1][1]);
    dp[i][0] = min(dp[i][0], x);
    dp[i][1] = min(dp[i][1], x + points[i] - Mxx);
  }
  printf("%lld\n", dp[sz - 1][1]);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
