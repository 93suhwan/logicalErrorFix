#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return ((a / gcd(a, b)) * b); }
bool sorta(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
bool sortd(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second > b.second);
}
void printarr(long long arr[], long long n) {
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << "\n";
}
string decToBinary(int n) {
  string s = "";
  int i = 0;
  while (n > 0) {
    s = to_string(n % 2) + s;
    n = n / 2;
    i++;
  }
  return s;
}
long long binaryToDecimal(string n) {
  string num = n;
  long long dec_value = 0;
  int base = 1;
  int len = num.length();
  for (int i = len - 1; i >= 0; i--) {
    if (num[i] == '1') dec_value += base;
    base = base * 2;
  }
  return dec_value;
}
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool isPowerOfTwo(int n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
bool isPerfectSquare(long long x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
long long moduloMultiplication(long long a, long long b, long long mod) {
  a %= mod;
  b %= mod;
  return (a * b) % mod;
}
long long powermod(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
vector<int> primees(10000000, 1);
vector<int> anses(10000000, 0);
void isPrimes() {
  int c = 0;
  for (int p = 2; p * p <= 10000000; p++)
    if (primees[p] == 1)
      for (int i = p * 2; i <= 10000000; i += p) {
        primees[i] = 0;
      }
  for (int p = 2; p <= 10000000; p++) {
    anses[p] = anses[p - 1] + primees[p];
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int count = 0;
    count += (long long)sqrt(n);
    long long temp = (long long)cbrt(n);
    count += temp;
    count -= (long long)sqrt(temp);
    cout << count << endl;
  }
}
