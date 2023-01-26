#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, s;
  cin >> n >> s;
  long long int m = n, o = s;
  string str = "";
  while (s) {
    if (n % 10 > s % 10) {
      str = to_string(s % 100 - n % 10) + str;
      s /= 100;
      n /= 10;
    } else {
      str = to_string(s % 10 - n % 10) + str;
      s /= 10;
      n /= 10;
    }
  }
  long long int i = 0;
  while (str[i] == '0' && i < str.length()) {
    i++;
  }
  str = str.substr(i, str.length());
  string tmpsr = "";
  long long int tmp = stoll(str);
  while (tmp || m) {
    tmpsr = to_string(tmp % 10 + m % 10) + tmpsr;
    tmp /= 10;
    m /= 10;
  }
  if (tmpsr != to_string(o)) {
    cout << -1 << "\n";
  } else {
    cout << str << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
