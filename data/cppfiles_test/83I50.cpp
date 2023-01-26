#include <bits/stdc++.h>
using namespace std;
const int inf = 2e18 + 100;
const int maxn = 1e6 + 100;
string a[maxn], b[maxn];
map<string, int> mp;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int cnt = 0, len = 0;
    for (int i = 0; i < n; i++) {
      string tp = "";
      for (int j = i; j < n; j++) {
        tp += str[j];
        a[++cnt] = tp;
      }
    }
    b[len] = a[len];
    for (int i = 2; i <= cnt; i++) {
      if (a[i] > b[len]) {
        b[++len] = a[i];
      } else {
        int pos = lower_bound(b + 1, b + len + 1, a[i]) - b;
        b[pos] = a[i];
      }
    }
    cout << len << "\n";
  }
}
