#include <bits/stdc++.h>
using namespace std;
inline double dist(pair<int, int>& a, pair<int, int>& b) {
  return sqrt(1LL * (a.first - b.first) * (a.first - b.first) +
              1LL * (a.second - b.second) * (a.second - b.second));
}
inline long long areaWithOrigin(pair<int, int>& a, pair<int, int>& b) {
  return 1LL * a.first * b.second - 1LL * a.second * b.first;
}
inline double bestRoute(vector<pair<int, int>>& firstSide,
                        vector<pair<int, int>>& secondSide,
                        pair<int, int> specialPoint,
                        pair<int, int> initialPoint) {
  double ans = 1e18;
  for (int i = 0; i < (int)firstSide.size(); i++) {
    pair<int, int> firstPoint = i == 0 ? initialPoint : firstSide[i - 1];
    pair<int, int> otherEnd =
        secondSide.empty() ? firstSide[i] : secondSide.back();
    ans = min(ans, dist(initialPoint, firstPoint) +
                       dist(firstPoint, specialPoint) +
                       min(dist(specialPoint, firstSide.back()),
                           dist(specialPoint, otherEnd)) +
                       dist(firstSide.back(), otherEnd));
  }
  double offset = firstSide.empty() ? 0 : dist(initialPoint, firstSide.back());
  initialPoint = firstSide.empty() ? initialPoint : firstSide.back();
  for (int i = 0; i < (int)secondSide.size(); i++) {
    pair<int, int> firstPoint = i == 0 ? initialPoint : secondSide[i - 1];
    ans = min(ans, offset + dist(initialPoint, firstPoint) +
                       dist(firstPoint, specialPoint) +
                       min(dist(specialPoint, secondSide.back()),
                           dist(specialPoint, secondSide[i])) +
                       dist(secondSide[i], secondSide.back()));
  }
  pair<int, int> lastPoint =
      secondSide.empty() ? initialPoint : secondSide.back();
  ans = min(ans, offset + dist(initialPoint, lastPoint) +
                     dist(lastPoint, specialPoint));
  return ans;
}
inline bool othersOnTheSameLine(int special, int n, long long totalArea,
                                vector<pair<int, int>>& points) {
  totalArea -= areaWithOrigin(points[special - 1], points[special]);
  totalArea -= areaWithOrigin(points[special], points[(special + 1) % n]);
  totalArea += areaWithOrigin(points[special - 1], points[(special + 1) % n]);
  return totalArea == 0;
}
void arrange(vector<pair<int, int>>& points, pair<int, int> reference) {
  sort(points.begin(), points.end());
  if (!points.empty() &&
      dist(points[0], reference) > dist(points.back(), reference)) {
    reverse(points.begin(), points.end());
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> points(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> points[i].first >> points[i].second;
  }
  int s = 1;
  long long totalArea = 0;
  points[0] = points[n];
  for (int i = 0; i < n; i++) {
    totalArea += areaWithOrigin(points[i], points[i + 1]);
  }
  while (!othersOnTheSameLine(s, n, totalArea, points)) {
    s++;
  }
  pair<int, int> specialPoint = points[s];
  int a = 1 + (s == 1), b = 1 + (s == 1);
  for (int i = 1; i <= n; i++) {
    if (i != s && points[i] < points[a]) {
      a = i;
    }
    if (i != s && points[i] > points[b]) {
      b = i;
    }
  }
  if (k == s) {
    cout << fixed << setprecision(9)
         << dist(points[a], points[b]) + min(dist(specialPoint, points[a]),
                                             dist(specialPoint, points[b]));
    return 0;
  }
  pair<int, int> initialPoint = points[k];
  vector<pair<int, int>> aSide, bSide;
  double toA = dist(initialPoint, points[a]),
         toB = dist(initialPoint, points[b]);
  for (int i = 1; i <= n; i++) {
    if (i != k && i != s) {
      if (fabs(dist(points[i], initialPoint) + dist(points[i], points[a]) -
               toA) < fabs(dist(points[i], initialPoint) +
                           dist(points[i], points[b]) - toB)) {
        aSide.push_back(points[i]);
      } else {
        bSide.push_back(points[i]);
      }
    }
  }
  arrange(aSide, initialPoint);
  arrange(bSide, initialPoint);
  cout << fixed << setprecision(9)
       << min(bestRoute(aSide, bSide, specialPoint, initialPoint),
              bestRoute(bSide, aSide, specialPoint, initialPoint));
  return 0;
}
