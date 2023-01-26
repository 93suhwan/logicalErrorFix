#include <bits/stdc++.h>
#pragma GCC optimize("O4,unroll-loops,no-stack-protector")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
void Why_does_competitive_programming_even_exist() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void YayXD() { return; }
long long arr[100005];
bool comp(long long a, long long b) { return abs(a) < abs(b); }
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return gcd(b % a, a);
}
signed main() {
  Why_does_competitive_programming_even_exist();
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    if (n % 2 == 0) {
      for (long long i = 1; i <= n; i += 2) {
        cout << arr[i + 1] << " " << -arr[i] << " ";
      }
      cout << "\n";
      continue;
    }
    sort(arr + 1, arr + 1 + n, comp);
    long long a = abs(arr[1]), b = abs(arr[2]), c = abs(arr[3]),
              g = gcd(a, gcd(b, c));
    a /= g;
    b /= g;
    c /= g;
    if (b == c) {
      long long x = b * 2, y = a;
      if (arr[1] > 0)
        cout << -x << " ";
      else
        cout << x << " ";
      if (arr[2] > 0)
        cout << y << " ";
      else
        cout << -y << " ";
      if (arr[3] > 0)
        cout << y << " ";
      else
        cout << -y << " ";
    } else {
      long long y = a, x = c - b;
      if (arr[1] > 0)
        cout << -x << " ";
      else
        cout << x << " ";
      if (arr[2] > 0)
        cout << -y << " ";
      else
        cout << y << " ";
      if (arr[3] > 0)
        cout << y << " ";
      else
        cout << -y << " ";
    }
    for (long long i = 4; i <= n; i += 2) {
      cout << arr[i + 1] << " " << -arr[i] << " ";
    }
    cout << "\n";
  }
}
