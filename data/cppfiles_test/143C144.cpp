#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
long double EPS = 1e-9;
long long MOD2 = 998244353;
long long binpow(long long b, long long p, long long mod) {
  long long ans = 1;
  b %= mod;
  for (; p; p >>= 1) {
    if (p & 1) ans = ans * b % mod;
    b = b * b % mod;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long expo(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
void extendgcd(long long a, long long b, long long *v) {
  if (b == 0) {
    v[0] = 1;
    v[1] = 0;
    v[2] = a;
    return;
  }
  extendgcd(b, a % b, v);
  long long x = v[1];
  v[1] = v[0] - v[1] * (a / b);
  v[0] = x;
  return;
}
long long mminv(long long a, long long b) {
  long long arr[3];
  extendgcd(a, b, arr);
  return arr[0];
}
long long mminvprime(long long a, long long b) { return expo(a, b - 2, b); }
bool revsort(long long a, long long b) { return a > b; }
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}
long long combination(long long n, long long r, long long m, long long *fact,
                      long long *ifact) {
  long long val1 = fact[n];
  long long val2 = ifact[n - r];
  long long val3 = ifact[r];
  return (((val1 * val2) % m) * val3) % m;
}
vector<long long> sieve(int n) {
  int *arr = new int[n + 1]();
  vector<long long> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
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
  return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
long long phin(long long n) {
  long long number = n;
  if (n % 2 == 0) {
    number /= 2;
    while (n % 2 == 0) n /= 2;
  }
  for (long long i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      number = (number / i * (i - 1));
    }
  }
  if (n > 1) number = (number / n * (n - 1));
  return number;
}
void pre() {}
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n), occ(n + 1);
  for (long long i = 0; i < (n); ++i) {
    cin >> arr[i];
    occ[arr[i]]++;
  }
  sort((arr).begin(), (arr).end());
  vector<pair<long long, long long> > extra;
  long long prev = 0, last = 0, res = 1;
  for (long long i = 0; i <= n; i++) {
    long long lesser = lower_bound((arr).begin(), (arr).end(), i) - arr.begin();
    if (res == -1 or lesser < i) {
      res = -1;
      cout << "-1 ";
      continue;
    }
    long long ans = occ[i] + prev;
    if (occ[i] > 1) {
      extra.push_back({i, occ[i] - 1});
    }
    if (occ[i] == 0) {
      if (!extra.empty()) {
        long long num = extra.back().first;
        prev += i - num;
        extra.back().second--;
        if (extra.back().second == 0) {
          extra.pop_back();
        }
      } else
        res = -1;
    }
    cout << ans << ' ';
  }
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  pre();
  long long _t = 1;
  cin >> _t;
  for (long long i = 1; i <= _t; i++) {
    solve();
  }
}
