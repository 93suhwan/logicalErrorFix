#include <bits/stdc++.h>
using namespace std;
vector<long long> fact(1001, 1);
long long pow(long long x, unsigned long long y, long long p) {
  long long res = 1LL;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long _pow(int a, int b) {
  if (!b) return 1;
  long long temp = _pow(a, b / 2);
  temp = (temp * temp);
  if (b % 2) return (a * temp);
  return temp;
}
long long invmod(int a, int m) { return pow(a, m - 2, m); }
long long ncr(int n, int r) {
  if (n < r) return 0;
  long long ans = fact[n];
  ans *= invmod(fact[n - r], 1000000007);
  ans %= 1000000007;
  ans *= invmod(fact[r], 1000000007);
  ans %= 1000000007;
  return ans;
}
long long ncr_2(long long n, long long k) {
  if (k > n) return 0;
  if (k * 2 > n) k = n - k;
  if (k == 0) return 1;
  long long result = n;
  for (long long i = 2; i <= k; ++i) {
    result = result * (n - i + 1);
    result /= i;
  }
  return result;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int tc = 1;
  cin >> tc;
  for (long long ti = 0; ti < tc; ti++) {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(5, 0));
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < 5; j++) {
        cin >> v[i][j];
      }
    }
    string ans = "NO";
    set<int> s, t;
    for (int i = 0; i < 4; i++) {
      s.clear();
      for (long long j = 0; j < n; j++) {
        if (v[j][i]) {
          s.insert(j);
        }
      }
      for (int j = i + 1; j < 5; j++) {
        t.clear();
        set<int> st = s;
        for (long long k = 0; k < n; k++) {
          if (v[k][j] && st.find(k) == st.end()) {
            t.insert(k);
          }
        }
        if (t.size() == n / 2 && st.size() == n / 2) {
          ans = "YES";
          break;
        }
        if (st.size() > t.size()) {
          for (long long k = 0; k < n; k++) {
            if (st.size() == n / 2 && t.size() == n / 2) {
              ans = "YES";
              break;
            }
            if (v[k][j] && st.find(k) != st.end()) {
              t.insert(k);
              s.erase(k);
            }
          }
        } else {
          for (long long k = 0; k < n; k++) {
            if (st.size() == n / 2 && t.size() == n / 2) {
              ans = "YES";
              break;
            }
            if (v[k][i] && t.find(k) != t.end()) {
              st.insert(k);
              t.erase(k);
            }
          }
        }
        if (st.size() == t.size() && st.size() == n / 2) {
          break;
        }
      }
      if (ans == "YES") break;
    }
    cout << ans << '\n';
  }
}
