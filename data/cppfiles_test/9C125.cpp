#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long inf = 1e15;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
int large_power(int x, unsigned int y) {
  int res = 1;
  x = x % mod;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
int power(int x, int y) {
  int res = 1;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
string bin(int n) {
  string s = "";
  while (n > 1) {
    int rem = n % 2;
    if (rem)
      s = "1" + s;
    else
      s = "0" + s;
    n = n / 2;
  }
  if (n) s = "1" + s;
  return s;
}
long long exp(long long i, long long j) {
  if (j == 1) return i;
  if (j == 0) return 1;
  if (j & 1) {
    return (i * exp((i * i) % mod, j / 2)) % mod;
  }
  return exp((i * i) % mod, j / 2) % mod;
}
long long invMod(long long i) { return exp(i, mod - 2) % mod; }
long long nCr(long long n, long long r) {
  long long ans = 1;
  for (long long i = n; i > n - r; i--) {
    ans = (ans * i) % mod;
  }
  for (long long i = 1; i <= r; i++) {
    ans = (ans * invMod(i)) % mod;
  }
  return ans;
}
tuple<int, int> divisors(int n) {
  map<int, int> mp;
  int e = 0, o = 0;
  while (n % 2 == 0) {
    if (mp[2] > 0)
      mp[2]++;
    else
      mp[2] = 1;
    n /= 2;
    e += 1;
  }
  int i = 3;
  while (i * i <= n) {
    if (n % i == 0) {
      o += 1;
      if (mp[i] > 0)
        mp[i]++;
      else
        mp[i] = 1;
      n /= i;
    } else {
      i += 2;
    }
  }
  if (n > 2) {
    o += 1;
    if (mp[n] > 0)
      mp[n]++;
    else
      mp[n] = 1;
  }
  return make_tuple(e, o);
}
int n, m, k;
vector<int> ans;
int pi = -1, pj = -1;
void add(vector<vector<int>>& mat, int row, int col) {
  if (row == n) {
    ans.push_back(col + 1);
    pi = -1;
    pj = -1;
    return;
  }
  if (pi != -1 && pj != -1) {
    mat[pi][pj] = 2;
  }
  if (mat[row][col] == 2) {
    pi = row;
    pj = col;
    add(mat, row + 1, col);
    return;
  } else if (mat[row][col] == 1) {
    pi = row;
    pj = col;
    add(mat, row, col + 1);
    return;
  } else if (mat[row][col] == 3) {
    pi = row;
    pj = col;
    add(mat, row, col - 1);
    return;
  }
}
void solve() {
  cin >> n >> m >> k;
  vector<vector<int>> mat(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }
  vector<int> balls(k);
  for (int i = 0; i < k; i++) {
    cin >> balls[i];
  }
  for (int i = 0; i < k; i++) {
    add(mat, 0, balls[i] - 1);
  }
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << endl;
  return;
}
int32_t main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
