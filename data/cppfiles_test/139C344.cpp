#include <bits/stdc++.h>
using namespace std;
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  init_code();
  long long t = 1;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int h = n / 2;
    bool ans = true;
    if (n % 2 != 0)
      ans = false;
    else {
      for (int i = 0, j = h; i < h; i++, j++) {
        if (s[i] != s[j]) {
          ans = false;
          break;
        }
      }
    }
    if (ans)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
