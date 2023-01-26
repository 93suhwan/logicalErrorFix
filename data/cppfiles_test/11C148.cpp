#include <bits/stdc++.h>
long long mod = (long long)(1e9 + 7);
using namespace std;
long long GCD(long long a, long long b) {
  if (a % b == 0) {
    return b;
  }
  return (b, b % a);
}
void sieve() {
  long long prime[10000000];
  memset(prime, 1, sizeof(prime));
  for (long long i = 2; i * i <= (long long)1e7 + 7; i++) {
    if (prime[i]) {
      for (long long j = i * i; j < (long long)1e7 + 7; j += i) {
        prime[j] = 0;
      }
    }
  }
  for (long long i = 3; i <= (long long)1e7 + 7; i++) {
    prime[i] += prime[i - 1];
  }
}
long long mod_mul(long long a, long long b, long long m) {
  return (a % m * b % m + m) % m;
}
long long pow1(long long a, long long b, long long m) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mod_mul(res, a, m);
    }
    a = mod_mul(a, a, m);
    b >>= 1;
  }
  return res;
}
long long max3(long long a, long long b, long long c) {
  if (a >= b && a >= c) {
    return a;
  }
  if (b >= a && b >= c) {
    return b;
  }
  return c;
}
long long min3(long long a, long long b, long long c) {
  if (a <= b && a <= c) {
    return a;
  }
  if (b <= a && b <= c) {
    return b;
  }
  return c;
}
long long maxar(long long ar[], long long n) {
  long long k = ar[0];
  for (long long i = 1; i < n; i++) {
    if (k < ar[i]) {
      k = ar[i];
    }
  }
  return k;
}
long long minar(long long ar[], long long n) {
  long long k = ar[0];
  for (long long i = 1; i < n; i++) {
    if (ar[i] < k) {
      k = ar[i];
    }
  }
  return k;
}
void swap(long long *a, long long *b) {
  long long c = *a;
  *a = *b;
  *b = c;
}
void yes() { cout << "Yes\n"; }
void no() { cout << "No\n"; }
void factor(long long n, long long k) {
  vector<long long> P;
  while (n % 2 == 0) {
    P.push_back(2);
    n = n / 2;
  }
  for (long long i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      n = n / i;
      P.push_back(i);
    }
  }
  if (n > 2) {
    P.push_back(n);
  }
  if (P.size() < k) {
    printf("-1");
    return;
  }
  for (long long i = 0; i < k - 1; i++) {
    printf("%d ", P[i]);
  }
}
void printmat(vector<vector<long long> > &G, long long n, long long m) {
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      cout << G[i][j] << " ";
    }
    cout << "\n";
  }
}
long long po[31];
void pre() {}
void solve() {
  long long n;
  cin >> n;
  long long count[n][5];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < 5; j++) {
      count[i][j] = 0;
    }
  }
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (long long j = 0; j < s.length(); j++) {
      count[i][s[j] - 'a']++;
    }
  }
  long long ans = 0;
  for (long long i = 0; i < 5; i++) {
    long long sum1 = 0, val = 0, dum[n];
    for (long long j = 0; j < n; j++) {
      long long sum = 0;
      for (long long k = 0; k < 5; k++) {
        if (i == k) {
          sum += count[j][k];
        } else {
          sum -= count[j][k];
        }
      }
      dum[j] = sum;
    }
    sort(dum, dum + n, greater<long long>());
    long long co = 0;
    for (long long i1 = 0; i1 < n; i1++) {
      sum1 += dum[i1];
      if (sum1 <= 0) {
        break;
      }
      co++;
    }
    ans = max(co, ans);
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }
}
