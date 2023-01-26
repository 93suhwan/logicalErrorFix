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
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (temp[i] != s[i]) {
        count++;
      }
    }
    cout << count << "\n";
  }
  return 0;
}
