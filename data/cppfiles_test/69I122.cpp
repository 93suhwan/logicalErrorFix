#include <bits/stdc++.h>
using namespace std;
int str(string& s1, string& s2) {
  int n = s1.length(), m = s2.length();
  int i = 0, j = 0;
  while (i < n) {
    if (s1[i] == s2[j]) ++j;
    ++i;
  }
  return j + 1;
}
string a[32];
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < 32; ++i) {
    int num = 1 << i;
    a[i] = to_string(num);
  }
  while (t) {
    --t;
    string num;
    cin >> num;
    int n = num.length();
    int ans = 30;
    for (int i = 0; i < 32; ++i) {
      int len = str(num, a[i]);
      int minN = n + a[i].length() - 2 * len;
      ans = min(ans, minN);
    }
    cout << ans << endl;
  }
  return 0;
}
