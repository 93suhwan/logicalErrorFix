#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = LLONG_MAX;
string binary(long long x) {
  if (x > 1) {
    if (x % 2 != 0)
      return binary(x / 2) + '1';
    else
      return binary(x / 2) + '0';
  } else if (x % 2 == 1)
    return "1";
  else
    return "0";
}
bool onecheck(string s) {
  bool check = true;
  for (long long i = long long(0); i < long long(s.size()); i++) {
    if (s[i] != '1') {
      check = false;
      break;
    }
  }
  return check;
}
bool check(string t, string y) {
  int i = 0;
  while (i + t.size() <= y.size()) {
    string s1 = y.substr(0, i);
    string s2 = y.substr(i, t.size());
    string s3 = y.substr(i + t.size(), y.size() - s1.size() - s2.size());
    if (onecheck(s1) && onecheck(s3) && s2 == t) return true;
    i++;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long x;
  cin >> x;
  ;
  long long y;
  cin >> y;
  ;
  string s1 = binary(x);
  string s2 = binary(y);
  if (s1 == s2) {
    cout << "YES" << endl;
    return 0;
  }
  string t1 = s1 + '1';
  string t2 = t1;
  reverse(t1.begin(), t1.end());
  string trial = s1;
  bool foound = false;
  string t3 = "";
  for (int i = 0; i < trial.size(); i++) {
    if (!foound && trial[i] == '0') continue;
    if (!foound && trial[i] == '1') {
      foound = true;
      t3 += '1';
    } else
      t3 += trial[i];
  }
  string t4 = t3;
  reverse(t4.begin(), t4.end());
  if (check(t1, s2) || check(t2, s2) || check(t3, s2) || check(t4, s2))
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
