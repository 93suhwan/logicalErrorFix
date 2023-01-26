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
  vector<long long> x = v;
  sort(x.begin(), x.end());
  long long k2 = k;
  long long low = n - 2;
  long long high = n - 1;
  long long sum = 0;
  while (k--) {
    sum += (long long)(v[low] / v[high]);
    v[high] = 0;
    v[low] = 0;
    high -= 2;
    low -= 2;
  }
  for (int i = 0; i < n; i++) {
    if (v[i] != 0) {
      sum += (v[i]);
    }
  }
  long long low2 = 0, high2 = n - 1;
  long long sum2 = 0;
  while (k2--) {
    sum2 += (long long)(x[low2] / x[high2]);
    x[low2] = 0;
    x[high2] = 0;
    low2++;
    high2--;
  }
  for (int i = 0; i < n; i++) {
    if (x[i] != 0) {
      sum2 += x[i];
    }
  }
  long long mn = min(sum, sum2);
  cout << mn << "\n";
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
