#include <bits/stdc++.h>
using namespace std;
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}
int XOR(int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
int isPrime(int N) {
  if (N < 2 || (!(N & 1) && N != 2)) return 0;
  for (int i = 3; i * i <= N; i += 2) {
    if (!(N % i)) return 0;
  }
  return 1;
}
void fillPrimes(vector<int> &prime, int high) {
  bool ck[high + 1];
  memset(ck, true, sizeof(ck));
  ck[1] = false;
  ck[0] = false;
  for (int i = 2; (i * i) <= high; i++) {
    if (ck[i] == true) {
      for (int j = i * i; j <= high; j = j + i) {
        ck[j] = false;
      }
    }
  }
  for (int i = 2; i * i <= high; i++) {
    if (ck[i] == true) {
      prime.push_back(i);
    }
  }
}
vector<bool> segmentedSieve(int low, int high) {
  vector<bool> prime(high - low + 1, true);
  vector<int> chprime;
  fillPrimes(chprime, high);
  for (int i : chprime) {
    int lower = (low / i);
    if (lower <= 1) {
      lower = i + i;
    } else if (low % i) {
      lower = (lower * i) + i;
    } else {
      lower = (lower * i);
    }
    for (int j = lower; j <= high; j = j + i) {
      prime[j - low] = false;
    }
  }
  return prime;
}
const double eps = 1e-7;
const long long N = 5e5 + 7, mod = 1e9 + 7;
long long POW(long long a, long long b, long long mod) {
  a %= mod;
  long long r = 1;
  for (long long i = b; i > 0; i >>= 1) {
    if (i & 1) r = (r * a) % mod;
    a = (a * a) % mod;
  }
  return r;
}
long long f[N];
void init() {
  f[0] = 1;
  for (long long i = 1; i < N; i++) {
    f[i] = (f[i - 1] * i) % mod;
  }
}
long long nCr(long long n, long long r) {
  if (n < r) return 0;
  return f[n] * POW(f[n - r] * f[r], mod - 2, mod) % mod;
}
long long nPr(long long n, long long r) { return nCr(n, r) * f[r] % mod; }
long long p = 1e9 + 7;
long long modadd(long long a, long long b) {
  a = a % p;
  b = b % p;
  return (((a + b) % p) + p) % p;
}
long long modmul(long long a, long long b) {
  a = a % p;
  b = b % p;
  return (((a * b) % p) + p) % p;
}
long long modsub(long long a, long long b) {
  a = a % p;
  b = b % p;
  return (((a - b) % p) + p) % p;
}
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  for (int i = 0; i < n; i += 1) cin >> arr[i];
  map<long long, long long> m;
  long long f = 0;
  for (int i = 0; i < n; i += 1) {
    m[arr[i]]++;
    if (m[arr[i]] > 1) {
      f = 1;
      break;
    }
  }
  if (f == 1) {
    cout << "YES" << endl;
    return;
  }
  bool vis[n + 1];
  fill(vis, vis + n, 0);
  long long c = 0;
  for (int i = 0; i < n; i += 1) {
    if (!vis[i]) {
      long long s = 1;
      vis[i] = 1;
      long long t = arr[i];
      while (1) {
        if (!vis[t - 1]) {
          s++;
          vis[t - 1] = 1;
          t = arr[t - 1];
        } else
          break;
      }
      if (s % 2 == 0) c++;
    }
  }
  if (c % 2 == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
