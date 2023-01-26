#include <bits/stdc++.h>
using namespace std;
void sol() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  for (int i = 0; i < n; i++) {
    if (s1[i] == '1' && s2[i] == '1') {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}
int main() {
  int t;
  cin >> t;
  while (t) {
    sol();
    t--;
  }
  return 0;
}
