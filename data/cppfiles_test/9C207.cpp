#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a[26], n = s.length();
    memset(a, 0, 104);
    for (char c : s) a[c - 97]++;
    for (int i : a) n -= max(0, i - 2);
    cout << n / 2 << '\n';
  }
}
