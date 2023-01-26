#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string b = s;
    sort(b.begin(), b.end());
    int k = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == b[i]) k++;
    }
    cout << n - k << "\n";
  }
  return 0;
}
