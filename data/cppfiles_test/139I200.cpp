#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string t;
    cin >> t;
    if (t.length() % 2 == 0 &&
        t.substr(0, t.length() / 2) == t.substr(t.length() / 2, t.length()))
      cout << "YES";
    else
      cout << "NO";
  }
}
