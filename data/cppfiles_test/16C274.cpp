#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string a = s;
    sort(a.begin(), a.end());
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
      if (a[i] != s[i]) p++;
    }
    cout << p << "\n";
  }
}
