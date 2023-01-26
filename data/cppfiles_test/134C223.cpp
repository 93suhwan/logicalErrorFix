#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long modx = 998244353;
long double PI = 3.1415926535897;
const long long N = 1000100;
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
long long ceils(long long x, long long y) { return x / y + ((x % y) != 0); }
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long powmod(long long x, long long y) {
  long long res = 1;
  for (long long i = 0; i < y; i++) {
    res = res * x % MOD;
  }
  return res;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool COMP(pair<long long, long long> l, pair<long long, long long> r) {
  return l.second < r.second;
}
long long kadanesAlgo(vector<long long> a) {
  long long n = a.size();
  long long currMax = 0;
  long long mx = INT_MIN;
  for (long long i = 0; i < n; i++) {
    currMax += a[i];
    if (currMax <= a[i]) {
      currMax = a[i];
    }
    mx = max(currMax, mx);
  }
  return mx;
}
long long ask(long long x, long long y) {
  cout << "?"
       << " ";
  cout << x << " " << y << endl;
  long long s;
  cin >> s;
  return s;
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
bool is_sorted(vector<long long> a) {
  long long x = 0;
  for (long long i = 0; i < a.size() - 1; i++) {
    if (a[i] < a[i + 1]) x++;
  }
  return x == a.size() - 1;
}
bool check(string a, string b) {
  long long n = a.size(), m = b.size();
  if (a < b) {
    return true;
  }
  if (a > b) {
    return false;
  }
  for (long long i = 0; i < a.size(); i++) {
    if (a[i] > b[i]) {
      return false;
    } else if (a[i] < b[i]) {
      return true;
    }
  }
  return false;
}
bool isSubSequence(string a, string b, long long m, long long n) {
  long long j = 0;
  for (long long i = 0; i < n and j < m; i++)
    if (a[j] == b[i]) j++;
  return (j == m);
}
long long power(long long n, long long x) {
  long long ans = 1;
  for (long long i = 0; i < n; i++) {
    ans *= x;
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  long long x = 0, y = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (i % 2) {
      x = gcd(a[i], x);
    } else
      y = gcd(a[i], y);
  }
  if (x == y) {
    cout << 0;
    return;
  }
  long long ans = y;
  for (long long i = 0; i < n; i++) {
    if (i % 2) {
      if (a[i] % y == 0) {
        ans = x;
      }
    }
  }
  if (ans == y) {
    cout << y;
    return;
  }
  for (long long i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (a[i] % x == 0) {
        cout << 0;
        return;
      }
    }
  }
  cout << ans;
}
