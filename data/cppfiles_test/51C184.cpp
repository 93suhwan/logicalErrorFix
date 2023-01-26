#include <bits/stdc++.h>
using namespace std;
int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}
bool palin(string s) {
  int error = 0;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] != s[n - 1 - i]) {
      return false;
    }
  }
  return true;
}
static int common;
long lcm(int n1, int n2) {
  common += n2;
  if (common % n1 == 0)
    return common;
  else
    return lcm(n1, n2);
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
bool isPerfectSquare(long long int x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
int stringTointeger(string str) {
  int temp = 0;
  for (int i = 0; i < str.length(); i++) {
    temp = temp * 10 + (str[i] - '0');
  }
  return temp;
}
string bn(int n) {
  string ans = "";
  while (n > 0) {
    if (n & 1) {
      ans += '1';
    } else {
      ans += '0';
    }
    n /= 2;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
int xorcal(long long int n) {
  if (n % 4 == 0) {
    return n;
  }
  if (n % 4 == 1) {
    return 1;
  }
  if (n % 4 == 2) {
    return n - 1;
  }
  return 0;
}
void arrayofprimeSieveOfEratosthenes(int n, vector<long long int> &v) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p <= n; p++)
    if (prime[p]) v.push_back(p);
}
bool isprime(long long int n) {
  if (n < 2) {
    return false;
  }
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
bool checkequal(int a[], int b[], int size) {
  long long int n = size;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}
vector<int> primefact(int n) {
  vector<int> ans;
  while (n % 2 == 0) {
    ans.push_back(2);
    n = n / 2;
  }
  for (int i = 3; i * i <= n; i += 2) {
    while (n % i == 0) {
      ans.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) {
    ans.push_back(n);
  }
  return ans;
}
void primeInRange(int L, int R, vector<long long int> &v) {
  int i, j, flag;
  for (i = L; i <= R; i++) {
    if (i == 1 || i == 0) continue;
    flag = 1;
    for (j = 2; j <= i / 2; ++j) {
      if (i % j == 0) {
        flag = 0;
        break;
      }
    }
    if (flag == 1) v.push_back(i);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n == 1) {
      cout << "0"
           << " "
           << "1"
           << "\n";
    } else {
      cout << "-" << n - 1 << " " << n << "\n";
    }
  }
  return 0;
}
