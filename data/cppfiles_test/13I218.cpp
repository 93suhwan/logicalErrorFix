#include <bits/stdc++.h>
using namespace std;
void cat(string s) {
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a')
      a++;
    else if (s[i] == 'b')
      b++;
    else
      c++;
  }
  if (abs(a - b) == abs(b - c))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  string s;
  int x;
  cin >> x;
  for (int i = 0; i < x; i++) cin >> s;
  cat(s);
}
