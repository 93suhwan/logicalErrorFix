#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string str = "";
    map<string, int> mp;
    for (int i = 0; i < 2 * n; i++) {
      if (i % 2 == 0)
        str += '(';
      else
        str += ')';
    }
    int last = 2 * n;
    for (int i = 0; i < n; i++) {
      if (i < last - i) {
        str[i] = '(';
        str[last - i] = ')';
        mp[str] = i + 1;
      }
    }
    map<string, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
      cout << it->first << endl;
    }
  }
  return 0;
}
