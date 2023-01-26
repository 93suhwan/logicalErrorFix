#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int s1 = 0;
    string a = s;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      if (a[i] != s[i]) {
        s1++;
      }
    }
    cout << s1 << endl;
  }
}
