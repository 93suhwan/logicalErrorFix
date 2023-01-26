#include <bits/stdc++.h>
long long int inf = 1e18;
using namespace std;
long long int add(long long a, long long b) {
  return ((a % 1000000007) + (b % 1000000007)) % 1000000007;
}
long long int subtract(long long a, long long b) {
  return ((a % 1000000007) - (b % 1000000007)) % 1000000007;
}
long long int mult(long long a, long long b) {
  return ((a % 1000000007) * (b % 1000000007)) % 1000000007;
}
long long int add1(long long a, long long b) {
  return ((a % 998244353) + (b % 998244353)) % 998244353;
}
long long int subtract1(long long a, long long b) {
  return ((a % 998244353) - (b % 998244353)) % 998244353;
}
long long int mult1(long long a, long long b) {
  return ((a % 998244353) * (b % 998244353)) % 998244353;
}
long long int binmodwithMOD1(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = mult1(res, a) % 998244353;
    a = mult1(a, a) % 998244353;
    b >>= 1;
  }
  return res;
}
long long int binmodwithMOD(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = mult(res, a) % 1000000007;
    a = mult(a, a) % 1000000007;
    b >>= 1;
  }
  return res;
}
long long int binmodwithoutMOD1orMOD2(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int inverse(long long int n) {
  return binmodwithMOD(n, 1000000007 - 2);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m, k;
  cin >> n >> m >> k;
  vector<vector<long long int> > a(n, vector<long long int>(m)),
      tmp(n, vector<long long int>(m, -1));
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) cin >> a[i][j];
  }
  map<pair<long long int, long long int>, long long int> mp;
  vector<long long int> ans(k, 0);
  vector<long long int> balls(k, 0);
  for (long long int i = 0; i < k; i++) cin >> balls[i];
  long long int cnt = 1001;
  set<pair<long long int, long long int> > s1;
  for (long long int x = 0; x < k; x++) {
    long long int i = 0;
    long long int j = balls[x];
    j--;
    while (i < n) {
      if (a[i][j] == 2)
        i++;
      else {
        if (a[i][j] == 1)
          a[i][j++] = 2;
        else
          a[i][j--] = 2;
      }
    }
    cout << j + 1 << " ";
  }
  cout << "\n";
  cout << "\n";
  return 0;
}
