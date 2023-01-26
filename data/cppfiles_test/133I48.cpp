#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
vector<long long> prime;
bool num[1000005 + 2];
void sieve() {
  num[0] = true;
  num[1] = true;
  for (long long i = 2; i <= 1000005; i++) {
    if (num[i] == false) {
      prime.push_back(i);
      for (long long j = 2 * i; j <= 1000005; j = j + i) {
        num[j] = true;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, i, j, k, l, a, b, c, p, q, r, t, ans, sum;
  cin >> t;
  while (t--) {
    n = 7;
    long long x[n + 1];
    for (i = 0; i < n; i++) {
      cin >> x[i];
    }
    sort(x, x + n);
    cout << x[0] << " " << x[1] << " " << x[n - 2] - x[1] << endl;
  }
  return 0;
}
