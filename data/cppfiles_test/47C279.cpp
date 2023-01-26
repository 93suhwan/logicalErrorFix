#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  long long int c = 1;
  while (b--) c *= a;
  return c;
}
long long int ar[5000005];
long long int ar2[5000005];
void testcase() {
  long long int n, k, i, j;
  cin >> n >> k;
  long long int c = 0, d = 0;
  for (i = 1; i <= n; i++) {
    long long int val;
    ar[i] = ar2[i] = 0;
    cin >> val;
    if (val > 0)
      ar[++c] = val;
    else if (val < 0)
      ar2[++d] = (val * -1);
  }
  if (c) sort(ar + 1, ar + c + 1);
  if (d) sort(ar2 + 1, ar2 + d + 1);
  long long int s1 = 0, s2 = 0;
  for (i = c; i > 0; i -= k) s1 += ar[i] * 2;
  s1 += ar2[d];
  for (i = d - k; i > 0; i -= k) s1 += ar2[i] * 2;
  for (i = d; i > 0; i -= k) s2 += ar2[i] * 2;
  s2 += ar[c];
  for (i = c - k; i > 0; i -= k) s2 += ar[i] * 2;
  cout << min(s1, s2) << '\n';
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  long long int test;
  cin >> test;
  while (test--) testcase();
  return 0;
}
