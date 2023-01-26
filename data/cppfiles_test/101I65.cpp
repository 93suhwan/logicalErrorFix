#include <bits/stdc++.h>
using namespace std;
void compress(map<int, int> &mp) {
  int pt = 1;
  for (auto &i : mp) {
    mp[i.first] = pt++;
  }
}
class BIT {
 private:
  vector<long long> tree;
  int n;
  int LSOne(int x) { return x & (-x); }

 public:
  BIT(int x) {
    n = x;
    tree.resize(n + 1);
  }
  long long sum(int a) {
    long long sum = 0;
    for (; a > 0; a -= LSOne(a)) sum += tree[a];
    return sum;
  }
  long long sum(int a, int b) { return sum(b) - (a == 1 ? 0 : sum(a - 1)); }
  void update(int p, long long v) {
    for (; p < n + 1; p += LSOne(p)) tree[p] += v;
  }
};
long long count(vector<vector<int> > &grp, vector<int> str, int tot) {
  long long ans = 0;
  BIT tree(tot + 1);
  for (int i = grp.size() - 1; i >= 0; i--) {
    for (auto v : grp[i]) {
      int added = 0;
      auto pt = lower_bound(str.begin(), str.end(), v);
      if (pt != str.end()) {
        int strval = *pt;
        if (strval > v) {
          ans += tree.sum(v, strval - 1);
          added += tree.sum(v, strval - 1);
        }
      }
      if (pt != str.begin() and (pt == str.end() or *pt != v)) {
        pt = prev(pt);
        int strval = *pt;
        if (strval < v) {
          ans += tree.sum(strval + 1, v);
          added += tree.sum(strval + 1, v);
        }
      }
    }
    for (auto v : grp[i]) tree.update(v, 1);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    map<int, int> x, y;
    vector<int> vertroad, horroad;
    unordered_set<int> xstr, ystr;
    for (int i = 0; i < (int)n; i++) {
      int temp;
      cin >> temp;
      x[temp] = 1;
      xstr.insert(temp);
      vertroad.push_back(temp);
    }
    vector<int> str;
    for (int i = 0; i < (int)m; i++) {
      int temp;
      cin >> temp;
      str.push_back(temp);
      y[temp] = 1;
      ystr.insert(temp);
      horroad.push_back(temp);
    }
    vector<array<int, 2> > pts(k);
    vector<int> xs, ys;
    for (int i = 0; i < (int)k; i++) {
      cin >> pts[i][0] >> pts[i][1];
      bool inx = xstr.count(pts[i][0]), iny = ystr.count(pts[i][1]);
      if (inx ^ iny) {
        if (inx)
          xs.push_back(i);
        else
          ys.push_back(i);
      }
      x[pts[i][0]] = y[pts[i][1]] = 1;
    }
    compress(x);
    compress(y);
    vector<vector<int> > grp(x.size());
    for (int i = 0; i < (int)k; i++) {
      pts[i][0] = x[pts[i][0]], pts[i][1] = y[pts[i][1]];
      grp[pts[i][0] - 1].push_back(pts[i][1]);
    }
    for (int i = 0; i < (int)vertroad.size(); i++) vertroad[i] = x[vertroad[i]];
    for (int i = 0; i < (int)horroad.size(); i++) horroad[i] = y[horroad[i]];
    long long ans = count(grp, horroad, y.size() + 1);
    grp.clear();
    grp.resize(y.size());
    for (int i = 0; i < (int)k; i++) grp[pts[i][1] - 1].push_back(pts[i][0]);
    ans += count(grp, vertroad, x.size() + 1);
    cout << ans << '\n';
  }
}
