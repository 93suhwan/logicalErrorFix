#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    bool flag = 0;
    for (int i = 1; i < n; i++) {
      if (s[i] != s[i - 1]) {
        cout << i << " " << i + 1 << "\n";
        flag = 1;
        break;
      }
    }
    if (!flag) cout << "-1 -1\n";
  }
}
