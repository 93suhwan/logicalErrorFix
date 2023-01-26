#include <bits/stdc++.h>
using namespace std;
long long N = 2 * 1e5 + 5;
vector<vector<long long>> bitz(31, vector<long long>(N));
void pre_compute() {
  for (long long i = 0; i < 31; i++) {
    long long set_bit = 1 << i;
    long long ctr = 0;
    for (long long j = 0; j < N; j++) {
      if (j & set_bit) ctr += 1;
      bitz[i][j] = ctr;
    }
  }
}
void c_p_c() {
  clock_t begin = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void c_p_c2() {
  clock_t begin = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void solve() {
  long long l, r;
  cin >> l >> r;
  long long len = 0;
  for (long long i = 0; i < 31; i++) {
    len = max(len, bitz[i][r] - bitz[i][l - 1]);
  }
  long long ans = r - l + 1 - len;
  cout << ans << '\n';
}
int32_t main() {
  c_p_c();
  pre_compute();
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }
  c_p_c2();
}
