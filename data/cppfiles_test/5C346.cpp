#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1;
    string s2;
    cin >> s1 >> s2;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s2[i] == '1') {
        if (s1[i] == '0')
          cnt++;
        else if (i > 0 && s1[i - 1] == '1') {
          cnt++;
          s1[i - 1] = '0';
        } else if (i < n && s1[i + 1] == '1') {
          cnt++;
          s1[i + 1] = '0';
        }
      }
    }
    cout << cnt << "\n";
  }
}
