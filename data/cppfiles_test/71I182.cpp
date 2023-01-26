#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> p;
int n, k;
pair<int, int> start, ool;
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
float trinary_search(int l, int r, float (*evaluator)(int)) {
  while (true) {
    if (r - l <= 3) {
      float res = std::numeric_limits<float>::infinity();
      for (int i = l; i <= r; i++) {
        res = min(res, evaluator(i));
      }
      return res;
    }
    int a = l + 1 * ((r - l) / 3);
    int b = l + 2 * ((r - l) / 3);
    float aev = evaluator(a), bev = evaluator(b);
    if (aev < bev) {
      r = b;
    } else {
      l = a;
    }
  }
}
float left_evaluator(int i) {
  float v = 0;
  v += 2 * dist(start, p[i]);
  v += dist(p.front(), start);
  v += dist(p.front(), ool);
  if (i != n - 2) {
    v += dist(ool, p[i + 1]);
    v += dist(p[i + 1], p.back());
  }
  return v;
}
float right_evaluator(int i) {
  float v = 0;
  v += 2 * dist(start, p[i]);
  v += dist(p.back(), start);
  v += dist(p.back(), ool);
  if (i != 0) {
    v += dist(ool, p[i - 1]);
    v += dist(p[i - 1], p.front());
  }
  return v;
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
  for (int i = 0; i < n; i++) {
    if (i == slref) continue;
    if (check_slope(p[slref], p[i]) != slope) {
      ool = p[i];
      assert(i != k - 1);
      swap(p[i], p.back());
      p.pop_back();
      break;
    }
  }
  sort(p.begin(), p.end());
  int startIdx =
      (int)distance(p.begin(), lower_bound(p.begin(), p.end(), start));
  float lval = trinary_search(startIdx, n - 2, left_evaluator);
  float rval = trinary_search(0, startIdx, right_evaluator);
  cout << setprecision(10) << min(lval, rval) << endl;
}
