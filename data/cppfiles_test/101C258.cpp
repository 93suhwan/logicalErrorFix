#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int maxn = 2e5 + 10;
int a[maxn];
char c[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> b;
    vector<int> r;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> c[i];
      if (c[i] == 'B')
        b.push_back(a[i]);
      else
        r.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    sort(r.begin(), r.end());
    int pos = 1;
    bool ok = 1;
    for (auto i : b) {
      if (i < pos) {
        ok = 0;
        break;
      }
      pos++;
    }
    if (!ok) {
      cout << "NO" << endl;
      continue;
    }
    for (auto i : r) {
      if (i > pos) {
        ok = 0;
        break;
      }
      pos++;
    }
    if (!ok) {
      cout << "NO" << endl;
    } else
      cout << "YES" << endl;
  }
  return 0;
}
