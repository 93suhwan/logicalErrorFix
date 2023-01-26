#include <bits/stdc++.h>
using namespace std;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
using ftype = double;
struct pt {
  long long x, y;
  pt(long long x = 0, long long y = 0) : x(x), y(y) {}
  ftype dist() const { return hypotl(x, y); }
  pt operator-(const pt &o) const { return pt(x - o.x, y - o.y); }
  long long cross(const pt &o) const { return x * o.y - y * o.x; }
  long long dot(const pt &o) const { return x * o.x + y * o.y; }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  k--;
  vector<pt> p(n);
  for (int i = (0); i < (n); i++) cin >> p[i].x >> p[i].y;
  int a = 0, b = 1;
  int cnt = 0;
  for (int i = (0); i < (n); i++) {
    if ((p[i] - p[a]).cross(p[b] - p[a]) == 0) {
      cnt++;
    }
  }
  if (cnt < n - 1) b = 2;
  vector<int> ve1, ve2;
  for (int i = (0); i < (n); i++) {
    if ((p[i] - p[a]).cross(p[b] - p[a]) != 0) {
      ve1.push_back(i);
    } else {
      ve2.push_back(i);
    }
  }
  assert(((int)(ve1).size()) <= 1);
  sort((ve2).begin(), (ve2).end(),
       [&](int i, int j) { return (p[i] - p[j]).dot(p[b] - p[a]) < 0; });
  vector<int> v;
  ftype ans = DBL_MAX;
  for (int j = (1); j < (((int)(ve2).size())); j++) {
    v.clear();
    if (!ve1.empty()) v.push_back(ve1[0]);
    v.push_back(k);
    v.push_back(ve2[0]);
    v.push_back(ve2[((int)(ve2).size()) - 1]);
    v.push_back(ve2[j]);
    v.push_back(ve2[j - 1]);
    sort((v).begin(), (v).end());
    v.erase(unique((v).begin(), (v).end()), v.end());
    do {
      if (v[0] != k) continue;
      ftype dist = 0;
      bool ok1 = false, ok2 = false;
      for (int i = (1); i < (((int)(v).size())); i++) {
        if ((v[i] == ve2[0] && v[i - 1] == ve2[j - 1]) ||
            (v[i] == ve2[j - 1] && v[i - 1] == ve2[0]))
          ok1 = true;
        if ((v[i] == ve2.back() && v[i - 1] == ve2[j]) ||
            (v[i] == ve2[j] && v[i - 1] == ve2.back()))
          ok2 = true;
        dist += (p[v[i]] - p[v[i - 1]]).dist();
      }
      if (ok1 && ok2 && dist < ans) ans = dist;
    } while (next_permutation((v).begin(), (v).end()));
  }
  cout << fixed << setprecision(8) << ans << '\n';
}
