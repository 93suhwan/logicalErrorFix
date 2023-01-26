#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
using namespace std;
vector<long long> sieve;
vector<long long> fact_dp;
long long power(long long base, long long exponent, long long modulo_factor);
long long modInverse(long long n, long long p);
long long combinate(long long n, long long r, long long modulo_factor);
long long gcd(long long num1, long long num2);
long long lcm(long long num1, long long num2);
void seive(long long limit);
vector<int> get_factors(int num);
long long factorial(long long num, long long mod);
void solve();
bool doubleequal(double a, double b) {
  if (abs(a - b) < 1e-9) return true;
  return false;
}
long long power(long long base, long long exponent, long long modulo_factor) {
  long long x = base, y = exponent, p = modulo_factor;
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInverse(long long n, long long p) { return power(n, p - 2, p); }
long long combinate(long long n, long long r, long long modulo_factor) {
  long long p = modulo_factor;
  if (n < r) return 0;
  if (r == 0) return 1;
  return (factorial(n, p) * modInverse(factorial(r, p), p) % p *
          modInverse(factorial(n - r, p), p) % p) %
         p;
}
long long permutate(long long n, long long r, long long modulo_factor) {
  long long p = modulo_factor;
  if (r == 0) return 1;
  return (factorial(n, p) * modInverse(factorial(n - r, p), p)) % p;
}
long long gcd(long long num1, long long num2) {
  if (num1 == 0 || num2 == 0) return max(num1, num2);
  if (num1 > num2) return gcd(num2, num1 % num2);
  return gcd(num1, num2 % num1);
}
long long lcm(long long num1, long long num2) {
  return (num1 * num2) / gcd(num1, num2);
}
void seive(long long limit) {
  long long arr[limit + 1];
  for (long long i = 0; i <= limit; i++) arr[i] = 0;
  for (long long i = 2; i <= limit; i++) {
    if (arr[i] == 0) {
      ::sieve.push_back(i);
      for (long long ptr = i * i; ptr <= limit; ptr += i) {
        arr[ptr] = 1;
      }
    }
  }
  return;
}
vector<int> get_factors(int num) {
  vector<int> factors_list;
  int divisor = 2;
  while (num > 1) {
    if (num % divisor == 0) {
      factors_list.push_back(divisor);
      num /= divisor;
    } else {
      if (divisor % 2 == 0)
        divisor++;
      else {
        divisor += 2;
      }
    }
  }
  return factors_list;
}
long long factorial(long long num, long long mod) {
  if (::fact_dp.size() == 0) {
    ::fact_dp.push_back(1);
  }
  for (long long i = ::fact_dp.size(); i <= num; i++) {
    ::fact_dp.push_back((::fact_dp[i - 1] * (i % mod)) % mod);
  }
  return ::fact_dp[num];
}
double sumharmonic(double a, double n, double d) {
  return (1.0 / d) * log(((2 * a) + (((2 * n) - 1) * d)) / ((2 * a) - d));
}
long long getroom(string** mat, long long i, long long j, long long** visited) {
  if (visited[i][j] == 1) return 0;
  visited[i][j] = 1;
  long long cnt = 1;
  if (mat[i][j][1] == '0' && mat[i][j + 1][3] == '0')
    cnt += getroom(mat, i, j + 1, visited);
  if (mat[i][j][2] == '0' && mat[i + 1][j][0] == '0')
    cnt += getroom(mat, i + 1, j, visited);
  if (mat[i][j][3] == '0' && mat[i][j - 1][1] == '0')
    cnt += getroom(mat, i, j - 1, visited);
  if (mat[i][j][0] == '0' && mat[i - 1][j][2] == '0')
    cnt += getroom(mat, i - 1, j, visited);
  return cnt;
}
bool testcase = false;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  if (testcase) cin >> t;
  while (t--) solve();
  return 0;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  string binary[16] = {"0000", "0001", "0010", "0011", "0100", "0101",
                       "0110", "0111", "1000", "1001", "1010", "1011",
                       "1100", "1101", "1110", "1111"};
  string** mat = new string*[n];
  for (long long i = 0; i < n; i++) {
    mat[i] = new string[m];
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      long long x;
      cin >> x;
      mat[i][j] = binary[x];
    }
  }
  long long** visited = new long long*[n];
  for (long long i = 0; i < n; i++) {
    visited[i] = new long long[m];
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      visited[i][j] = 0;
    }
  }
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (!visited[i][j]) {
        v.push_back(getroom(mat, i, j, visited));
      }
    }
  }
  sort(v.rbegin(), v.rend());
  for (auto val : v) cout << val << " ";
  cout << endl;
  return;
}
