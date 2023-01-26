#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long large = 1e11, remi2 = 998244353;
const long long remi = 1e9 + 7, inf = LLONG_MAX;
const long double Pi = acos(-1);
long long PowI(long long a, long long b, long long m) {
  long long ans = 1 % m;
  while (b > 0) {
    if (b % 2) ans = (((ans % m) * (a % m)) % m);
    a = (((a % m) * (a % m)) % m);
    b = (long long)(b / ((long long)2));
  }
  return ans;
}
void Foxtrot() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  long long sum = 0;
  for (int i = 0; i < (n - (2 * k)); i++) {
    sum += v[i];
  }
  for (long long i = n - 2 * k; i < (n - k); i++) {
    sum += (v[i] / v[i + k]);
  }
  cout << sum << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  cin >> T;
  for (int i = 1; i < T + 1; i++) {
    Foxtrot();
  }
  return 0;
}
