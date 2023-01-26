#include <bits/stdc++.h>
const long long MOD = (long long)1000000007;
using namespace std;
bool check(int a[], int b[]) {
  int i;
  for (i = 0; i < 26; i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a[26] = {0};
    int i;
    for (i = 0; i < s.size(); i++) {
      a[(int)s[i] - 'a']++;
    }
    map<char, int> m;
    string re = "";
    for (i = s.size() - 1; i >= 0; i--) {
      if (!m[s[i]]) re += s[i];
      m[s[i]]++;
    }
    reverse(re.begin(), re.end());
    int f = 0;
    for (i = 0; i < re.size(); i++) {
      if (a[(int)re[i] - 'a'] % (i + 1)) {
        f++;
        break;
      } else {
        a[(int)re[i] - 'a'] /= (i + 1);
      }
    }
    if (f) {
      cout << "-1"
           << "\n";
      continue;
    }
    int b[26] = {0};
    string req = "";
    for (i = 0; i < s.size(); i++) {
      req += s[i];
      b[(int)s[i] - 'a']++;
      int x = check(a, b);
      if (x) {
        break;
      }
    }
    string ans = req;
    string y = req;
    for (i = 0; i < re.size(); i++) {
      string z = "";
      for (int j = 0; j < y.size(); j++) {
        if (y[j] != re[i]) {
          z += y[j];
        }
      }
      ans += z;
      y = z;
    }
    if (ans == s)
      cout << req << " " << re << "\n";
    else
      cout << "-1"
           << "\n";
  }
}
