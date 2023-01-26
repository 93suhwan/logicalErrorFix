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
bool check(string t, string y) {
  bool sub = false;
  int start = -1;
  int j = 0;
  for (long long i = long long(0); i < long long(y.size()); i++) {
    if (start == -1 && t[0] == y[i]) {
      start = i;
      j++;
    } else if (start != -1 && t[j] == y[i]) {
      j++;
      if (j == t.size()) {
        sub = true;
        break;
      }
    } else if (start != -1 && t[j] != y[i]) {
      start = -1;
      j = 0;
    }
  }
  bool crude = true;
  if (!sub) return false;
  if (sub) {
    for (long long i = long long(0); i < long long(start); i++) {
      if (y[i] == '0') {
        crude = false;
        break;
      }
    }
    if (!crude) return false;
    for (long long i = long long(start + t.size()); i < long long(y.size());
         i++) {
      if (y[i] == '0') {
        crude = false;
        break;
      }
    }
    return crude;
  }
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
  reverse(trial.begin(), trial.end());
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
