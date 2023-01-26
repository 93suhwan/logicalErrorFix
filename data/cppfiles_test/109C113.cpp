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
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] - '0' > 0) {
        count += s[i] - '0';
        count++;
      }
    }
    if (s[s.size() - 1] != '0') count--;
    cout << count << endl;
  }
  return 0;
}
