#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
void solve() {
  string str;
  cin >> str;
  int sw1 = 0, sw2 = 0, sl1 = 0, sl2 = 0;
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      if (str[i] == '1') {
        sw1++;
        sl1++;
      } else if (str[i] == '?') {
        sw1++;
      }
      if (sl2 > (10 - i) / 2 - 1 + sl1) {
        cout << i + 1 << endl;
        return;
      }
      if (sw1 > (10 - i) / 2 + sw2) {
        cout << i + 1 << endl;
        return;
      }
    } else {
      if (str[i] == '1') {
        sw2++;
        sl2++;
      } else if (str[i] == '?') {
        sl2++;
      }
      if (sw1 > (10 - i - 1) / 2 + sw2) {
        cout << i + 1 << endl;
        return;
      }
      if (sl2 > (10 - i - 1) / 2 + sl1) {
        cout << i + 1 << endl;
        return;
      }
    }
  }
  cout << 10 << endl;
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) solve();
  return 0;
}
