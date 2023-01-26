#include <bits/stdc++.h>
using namespace std;
bool sgn[4][1000000];
int prv[4][1000000];
int p[1000000];
pair<int, int> put(pair<int, int> pr, int x) {
  if (pr.first <= x) return make_pair(x, pr.second);
  if (pr.second <= x) return make_pair(pr.first, x);
  return make_pair(INT32_MAX, INT32_MAX);
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  vector<pair<int, int> > ps, ps_tmp;
  ps.emplace_back(INT32_MIN, INT32_MIN);
  for (int i = 0; i < n; i++) {
    int pidx = 0;
    for (auto& pr : ps) {
      pair<int, int> rp = put(pr, p[i]);
      if (rp.first != INT32_MAX) {
        bool ok = false;
        int j = 0;
        for (auto& pt : ps_tmp) {
          if (pt.first >= rp.first && pt.second >= rp.second) {
            pt = rp;
            ok = true;
            prv[j][i] = pidx;
            sgn[j][i] = true;
            break;
          }
          if (pt.first <= rp.first && pt.second <= rp.second) {
            ok = true;
            break;
          }
          j++;
          assert(j < 4);
        }
        if (!ok) {
          prv[j][i] = pidx;
          sgn[j][i] = true;
          ps_tmp.push_back(rp);
        }
      }
      rp = put(pr, -p[i]);
      if (rp.first != INT32_MAX) {
        bool ok = false;
        int j = 0;
        for (auto& pt : ps_tmp) {
          if (pt.first >= rp.first && pt.second >= rp.second) {
            pt = rp;
            ok = true;
            prv[j][i] = pidx;
            sgn[j][i] = false;
            break;
          }
          if (pt.first <= rp.first && pt.second <= rp.second) {
            ok = true;
            break;
          }
          j++;
          assert(j < 4);
        }
        if (!ok) {
          prv[j][i] = pidx;
          sgn[j][i] = false;
          ps_tmp.push_back(rp);
        }
      }
      pidx++;
    }
    swap(ps, ps_tmp);
    ps_tmp.clear();
    if (ps.empty()) {
      cout << "NO\n";
      return;
    }
  }
  int j = 0;
  int i = n - 1;
  while (i >= 0) {
    if (!sgn[j][i]) p[i] = -p[i];
    j = prv[j][i];
    i--;
  }
  cout << "YES\n";
  for (i = 0; i < n; i++) {
    cout << p[i] << " ";
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  int ncases;
  cin >> ncases;
  for (int i = 1; i <= ncases; i++) {
    solve();
  }
  cout.flush();
  return 0;
}
