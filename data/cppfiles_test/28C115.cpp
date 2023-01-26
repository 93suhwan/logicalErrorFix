#include <bits/stdc++.h>
using namespace std;
const long long int N = 2e5;
const long long int INF = 1e9;
const long long int mod = 1e9 + 7;
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
void permutations(long long int a[], long long int n) {
  do {
    for (long long int i = 0; i < n; i++)
      cout << a[i] << ((i == n - 1) ? "\n" : " ");
  } while (next_permutation(a, a + n));
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
void prereq() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
signed main() {
  prereq();
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int sum = (a * 1) + (b * 2) + (c * 3);
    cout << sum % 2 << endl;
  }
  return 0;
}
