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
  bool f = false;
  for (int i = 0, j = n - 1; i < j; ++i, j--) {
    if (i == j) {
      fs += s[i];
      continue;
    }
    if (f) {
      fs += s[i];
      second = s[j] + second;
    } else if (s[i] != s[j]) {
      f = true;
      fs += s[i];
      second = s[j] + second;
    }
  }
  ms = fs + second;
  if (f == false) {
    cout << "0\n";
    return;
  } else {
    bool f1 = false;
    int cnt = 0;
    for (int i = 0, j = ms.size() - 1; i < j; ++i, j--) {
      if (ms[i] != ms[j]) {
        if (ms[i] == ms[0]) {
          while (ms[i] != ms[j] && ms[i] == ms[0]) {
            cnt++;
            i++;
          }
        } else if (ms[j] == ms[0] && ms[j] == ms[0]) {
          while (ms[j] != ms[i]) {
            cnt++;
            j--;
          }
        } else {
          f1 = true;
          break;
        }
      }
    }
    if (f1) cnt = INT_MAX;
    bool f2 = false;
    int cnt1 = 0, l = ms.size() - 1;
    for (int i = 0, j = ms.size() - 1; i < j; ++i, j--) {
      if (ms[i] != ms[j]) {
        if (ms[i] == ms[l]) {
          while (ms[i] != ms[j] && ms[i] == ms[l]) {
            cnt1++;
            i++;
          }
        } else if (ms[j] == ms[l]) {
          while (ms[j] != ms[i] && ms[j] == ms[l]) {
            cnt1++;
            j--;
          }
        } else {
          f2 = true;
          break;
        }
      }
    }
    if (f2) cnt1 = INT_MAX;
    if (f1 & f2) {
      cout << "-1\n";
      return;
    } else {
      cout << min(cnt1, cnt) << endl;
      return;
    }
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
