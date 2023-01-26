#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
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
    string t;
    cin >> s;
    t = s;
    long long cnt = 0;
    sort(t.begin(), t.end());
    for (int i = 0; i < n; i++) {
      if (s[i] != t[i]) cnt++;
    }
    cout << cnt << "\n";
  }
  return 0;
}
