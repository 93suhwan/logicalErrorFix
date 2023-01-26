#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e18 + 100;
const long long maxn = 2e5 + 100;
string a[maxn], b[maxn];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    string str;
    cin >> str;
    long long cnt = 0;
    for (long long i = 0; i < n; i++) {
      string tp = "";
      for (long long j = i; j < n; j++) {
        tp += str[j];
        a[++cnt] = tp;
      }
    }
    long long len = 1;
    b[len] = a[len];
    for (long long i = 2; i <= cnt; i++) {
      if (a[i] > b[len]) {
        b[++len] = a[i];
      } else {
        long long pos = upper_bound(b + 1, b + len + 1, a[i]) - b;
        b[pos] = a[i];
      }
    }
    cout << len << "\n";
  }
}
