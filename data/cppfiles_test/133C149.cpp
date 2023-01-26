#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int t, n;
string s;
string s1;
string temp;
void solve() {
  cin >> n;
  cin >> temp;
  s = "";
  s += temp;
  int flag = 1;
  for (int i = 2; i <= n - 2; i++) {
    cin >> s1;
    if (s1[0] != temp[1] && flag) {
      s += s1[0];
      flag = 0;
    }
    s += s1[1];
    temp = s1;
  }
  if (flag) {
    s += 'a';
  }
  cout << s << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
