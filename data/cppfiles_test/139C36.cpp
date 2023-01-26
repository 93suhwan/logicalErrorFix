#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s, p, q;
    int i;
    cin >> s;
    for (i = 0; i < s.size() / 2; i++) p.push_back(s[i]);
    for (; i < s.size(); i++) q.push_back(s[i]);
    if (s.size() % 2 == 1 || p != q)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
