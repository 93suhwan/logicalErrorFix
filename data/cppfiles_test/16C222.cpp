#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, count = 0, i;
    cin >> n;
    string s;
    cin >> s;
    string st = s;
    sort(st.begin(), st.end());
    for (i = 0; i < n; i++) {
      if (st[i] != s[i]) count++;
    }
    cout << count << "\n";
  }
}
