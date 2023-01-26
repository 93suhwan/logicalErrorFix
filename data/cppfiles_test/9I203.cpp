#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a[26];
    memset(a, 0, 104);
    for (char c : s) a[c - 97]++;
    cout << max((int)(s.length() > 1),
                (int)min(s.length() / 2, s.length() - *max_element(a, a + 26)))
         << '\n';
  }
}
