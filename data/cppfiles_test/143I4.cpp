#include <bits/stdc++.h>
using namespace std;
bool minimize(long long &x, long long y) {
  if (x > y) {
    x = y;
    return true;
  };
  return false;
}
bool maximize(long long &x, long long y) {
  if (x < y) {
    x = y;
    return true;
  };
  return false;
}
const int LOG = 20;
const int INF = 1e9 + 7;
const long long LNF = 1e18 + 7;
const int mod = 1e9 + 7;
long long a[200100];
long long f[200100] = {0};
long long b[200100] = {0};
long long c[200100] = {0};
long long s = 0;
long long k = 0;
long long n;
void write() {
  memset(f, 0, sizeof(f));
  s = 0, k = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    f[a[i]]++;
  }
  b[0] = f[0];
  for (int i = 1; i <= n; i++) {
    b[i] = b[i - 1] + f[i];
  }
}
void solve() {
  cout << b[0] << " ";
  long long cnt = 0;
  long long d = 0;
  c[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (b[i - 1] < i) {
      for (int j = i; j <= n; j++) cout << -1 << " ";
      cout << "\n";
      return;
    }
    cout << f[i] + k - (c[cnt] - c[cnt - d]) << " ";
    if (f[i] == 0) {
      k += i;
      d++;
    }
    if (f[i] > 1) {
      for (int j = 1; j < f[i]; j++) {
        ++cnt;
        c[cnt] = i + c[cnt - 1];
      }
    }
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  if (fopen("txt"
            ".inp",
            "r")) {
    freopen(
        "txt"
        ".inp",
        "r", stdin);
    freopen(
        "txt"
        ".out",
        "w", stdout);
  }
  int t;
  cin >> t;
  while (t--) {
    write();
    solve();
  }
  return 0;
}
