#include <bits/stdc++.h>
#pragma GCC optimize("O2,unroll-loops")
using namespace std;
const int inf = 1000000010;
const long long INF = 1000000000000001000LL;
const int mod = 1000000007;
const int MAXN = 300010, LOG = 20;
int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], B[30];
void Main() {
  memset(B, 0, sizeof(B));
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    for (int j = 0; j < 30; j++)
      if (A[i] & (1 << j)) B[j]++;
  }
  for (int i = 1; i <= n; i++) {
    int ok = 1;
    for (int j = 0; j < 30; j++)
      if (B[j] % i) ok = 0;
    if (ok) cout << i << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) Main();
  return 0;
}
