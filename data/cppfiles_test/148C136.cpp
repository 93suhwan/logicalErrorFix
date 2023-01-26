#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int w, h;
  cin >> w >> h;
  long long int area = 0;
  long long int u, d, l, r, base;
  cin >> d;
  vector<long long int> vd(d);
  for (long long int i = 0; i < d; i++) {
    cin >> vd[i];
  }
  cin >> u;
  vector<long long int> vu(u);
  for (long long int i = 0; i < u; i++) {
    cin >> vu[i];
  }
  cin >> l;
  vector<long long int> vl(l);
  for (long long int i = 0; i < l; i++) {
    cin >> vl[i];
  }
  cin >> r;
  vector<long long int> vr(r);
  for (long long int i = 0; i < r; i++) {
    cin >> vr[i];
  }
  if (u == 1)
    area = max(area, h * (vd.back() - vd[0]));
  else if (d == 1)
    area = max(area, h * (vu.back() - vu[0]));
  else {
    base = max((vd.back() - vd[0]), (vu.back() - vu[0]));
    area = max(area, h * base);
  }
  if (l == 1)
    area = max(area, w * (vr.back() - vr[0]));
  else if (r == 1)
    area = max(area, w * (vl.back() - vl[0]));
  else {
    base = max((vr.back() - vr[0]), (vl.back() - vl[0]));
    area = max(area, w * base);
  }
  cout << area << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
