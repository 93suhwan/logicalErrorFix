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
long long expo(long long a, long long b, long long m) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b = b >> 1;
  }
  return res;
}
long long inv(long long a, long long b) { return expo(a, b - 2, b); }
void swap(long long &x, long long &y) {
  long long temp = x;
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
long long fact[200001];
long long invfact[200001];
vector<long long> sieve(long long n) {
  long long *arr = new long long[n + 1]();
  vector<long long> vect;
  for (long long i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (long long j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
void toposort(long long n, vector<vector<long long>> &adj,
              vector<long long> &indegree, vector<long long> &dp) {
  queue<long long> q;
  vector<long long> done;
  for (long long i = 1; i <= n; i++) {
    if (indegree[i] == 0) {
      q.push(i);
      done.push_back(i);
    }
  }
  while (!q.empty()) {
    long long sz = q.size();
    while (sz--) {
      long long node = q.front();
      q.pop();
      for (auto x : adj[node]) {
        indegree[x]--;
        if (indegree[x] == 0) {
          q.push(x);
          done.push_back(x);
        }
        if (x > node) {
          dp[x] = max(dp[x], dp[node]);
        } else {
          dp[x] = max(dp[x], dp[node] + 1);
        }
      }
    }
  }
  if (done.size() != n) {
    cout << -1 << '\n';
  } else {
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
      ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  for (long long tt = 1; tt <= t; tt++) {
    long long n;
    cin >> n;
    vector<vector<long long>> adj(n + 1);
    vector<long long> indegree(n + 1, 0);
    for (long long i = 0; i < n; i++) {
      long long k;
      cin >> k;
      for (long long j = 0; j < k; j++) {
        long long y;
        cin >> y;
        adj[y].push_back(i + 1);
        indegree[i + 1]++;
      }
    }
    vector<long long> dp(n + 1, 1);
    toposort(n, adj, indegree, dp);
  }
}
