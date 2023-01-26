#include <bits/stdc++.h>
using namespace std;
const unsigned long long mod = 1e9 + 7;
unsigned long long binpow(unsigned long long a, unsigned long long b) {
  if (b == 0) {
    return 1;
  }
  unsigned long long ans = binpow(a, b / 2);
  ans *= ans;
  ans %= mod;
  if (b % 2) {
    ans *= a;
  }
  return ans % mod;
}
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
vector<int> div(int n) {
  vector<int> v;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      v.push_back(i);
      v.push_back(n / i);
    }
  }
  return v;
}
unsigned long long fact(unsigned long long n) {
  if (n == 0 || n == 1) return 1;
  return n * fact(n - 1);
}
vector<int> decimal(int n) {
  vector<int> v;
  while (n) {
    v.push_back(n % 2);
    n /= 2;
  }
  reverse(v.begin(), v.end());
  return v;
}
void dfs(int i, int j, int n, int m, vector<vector<string>>& vec,
         vector<vector<int>>& visited, int& cc) {
  if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] == 1) return;
  visited[i][j] = 1;
  ++cc;
  string second;
  if (j + 1 < m) {
    second = vec[i][j + 1];
    if (second[3] == '0') dfs(i, j + 1, n, m, vec, visited, cc);
  }
  if (i + 1 < n) {
    second = vec[i + 1][j];
    if (second[0] == '0') dfs(i + 1, j, n, m, vec, visited, cc);
  }
  if (i - 1 >= 0) {
    second = vec[i - 1][j];
    if (second[2] == '0') dfs(i - 1, j, n, m, vec, visited, cc);
  }
  if (j - 1 >= 0) {
    second = vec[i][j - 1];
    if (second[1] == '0') dfs(i, j - 1, n, m, vec, visited, cc);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  unsigned long long t;
  t = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> v(16);
    for (int i = 1; i <= 15; i++) {
      vector<int> vv = decimal(i);
      string second = "";
      for (auto j : vv) second += char(j + '0');
      while (second.size() != 4) second = "0" + second;
      v[i] = second;
    }
    vector<vector<string>> vec(n, vector<string>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x;
        cin >> x;
        vec[i][j] = v[x];
      }
    }
    vector<int> arr;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int c = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!visited[i][j]) {
          int cc = 0;
          ++c;
          dfs(i, j, n, m, vec, visited, cc);
          arr.push_back(cc);
        }
      }
    }
    sort(arr.begin(), arr.end(), greater<int>());
    for (auto i : arr) cout << i << " ";
    cout << endl;
  }
}
