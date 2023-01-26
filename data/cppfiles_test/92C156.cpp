#include <bits/stdc++.h>
using namespace std;
void fastIO();
int main() {
  fastIO();
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int len = s.size();
    s[len - 1] = s[0];
    cout << s << "\n";
  }
  return 0;
}
void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
