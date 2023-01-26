#include <bits/stdc++.h>
using namespace std;
void io() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
long long mod = 1e9 + 7, mxn = 3e5 + 5;
void deb(vector<long long> v) {
  for (auto t : v) cerr << t << " ";
  cerr << "\n";
}
long long mul(long long a, long long b, long long mod) {
  a %= mod;
  b %= mod;
  a *= b;
  a += mod;
  return a % mod;
}
bool sortbysecdesc(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second > b.second;
}
bool check_sorted(vector<long long> a) {
  long long n = a.size();
  for (long long i = 1; i < n; i++) {
    if (a[i] >= a[i - 1]) continue;
    return false;
  }
  return true;
}
long long po(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  if (b % 2 == 0) return po(mul(a, a, mod), b / 2, mod);
  return mul(a, po(mul(a, a, mod), (b - 1) / 2, mod), mod);
}
long long power(long long X, long long N) {
  if (N == 0) return 1;
  if (N % 2 == 0) return power(X * X, N / 2);
  return X * power(X, N - 1);
}
long long fact(long long n) {
  long long res = 1, i;
  for (long long i = 2; i <= n; i++) {
    res = (res * i) % mod;
  }
  return res;
}
long combi(long long n, long long k) {
  long long ans = 1;
  k = k > n - k ? n - k : k;
  long long j = 1;
  for (; j <= k; j++, n--) {
    if (n % j == 0) {
      ans *= n / j;
    } else if (ans % j == 0) {
      ans = ans / j * n;
    } else {
      ans = (ans * n) / j;
    }
  }
  return ans;
}
vector<int> sieveOfEratosthenes(int N) {
  bool primes[N + 1];
  memset(primes, true, sizeof(primes));
  vector<int> arr;
  for (int i = 2; i * i <= N; i++)
    if (primes[i] == true) {
      for (int j = i * i; j <= N; j += i) primes[j] = false;
    }
  for (int i = 2; i <= N; i++)
    if (primes[i]) arr.emplace_back(i);
  return arr;
}
void prime_fact(long long n, vector<long long> &res) {
  while (n % 2 == 0) {
    res.push_back(2);
    n = n / 2;
  }
  for (long long i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      res.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) {
    res.push_back(n);
  }
}
bool valid_coordinate(long long x, long long y, long long n, long long m) {
  if (x < 0 || y < 0)
    return false;
  else if (x >= n || y >= m)
    return false;
  else
    return true;
}
int sod(int n) {
  int sum = 0;
  while (n) {
    sum += (n % 10);
    n /= 10;
  }
  return sum;
}
bool isPowerOfTwo(long long n) { return n && (!(n & (n - 1))); }
bool ce(long long n) {
  if (ceil((double)sqrt(n)) == floor((double)sqrt(n))) {
    return true;
  }
  return false;
}
void solve() {
  long long n;
  cin >> n;
  string s = to_string(n);
  long long sum1 = 0;
  for (long long i = 0; i < s.size(); i += 2) {
    long long num = s[i] - '0';
    sum1 = sum1 * 10 + num;
  }
  sum1++;
  long long sum2 = 0;
  for (long long i = 1; i < s.size(); i += 2) {
    long long num = s[i] - '0';
    sum2 = sum2 * 10 + num;
  }
  sum2++;
  long long ans = (sum1 * sum2);
  ans -= 2;
  cout << ans << endl;
  return;
  return;
}
int main() {
  io();
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
