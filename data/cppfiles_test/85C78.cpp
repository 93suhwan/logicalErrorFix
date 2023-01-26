#include <bits/stdc++.h>
using namespace std;
const int N = 2020;
int a[N];
void solve() {
  string s;
  cin >> s;
  int len = s.length();
  int f1 = 0, f2 = 0, f3 = 0;
  for (int i = 0; i < len; i++) {
    if (s[i] == '0') {
      while (s[i] == '0' && i < len) {
        i++;
      }
      f1++;
    }
    if (s[i] == '1') f2++;
  }
  if (f1 == 1) {
    cout << 1 << endl;
    return;
  }
  if (f1 && !f2) {
    cout << 1 << endl;
  } else if (!f1) {
    cout << 0 << endl;
  } else
    cout << 2 << endl;
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
