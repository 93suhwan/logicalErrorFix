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
    string temp = s;
    sort(temp.begin(), temp.end());
    int k = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != temp[i]) {
        k++;
      }
    }
    cout << k << endl;
  }
  return 0;
}
