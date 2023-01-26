#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string* d = new string[t];
  for (int y = 0; y < t; y++) {
    string s, k;
    int a = 0, b = 0, c = 0;
    cin >> s >> k;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'a') a++;
      if (s[i] == 'b') b++;
      if (s[i] == 'c') c++;
    }
    sort(s.begin(), s.end());
    if (k[0] != 'a' || k[1] == 'c' || a == 0 || b == 0 || c == 0)
      d[y] = s;
    else {
      for (int i = a; i < a + c; i++) {
        s.erase(i, 1);
        s.insert(i, "c");
      }
      for (int i = a + c; i < a + b + c; i++) {
        s.erase(i, 1);
        s.insert(i, "b");
      }
      d[y] = s;
    }
  }
  for (int i = 0; i < t; i++) cout << d[i] << endl;
}
