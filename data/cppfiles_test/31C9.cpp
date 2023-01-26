#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
void swap(long long &x, long long &y) {
  long long temp = x;
  x = y;
  y = temp;
}
long long expo(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
long long mminvprime(long long a, long long b) { return expo(a, b - 2, b); }
void precision(long long a) { cout << setprecision(a) << fixed; }
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
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
vector<long long> sieve(long long n) {
  long long *ssssssssssssssssasdqad = new long long[n + 1]();
  vector<long long> vect;
  for (long long i = 2; i <= n; i++)
    if (ssssssssssssssssasdqad[i] == 0) {
      vect.push_back(i);
      for (long long j = 2 * i; j <= n; j += i) ssssssssssssssssasdqad[j] = 1;
    }
  return vect;
}
template <typename Node>
struct SparseTable {
  vector<vector<Node>> table;
  vector<long long> logValues;
  long long n;
  long long maxLog;
  vector<long long> a;
  SparseTable(long long n1, vector<long long> &ssssssssssssssssasdqad) {
    n = n1;
    a = ssssssssssssssssasdqad;
    table.resize(n);
    logValues.resize(n + 1);
    maxLog = log2(n);
    logValues[1] = 0;
    for (long long i = 2; i <= n; i++) {
      logValues[i] = logValues[i / 2] + 1;
    }
    for (long long i = 0; i < n; i++) {
      table[i].resize(maxLog + 1);
      fill(table[i].begin(), table[i].end(), Node());
    }
    build();
  }
  void build() {
    for (long long i = 0; i < n; i++) {
      table[i][0] = Node(a[i]);
    }
    for (long long i = 1; i <= maxLog; i++) {
      for (long long j = 0; (j + (1 << i)) <= n; j++) {
        table[j][i].merge(table[j][i - 1], table[j + (1 << (i - 1))][i - 1]);
      }
    }
  }
  Node queryNormal(long long left, long long right) {
    Node sssasdsssssssssssssasdqad = Node();
    for (long long j = logValues[right - left + 1]; j >= 0; j--) {
      if ((1 << j) <= right - left + 1) {
        sssasdsssssssssssssasdqad.merge(sssasdsssssssssssssasdqad,
                                        table[left][j]);
        left += (1 << j);
      }
    }
    return sssasdsssssssssssssasdqad;
  }
  Node queryIdempotent(long long left, long long right) {
    long long j = logValues[right - left + 1];
    Node sssasdsssssssssssssasdqad = Node();
    sssasdsssssssssssssasdqad.merge(table[left][j],
                                    table[right - (1 << j) + 1][j]);
    return sssasdsssssssssssssasdqad;
  }
};
struct Node1 {
  long long val;
  Node1() { val = 0; }
  Node1(long long v) { val = v; }
  void merge(Node1 &l, Node1 &r) { val = min(l.val, r.val); }
};
void solve() {
  long long n;
  cin >> n;
  long long sssasdsssssssssssssasdqadaa[n];
  for (long long i = 0; i < n; i++) {
    cin >> sssasdsssssssssssssasdqadaa[i];
  }
  vector<long long> sssasdsssssssssssssasdqad;
  if (n % 2 == 0) {
    for (long long i = 0; i < n; i += 2) {
      sssasdsssssssssssssasdqad.push_back(sssasdsssssssssssssasdqadaa[i + 1]);
      sssasdsssssssssssssasdqad.push_back(-1 * sssasdsssssssssssssasdqadaa[i]);
    }
  } else {
    if (sssasdsssssssssssssasdqadaa[0] + sssasdsssssssssssssasdqadaa[1] != 0) {
      sssasdsssssssssssssasdqad.push_back(sssasdsssssssssssssasdqadaa[2]);
      sssasdsssssssssssssasdqad.push_back(sssasdsssssssssssssasdqadaa[2]);
      sssasdsssssssssssssasdqad.push_back(
          -1 *
          (sssasdsssssssssssssasdqadaa[0] + sssasdsssssssssssssasdqadaa[1]));
    } else {
      sssasdsssssssssssssasdqad.push_back(sssasdsssssssssssssasdqadaa[2]);
      sssasdsssssssssssssasdqad.push_back(-1 * sssasdsssssssssssssasdqadaa[2]);
      sssasdsssssssssssssasdqad.push_back(
          -1 *
          (sssasdsssssssssssssasdqadaa[0] - sssasdsssssssssssssasdqadaa[1]));
    }
    for (long long i = 3; i < n; i += 2) {
      sssasdsssssssssssssasdqad.push_back(sssasdsssssssssssssasdqadaa[i + 1]);
      sssasdsssssssssssssasdqad.push_back(-1 * sssasdsssssssssssssasdqadaa[i]);
    }
  }
  for (auto i : sssasdsssssssssssssasdqad) {
    cout << i << " ";
  }
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
