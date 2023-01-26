#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    queue<char> q;
    cin >> s;
    cout << s << endl;
    int n = s.size();
    if (n % 2 == 0) {
      int cond = 0;
      int i;
      for (i = 0; i < n / 2; i++) {
        q.push(s[i]);
      }
      for (; i < n; i++) {
        if (q.front() == s[i]) {
          q.pop();
        } else {
          cond = 1;
          break;
        }
      }
      if (cond == 1) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
}
