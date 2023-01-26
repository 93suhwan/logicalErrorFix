#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    string str;
    cin >> str;
    bool ans = 1;
    int n = str.size();
    if (n == 2 && str[0] != str[1])
      cout << "NO\n";
    else if (n == 3 && (str == "ENE" || str == "NEN"))
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
