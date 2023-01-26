#include <bits/stdc++.h>
using namespace std;
void testcase() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1;
  cin >> s2;
  for (int i = 0; i < n; i++) {
    if (s1[i] == '1' && s2[i] == '1') {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    testcase();
  }
}
