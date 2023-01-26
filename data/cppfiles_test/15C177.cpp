#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void read(T &...args) {
  ((cin >> args), ...);
}
template <typename... T>
void write(T... args) {
  ((cout << args << " "), ...);
  cout << "\n";
}
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long add(long long a, long long b) {
  a = a % 1000000007;
  b = b % 1000000007;
  return (((a + b) % 1000000007) + 1000000007) % 1000000007;
}
long long sub(long long a, long long b) {
  a = a % 1000000007;
  b = b % 1000000007;
  return (((a - b) % 1000000007) + 1000000007) % 1000000007;
}
long long mul(long long a, long long b) {
  a = a % 1000000007;
  b = b % 1000000007;
  return (((a * b) % 1000000007) + 1000000007) % 1000000007;
}
long long power(long long x, long long y) {
  long long res = 1;
  x = x % 1000000007;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % 1000000007;
    }
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res;
}
long long find(vector<long long> &parent, long long x) {
  if (parent[x] != x) parent[x] = find(parent, parent[x]);
  return parent[x];
}
void join(vector<long long> &parent, vector<long long> &rank, long long x,
          long long y) {
  long long xParent = find(parent, x);
  long long yParent = find(parent, y);
  if (xParent == yParent) return;
  if (rank[xParent] > rank[yParent]) {
    parent[yParent] = xParent;
  } else if (rank[xParent] < rank[yParent]) {
    parent[xParent] = yParent;
  } else {
    parent[xParent] = yParent;
    rank[yParent]++;
  }
}
void solve() {
  long long n, m, k;
  read(n, m, k);
  vector<vector<long long> > mat(n, vector<long long>(m, 0));
  for (long long i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (long long j = 0; j < m; j++) {
      if (str[j] == '*') mat[i][j] = 1;
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (mat[i][j] == 0) continue;
      long long len = 0;
      while (j - len >= 0 && i - len >= 0 && j + len < m) {
        if (mat[i - len][j - len] == 0 || mat[i - len][j + len] == 0) break;
        len++;
      }
      len--;
      if (len >= k) {
        for (long long p = 0; p < len + 1; p++) {
          mat[i - p][j - p] = 2;
          mat[i - p][j + p] = 2;
        }
      }
    }
  }
  bool found = false;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (mat[i][j] == 1) found = true;
    }
  }
  if (found)
    write("NO");
  else
    write("YES");
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long iter;
  cin >> iter;
  while (iter) {
    solve();
    iter--;
  }
}
