#include <bits/stdc++.h>
using namespace std;
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }
int gcd(unsigned long long a, unsigned long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool compare(pair<unsigned long long, int> &a,
             pair<unsigned long long, int> &b) {
  return a.first <= b.first;
}
struct s {
  int x, y;
};
bool check(unsigned long long x) {
  unsigned long long p = sqrt(x);
  p = p - 1 >= 0 ? p - 1 : p;
  while (p * p < x) {
    p++;
  }
  return p * p == x ? true : false;
}
int pow(int a, int b) {
  if (b == 0) return 1;
  unsigned long long y = pow(a, b / 2);
  if (b % 2) {
    return (((y * y) % 1000000007) * a) % 1000000007;
  }
  return (y * y) % 1000000007;
}
unsigned long long pow(int x) {
  if (x == 0) return 1;
  if (x & 1) return pow(x / 2) * pow(x / 2) * 2;
  return pow(x / 2) * pow(x / 2);
}
bool check_prime(int n) {
  if (n == 1) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
void dfs(vector<vector<int>> &v, int i, bool visited[], stack<int> &s) {
  visited[i] = true;
  for (auto x : v[i]) {
    if (visited[x] == false) {
      dfs(v, x, visited, s);
    }
  }
  s.push(i);
}
void dfsutil(vector<vector<int>> &v, bool visited[], int i, vector<int> &ans) {
  visited[i] = true;
  ans.push_back(i + 1);
  for (auto x : v[i]) {
    if (visited[x] == false) {
      dfsutil(v, visited, x, ans);
    }
  }
}
const long long maxm = 2 * (long long)(1e5) + 2;
void main_() {
  long long n, m;
  cin >> n >> m;
  long long a, b;
  cin >> a >> b;
  long long x, y;
  cin >> x >> y;
  long long p, q;
  p = (a <= x) ? (x - a) : (2 * n - a - x);
  q = (b <= y) ? (y - b) : (2 * m - b - y);
  cout << min(p, q) << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test = 1;
  cin >> test;
  while (test--) {
    main_();
  }
  return 0;
}
