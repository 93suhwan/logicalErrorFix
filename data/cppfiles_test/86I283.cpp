#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    cin >> t;
    int i = 0;
    long long sum = 0;
    while (i < n) {
      if (s[i] == '0' && t[i] == '0') {
        if (i > 0 && s[i - 1] == '1' && t[i - 1] == '1') {
          sum += 2;
          i++;
        } else if (i < n && s[i + 1] == '1' && t[i + 1] == '1') {
          sum += 2;
          i = i + 2;
        } else {
          sum++;
          i++;
        }
      } else if ((s[i] == '1' && t[i] == '0') || (s[i] == '0' && t[i] == '1')) {
        sum += 2;
        i++;
      } else {
        i++;
      }
    }
    cout << sum << endl;
  }
}
