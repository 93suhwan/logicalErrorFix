#include <bits/stdc++.h>
using namespace std;
long long vis[10];
vector<char> ans;
string f;
long long mx = -1;
void go() {
  string res = "";
  vis[f[0] - '0']++;
  mx = max(mx, f[0] - '0' + 0ll);
  for (int i = 0; i < f.size(); i++) {
    if (f[i] - '0' > mx) {
      vis[f[0] - '0']--;
      vis[f[0] - '0' + 1]++;
      f[0]++;
      cout << f[0];
      for (int j = 0; j < f.size() - 1; j++) {
        for (int z = 0; z <= 9; z++) {
          if (vis[z] > 0) {
            cout << z;
            break;
          }
        }
      }
      return;
    }
    if (f[i] - '0' <= mx) {
      for (int z = 0; z <= 9; z++) {
        if (z >= f[i] - '0' && vis[z] > 0) {
          res += ('0' + z);
          if (z > f[i] - '0') {
            mx = 10;
            if (i + 1 < f.size()) {
              f[i + 1] = '0';
              f[i + 1]--;
            }
          }
          break;
        }
      }
    }
  }
  cout << res;
  return;
}
int main() {
  long long Q;
  cin >> Q;
  while (Q--) {
    mx = -1;
    memset(vis, 0, sizeof vis);
    ans.clear();
    long long n, k;
    cin >> n >> k;
    string s = "";
    while (n != 0) {
      s += '0' + n % 10;
      n /= 10;
    }
    reverse(s.begin(), s.end());
    int i = 0;
    for (i = 0; i < s.size(); i++) {
      if (k == 1 && i == 0) break;
      if (k == 1) {
        while (i < s.size() && vis[s[i] - '0'] > 0) {
          ans.push_back(s[i]);
          i++;
        }
        break;
      }
      if (vis[s[i] - '0'] == 0) {
        vis[s[i] - '0']++;
        k--;
        mx = max(mx, s[i] - '0' + 0ll);
      }
      ans.push_back(s[i]);
    }
    f = "";
    for (int j = i; j < s.size(); j++) {
      f += s[j];
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i];
    if (f.size() > 0) go();
    cout << endl;
  }
  return 0;
}
