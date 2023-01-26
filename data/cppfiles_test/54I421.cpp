#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 5, M = 1e9 + 7, OO = 0x3f3f3f3f;
long long t, n, k, cm;
long long nCr[N];
long long mem[N][2];
long long power(long long a, long long b, long long m) {
  if (!b) return 1;
  long long t = power(a, b >> 1, m) % m;
  return ((t * t) % m * (b & 1 ? a : 1) % m) % m;
}
long long modinv(long long x) { return power(x, M - 2, M); }
void calc() {
  nCr[0] = 1;
  nCr[1] = n;
  nCr[2] = (n * (n - 1)) / 2;
  for (int i = 3; i <= n; ++i) {
    nCr[i] = (((n - i + 1) * nCr[i - 1]) % M * modinv(i)) % M;
  }
}
long long solve(long long idx, bool gr) {
  if (idx == k) return 1;
  if (mem[idx][gr] != -1) return mem[idx][gr];
  long long op1 = 0, op2 = 0;
  if (gr == 1) {
    op1 = (solve(idx + 1, gr) * power(2, n, M)) % M;
  } else {
    op1 = (solve(idx + 1, gr) * cm) % M;
    if (n % 2 == 0)
      op2 = solve(idx + 1, 1);
    else
      op2 = 1;
  }
  return mem[idx][gr] = (op1 + op2) % M;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    if (k == 0) {
      cout << 1 << endl;
      continue;
    }
    calc();
    cm = 0;
    if (n % 2 == 0) {
      for (int i = 0; i <= n - 2; i += 2) {
        cm = (cm + nCr[i]) % M;
      }
    } else {
      for (int i = 0; i <= n - 1; i += 2) {
        cm = (cm + nCr[i]) % M;
      }
    }
    for (int i = 0; i < k; ++i) mem[i][0] = mem[i][1] = -1;
    long long ans = solve(0, 0);
    cout << ans << endl;
  }
}
