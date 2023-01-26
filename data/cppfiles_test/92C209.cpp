#include <bits/stdc++.h>
using namespace std;
int T;
string s;
int main() {
  scanf("%d", &T);
  while (T--) {
    cin >> s;
    if (s[0] == s[s.size() - 1])
      cout << s << endl;
    else
      s[0] = s[s.size() - 1], cout << s << endl;
  }
  return 0;
}
