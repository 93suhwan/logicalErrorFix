#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
const long long INF = 1e18;
using namespace std;
long long hcf(long long a, long long b) {
  if (b == 0) return a;
  return hcf(b, a % b);
}
long long lcm(long long a, long long b) { return (a / hcf(a, b)) * b; }
long long stringtoll(string s) {
  long long ans = 0;
  for (long long i = 0; i < s.length(); i++) {
    ans = ans * 10 + (s[i] - '0');
  }
  return ans;
}
bool ifprime(long long n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long logat(long long n, long long base) { return (log(n) / log(base)); }
vector<long long> root(long long n) {
  vector<long long> ans;
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      ans.push_back(i);
      if (i != n / i) ans.push_back(n / i);
    }
  }
  return ans;
}
vector<pair<long long, long long>> prime_fact(long long n) {
  vector<pair<long long, long long>> ans;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      long long another = 0;
      while (n % i == 0) {
        n = n / i;
        another++;
      }
      ans.push_back({i, another});
    }
  }
  if (n > 1) ans.push_back({n, 1});
  return ans;
}
long long clearbits(long long n, long long i, long long j) {
  long long a = (~0) << (j + 1);
  long long b = ~((~0) << (i));
  long long mask = a | b;
  long long ans = mask & n;
  return ans;
}
vector<vector<long long>> multiplymatrix(vector<vector<long long>> a,
                                         vector<vector<long long>> b) {
  long long n1 = a.size();
  long long n2 = b.size();
  long long m2 = b[0].size();
  vector<vector<long long>> ans(n1, vector<long long>(m2));
  for (long long i = 0; i < n1; i++) {
    for (long long j = 0; j < m2; j++) {
      long long sum = 0;
      for (long long k = 0; k < n2; k++) {
        sum = (sum + (a[i][k] * b[k][j]) % 1000000007) % 1000000007;
      }
      ans[i][j] = sum;
    }
  }
  return ans;
}
vector<vector<long long>> expomatrix(long long k, vector<vector<long long>> a) {
  long long n = a.size();
  long long m = a[0].size();
  vector<vector<long long>> ans(n, vector<long long>(m));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (i == j) ans[i][j] = 1;
    }
  }
  while (k > 0) {
    if (k % 2) {
      ans = multiplymatrix(ans, a);
      k--;
    } else {
      a = multiplymatrix(a, a);
      k = k / 2;
    }
  }
  return ans;
}
long long computematrixexpo(long long n, long long k, vector<long long> b,
                            vector<long long> c) {
  vector<vector<long long>> f1(k, vector<long long>(1));
  for (long long i = 0; i < k; i++) {
    f1[i][0] = b[i];
  }
  vector<vector<long long>> tran(k, vector<long long>(k, 0));
  for (long long i = 0; i < k; i++) {
    for (long long j = 0; j < k; j++) {
      if (i != k - 1) {
        if (i + 1 == j) tran[i][j] = 1;
      } else {
        tran[i][j] = c[k - j - 1];
      }
    }
  }
  vector<vector<long long>> ans = expomatrix(n - 1, tran);
  vector<vector<long long>> yo = multiplymatrix(ans, f1);
  return yo[0][0];
}
void baspri(bool flag) {
  if (flag)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
}
long long pw(long long n, long long r, long long mop) {
  long long res = 1;
  while (r != 0) {
    if (r % 2) {
      res = (res * n) % mop;
      r--;
    }
    n = (n * n) % mop;
    r = r / 2;
  }
  return res;
}
void solve() {
  long long n;
  cin >> n;
  vector<vector<long long>> v(n, vector<long long>(5));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < 5; j++) cin >> v[i][j];
  }
  for (long long i = 0; i < 5; i++) {
    for (long long j = i + 1; j < 5; j++) {
      vector<long long> temp(5, 0);
      temp[i] = 1;
      temp[j] = 1;
      long long ii = 0;
      long long jj = 0;
      long long kk = 0;
      bool flag = true;
      for (long long k = 0; k < n; k++) {
        if (v[k][i] == 1 && v[k][j] == 1)
          kk++;
        else if (v[k][i] == 1)
          ii++;
        else if (v[k][j] == 1)
          jj++;
        else {
          flag = false;
          break;
        }
      }
      if (flag) {
        if (ii <= n / 2 && jj <= n / 2) {
          cout << "YES"
               << "\n";
          return;
        }
      }
    }
  }
  cout << "NO"
       << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
