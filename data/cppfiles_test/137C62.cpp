#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 7;
const long long MOD = 998244353;
const double pi = acos(-1);
const double eps = 1e-4;
vector<int> di = {-1, 1, 0, 0}, dj = {0, 0, -1, 1};
string to_bin(long long x) {
  string ans;
  while (x) {
    if (x % 2 == 1)
      ans += "1";
    else
      ans += "0";
    x /= 2;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
int main() {
  long long a, b;
  cin >> a >> b;
  string bina = to_bin(a);
  string binb = to_bin(b);
  if (a == b) {
    cout << "YES"
         << "\n";
    return 0;
  }
  vector<string> s;
  if (bina.back() == '0')
    s.push_back(bina + "1");
  else
    s.push_back(bina);
  for (int i = bina.size() - 1; i >= 0; i--) {
    if (bina[i] != '0') {
      s.push_back(bina.substr(0, i + 1));
      break;
    }
  }
  int n = s.size();
  for (int i = 0; i < n; i++) {
    string tep = s[i];
    reverse(tep.begin(), tep.end());
    s.push_back(tep);
  }
  bool ok = false;
  for (int i = 0; i < s.size(); i++) {
    int pos = binb.find(s[i]);
    bool yes = true;
    if (pos != binb.npos) {
      for (int j = 0; j < pos; j++)
        if (binb[j] != '1') yes = false;
      for (int j = pos + s[i].size(); j < binb.size(); j++)
        if (binb[j] != '1') yes = false;
      if (yes) {
        ok = true;
        break;
      }
    }
  }
  if (ok)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
  return 0;
}
