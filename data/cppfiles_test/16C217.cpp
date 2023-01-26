#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int q;
  cin >> q;
  while (q--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    long long int cnt = 0;
    string temp = s;
    sort(s.begin(), s.end());
    for (long long int i = 0; i < n; i++) {
      if (s[i] != temp[i]) {
        cnt++;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
