#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int l;
    int flag = 1;
    l = s.size();
    if (l % 2 == 1)
      cout << "no" << endl;
    else {
      int mid = l / 2;
      for (int i = 0; i < mid; i++) {
        if (s[i] != s[mid + i]) {
          cout << "no" << endl;
          flag = 0;
          break;
        }
      }
      if (flag == 1) cout << "yes" << endl;
    }
  }
  return 0;
}
