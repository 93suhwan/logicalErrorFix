#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<pair<double, double> > vp;
bool cmp(const pair<double, int>& a, const pair<double, int>& b) {
  return a.first < b.first;
}
int main() {
  double pig = 4 * atan(1);
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    pair<double, double> p;
    cin >> p.first >> p.second;
    if (p.first == 0 and p.second == 0)
      --K;
    else
      vp.push_back(p);
  }
  double rm = 0, rM = 1000000;
  while (abs(rM - rm) > 0.00001) {
    double r = (rM + rm) / 2;
    vector<bool> used(vp.size() + 1, false);
    vector<pair<double, int> > v;
    for (int i = 0; i < vp.size(); ++i) {
      pair<double, double> p = vp[i];
      double x = p.first, y = p.second;
      double phi = atan2(y, x), d = sqrt(x * x + y * y);
      if ((d / 2) > r) continue;
      double alpha = acos((d / 2) / r);
      double phi1 = phi - alpha, phi2 = phi + alpha;
      while (phi1 < 0) phi1 += 2 * pig;
      while (phi1 >= 2 * pig) phi2 -= 2 * pig;
      while (phi2 < 0) phi2 += 2 * pig;
      while (phi2 >= 2 * pig) phi2 -= 2 * pig;
      v.push_back(make_pair(phi1, i + 1));
      v.push_back(make_pair(phi2, -i - 1));
    }
    sort(v.begin(), v.end(), cmp);
    int count = 0, sol = 0;
    for (int i = 0; i < 2; ++i) {
      for (pair<double, int>& p : v) {
        if (p.second < 0 && used[-p.second]) {
          used[-p.second] = false;
          count -= 1;
        } else if (p.second > 0 && !used[p.second]) {
          used[p.second] = true;
          count += 1;
        }
        sol = max(sol, count);
      }
    }
    if (sol >= K)
      rM = r;
    else
      rm = r;
  }
  cout << (rm + rM) / 2 << endl;
}
