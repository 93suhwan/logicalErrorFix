#include <bits/stdc++.h>
using namespace std;
void iofun() {}
long long Pow(long long c, long long d) {
  return d == 0 ? 1 : c * pow(c, d - 1);
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return ((a * b) / gcd(a, b)); }
void solve() {
  int n;
  string s, fs, second, ms;
  cin >> n >> s;
  int p1, p2;
  bool f = true;
  for (int i = 0, j = n - 1; i < j; ++i, j--) {
    if (s[i] != s[j]) {
      f = false;
      p1 = i;
      p2 = j;
      break;
    }
  }
  if (f) {
    cout << "0\n";
    return;
  } else {
    bool f1 = false;
    int cnt = 0;
    for (int i = 0, j = n - 1; i < j;) {
      if (s[i] != s[j]) {
        if (s[i] == s[p1]) {
          cnt++;
          i++;
        } else if (s[j] == s[p1]) {
          cnt++;
          j--;
        } else {
          f1 = true;
          break;
        }
      } else {
        i++;
        j--;
      }
    }
    bool f2 = false;
    int cnt1 = 0;
    for (int i = 0, j = n - 1; i < j;) {
      if (s[i] != s[j]) {
        if (s[i] == s[p2]) {
          cnt1++;
          i++;
        } else if (s[j] == s[p2]) {
          cnt1++;
          j--;
        } else {
          f2 = true;
          break;
        }
      } else {
        i++;
        j--;
      }
    }
    if (f1) cnt = INT_MAX;
    if (f2) cnt1 = INT_MAX;
    if (f1 & f2)
      cout << "-1\n";
    else
      cout << min(cnt, cnt1) << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  iofun();
  long long tc;
  cin >> tc;
  while (tc--) {
    solve();
  };
  return 0;
}
