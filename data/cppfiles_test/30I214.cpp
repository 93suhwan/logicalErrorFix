#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3F3F3F3F;
const long long N = 1e5 + 7;
const long long mod = 1e9 + 7;
vector<int> a[30];
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    int c;
    int ans = -1;
    int mid1, mid2;
    if (n & 1) {
      mid1 = mid2 = n / 2;
    } else {
      mid2 = n / 2;
      mid1 = mid2 - 1;
    }
    for (int i = 0; i < n; i++) {
      c = s[i] - 'a';
      a[c].push_back(i);
    }
    for (int i = 0; i < 26; i++) {
      if (!a[i].empty()) {
        string noww;
        for (int j = 0; j < n; j++) {
          if (s[j] != 'a' + i) noww += s[j];
        }
        string re;
        re.assign(noww.rbegin(), noww.rend());
        if (re == noww) {
          int l, r;
          l = 0;
          r = a[i].size();
          r--;
          int val = noww.size();
          while (l <= r) {
            if (l == r && n & 1 && a[i][l] == mid1)
              val++;
            else if (mid1 - a[i][l] == a[i][r] - mid2)
              val += 2;
            l++;
            r--;
          }
          ans = max(ans, val);
        }
      }
      a[i].resize(0);
    }
    if (ans == -1)
      cout << -1 << '\n';
    else
      cout << n - ans << '\n';
  }
  return 0;
}
