#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'A') a++;
      if (s[i] == 'B') b++;
      if (s[i] == 'C') c++;
    }
    if (b - a == c)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
}
