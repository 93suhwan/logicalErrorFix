#include <bits/stdc++.h>
using namespace std;
long long bigmod(long long l, long long r) {
  if (r == 0) return 1;
  unsigned long long res = bigmod(l, r / 2) % 1000000007;
  res = (res * res) % 1000000007;
  if (r & 1) res = (res * l) % 1000000007;
  return res;
}
long long arr[111];
long long sum;
void fun(long long i, long long j, long long k, long long n) {
  if (i == n) {
    sum += k;
    return;
  }
  if (i + 1 == n) {
    fun(i + 1, 0, k + arr[i] * pow(10, j), n);
    return;
  }
  fun(i + 1, 0, k + arr[i] * pow(10, j), n);
  fun(i + 1, j + 1, k + arr[i] * pow(10, j), n);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t, i, j, l, k, n, m, p, q;
  cin >> t;
  while (t--) {
    int x[3];
    cin >> x[0] >> x[1] >> x[2];
    p = 0;
    if (x[0] % 2) p += 1;
    if (x[1] % 2) p += 2;
    if (x[2] % 2) p += 3;
    cout << p % 2 << endl;
  }
  return 0;
}
