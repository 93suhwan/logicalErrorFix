#include <bits/stdc++.h>
using namespace std;
long long int expo(long long int a, long long int b, long long int mod) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
void google(int t) { cout << "Case #" << t << ": "; }
vector<long long int> sieve(int n) {
  int *arr = new int[n + 1]();
  vector<long long int> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
long long int mod_add(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long int mod_mul(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long int mod_sub(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long int ceiling(long long int n, long long int m) {
  if (n % m == 0)
    return n / m;
  else
    return n / m + 1;
}
long long int fact(long long int n) {
  long long int res = 1;
  for (long long int i = 2; i <= n; i++) res = res * i;
  return res;
}
long long int nCr(long long int n, long long int r) {
  return fact(n) / (fact(r) * fact(n - r));
}
bool isprime(long long int n) {
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}
long long int oor(long long int i, long long int j) {
  cout << "or"
       << " " << i << " " << j << "\n";
  long long int x;
  cin >> x;
  return x;
}
long long int an(long long int i, long long int j) {
  cout << "and"
       << " " << i << " " << j << "\n";
  long long int x;
  cin >> x;
  return x;
}
void re() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> a(n + 1, 0);
  vector<long long int> o(n + 1);
  vector<long long int> ad(n + 1);
  for (long long int i = 2; i < n + 1; i++) {
    o[i] = oor(1, i);
    ad[i] = an(1, i);
  }
  vector<long long int> hh(32, -1);
  for (long long int i = 0; i < 32; i++) {
    for (long long int j = 2; j < n + 1; j++) {
      long long int o1 = (o[j] & (1LL << i) ? 1 : 0);
      long long int ad1 = (ad[j] & (1LL << i) ? 1 : 0);
      if (o1 == 1 && ad1 == 1) hh[i] = 1;
      if (o1 == 0 && ad1 == 0) hh[i] = 0;
    }
    if (hh[i] == -1) {
      long long int o1 = (oor(2, 3) & (1LL << i) ? 1 : 0);
      long long int ad1 = (an(2, 3) & (1LL << i) ? 1 : 0);
      if (o1 == 1 && ad1 == 1) hh[i] = 1;
      if (o1 == 0 && ad1 == 0) hh[i] = 0;
    }
  }
  for (long long int i = 0; i < 32; i++) {
    if (hh[i] == 1) a[1] += (1LL << i);
  }
  for (long long int i = 2; i < n + 1; i++) {
    for (long long int j = 0; j < 32; j++) {
      long long int o1 = (o[i] & (1LL << j) ? 1 : 0);
      long long int ad1 = (ad[i] & (1LL << j) ? 1 : 0);
      if (ad1) a[i] += (1LL << j);
      if (ad1 == 0 && o1 == 1 && hh[j] == 0) a[i] += (1LL << j);
    }
  }
  a.erase(a.begin());
  sort(a.begin(), a.end());
  cout << "finish " << a[k - 1] << "\n";
}
int main() {
  long long int t = 1;
  while (t--) {
    re();
  }
}
