#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int t, counter;
  cin >> t;
  while (t--) {
    int n;
    counter = 0;
    cin >> n;
    string s;
    cin >> s;
    n = s.size();
    if (s[n - 1] > '0') counter--;
    for (int i = 0; i < n; i++) {
      if (s[i] > '0') {
        counter++;
      }
      counter += (s[i] - '0');
    }
    cout << counter << endl;
  }
  return 0;
}
