#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, sum = 0;
  cin >> n;
  string str, ch;
  cin >> str >> ch;
  for (int i = 0; i < n; i++)
    if (ch[i] == '1') {
      if (str[i] == '0')
        sum++;
      else {
        if (i - 1 >= 0 && str[i - 1] == '1') str[i - 1] = '*', sum++;
        if (i + 1 < n && str[i + 1] == '1') str[i + 1] = '*', sum++;
      }
    }
  cout << sum << endl;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
  return 0;
}
