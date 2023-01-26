#include <bits/stdc++.h>
using namespace std;
int dx[] = {+0, +0, -1, +1};
int dy[] = {+1, -1, +0, +0};
long long int gcd(long long int a, long long int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b) * b);
}
long long int bigmod(long long int a, long long int b, long long int mod) {
  b %= (mod - 1);
  long long int result = 1ll;
  while (b > 0ll) {
    if (b & 1ll) result = result * a % mod;
    a = a * a % mod;
    b >>= 1ll;
  }
  return result;
}
long long int inverse(long long int a, long long int M) {
  if (gcd(a, M) == 1) return bigmod(a, M - 2, M) % M;
  return 1;
}
long long int ncr(long long int a, long long int b, long long int mod) {
  long long int x = max(a - b, b), ans = 1;
  for (long long int K = a, L = 1; K >= x + 1; K--, L++) {
    ans = ans * K % mod;
    ans = ans * inverse(L, mod) % mod;
  }
  return ans;
}
long long int fact(long long int n, long long int mod) {
  long long int res = 1;
  for (long long int i = 2; i <= n; i++) {
    res = (res % mod * i % mod) % mod;
  }
  return res;
}
void prime(long long int n) {
  long long int cnt = 1;
  while (n % 2 == 0) {
    n /= 2;
    cnt *= 2;
  }
  for (long long int i = 3; i * i <= n; i += 2) {
    cnt = 1;
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
        cnt *= i;
      }
    }
  }
  if (n > 1) {
  }
}
vector<long long int> primes;
bool isprime[64000];
void seive() {
  memset(isprime, false, sizeof(isprime));
  for (long long int i = 3; i * i <= 64000; i += 2) {
    if (!isprime[i]) {
      for (long long int j = i; j <= 64000; j += 2) {
        isprime[j] = true;
      }
    }
  }
  primes.push_back(2);
  for (long long int i = 3; i <= 64000; i += 2) {
    if (isprime[i]) primes.push_back(i);
  }
}
long long int segseive(long long int l, long long int r) {
  bool isprime1[r - l + 1];
  memset(isprime1, true, sizeof(isprime1));
  for (long long int i = 0; primes[i] * primes[i] <= r; i++) {
    long long int cur = primes[i];
    long long int base = (l / cur) * cur;
    if (base < l) base += cur;
    for (long long int j = base; j <= r; j += cur) {
      isprime1[j - l] = false;
    }
    if (base == cur) isprime1[base - l] = true;
  }
  long long int cnt;
  for (long long int i = 0; i < r - l + 1; i++) {
    if (isprime1[i]) {
      cnt = i + l;
    }
  }
  return cnt;
}
void urmi() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
vector<long long int> v[200005];
int main() {
  urmi();
  int t = 1;
  cin >> t;
  while (t--) {
    long long int n, ans = 0;
    cin >> n;
    string s, s1;
    cin >> s >> s1;
    for (long long int i = 0; i < n; i++) {
      if (i == 0) {
        if (s1[i] == '1') {
          if (s[i] == '0') {
            ans++;
            continue;
          }
          if (s[i + 1] == '1' && i + 1 < n) {
            ans++;
            s[i + 1] = '*';
            continue;
          }
        }
      } else if (i == n - 1) {
        if (s1[i] == '1') {
          if (s[i] == '0') {
            ans++;
            continue;
          }
          if (s[i - 1] == '1' && i - 1 >= 0) {
            ans++;
            s[i - 1] = '*';
            continue;
          }
        }
      } else {
        if (s1[i] == '1') {
          if (s[i] == '0') {
            ans++;
            continue;
          }
          if (s[i - 1] == '1' && i - 1 >= 0) {
            ans++;
            s[i - 1] = '*';
            continue;
          }
        }
        if (s1[i] == '1') {
          if (s[i] == '0') {
            ans++;
            continue;
          }
          if (s[i + 1] == '1' && i + 1 < n) {
            ans++;
            s[i + 1] = '*';
            continue;
          }
        }
      }
    }
    cout << ans << '\n';
  }
}
