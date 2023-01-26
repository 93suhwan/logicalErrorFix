#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string str;
    int j = 0;
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == 'N') {
        j++;
      }
    }
    if (j == 1) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
