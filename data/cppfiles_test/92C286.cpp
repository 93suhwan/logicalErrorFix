#include <bits/stdc++.h>
using namespace std;
void initial_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int t;
string s;
void change(char *ch) {
  if (*ch == 'a')
    *ch = 'b';
  else
    *ch = 'a';
}
int main() {
  initial_code();
  cin >> t;
  while (t--) {
    cin >> s;
    if (s[0] != s[s.size() - 1]) change(&s[0]);
    cout << s << endl;
  }
  return 0;
}
