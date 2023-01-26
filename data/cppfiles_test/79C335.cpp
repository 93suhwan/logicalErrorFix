#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
struct interval {
  long long sp, b;
};
bool compareInterval(interval i1, interval i2) {
  if (i1.sp == i2.sp) return (i1.b < i2.b);
  return (i1.sp < i2.sp);
}
void solve() {
  long long i, j, n;
  cin >> n;
  string s, mv = "";
  cin >> s;
  int a[100] = {0};
  int ms = INT_MAX;
  a[s[0]]++;
  if (s[0] == '1' || s[0] == '4' || s[0] == '6' || s[0] == '8' || s[0] == '9') {
    cout << 1 << endl;
    cout << s[0] << endl;
    return;
  }
  for (int i = 1; i < n; i++) {
    if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' ||
        s[i] == '9') {
      cout << 1 << endl;
      cout << s[i] << endl;
      return;
    } else if (ms > 2) {
      if (s[i] == '2' || s[i] == '5') {
        ms = 2;
        mv = "";
        mv = mv + s[i - 1] + s[i];
      } else if (a[s[i]] > 0) {
        ms = 2;
        mv = "";
        mv = mv + s[i] + s[i];
      } else if (s[i] == '7') {
        if (s[0] == '2') {
          ms = 2;
          mv = "27";
        }
        if (s[0] == '5') {
          ms = 2;
          mv = "57";
        }
      }
    }
    a[s[i]] += 1;
  }
  cout << ms << endl << mv << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
