#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string temp = s;
    sort(temp.begin(), temp.end());
    int c = 0;
    for (int i = 0; i < temp.length(); i++) {
      if (s[i] != temp[i]) c++;
    }
    cout << c << "\n";
  }
  return 0;
}
