#include <bits/stdc++.h>
using namespace std;
long long t, n, k, x, ba[2005], dp[2005];
string s;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  cin >> t;
  for (long long ca = 1; ca <= t; ++ca) {
    cin >> n >> k >> x >> s;
    --x;
    long long it = 0, c = 0, tar = 0;
    for (int i = 0; i < 2005; ++i) {
      ba[i] = dp[i] = 0;
    }
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '*') {
        c += k;
      } else {
        if (c) {
          ba[it++] = c;
          c = 0;
        }
      }
    }
    if (c) {
      ba[it++] = c;
      c = 0;
    }
    c = 1;
    for (int i = it; i >= 0; --i) {
      c = ba[i] * c + c;
      dp[i] = c;
      if (c >= x) {
        tar = i;
        break;
      }
    }
    for (int i = tar; i <= it; ++i) {
      if (dp[i] > x) {
        ba[i] = 0;
      } else {
        ba[i] = x / dp[i];
        x %= dp[i];
      }
    }
    c = 0;
    it = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'a') {
        if (c) {
          ++it;
        }
        c = 0;
        if (it >= tar) {
          while (ba[it]) {
            ba[it]--;
            cout << 'b';
          }
        }
        cout << 'a';
      } else {
        ++c;
      }
    }
    if (c) {
      ++it;
    }
    if (it >= tar) {
      while (ba[it]) {
        ba[it]--;
        cout << 'b';
      }
    }
    cout << "\n";
  }
}
