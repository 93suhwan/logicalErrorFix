#include <bits/stdc++.h>
#pragma GCC optimize("O2,unroll-loops")
using namespace std;
const int inf = 1000000010;
const long long INF = 1000000000000001000LL;
const int mod = 1000000007;
const int N = 1010;
int n, m, k, u, v, x, y, t, a, b, ans;
int A[N][N];
void Solve(int l, int r, int val) {
  if (r <= l) return;
  for (int i = l; i <= r; i++)
    for (int j = i + 1; j <= r; j++) A[i][j] = val;
  vector<int> shit(k, (r - l + 1) / k);
  for (int i = 0; i < ((r - l + 1) % k); i++) shit[i]++;
  for (int i = 0; i < k; i++) {
    Solve(l, l + shit[i] - 1, val - 1);
    l += shit[i];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  int shit = 1;
  while (shit < n) {
    shit *= k;
    ans++;
  }
  Solve(1, n, ans);
  cout << ans << "\n";
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) cout << A[i][j] << " ";
  cout << "\n";
  return 0;
}
