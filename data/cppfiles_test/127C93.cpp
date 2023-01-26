#include <bits/stdc++.h>
using namespace std;
void func(string &s) {
  int cpt = 0, aux = s.size(), posc;
  if (s.find('a') == string::npos or s.find('b') == string::npos or
      s.find('c') == string::npos) {
    cout << s << endl;
    return;
  }
  for (int i = 0; i < aux; i++) {
    if (s[i] == 'b') cpt++;
    if (s[i] == 'c') posc = i;
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'b')
      continue;
    else if (i == posc) {
      cout << 'c';
      for (int j = 0; j < cpt; j++) cout << 'b';
    } else
      cout << s[i];
  }
  cout << endl;
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end());
    if (b == "abc")
      func(a);
    else
      cout << a << endl;
  }
}
