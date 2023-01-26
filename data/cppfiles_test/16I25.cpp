#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
bool cmp(vector<int> a, vector<int> b) {
  int sum = 0;
  for (int i = 1; i < 6; i++)
    if (a[i] < b[i]) sum++;
  if (sum >= 3)
    return 1;
  else
    return 0;
}
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> score(n, vector<int>(6, 0));
  for (int i = 0; i < n; i++) {
    score[i][0] = i + 1;
    for (int j = 1; j < 6; j++) {
      cin >> score[i][j];
    }
  }
  sort(score.begin(), score.end(), cmp);
  for (int i = 2; i < n; i++) {
    int sum = 0;
    for (int j = 1; j < 6; j++) {
      if (score[0][j] < score[i][j]) sum++;
    }
    if (sum < 3) {
      cout << -1 << endl;
      return;
    }
  }
  cout << score[0][0] << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
