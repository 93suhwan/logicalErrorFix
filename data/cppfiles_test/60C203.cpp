#include <bits/stdc++.h>
using namespace std;
long long maxm = -1e18;
long long minm = 1e18;
long long mod = 1e9 + 7;
long long mod1 = 1e9 + 9;
const long double Pi = 3.141592653;
bool sortbysec(const pair<string, long long int> &a,
               const pair<string, long long int> &b) {
  return (a.second > b.second);
}
long long int fact(long long int n) {
  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return 1;
  }
  long long int res = 1;
  for (long long int i = 2; i <= n; i++) res = res * i;
  return res;
}
long long int nCr(long long int n, long long int r) {
  return fact(n) / (fact(r) * fact(n - r));
}
bool cmp(pair<long long int, long long int> a,
         pair<long long int, long long int> b) {
  return (a.first < b.first) || (a.first == b.first && a.second < b.second);
}
bool isint(double n) {
  long long int j = n;
  double w = n - j;
  if (w > 0) {
    return false;
  }
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long int cnt = a[0];
    for (long long int i = 1; i < n; i++) {
      cnt &= a[i];
    }
    cout << cnt << '\n';
  }
  return 0;
}
