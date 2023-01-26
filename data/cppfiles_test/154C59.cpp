#include <bits/stdc++.h>
using namespace std;
long long int M = 1e9 + 1;
long long int MM = 998244353;
template <typename... T>
void read(T &...args) {
  ((cin >> args), ...);
}
long long int gcd(long long int a, long long int b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
void swap(long long int &x, long long int &y) {
  long long int temp = x;
  x = y;
  y = temp;
}
bool revsort(long long int a, long long int b) { return a > b; }
void google(long long int t) { cout << "Case #" << t << ": "; }
void precision(long long int a) { cout << setprecision(a) << fixed; }
vector<long long int> sieve(long long int n) {
  long long int *arr = new long long int[n + 1]();
  vector<long long int> vect;
  for (long long int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (long long int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
long long int expo(long long int a, long long int b, long long int mod) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
long long int mod_add(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m)) % m;
}
long long int mod_mul(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m)) % m;
}
long long int mod_sub(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
void solve() {
  long long int a, b, c;
  read(a, b, c);
  if (a == b + c) {
    cout << "YES"
         << "\n";
    return;
  } else {
    if (b == c and a % 2 == 0) {
      cout << "YES"
           << "\n";
      return;
    }
  }
  if (b == a + c) {
    cout << "YES"
         << "\n";
    return;
  } else {
    if (a == c and b % 2 == 0) {
      cout << "YES"
           << "\n";
      return;
    }
  }
  if (c == b + a) {
    cout << "YES"
         << "\n";
    return;
  } else {
    if (b == a and c % 2 == 0) {
      cout << "YES"
           << "\n";
      return;
    }
  }
  cout << "NO"
       << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve();
  }
}
