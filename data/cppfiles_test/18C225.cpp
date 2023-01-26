#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int n, k;
int st[N], en[N];
int mem[N];
int tot[N][N];
vector<int> sp;
vector<pair<int, int> > v;
int cost(int x, int y) {
  if (x >= y) return 0;
  int &ret = tot[x][y];
  if (ret != -1) return ret;
  ret = 0;
  for (int i = 0; i < k; i++) {
    int a = v[i].first, b = v[i].second, c = sp[x], d = sp[y];
    if (a > c) {
      swap(a, c);
      swap(b, d);
    }
    if (c < b && b < d) ret++;
  }
  ret += cost(x + 1, y - 1);
  return ret;
}
int go(int ind) {
  if (ind >= sp.size()) return 0;
  int &ret = mem[ind];
  if (ret != -1) return ret;
  ret = -(1 << 30);
  for (int en = ind + 1; en < sp.size(); en += 2) {
    int len = (en - ind + 1) / 2;
    ret = max(ret, cost(ind, en) + go(en + 1) + len * (len - 1) / 2);
  }
  return ret;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    memset(st, -1, sizeof st);
    memset(en, -1, sizeof en);
    memset(mem, -1, sizeof mem);
    sp.clear();
    v.clear();
    memset(tot, -1, sizeof tot);
    for (int i = 0; i < k; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      x--;
      y--;
      if (x > y) swap(x, y);
      st[x] = y;
      en[y] = x;
      v.push_back({x, y});
    }
    n *= 2;
    for (int i = 0; i < n; i++) {
      if (st[i] == -1 && en[i] == -1) sp.push_back(i);
    }
    for (int i = 0; i < sp.size() / 2; i++) {
      v.push_back({sp[i], sp[i + sp.size() / 2]});
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
      for (int j = i + 1; j < v.size(); j++) {
        if (v[j].first < v[i].second && v[i].second < v[j].second) ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
