#include <bits/stdc++.h>
using namespace std;
bool iSp(int x) {
  long long i;
  for (i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      return 1;
      exit;
    }
  }
  return 0;
}
bool IsSub(string a, string b) {
  string c;
  long long i;
  for (i = 0; i <= b.size() - a.size(); i++) {
    c = b.substr(i, a.size());
    if (c == a) {
      return true;
      exit;
    }
  }
  return false;
}
map<long long, long long> A;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, t, i, r, x, j, y, ans, s, p;
  cin >> t;
  while (t--) {
    cin >> n;
    long long a[n + 2], b[n + 2];
    for (i = 1; i <= n; i++) cin >> a[i];
    for (i = 1; i <= n; i++) cin >> b[i];
    for (i = 1; i <= n; i++) {
      if (a[i] < b[1]) break;
    }
    for (j = 1; j <= n; j++) {
      if (b[j] > a[1]) break;
    }
    cout << min(i - 1, j - 1) << endl;
  }
}
