#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
const long long mod = 998244353;
const long long mxN = 2e2 + 1;
void fileio() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
vector<long long> find(vector<long long> &a, long long &x0, long long &x1,
                       long long ind) {
  long long n = 6;
  for (long long i = 1; i < n - 1; i++) {
    if (a[i] != -1) continue;
    cout << "? " << i + ind << " " << i + 1 + ind << " " << i + 2 + ind << endl;
    cin >> a[i];
  }
  vector<long long> res(n + 1, -1);
  for (long long i = 1; i < n - 2; i++) {
    if (a[i] == 0 && a[i + 1] == 1) {
      res[i] = 0;
      res[i + 3] = 1;
      if (x1 == -1) x0 = i, x1 = i + 3;
    }
    if (a[i] == 1 && a[i + 1] == 0) {
      res[i] = 1;
      res[i + 3] = 0;
      if (x1 == -1) x0 = i + 3, x1 = i;
    }
  }
  for (long long i = 1; i < n + 1; i++) {
    if (res[i] != -1) continue;
    cout << "? " << x0 + ind << " " << x1 + ind << " " << i + ind << endl;
    cin >> res[i];
  }
  x0 += ind;
  x1 += ind;
  return res;
}
void solve() {
  long long n;
  cin >> n;
  long long x0 = -1, x1 = -1;
  vector<long long> a(n + 1, -1), res(n + 1, -1);
  for (long long i = 1; i < n - 1; i++) {
    cout << "? " << i << " " << i + 1 << " " << i + 2 << endl;
    cin >> a[i];
    i += 2;
  }
  for (long long i = 1; i < n - 2; i++) {
    if (a[i] != a[i + 3]) {
      vector<long long> b(7, -1);
      b[1] = a[i];
      b[4] = a[i + 3];
      vector<long long> v = find(b, x0, x1, i - 1);
      for (long long j = 1; j < 7; j++) res[i + j - 1] = v[j];
      break;
    }
    i += 2;
  }
  for (long long i = 1; i < n - 1; i++) {
    if (res[i] != -1) {
      i += 2;
      continue;
    }
    if (a[i] == 0) {
      cout << "? " << i << " " << i + 1 << " " << x1 << endl;
      long long q;
      cin >> q;
      if (q == 0) {
        res[i] = 0;
        res[i + 1] = 0;
        cout << "? " << i + 2 << " " << x0 << " " << x1 << endl;
        cin >> res[i + 2];
      } else {
        res[i + 2] = 0;
        cout << "? " << i << " " << x0 << " " << x1 << endl;
        cin >> res[i];
        if (res[i] == 0)
          res[i + 1] = 1;
        else
          res[i + 1] = 0;
      }
    } else {
      cout << "? " << i << " " << i + 1 << " " << x0 << endl;
      long long q;
      cin >> q;
      if (q == 1) {
        res[i] = 1;
        res[i + 1] = 1;
        cout << "? " << i + 2 << " " << x0 << " " << x1 << endl;
        cin >> res[i + 2];
      } else {
        res[i + 2] = 1;
        cout << "? " << i << " " << x0 << " " << x1 << endl;
        cin >> res[i];
        if (res[i] == 0)
          res[i + 1] = 1;
        else
          res[i + 1] = 0;
      }
    }
    i += 2;
  }
  long long ans = 0;
  for (long long i = 1; i < n + 1; i++)
    if (res[i] == 0) ans++;
  cout << "! ";
  cout << ans << " ";
  for (long long i = 1; i < n + 1; i++)
    if (res[i] == 0) cout << i << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int tc;
  cin >> tc;
  while (tc--) solve();
}
