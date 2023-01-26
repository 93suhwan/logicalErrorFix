#include <bits/stdc++.h>
using namespace std;
const long long int mod = 998244353;
const double PIE = 3.1415926536;
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
long long int gcdExtended(long long int a, long long int b, long long int *x,
                          long long int *y);
long long int modInverse(long long int b, long long int m) {
  long long int x, y;
  long long int g = gcdExtended(b, m, &x, &y);
  if (g != 1) return -1;
  return (x % m + m) % m;
}
long long int modDivide(long long int a, long long int b, long long int m) {
  a = a % m;
  long long int inv = modInverse(b, m);
  if (inv == -1)
    return -1;
  else
    return (inv * a) % m;
}
long long int gcdExtended(long long int a, long long int b, long long int *x,
                          long long int *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long int x1, y1;
  long long int gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
vector<long long int> decToBinary(long long int n) {
  vector<long long int> binaryNum;
  long long int i = 0;
  while (n > 0) {
    binaryNum.push_back(n % 2);
    n = n / 2;
    i++;
  }
  return binaryNum;
}
long long int binaryToDecimal(vector<long long int> num, long long int n = 2) {
  long long int dec_value = 0;
  long long int base = 1;
  long long int i = 0;
  long long int temp = num[i];
  i++;
  while (i < num.size() + 1) {
    long long int last_digit = temp;
    temp = num[i];
    i++;
    dec_value = mod_add(dec_value, mod_mul(last_digit, base, mod), mod);
    base = mod_mul(base, n, mod);
  }
  return dec_value;
}
vector<long long int> primeFactors(long long int n) {
  vector<long long int> factors;
  while (n % 2 == 0) {
    factors.push_back(2);
    n = n / 2;
  }
  for (long long int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      factors.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) factors.push_back(n);
  return factors;
}
set<long long int> Divisors(long long int n) {
  set<long long int> ans;
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        ans.insert(i);
      else {
        ans.insert(i);
        ans.insert(n / i);
      }
    }
  }
  return ans;
}
long long int permutations(vector<long long int> &a, long long int n) {
  long long int sum = 0;
  do {
    for (long long int i = 0; i < n; i++) {
      sum += (i + 1) * a[i];
    }
  } while (next_permutation(a.begin(), a.end()));
  return sum;
}
void prereq() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void SieveOfEratosthenes(long long int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (long long int p = 2; p <= n; p++)
    if (prime[p]) cout << p << " ";
}
double tri(long long int x1, long long int y1, long long int x2,
           long long int y2, long long int x3, long long int y3) {
  double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
  double b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
  double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
  double s = (a + b + c) / 2;
  return 2 * sqrt(s * (s - a) * (s - b) * (s - c));
}
signed main() {
  prereq();
  long long int t;
  cin >> t;
  while (t--) {
    long long int w, h;
    cin >> w >> h;
    long long int ka, kb, kc, kd;
    cin >> ka;
    vector<long long int> a(ka);
    for (long long int i = 0; i < ka; i++) cin >> a[i];
    cin >> kb;
    vector<long long int> b(kb);
    for (long long int i = 0; i < kb; i++) cin >> b[i];
    cin >> kc;
    vector<long long int> c(kc);
    for (long long int i = 0; i < kc; i++) cin >> c[i];
    cin >> kd;
    vector<long long int> d(kd);
    for (long long int i = 0; i < kd; i++) cin >> d[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    double area = 0;
    for (long long int i = 0; i < kb; i++) {
      area = max(tri(a[0], 0, b[i], h, a[ka - 1], 0), area);
    }
    for (long long int i = 0; i < ka; i++) {
      area = max(tri(b[0], h, a[i], 0, b[kb - 1], h), area);
    }
    for (long long int i = 0; i < kd; i++) {
      area = max(tri(0, c[0], w, d[i], 0, c[kc - 1]), area);
    }
    for (long long int i = 0; i < kc; i++) {
      area = max(tri(w, d[0], 0, c[i], w, d[kd - 1]), area);
    }
    cout << area << endl;
  }
  return 0;
}
