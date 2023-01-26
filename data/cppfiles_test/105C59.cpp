#include <bits/stdc++.h>
using namespace std;
const int N = 200050;
struct node {
  int f, g, h, id;
};
int a[N], b[N], m[N];
int x[N], y[N];
vector<node> les[200050];
map<int, int> mp;
bool cmp(node x, node y) {
  if (x.f == y.f) return x.g > y.g;
  return x.f < y.f;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    mp.clear();
    for (int i = 1; i <= n; i++) {
      vector<node>().swap(les[i]);
      x[i] = y[i] = 0;
    }
    int c = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i] >> m[i];
      if (mp.find(a[i] + b[i] - m[i]) == mp.end()) mp[a[i] + b[i] - m[i]] = ++c;
      if (m[i] > a[i]) {
        b[i] -= m[i] - a[i];
        y[i] = m[i] - a[i];
        m[i] = a[i];
      }
      if (m[i] > b[i]) {
        a[i] -= m[i] - b[i];
        x[i] = m[i] - b[i];
        m[i] = b[i];
      }
      les[mp[a[i] + b[i] - m[i]]].push_back({a[i], b[i], b[i] - m[i], i});
    }
    int cnt = 0;
    for (int i = 1; i <= c; i++) {
      sort(les[i].begin(), les[i].end(), cmp);
      int now = 1, idx = 0;
      y[les[i][0].id] += m[les[i][0].id];
      for (int j = 1, sz = les[i].size(); j < sz; j++) {
        if (les[i][idx].h <= les[i][j].g) {
          x[les[i][j].id] += les[i][j].f - les[i][idx].f;
          y[les[i][j].id] += les[i][j].g - les[i][idx].h;
          now++;
        } else {
          y[les[i][j].id] += m[les[i][j].id];
          cnt += now - 1;
          now = 1;
          idx = j;
        }
      }
      cnt += now - 1;
    }
    cout << n - cnt << '\n';
    for (int i = 1; i <= n; i++) {
      cout << x[i] << ' ' << y[i] << '\n';
    }
  }
  return 0;
}
