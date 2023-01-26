#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct node {
  int x, y, pos;
  bool operator<(const node &t) const { return x < t.x; }
};
int a[N], b[N], m[N], n, t, ind;
int xx[N], yy[N];
vector<int> v[N];
int mp[N * 10];
int sol(int x) {
  vector<node> line;
  for (auto k : v[x]) {
    line.push_back({a[k] - min(a[k], m[k]), a[k] - max(0, m[k] - b[k]), k});
  }
  sort(line.begin(), line.end());
  int res = 1;
  int i = 0, j = 1, st = line[0].x, ed = line[0].y;
  for (; i < line.size() && j < line.size();) {
    auto t = line[i], k = line[j];
    if (ed >= k.x) {
      st = k.x;
      ed = min(ed, k.y);
      j++;
    } else {
      while (i < j) {
        xx[line[i].pos] = a[line[i].pos] - st;
        yy[line[i].pos] = m[line[i].pos] - xx[line[i].pos];
        i++;
      }
      st = line[j].x;
      ed = line[j].y;
      res++;
    }
  }
  while (i < j) {
    xx[line[i].pos] = a[line[i].pos] - st;
    yy[line[i].pos] = m[line[i].pos] - xx[line[i].pos];
    i++;
  }
  return res;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    ind = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d %d %d", &a[i], &b[i], &m[i]);
      int x = a[i] + b[i] - m[i];
      if (!mp[x]) mp[x] = ++ind;
      v[mp[x]].push_back(i);
    }
    int res = 0;
    for (int i = 1; i <= ind; i++) {
      res += sol(i);
      v[i].clear();
    }
    cout << res << '\n';
    for (int i = 1; i <= n; i++) {
      printf("%d %d\n", xx[i], yy[i]);
      int x = a[i] + b[i] - m[i];
      mp[x] = 0;
    }
  }
}
