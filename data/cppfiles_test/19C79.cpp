#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(vector<T> a) {
  int n = a.size();
  for (long long i = 0; i < n; ++i) {
    cout << a[i] << (i == n - 1 ? "\n" : " ");
  }
}
int sum_vector(vector<int> v) { return accumulate(v.begin(), v.end(), 0); }
void sort_vector(vector<int> &v) { sort(v.begin(), v.end()); }
void sort_comp(vector<int> &v, bool func(int, int)) {
  sort(v.begin(), v.end(), func);
}
bool comp(array<long long, 2> a, array<long long, 2> b) { return a[1] < b[1]; }
long long gcd(long long a, long long b) {
  a = abs(a);
  b = abs(b);
  while (a) {
    long long temp = a;
    a = b % a;
    b = temp;
  }
  return abs(b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
string binary(long long num) {
  string ans = "";
  do {
    ans = to_string(num % 2) + ans;
    num /= 2;
  } while (num);
  return ans;
}
const int mxn = 2e5 + 7;
const int di = 18;
const int mill = 1e6 + 3;
const long long mod = 1e9 + 7;
long long pwr(long long num, long long p) {
  long long res = 1;
  while (p > 0) {
    if (p & 1) res = (res * num) % mod;
    num = (num * num) % mod;
    p /= 2;
  }
  return res;
}
long long inverse(long long num) { return pwr(num, mod - 2); }
long long get_rand(long long n) { return ((rand() << 15) + rand()) % n; }
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<vector<int> > dp(n, vector<int>(2500, 33333));
  dp[0][v[0]] = v[0];
  dp[0][0] = v[0];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 2500; j++) {
      if (dp[i - 1][j] != 33333) {
        if (j + v[i] < 2500)
          dp[i][j + v[i]] = min(dp[i][j + v[i]], max(dp[i - 1][j], j + v[i]));
        if (v[i] > j) {
          dp[i][0] = min(dp[i][0], v[i] - j + dp[i - 1][j]);
        } else {
          dp[i][j - v[i]] = min(dp[i][j - v[i]], dp[i - 1][j]);
        }
      }
    }
  }
  int mn = 1e4;
  for (int j = 0; j < 2500; j++) {
    mn = min(mn, dp[n - 1][j]);
  }
  cout << mn << "\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t = 1;
  cin >> t;
  for (int ii = 1; ii <= t; ii++) {
    solve();
  }
  return 0;
}
