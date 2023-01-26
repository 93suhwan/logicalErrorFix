#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t) {
    string s;
    cin >> s;
    int abcount = 0, bacount = 0;
    for (int i = 0; i < s.length() - 1; i++) {
      string temp = "";
      temp += s[i];
      temp += s[i + 1];
      if (temp == "ab")
        abcount++;
      else if (temp == "ba")
        bacount++;
    }
    if (abcount > bacount)
      s[0] = 'b';
    else if (abcount < bacount)
      s[0] = 'a';
    cout << s << "\n";
    t--;
  }
  return 0;
}
