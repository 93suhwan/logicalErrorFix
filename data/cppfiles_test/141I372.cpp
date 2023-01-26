#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b;
  cin >> a >> b;
  int aa[19];
  int bb[19];
  if (a == b) {
    cout << 0 << endl;
    return;
  }
  int k = 0;
  while (a != 0) {
    int r = a % 10;
    a /= 10;
    aa[k++] = r;
  }
  int sa = k;
  k = 0;
  while (b != 0) {
    int r = b % 10;
    b /= 10;
    bb[k++] = r;
  }
  int sb = k;
  if (sb < sa) {
    cout << "-1";
  } else {
    string bbb = "";
    int pa, push_back;
    pa = push_back = 0;
    for (int i = 0; i < sa; i++) {
      if (push_back == sb) {
        cout << "-1\n";
        return;
      }
      if (bb[push_back] >= aa[i]) {
        int d = bb[push_back] - aa[i];
        char c = '0' + d;
        bbb += c;
        push_back++;
      } else {
        if (push_back == sb - 1) {
          cout << "-1\n";
          return;
        } else {
          int d = bb[push_back + 1] * 10 + bb[push_back];
          d = d - aa[i];
          if (d >= 10) {
            cout << "-1\n";
            return;
          }
          char c = '0' + d;
          bbb += c;
          push_back += 2;
        }
      }
    }
    if (push_back < sb) {
      while (push_back != sb) {
        int d = bb[push_back];
        char c = '0' + d;
        bbb += c;
        push_back++;
      }
    }
    reverse(bbb.begin(), bbb.end());
    if (bbb[0] != '0')
      cout << bbb << endl;
    else {
      string ans = "";
      int pos = 0;
      for (int i = 1; i < bbb.size(); i++) {
        if (bbb[i] != '0') {
          pos = i;
          break;
        }
      }
      for (int i = pos; i < bbb.size(); i++) {
        ans += bbb[i];
      }
      cout << ans << endl;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
