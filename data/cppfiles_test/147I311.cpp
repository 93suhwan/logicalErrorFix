#include <bits/stdc++.h>
using namespace std;
int main() {
  int t1 = 1;
  cin >> t1;
  for (int i1 = 0; i1 < t1; i1++) {
    string str;
    cin >> str;
    if (str[0] == str[str.length() - 1])
      cout << "YES";
    else
      cout << "NO";
  }
  return 0;
}
