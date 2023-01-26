#include <bits/stdc++.h>
using namespace std;
void f(string s, int n) {
  int ans = 0;
  ans += s[n - 1] - '0';
  for (int i = n - 2; i >= 0; i--) {
    if (s[i] != '0') {
      ans += (s[i] - '0');
      ans += 1;
    }
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    f(s, n);
  }
}
