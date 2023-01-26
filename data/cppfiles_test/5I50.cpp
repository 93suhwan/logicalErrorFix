#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    int cnt = 0;
    for (int i = 0; i < s2.length(); i++) {
      if (i != 0 && i != n - 1 && s2[i] == '1' && s1[i - 1] == '1') {
        cnt++;
        s1[i - 1] = '0';
      } else if (i != 0 && i != n - 1 && s2[i] == '1' && s1[i + 1] == '1') {
        cnt++;
        s1[i + 1] = '0';
      } else if (i == 0 && s2[i] == '1' && s1[i + 1] == '1') {
        cnt++;
        s1[i + 1] = '0';
      } else if (i == n - 1 && s2[i] == '1' && s1[i - 1] == '1') {
        cnt++;
        s1[i - 1] = '0';
      }
    }
    cout << cnt << endl;
  }
}
