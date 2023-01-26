#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  string s1, s2;
  cin >> s1;
  cin >> s2;
  if (count(s1.begin(), s1.end(), '0') == n &&
      count(s1.begin(), s1.end(), '0') == n) {
    cout << 2 * s1.size() << "\n";
    return;
  } else if (count(s1.begin(), s1.end(), '1') == n &&
             count(s1.begin(), s1.end(), '1') == n) {
    cout << 0 << "\n";
    return;
  }
  long long int mex = 0;
  string aa = "";
  vector<string> a;
  for (long long int i = 0; i < n; i++) {
    if (s1.at(i) != s2.at(i)) {
      mex += 2;
      if (aa != "") {
        a.push_back(aa);
        aa = "";
      }
    } else {
      aa = aa + s1.at(i);
    }
  }
  if (aa != "") {
    a.push_back(aa);
    aa = "";
  }
  vector<string>::iterator i;
  for (i = a.begin(); i != a.end(); i++) {
    string s = *i;
    if (count(s.begin(), s.end(), '1') == s.size()) {
      mex += 0;
    } else if (count(s.begin(), s.end(), '0') == s.size()) {
      mex += s.size();
    } else {
      for (long long int i = 0; i != s.length() - 1; i++) {
        if ((s.at(i) == '0' && s.at(i + 1) == '1') ||
            (s.at(i) == '1' && s.at(i + 1) == '0')) {
          s.at(i) = '*';
          s.at(i + 1) = '*';
          mex += 2;
        }
      }
      mex += count(s.begin(), s.end(), '0');
    }
  }
  cout << mex << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
