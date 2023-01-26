#include <bits/stdc++.h>
using namespace std;
int T, N, M;
int n;
int A[90005];
int C[90005];
int D[305][305];
vector<int> V;
void Fill(int l, int r) {
  V.clear();
  int b = l;
  for (int i = l; i <= r; i++) {
    if (i == r || i % M == M - 1) {
      for (int j = i; j >= b; j--) V.push_back(j);
      b = i + 1;
    }
  }
}
int Insert(int id) {
  int r = id / M, c = id % M;
  int rt = 0;
  for (int i = 0; i <= c - 1; i++) rt += D[r][i];
  D[r][c]++;
  return rt;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N >> M;
    n = N * M;
    vector<pair<int, int> > P;
    for (int i = 0; i <= n - 1; i++) {
      cin >> A[i];
      D[i / M][i % M] = 0;
      P.push_back(make_pair(A[i], i));
    }
    sort(P.begin(), P.end());
    int b = 0;
    for (int i = 0; i <= n - 1; i++) {
      int x = P[i].first;
      if (i == n - 1 || x != P[i + 1].first) {
        Fill(b, i);
        for (int j = b; j <= i; j++) C[P[j].second] = V[j - b];
        b = i + 1;
      }
    }
    int ans = 0;
    for (int i = 0; i <= n - 1; i++) {
      ans += Insert(C[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}
