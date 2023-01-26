#include <bits/stdc++.h>
using namespace std;
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a == 1 || b == 1) return 1;
  if (a == b) return a;
  if (a > b)
    return gcd(b, a % b);
  else
    return gcd(a, b % a);
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
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}
void google(int t) { cout << "Case #" << t << ": "; }
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
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
void Hail_Hydra() {
  long long int m, k;
  cin >> m >> k;
  long long int a[m];
  long long int maxi = 0;
  vector<long long int> p, n;
  for (int i = 0; i < m; i++) {
    long long int x;
    cin >> x;
    if (x > 0) {
      p.push_back(x);
    } else {
      n.push_back(-x);
    }
    maxi = ((maxi < abs(x)) ? abs(x) : maxi);
  }
  sort(p.begin(), p.end());
  sort(n.begin(), n.end());
  long long int sum = 0;
  for (int i = p.size() - 1; i >= 0; i -= k) {
    sum += 2 * p[i];
  }
  for (int i = n.size() - 1; i >= 0; i -= k) {
    sum += 2 * n[i];
  }
  cout << sum - maxi << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    Hail_Hydra();
  }
  return 0;
}
