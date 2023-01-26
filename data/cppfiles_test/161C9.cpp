#include <bits/stdc++.h>
using namespace std;
long long gcd(long long A, long long B) { return (B == 0) ? A : gcd(B, A % B); }
long long lcm(long long A, long long B) { return A * B / gcd(A, B); }
const long long N = 2e6 + 10;
const long long NN = 1e9 + 10;
const long long mod = 1e9 + 7;
long long bmul(long long a, long long b) {
  long long ans = 0;
  while (b > 0) {
    if (b & 1) {
      ans = (ans + a) % mod;
    }
    a = (a + a) % mod;
    b >>= 1;
  }
  return ans;
}
long long bexpo(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = bmul(ans, a);
    }
    a = bmul(a, a);
    b >>= 1;
  }
  return ans;
}
long long hp[N + 10];
long long factormultiple[N + 10];
void precompute() {
  for (long long i = 2; i < N; i++) {
    if (hp[i] == 0) {
      for (long long j = i; j < N; j += i) {
        hp[j] = i;
      }
    }
  }
}
vector<long long> distinctpf(long long num) {
  vector<long long> ans;
  while (num > 1) {
    long long val = hp[num];
    while (num % val == 0) {
      num /= val;
    }
    ans.push_back(val);
  }
  return ans;
}
long long hsh[N];
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}
void dfs(long long l, long long r,
         map<pair<long long, long long>, long long>& ans,
         map<pair<long long, long long>, bool>& pres) {
  if (l != r) {
    for (long long i = l; i <= r; i++) {
      if (i == r) {
        if (pres[{l, i - 1}]) {
          ans[{l, r}] = i;
          dfs(l, i - 1, ans, pres);
          return;
        }
      }
      if (i == l) {
        if (pres[{i + 1, r}]) {
          ans[{l, r}] = i;
          dfs(i + 1, r, ans, pres);
          return;
        }
      } else {
        if (pres[{l, i - 1}] and pres[{i + 1, r}]) {
          ans[{l, r}] = i;
          dfs(i + 1, r, ans, pres);
          dfs(l, i - 1, ans, pres);
          return;
        }
      }
    }
    return;
  }
  ans[{l, r}] = r;
  return;
}
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> arr(n);
  map<pair<long long, long long>, long long> m;
  map<pair<long long, long long>, bool> pres;
  for (pair<long long, long long>& it : arr) {
    cin >> it.first >> it.second;
    pres[{it.first, it.second}] = true;
  }
  dfs(1, n, m, pres);
  for (auto it : arr) {
    cout << it.first << " " << it.second << " " << m[{it.first, it.second}];
    cout << "\n";
    ;
  }
  return;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }
}
