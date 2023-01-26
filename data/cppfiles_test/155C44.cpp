#include <bits/stdc++.h>
using namespace std;
long long gcd(long long n, long long m) {
  if (m == 0)
    return n;
  else
    return gcd(m, n % m);
}
int longestsub(string x, string y, int n, int m) {
  int lcs[n + 1][m + 1];
  int result = 0;
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < m + 1; j++) {
      if (i == 0 || j == 0) {
        lcs[i][j] = 0;
      } else if (x[i - 1] == y[j - 1]) {
        lcs[i][j] = 1 + lcs[i - 1][j - 1];
        result = max(result, lcs[i][j]);
      } else
        lcs[i][j] = 0;
    }
  }
  return result;
}
long long fast_pow(long long a, long long p) {
  long long res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = a * 1ll * a % 1000000007;
      p /= 2;
    } else {
      res = res * 1ll * a % 1000000007;
      p--;
    }
  }
  return res;
}
long long fact(long long n) {
  long long res = 1;
  for (int i = 1; i <= n; i++) {
    res = res * 1ll * i % 1000000007;
  }
  return res;
}
long long C(long long n, long long k) {
  return fact(n) * 1ll * fast_pow(fact(k), 1000000007 - 2) % 1000000007 * 1ll *
         fast_pow(fact(n - k), 1000000007 - 2) % 1000000007;
}
bool mycmp(pair<int, int> p1, pair<int, int> p2) {
  return p1.second <= p2.second;
}
bool mycmp1(pair<int, int> p1, pair<int, int> p2) {
  return p1.second >= p2.second;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int p[n], q[n];
    string s;
    for (int i = 0; i < n; i++) cin >> p[i];
    cin >> s;
    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') cnt1++;
    }
    if (cnt1 == 0 or cnt1 == n) {
      for (int i = 0; i < n; i++) {
        q[i] = p[i];
      }
    } else {
      vector<pair<int, int>> v, t;
      for (int i = 0; i < n; i++) {
        if (s[i] == '0')
          v.push_back({i, p[i]});
        else
          t.push_back({i, p[i]});
      }
      sort(v.begin(), v.end(), mycmp);
      sort(t.begin(), t.end(), mycmp1);
      int x = 1, y = n;
      for (auto i : v) {
        q[i.first] = x;
        x++;
      }
      for (auto i : t) {
        q[i.first] = y;
        y--;
      }
    }
    for (auto i : q) cout << i << " ";
    cout << '\n';
  }
}
