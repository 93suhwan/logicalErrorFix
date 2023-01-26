#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, counter = 0;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1;
    cin >> s1;
    string s2;
    s2 = s1;
    sort(s2.begin(), s2.end());
    for (int i = 0; i < n; i++) {
      if (s1[i] == s2[i]) {
        counter++;
      }
    }
    cout << (n - counter) << endl;
  }
  return 0;
}
