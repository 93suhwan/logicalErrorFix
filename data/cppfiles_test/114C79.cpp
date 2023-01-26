#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MOD2 = 998244353;
long long power(long long a, long long b) {
  long long res = 1;
  a = a % MOD;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % MOD;
    }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
long long fermat_inv(long long y) { return power(y, MOD - 2); }
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
void print(vector<long long> &v) {
  for (long long x : v) {
    cout << x << " ";
  }
  cout << "\n";
}
void solveQuestion() {
  long long n;
  cin >> n;
  vector<long long> slots[n];
  for (long long i = 0; i < n; i++) {
    long long sz;
    cin >> sz;
    slots[i].resize(sz);
    for (long long j = 0; j < sz; j++) {
      cin >> slots[i][j];
    }
  }
  long long m;
  cin >> m;
  vector<vector<long long>> arr(m);
  map<vector<long long>, long long> banned;
  for (long long i = 0; i < m; i++) {
    vector<long long> ban(n);
    long long sum = 0;
    for (long long &x : ban) {
      cin >> x;
      sum += x;
    }
    banned[ban] = sum;
    arr[i] = ban;
  }
  auto isSafe = [&](vector<long long> &v1) { return !banned.count(v1); };
  vector<long long> ans(n);
  for (long long i = 0; i < n; i++) {
    ans[i] = slots[i].size();
  }
  if (isSafe(ans)) {
    print(ans);
    return;
  }
  long long maxAns = 0;
  for (long long i = 0; i < m; i++) {
    for (long long j = 0; j < n; j++) {
      if (arr[i][j] == 1) {
        continue;
      }
      vector<long long> copy = arr[i];
      copy[j]--;
      if (isSafe(copy)) {
        long long val = 0;
        for (long long k = 0; k < n; k++) {
          val += slots[k][copy[k] - 1];
        }
        if (val > maxAns) {
          maxAns = val;
          ans = copy;
        }
      }
    }
  }
  print(ans);
}
int32_t main(int32_t argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tt = 1;
  while (tt-- > 0) {
    solveQuestion();
  }
  return 0;
}
