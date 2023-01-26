#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string k, s;
    cin >> k >> s;
    int b, c, cnt = 0;
    map<char, int> a;
    for (int i = 0; i < k.size(); i++) {
      a[k[i]] = i + 1;
    }
    for (int i = 0; i < s.size() - 1; i++) {
      b = a[s[i]];
      c = a[s[i + 1]];
      cnt += abs(b - c);
    }
    cout << cnt << endl;
  }
}
