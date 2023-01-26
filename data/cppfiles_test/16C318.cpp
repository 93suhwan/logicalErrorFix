#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    string s, s1;
    cin >> s;
    s1 = s;
    sort(s1.begin(), s1.end());
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != s1[i]) count++;
    }
    cout << count << "\n";
  }
  return 0;
}
