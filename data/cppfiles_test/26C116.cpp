#include <bits/stdc++.h>
using namespace std;
const int Inf = (int)2e9 + 5;
const long long Lnf = (long long)2e18 + 5;
const int N = 5e5 + 5;
const int NN = 1e6 + 5;
const int M = 1e9 + 7;
int fact[N];
inline int mul(int a, int b, int mod) { return (long long)a * b % mod; }
int solve() {
  fact[0] = 1;
  fact[1] = 1;
  fact[2] = 1;
  for (int i = 3; i < N; i++) {
    fact[i] = mul(fact[i - 1], i, M);
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    n *= 2;
    int ans = fact[n];
    cout << ans << endl;
  }
  return 0;
}
int main(void) { solve(); }
