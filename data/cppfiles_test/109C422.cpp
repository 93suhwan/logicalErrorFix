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
    string a;
    cin >> n >> a;
    s = 0;
    r = 0;
    for (i = 0; i < n; i++) {
      s += (a[i] - 48);
      if (i != n - 1) {
        if (a[i] != 48) r++;
      }
    }
    cout << r + s << endl;
  }
}
