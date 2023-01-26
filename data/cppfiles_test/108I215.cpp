#include <bits/stdc++.h>
using namespace std;
const long long MAX = 200005;
const long long MOD = 1e9 + 7;
vector<bool> Prime(MAX, 1);
void sieve() {
  Prime[0] = Prime[1] = 0;
  for (long long i = 2; i < MAX; i++) {
    if (Prime[i]) {
      for (long long j = i * i; j < MAX && j > 0; j += i) {
        Prime[j] = 0;
      }
    }
  }
}
string decimaltobinary(long long n) {
  string s;
  while (n > 0) {
    char c = '0' + n % 2;
    s.push_back(c);
    n = n / 2;
  }
  return s;
}
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long x = power(a, b / 2);
  if (b % 2 == 0) {
    return x * x;
  }
  return a * x * x;
}
long long powermod(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a;
    }
    b = b / 2;
    a = a * a;
    a = a % MOD;
    res = res % MOD;
  }
  return res;
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
class triplet {
 public:
  long long first, second, third;
};
long long moddivide(long long a, long long b) {
  return (a % MOD * power(a, MOD - 2) % MOD) % MOD;
}
const long long INF = 1e18;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (long long INPUT = 0; INPUT < n; INPUT++) cin >> a[INPUT];
  ;
  for (long long INPUT = 0; INPUT < n; INPUT++) cin >> b[INPUT];
  ;
  long long sol[n];
  memset(sol, 0, sizeof(sol));
  long long mx = a[0];
  long long mxindx = 0;
  for (long long i = 1; i < n; i++) {
    if (a[i] > mx) {
      mx = a[i];
      mxindx = i;
    }
  }
  sol[mxindx] = 1;
  long long mas = 0;
  long long masindx = 0;
  for (long long i = 0; i < n; i++) {
    if (b[i] > b[mxindx]) {
      sol[i] = 1;
    }
    if (b[i] > mas) {
      mas = b[i];
      masindx = i;
    }
  }
  sol[masindx] = 1;
  for (long long i = 0; i < n; i++) {
    if (a[i] > a[masindx]) {
      sol[i] = 1;
    }
  }
  long long mina = a[masindx], minb = b[mxindx];
  bool change = false;
  queue<long long> q;
  for (long long i = 0; i < n; i++) {
    if (a[i] > mina) {
      sol[i] = 1;
    }
    if (b[i] > minb) {
      sol[i] = 1;
    }
    if (sol[i]) {
      if (mina > a[i]) {
        change = true;
        mina = a[i];
      }
      if (minb > b[i]) {
        change = true;
        minb = b[i];
      }
    } else {
      q.push(i);
    }
  }
  while (change) {
    change = false;
    long long m = q.size();
    for (long long i = 0; i < m; i++) {
      long long x = q.front();
      q.pop();
      if (a[x] > mina) {
        sol[x] = 1;
      }
      if (b[i] > minb) {
        sol[i] = 1;
      }
      if (sol[i]) {
        if (mina > a[i]) {
          change = true;
          mina = a[i];
        }
        if (minb > b[i]) {
          change = true;
          minb = b[i];
        }
      } else {
        q.push(x);
      }
    }
  }
  for (long long i = 0; i < n; i++) cout << sol[i];
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
