#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> p;
int n, k;
pair<int, int> start, ool;
int startIdx = -5;
float check_slope(pair<int, int>& a, pair<int, int>& b) {
  int xd = b.first - a.first;
  if (xd == 0) return std::numeric_limits<float>::infinity();
  int yd = b.second - a.second;
  return (float)yd / (float)xd;
}
float dist(pair<int, int>& a, pair<int, int>& b) {
  return sqrtf(powf((float)(a.first - b.first), 2) +
               powf((float)(a.second - b.second), 2));
}
float e_ival(int l, int r) {
  if (r < l) return 0;
  if (l <= startIdx && startIdx <= r) {
    float rl = dist(start, p[l]) + dist(p[l], p[r]) + dist(p[r], ool);
    float rr = dist(start, p[r]) + dist(p[r], p[l]) + dist(p[l], ool);
    return min(rl, rr);
  } else {
    return dist(p[l], p[r]) + min(dist(p[l], ool), dist(p[r], ool));
  }
}
int main() {
  cin >> n >> k;
  p.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  start = p[k - 1];
  float slope;
  int slref;
  for (int i = 0; i < 4; i++) {
    slope = check_slope(p[i], p[(i + 1) % 4]);
    if (slope == check_slope(p[(i + 1) % 4], p[(i + 2) % 4])) {
      slref = i;
      break;
    }
  }
  bool sool = false;
  for (int i = 0; i < n; i++) {
    if (i == slref) continue;
    if (check_slope(p[slref], p[i]) != slope) {
      ool = p[i];
      sool = i == k - 1;
      swap(p[i], p.back());
      p.pop_back();
      break;
    }
  }
  sort(p.begin(), p.end());
  if (sool) {
    cout << setprecision(10) << e_ival(0, n - 2) << endl;
    return 0;
  }
  startIdx = (int)distance(p.begin(), lower_bound(p.begin(), p.end(), start));
  float res = std::numeric_limits<float>::infinity();
  for (int i = -1; i <= n - 2; i++) {
    float v = e_ival(0, i) + e_ival(i + 1, n - 2);
    res = min(res, v);
  }
  cout << setprecision(10) << res << endl;
}
