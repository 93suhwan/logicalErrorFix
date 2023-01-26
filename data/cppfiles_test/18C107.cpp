#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
long long ksm(long long a, long long n, long long mod) {
  long long t = 1;
  for (; n; n >>= 1, (a *= a) %= mod)
    if (n & 1) (t *= a) %= mod;
  return t;
}
map<int, int> mp;
vector<pair<int, int> > edge;
vector<int> v;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    int res = 0;
    mp.clear();
    edge.clear();
    v.clear();
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
      int x, y;
      cin >> x >> y;
      mp[x] = y, mp[y] = x;
      edge.push_back({min(x, y), max(x, y)});
    }
    for (int i = 1; i <= 2 * n; i++) {
      if (!mp[i]) {
        v.push_back(i);
      }
    }
    for (int i = 0; i < v.size() / 2; i++) {
      mp[i] = i + v.size() / 2, mp[i + v.size() / 2] = i;
      edge.push_back({v[i], v[i + v.size() / 2]});
    }
    sort(edge.begin(), edge.end());
    for (int i = 0; i < edge.size(); i++) {
      int x = edge[i].first, y = edge[i].second;
      for (int j = i + 1; j < edge.size(); j++) {
        int u = edge[j].first, v = edge[j].second;
        if (u < y && u > x && v > y) res++;
      }
    }
    cout << res << endl;
  }
  return 0;
}
