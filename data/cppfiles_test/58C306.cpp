#include <bits/stdc++.h>
using namespace std;
void AIA() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void file() {}
const int OO = 1000000000 + 7;
const double PI = acos(-1);
int main() {
  AIA();
  file();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    bool b = 1;
    for (int i = 0; i < n; i++) {
      if (s1[i] == s2[i] && s1[i] == '1') {
        b = 0;
        break;
      }
    }
    cout << (b ? "YES\n" : "NO\n");
  }
}
