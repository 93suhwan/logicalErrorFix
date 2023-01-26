#include <bits/stdc++.h>
using namespace std;
int code() {
  string s;
  cin >> s;
  long long int ans1 = 0, ans2 = 0, a[2] = {0}, c = 0, o = 1;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '1') {
      a[1]++;
    } else if (s[i] == '0') {
      ans1++;
      a[0]++;
    }
  }
  for (int i = 1; i < s.length(); i++) {
    if (s[i] != s[i - 1]) c++;
  }
  if (a[0] == 0) {
    ans2 = 0;
  } else if (a[0] != 0 && a[1] == 0) {
    ans2 = 1;
  } else {
    ans2 = 2;
  }
  if (c + 1 == 2) ans2 = min(ans2, o);
  cout << min(ans1, ans2) << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    code();
  }
}
