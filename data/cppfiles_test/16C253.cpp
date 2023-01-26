#include <bits/stdc++.h>
using namespace std;
int T, n;
string str;
signed main() {
  cin >> T;
  while (T--) {
    cin >> n >> str;
    int res = 0;
    string t = str;
    sort(t.begin(), t.end());
    for (int i = 0; i < str.size(); i++) res += t[i] != str[i];
    cout << res << endl;
  }
}
