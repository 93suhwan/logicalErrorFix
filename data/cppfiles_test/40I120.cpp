#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000007;
const double eps = 1e-6;
const long long Inf = 1LL << 62;
const long long mod = 1000000007;
const long long pnum = 5761460;
void solve_with_case(int cas) {}
void solve_without_case() {
  long long x;
  cin >> x;
  long long arr[2][x];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < x; j++) {
      cin >> arr[i][j];
    }
  }
  long long c1[x], c2[x], c3[x], mx = -1, p = -1;
  memset(c1, 0, sizeof(c1));
  memset(c2, 0, sizeof(c2));
  memset(c3, 0, sizeof(c3));
  c1[0] = arr[0][0];
  c2[0] = arr[1][0];
  for (int i = (1); i <= (x - 1); i++) c1[i] = arr[0][i] + c1[i - 1];
  for (int i = (1); i <= (x - 1); i++) c2[i] = arr[1][i] + c2[i - 1];
  for (int i = 0; i < x; i++) {
    c3[i] = c1[i] + c2[x - 1];
    if (i - 1 > 0) {
      c3[i] -= c2[i - 1];
    }
    if (c3[i] > mx) {
      mx = c3[i];
      p = i;
    }
  }
  for (int i = 0; i <= p; i++) {
    arr[0][i] = 0;
  }
  for (int i = p; i < x; i++) {
    arr[1][i] = 0;
  }
  c1[0] = arr[0][0];
  c2[0] = arr[1][0];
  for (int i = (1); i <= (x - 1); i++) c1[i] = arr[0][i] + c1[i - 1];
  for (int i = (1); i <= (x - 1); i++) c2[i] = arr[1][i] + c2[i - 1];
  memset(c3, 0, sizeof(c3));
  mx = -1;
  for (int i = 0; i < x; i++) {
    c3[i] = c1[i] + c2[x - 1];
    if (i - 1 > 0) {
      c3[i] -= c2[i - 1];
    }
    if (c3[i] > mx) {
      mx = c3[i];
    }
  }
  cout << mx << "\n";
  ;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t, cas = 0;
  cin >> t;
  while (t--) {
    solve_without_case();
  }
  return 0;
}
