#include <bits/stdc++.h>
using namespace std;
void del(string s) {
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A')
      a++;
    else if (s[i] == 'B')
      b++;
    else if (s[i] == 'C')
      c++;
  }
  if (a > b || c > b)
    cout << "NO";
  else if (s.size() % 2 == 1)
    cout << "NO";
  else if (a == b && c == 0)
    cout << "YES";
  else if (b == c && a == 0)
    cout << "YES";
  else if (a == c && b == 0)
    cout << "NO";
  else if (b == a + c)
    cout << "YES";
  cout << endl;
}
int main() {
  int n;
  cin >> n;
  string s[n];
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) del(s[i]);
}
