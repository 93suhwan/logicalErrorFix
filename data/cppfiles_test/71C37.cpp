#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1000000007LL;
const int N = 2e5 + 10;
const long long Inf = 2242545357980376863LL;
const long long Log = 30;
pair<long long, long long> A[N];
int n, k;
vector<int> U;
void Check(int a, int b) {
  pair<long long, long long> V = pair<long long, long long>(
      A[a].first - A[b].first, A[a].second - A[b].second);
  vector<int> res = {a, b};
  for (int i = 0; i < n; i++) {
    if (i == a || i == b) continue;
    pair<long long, long long> V2 = pair<long long, long long>(
        A[a].first - A[i].first, A[a].second - A[i].second);
    if (V.first * V2.second == V.second * V2.first) res.push_back(i);
  }
  if (res.size() == n - 1) U = res;
}
long double dis(int i, int j) {
  return sqrt((A[i].first - A[j].first) * (A[i].first - A[j].first) +
              (A[i].second - A[j].second) * (A[i].second - A[j].second));
}
int mk[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  k--;
  for (int i = 0; i < n; i++) cin >> A[i].first >> A[i].second;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < i; j++) Check(i, j);
  sort(U.begin(), U.end(), [&](int i, int j) { return A[i] < A[j]; });
  cerr << "U.size()"
       << " : " << U.size() << '\n';
  for (auto c : U) mk[c] = 1;
  int nt = -1;
  for (int i = 0; i < n; i++)
    if (!mk[i]) nt = i;
  int idx = -1;
  for (int i = 0; i < n - 1; i++)
    if (U[i] == k) idx = i;
  long double al = dis(U[0], U[n - 2]);
  if (idx == -1) {
    long double ans = Inf;
    for (int i = 0; i < n - 1; i++)
      ans = min(ans,
                al + dis(k, U[i]) + min(dis(U[0], U[i]), dis(U[i], U[n - 2])));
    cout << fixed << setprecision(16) << ans << '\n';
    return 0;
  }
  long double ln = al + min(dis(U[0], k), dis(k, U[n - 2]));
  long double ans = Inf;
  ans = min(ans, al + dis(k, U[0]) + dis(U[n - 2], nt));
  ans = min(ans, al + dis(k, U[n - 2]) + dis(U[0], nt));
  ans = min(ans, dis(k, nt) + al + min(dis(nt, U[0]), dis(nt, U[n - 2])));
  if (idx != 0) {
    ans = min(ans, dis(k, U[n - 2]) + dis(U[n - 2], nt) + dis(nt, U[idx - 1]) +
                       dis(U[idx - 1], U[0]));
    ans = min(ans,
              al - dis(U[idx], U[idx - 1]) + dis(U[0], nt) + dis(U[n - 2], nt));
  }
  if (idx != n - 2) {
    ans = min(ans, dis(k, U[0]) + dis(U[0], nt) + dis(nt, U[idx + 1]) +
                       dis(U[idx + 1], U[n - 2]));
    ans = min(ans,
              al - dis(U[idx], U[idx + 1]) + dis(U[0], nt) + dis(U[n - 2], nt));
  }
  for (int i = idx + 1; i + 1 < n - 2; i++) {
    long double mn = min(dis(nt, U[i + 1]), dis(nt, U[n - 2]));
    ans =
        min(ans, dis(U[0], k) + al - dis(U[i], U[i + 1]) + dis(nt, U[i]) + mn);
    ans =
        min(ans, dis(k, U[i]) + al - dis(U[i], U[i + 1]) + dis(nt, U[0]) + mn);
  }
  for (int i = 1; i < idx; i++) {
    long double mn = min(dis(nt, U[i - 1]), dis(nt, U[0]));
    ans = min(ans,
              dis(U[n - 2], k) + al - dis(U[i], U[i - 1]) + dis(nt, U[i]) + mn);
    ans = min(ans,
              dis(k, U[i]) + al - dis(U[i], U[i - 1]) + dis(nt, U[n - 2]) + mn);
  }
  cout << fixed << setprecision(16) << ans << '\n';
  return 0;
}
