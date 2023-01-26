#include <bits/stdc++.h>
using namespace std;
int T;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string stroka;
    cin >> stroka;
    int ans = 0;
    string temp = stroka;
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++)
      if (temp[i] != stroka[i]) ans++;
    cout << ans << '\n';
  }
  return 0;
}
