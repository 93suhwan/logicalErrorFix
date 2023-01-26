#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)(1e18) + 9;
bool sortbysec(const pair<int, int>& a, const pair<int, int>& b) {
  return (a.second < b.second);
}
long long __gcd(long long a, long long b) {
  if (b == 0) return a;
  return __gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / __gcd(a, b) * b); }
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
long long expmod(long long a, long long b, long long m) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b = b >> 1;
  }
  return res;
}
long long mmiprime(long long a, long long m) { return expmod(a, m - 2, m); }
void extendedgcd(long long a, long long b, long long* arr) {
  if (b == 0) {
    arr[0] = 1;
    arr[1] = 0;
    arr[2] = a;
    return;
  }
  extendedgcd(b, a % b, arr);
  long long x = arr[1];
  arr[1] = arr[0] - arr[1] * (a / b);
  arr[0] = x;
  return;
}
long long mmicoprime(long long a, long long m) {
  long long* arr = new long long;
  extendedgcd(a, m, arr);
  return ((arr[0] + m) % m);
}
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long mod_div(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mmiprime(b, m), m) + m) % m;
}
vector<long long> sieve(int n) {
  int* arr = new int[n + 1]();
  vector<long long> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = (2 * i); j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
vector<int> SPF(int n) {
  vector<int> spf(n + 1, -1);
  for (int i = 2; i <= n; i++) spf[i] = i;
  for (int i = 2; (i * i) <= n; i++) {
    if (spf[i] == i) {
      for (int j = (i * i); j <= n; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
  return spf;
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
void $hubham() {
  long long n, k;
  cin >> n >> k;
  long long ans = 0;
  while (k > 0) {
    if (k == 1) {
      ans += 1;
      k = 0;
    }
    if (k == 2) {
      ans += n;
      k = 0;
    }
    if (k == 3) {
      ans += (n + 1);
      k = 0;
    }
    if (isPowerOfTwo(k)) {
      ans += expmod(n, log2(k), 1000000007);
      k = 0;
    } else {
      ans = (ans + expmod(n, floor(log2(k)), 1000000007));
      k -= (long long)pow(2, floor(log2(k)));
    }
  }
  cout << (ans % 1000000007) << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  auto begin = chrono::high_resolution_clock::now();
  long long t;
  cin >> t;
  while (t--) {
    $hubham();
  }
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - begin);
  return 0;
}
