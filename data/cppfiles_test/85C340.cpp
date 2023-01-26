#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void eraseAllSubStr(std::string& mainStr, const std::string& toErase) {
  size_t pos = std::string::npos;
  while ((pos = mainStr.find(toErase)) != std::string::npos) {
    mainStr.erase(pos, toErase.length());
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    ll one = 0;
    ll zer = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        zer++;
      } else {
        one++;
      }
    }
    if (zer == 0) {
      int ans = 0;
      cout << ans << "\n";
      continue;
    }
    if (one == 0) {
      int ans = 1;
      cout << ans << "\n";
      continue;
    }
    if (zer == 1) {
      cout << 1 << "\n";
      continue;
    }
    if (one != 0 && zer > 1) {
      string zero;
      while (zer--) {
        zero.push_back('0');
      }
      eraseAllSubStr(s, zero);
      bool flag = true;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
          flag = false;
          break;
        }
      }
      if (flag == false) {
        cout << 2 << "\n";
        continue;
      } else {
        cout << 1 << "\n";
      }
    }
  }
  return 0;
}
