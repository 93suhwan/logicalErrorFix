#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1e9 + 7;
long long int mpow(long long int base, long long int exp) {
  base %= MOD;
  long long int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long int)result * base) % MOD;
    base = ((long long int)base * base) % MOD;
    exp >>= 1;
  }
  return result;
}
void solver() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) cin >> a[i];
  long long int index = 0;
  for (long long int i = 0; i < n; i++) {
    if (index < a[i]) {
      index += (a[i] - index - 1);
    }
    index++;
  }
  cout << index - n << "\n";
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solver();
  }
  return 0;
}
