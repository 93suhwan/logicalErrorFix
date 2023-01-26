#include <bits/stdc++.h>
using namespace std;
bool isPrime[1000005] = {false};
vector<long long> prm;
vector<long long> SPF(1000005);
void sieve() {
  isPrime[1] = isPrime[0] = 0;
  long long i;
  for (i = 2; i < 1000005; ++i) isPrime[i] = 1;
  for (i = 2; i * i < 1000005; ++i) {
    if (isPrime[i]) {
      for (long long j = i * i; j < 1000005; j += i) isPrime[j] = 0;
    }
  }
  if (!prm.empty()) prm.clear();
  for (i = 2; i < 1000005; ++i) {
    if (isPrime[i]) prm.push_back(i);
  }
}
bool flip(bool f) {
  if (f) return 0;
  return 1;
}
long long fastPower(long long a, long long b) {
  if (b == 0) return 1;
  long long prod = 1;
  while (b > 0) {
    if (b & 1) prod = prod * a;
    b = b >> 1;
    a = a * a;
  }
  return prod;
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; i++) {
    res *= i;
  }
  return res;
}
long long nCr(long long n, long long r) {
  return (long double)fact(n) / (long double)(fact(r) * fact(n - r));
}
void printa(bool f) {
  if (f)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
}
long long dfsL(vector<vector<long long> > &a, vector<vector<long long> > &vis,
               long long i, long long j, bool cnt) {
  long long n = a.size(), m = a[0].size();
  long long res = 0;
  while (i > 0 && j > 0) {
    if (a[i][j] != 1) break;
    if (cnt)
      ++res;
    else
      vis[i][j] = 1;
    --i;
    --j;
  }
  return res;
}
long long dfsR(vector<vector<long long> > &a, vector<vector<long long> > &vis,
               long long i, long long j, bool cnt) {
  long long n = a.size(), m = a[0].size();
  long long res = 0;
  while (i > 0 && j <= m) {
    if (a[i][j] != 1) break;
    if (cnt)
      ++res;
    else
      vis[i][j] = 1;
    --i;
    ++j;
  }
  return res;
}
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<vector<long long> > a(n + 2, vector<long long>(m + 2, 0));
  long long i, j;
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= m; ++j) {
      char x;
      cin >> x;
      if (x == '*')
        a[i][j] = 1;
      else
        a[i][j] = 0;
    }
  }
  vector<vector<long long> > vis(n + 2, vector<long long>(m + 2, 0));
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= m; ++j) {
      if (a[i][j] != 1) continue;
      if (a[i - 1][j - 1] == 1 && a[i - 1][j + 1] == 1) {
        long long leftCnt = dfsL(a, vis, i - 1, j - 1, 1);
        long long rightCnt = dfsR(a, vis, i - 1, j + 1, 1);
        if (min(leftCnt, rightCnt) >= k) {
          dfsL(a, vis, i, j, 0);
          dfsR(a, vis, i, j, 0);
        }
      }
    }
  }
  for (i = 1; i < n + 1; ++i) {
    for (j = 1; j < m + 1; ++j) {
      if (a[i][j] == 1 && vis[i][j] != 1) {
        printa(0);
        return;
      }
    }
  }
  printa(1);
}
int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
