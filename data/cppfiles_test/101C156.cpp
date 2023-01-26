#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int blue[N], red[N], c[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int cnt = 0, cns = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    string ss;
    cin >> ss;
    for (int i = 0, j = 1; i < ss.size(); i++, j++)
      if (ss[i] == 'B')
        blue[++cnt] = c[j];
      else
        red[++cns] = c[j];
    sort(blue + 1, blue + 1 + cnt);
    sort(red + 1, red + 1 + cns);
    bool flag = true;
    for (int i = 1; i <= cnt; i++)
      if (blue[i] < i) {
        flag = false;
        break;
      }
    for (int i = cns, j = n; i >= 1; i--, j--)
      if (red[i] > j) {
        flag = false;
        break;
      }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
