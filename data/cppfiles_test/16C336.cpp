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
    string s1 = s;
    int count = 0;
    sort(s.begin(), s.end());
    for (int i = 0; i < s1.length(); i++) {
      if (s1[i] - s[i] != 0) count++;
    }
    cout << count << endl;
  }
}
