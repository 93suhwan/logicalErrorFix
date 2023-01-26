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
      if (i == 0 && s2[0] == '1') {
        if (s1[0] == '0') {
          cnt++;
        } else if (s1[1] == '1') {
          cnt++;
          s1[1] = '2';
        }
      } else if (i == n - 1 && s2[i] == '1') {
        if (s1[n - 1] == '0')
          cnt++;
        else if (s1[n - 2] == '1') {
          s1[n - 2] = '2';
          cnt++;
        }
      } else if (s2[i] == '1') {
        if (s1[i] == '0')
          cnt++;
        else if (s1[i - 1] == '1') {
          cnt++;
          s1[i - 1] == '2';
        } else if (s1[i + 1] == '1') {
          cnt++;
          s1[i + 1] == '2';
        }
      }
    }
    cout << cnt << "\n";
  }
}
