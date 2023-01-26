#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 99;
const int INF = 1e9 + 99;
int n, m;
vector<pair<int, int>> L[N], P[N];
vector<int> MINP[N];
vector<int> points;
int DP[2][N];
pair<int, int> findpoints(int a, int b) {
  int p, k, s;
  int w;
  p = 0;
  k = n - 1;
  while (p < k) {
    s = (p + k + 1) / 2;
    if (points[s] >= a)
      k = s - 1;
    else
      p = s;
  }
  w = p;
  if (points[p] >= a) w--;
  p = 0;
  k = n - 1;
  while (p < k) {
    s = (p + k) / 2;
    if (points[s] <= b)
      p = s + 1;
    else
      k = s;
  }
  if (points[p] <= b) p++;
  return {w, p};
}
void solve() {
  cin >> n >> m;
  for (int i = 0, a; i < n; i++) {
    cin >> a;
    points.push_back(a);
  }
  DP[0][0] = 0;
  sort(points.begin(), points.end());
  for (int i = 0, a, b; i < m; i++) {
    cin >> a >> b;
    pair<int, int> fin;
    fin = findpoints(a, b);
    if (fin.first != fin.second - 1) {
      i--;
      m--;
      continue;
    }
    if (fin.first != -1)
      P[fin.first].push_back({a, b});
    else
      DP[0][0] = max(DP[0][0], points[0] - b);
    if (fin.second != n) L[fin.second].push_back({a, b});
  }
  for (int i = 0; i < n; i++) {
    sort(L[i].begin(), L[i].end());
    sort(P[i].begin(), P[i].end());
    if (P[i].size() == 0) continue;
    MINP[i].resize(P[i].size());
    MINP[i][P[i].size() - 1] = P[i][P[i].size() - 1].second;
    for (int j = P[i].size() - 2; j >= 0; j--) {
      MINP[i][j] = min(MINP[i][j + 1], P[i][j].second);
    }
  }
  for (int i = 1; i <= P[0].size(); i++) {
    DP[0][i] = 2 * DP[0][0] + P[0][i - 1].first - points[0];
  }
  for (int i = 1; i < n; i++) {
    DP[i % 2][0] = DP[(i - 1) % 2][P[i - 1].size()];
    for (int j = 0; j < L[i].size(); j++) {
      DP[i % 2][0] =
          min(DP[i % 2][0], DP[(i - 1) % 2][j] + points[i] - MINP[i - 1][j]);
    }
    if (P[i].size()) {
      int l = P[i][0].first - points[i];
      DP[i % 2][1] = DP[(i + 1) % 2][P[i - 1].size()] + l;
      for (int j = 0; j < L[i].size(); j++) {
        DP[i % 2][1] =
            min(DP[i % 2][1],
                DP[(i - 1) % 2][j] + 2 * (points[i] - MINP[i - 1][j]) + l);
      }
    }
    for (int j = 2; j <= P[i].size(); j++) {
      DP[i % 2][j] = DP[i % 2][j - 1] + (P[i][j - 1].first - P[i][j - 2].first);
    }
  }
  cout << DP[(n - 1) % 2][P[n - 1].size()] << "\n";
  points.clear();
  for (int i = 0; i < n; i++) {
    L[i].clear();
    P[i].clear();
    MINP[i].clear();
  }
}
int main() {
  int Q;
  cin >> Q;
  while (Q--) {
    solve();
  }
}
