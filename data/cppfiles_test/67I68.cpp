#include <bits/stdc++.h>
using namespace std;
long long cmb(long long n, long long k) {
  if (k == 3) {
    return 1LL * n * (n - 1) * (n - 2) / 6;
  }
  if (k == 2) {
    return 1LL * n * (n - 1) / 2;
  }
  if (k == 1) {
    return 1LL * n;
  }
  return 0;
}
double check(int chosen, int n) {
  long long total = cmb(n, 3);
  long long all3 = cmb(chosen, 3);
  long long all2 = cmb(chosen, 2) * cmb((n - chosen), 1);
  long long all1 = cmb(chosen, 1) * cmb(n - chosen, 2);
  double prob =
      (double)all3 / total + (double)all2 / total + (double)0.5 * all1 / total;
  return prob;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  double p;
  cin >> n >> p;
  int pas = 0;
  for (int p2 = 1 << 10; p2 > 0; p2 >>= 1) {
    if (pas + p2 <= n && check(pas + p2, n) < p) pas += p2;
  }
  pas++;
  cout << pas;
  return 0;
}
