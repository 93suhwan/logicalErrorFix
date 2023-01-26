#include <bits/stdc++.h>
using namespace std;
long long vis[10];
vector<char> ans;
string f;
long long mx = -1;
void go() {
  string res = "";
  vis[f[0] - '0']++;
  string ff = f;
  mx = max(mx, f[0] - '0' + 0ll);
  for (int i = 0; i < f.size(); i++) {
    if (f[i] - '0' > mx) {
      bool flag = 0;
      for (int j = res.size() - 1; j >= 1; j--) {
        if (res[j] - '0' < mx) {
          for (int k = 0; k <= 9; k++) {
            if (k > res[j] - '0' && vis[k] > 0) {
              res[j] = '0' + k;
              flag = 1;
              break;
            }
          }
          if (flag == 0) break;
          for (int k = 0; k <= j; k++) cout << res[k];
          for (int k = j + 1; k < f.size(); k++) {
            for (int z = 0; z <= 9; z++) {
              if (vis[z] > 0) {
                cout << z;
                break;
              }
            }
          }
        }
      }
      if (flag) return;
      vis[ff[0] - '0']--;
      if (vis[ff[0] - '0' + 1] == 0)
        vis[ff[0] - '0' + 1]++;
      else
        vis[0]++;
      ff[0]++;
      cout << ff[0];
      for (int j = 0; j < ff.size() - 1; j++) {
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
            mx = 1000;
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
