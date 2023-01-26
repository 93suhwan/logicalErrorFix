#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    string s = "";
    int cnt = n / 2 + 1 + n / 2 - 1;
    for (int i = 1; i <= n / 2; i++) s += 'a';
    s += 'b';
    for (int i = 1; i <= n / 2 - 1; i++) s += 'a';
    if (cnt != n) s += 'c';
    for (int i = 0; i < n; i++) cout << s[i];
    cout << endl;
  }
}
