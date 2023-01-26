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
  double rm = 0, rM = 0;
  for (pair<double, double>& p : vp)
    rM = max(rM, p.first * p.first + p.second * p.second);
  while (abs(rM - rm) > 0.00001) {
    double r = (rM + rm) / 2;
    vector<pair<double, int> > v;
    for (pair<double, double>& p : vp) {
      double x = p.first, y = p.second;
      double phi = atan2(y, x), d = sqrt(x * x + y * y);
      if ((d / 2) > r) continue;
      double alpha = acos((d / 2) / r);
      double phi1 = phi - alpha, phi2 = phi + alpha;
      while (phi1 < 0) phi1 += 2 * pig;
      while (phi2 >= 2 * pig) phi2 -= 2 * pig;
      v.push_back(make_pair(phi - alpha, 1));
      v.push_back(make_pair(phi + alpha, -1));
    }
    sort(v.begin(), v.end(), cmp);
    int count = 0, sol = 0;
    for (pair<double, int>& p : v) {
      count = max(0, count + p.second);
      sol = max(sol, count);
    }
    for (pair<double, int>& p : v) {
      count = max(0, count + p.second);
      sol = max(sol, count);
    }
    if (sol >= K)
      rM = r;
    else
      rm = r;
  }
  cout << (rm + rM) / 2 << endl;
}
