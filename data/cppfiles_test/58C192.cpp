#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    string s1, s2;
    bool flag = true;
    cin >> s1 >> s2;
    for (int i = 0; i < n; i++) {
      if (s1[i] == '1' && s2[i] == '1') {
        flag = false;
        break;
      }
    }
    if (flag == true)
      cout << "YES";
    else
      cout << "NO";
    cout << "\n";
  }
  return 0;
}
