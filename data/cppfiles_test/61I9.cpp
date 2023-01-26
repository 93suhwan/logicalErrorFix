#include <bits/stdc++.h>
using namespace std;
long long i, j, c = 0, x = 1, y = 1, r = 0, result = 0, ans = 1, temp = 0,
                sum = 1, a, b, d, n, m, t;
string str, str1, str2, s1, s2, s3 = " ";
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
bool isprime(int n) {
  if (n == 1) return 0;
  if (n == 2 || n == 3) return 1;
  if (n % 2 == 0 || n % 3 == 0) return 0;
  for (long long i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return 0;
    return 1;
  }
}
long long divisors(long long n) {
  long long i;
  for (i = 1; i < sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        cout << i << " ";
      else
        cout << i << " " << n / i << " ";
    }
  }
}
void sieve(int n) {
  vector<bool> isprime(n + 1, true);
  {
    for (i = 2; i <= n; i++) {
      if (isprime[i]) {
        cout << i << " ";
        for (j = i * i; j <= n; j += i) {
          isprime[j] = false;
        }
      }
    }
  }
}
int power(long long n, long long m) {
  for (i = 0; i < m; i++) {
    sum = sum * n;
  }
  cout << sum;
}
long long powe(long long n, long long m) {
  while (m > 0) {
    if (m & 1) ans *= n;
    n *= n;
    m = m >> 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n >> str;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        str1 += 'B';
        str2 += 'R';
      } else {
        str1 += 'R';
        str2 += 'B';
      }
    }
    for (i = 0; i < n; i++) {
      if (str[i] != '?') {
        str1[i] = str[i];
        str2[i] = str[i];
      }
    }
    long long c = 0, c1 = 0;
    for (i = 1; i < n; i++) {
      c += (str1[i - 1] == str1[i]);
      c1 += (str2[i - 1] == str2[i]);
    }
    if (c < c1) {
      cout << str1;
    } else {
      cout << str2;
    }
    cout << "\n";
  }
  return 0;
}
