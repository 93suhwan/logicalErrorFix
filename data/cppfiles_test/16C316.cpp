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
    sort(s.begin(), s.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += (s[i] == s1[i]);
    cout << n - cnt << '\n';
  }
}
