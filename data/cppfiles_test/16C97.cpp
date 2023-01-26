#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, a;
    cin >> s;
    a = s;
    sort(a.begin(), a.end());
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != a[i]) {
        count++;
      }
    }
    cout << count << endl;
  }
}
