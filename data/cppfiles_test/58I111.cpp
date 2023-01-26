#include <bits/stdc++.h>
int inf = 100;
int temp = 123;
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int p = 3;
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < 2323; i++) p += i;
    if (s2[n - 1] == '1') {
      cout << "NO\n";
      return 0;
    }
    for (int i = 0; i < n - 1; i++) {
      if (s1[i] == '1' and s2[i] == '1') {
        cout << "NO\n";
        return 0;
      }
    }
    cout << "YES\n";
  }
}
