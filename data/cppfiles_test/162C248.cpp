#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const long long MOD = 1000000007;
const long long mod = 998244353;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
bool isPrime(long long n) {
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) return 0;
  return 1;
}
string binaryRepresentation(int x) {
  string s = "";
  for (int i = 31; i >= 0; i--) {
    if (x & (1 << i))
      cout << "1";
    else
      cout << "0";
  }
  return s;
}
long long factorial(long long n) {
  long long ans = 1;
  long long prev = 1;
  for (long long i = 2; i <= n; i++) {
    ans = i * prev;
    ans %= MOD;
    prev = ans;
  }
  return ans;
  ;
}
bool isPowerOfTwo(long long n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
long long power(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % MOD;
    b /= 2;
    a = (a * a) % MOD;
  }
  return ans % MOD;
}
long long inverse(long long i) {
  if (i == 1) return 1;
  return (MOD - ((MOD / i) * inverse(MOD % i)) % MOD + MOD) % MOD;
}
string toString(long long a) {
  ostringstream temp;
  temp << a;
  return temp.str();
}
long long toNumber(string s) {
  stringstream num(s);
  long long x = 0;
  num >> x;
  return x;
}
bool cmp(const pair<long long, long long> &a,
         const pair<long long, long long> &b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}
long long solve(vector<long long> &ar, long long mid, long long n) {
  vector<long long> temp = ar;
  for (long long i = n - 1; i >= 0; i--) {
    long long d = min(ar[i], temp[i] - mid);
    if (d < 0) return false;
    d /= 3;
    if (i >= 2) {
      temp[i - 2] += 2 * d;
      temp[i - 1] += d;
      temp[i] -= 3 * d;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> ar(n);
    for (long long i = 0; i < n; i++) {
      cin >> ar[i];
    }
    long long low = 1;
    long long high = 1e9;
    while (low <= high) {
      long long mid = (low + high) / 2;
      if (solve(ar, mid, n))
        low = mid + 1;
      else
        high = mid - 1;
    }
    cout << low - 1 << "\n";
  }
  return 0;
}
