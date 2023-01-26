#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 9;
const int N = 2e5 + 99;
int n, m;
vector<long long> points;
vector<pair<long long, long long>> P[N], PP[N];
vector<long long> DP[N];
long long fin(long long a, long long b) {
  int p = 1;
  int k = n + 1;
  int s;
  while (p < k) {
    s = (p + k) / 2;
    if (points[s] < a)
      p = s + 1;
    else
      k = s;
  }
  if (points[p - 1] < a && b < points[p]) return p - 1;
  return -1;
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    points.push_back(a);
  }
  points.push_back(INF);
  points.push_back(-INF);
  sort(points.begin(), points.end());
  for (int i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    long long poz = fin(a, b);
    if (poz == -1) continue;
    PP[poz].push_back({a, b});
  }
  for (int i = 0; i < n + 9; i++) {
    if (PP[i].empty()) continue;
    sort(PP[i].begin(), PP[i].end());
    P[i].push_back(PP[i][0]);
    for (int j = 1; j < PP[i].size(); j++) {
      while (P[i].size() && PP[i][j].second <= P[i][P[i].size() - 1].second)
        P[i].pop_back();
      P[i].push_back(PP[i][j]);
    }
  }
  DP[1].resize(P[1].size() + 1);
  DP[1][0] = 0;
  if (P[0].size()) DP[1][0] = points[1] - P[0][0].second;
  for (int j = 0; j < P[1].size(); j++)
    DP[1][j + 1] = min(2 * DP[1][0] + (P[1][j].first - points[1]),
                       DP[1][0] + 2 * (P[1][j].first - points[1]));
  for (int i = 2; i <= n; i++) {
    DP[i].resize(P[i].size() + 1);
    DP[i][0] = DP[i - 1][DP[i - 1].size() - 1];
    for (int j = 0; j < P[i - 1].size(); j++)
      DP[i][0] = min(DP[i][0], DP[i - 1][j] + (points[i] - P[i - 1][j].second));
    long long L1 = DP[i - 1][DP[i - 1].size() - 1];
    long long L2 = DP[i - 1][DP[i - 1].size() - 1];
    for (int j = 0; j < P[i - 1].size(); j++) {
      L1 = min(L1, DP[i - 1][j] + 2 * (points[i] - P[i - 1][j].second));
      L2 = min(L2, DP[i - 1][j] + points[i] - P[i - 1][j].second);
    }
    for (int j = 0; j < P[i].size(); j++)
      DP[i][j + 1] = min(L1 + (P[i][j].first - points[i]),
                         L2 + 2 * (P[i][j].first - points[i]));
  }
  cout << DP[n][DP[n].size() - 1] << "\n";
  points.clear();
  for (int i = 0; i < n + 9; i++) {
    P[i].clear();
    PP[i].clear();
    DP[i].clear();
  }
}
int main() {
  int Q;
  cin >> Q;
  while (Q--) {
    solve();
  }
}
