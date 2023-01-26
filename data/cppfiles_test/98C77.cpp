#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    string s;
    long long int l = -1, r = -1;
    int flag = 0;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
      int val = 0;
      for (int j = i; j < n; j++) {
        if (s[j] == 'a')
          val += 1;
        else
          val -= 1;
        if (val == 0) {
          l = i;
          r = j;
          flag = 1;
          break;
        }
      }
      if (flag == 1) break;
    }
    if (flag == 0)
      cout << -1 << " " << -1 << endl;
    else
      cout << l + 1 << " " << r + 1 << endl;
  }
  return 0;
}
