#include <bits/stdc++.h>
using namespace std;
string s, t;
bool solve(int i) {
  int n = s.size(), j = 1, n2 = t.length();
  string temp;
  while (i < n) {
    if (j <= n2 && s[i] == t[j - 1]) {
      j++;
      temp.push_back(s[i]);
    } else {
      if (temp.size()) {
        temp.pop_back();
        j--;
      }
    }
    i++;
  }
  if (temp == t) return true;
  return false;
}
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  int k;
  cin >> k;
  while (k--) {
    cin >> s >> t;
    int i;
    bool flag = false;
    for (i = 0; i < s.length(); i++) {
      if (s[i] == t[0] && solve(i)) {
        flag = true;
        cout << "YES\n";
        break;
      }
    }
    if (!flag) cout << "NO\n";
  }
  return 0;
}
