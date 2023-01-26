#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string a;
    a = s;
    sort(a.begin(), a.end());
    int count = 0;
    for (int i = 0; i < 10; i++) {
      if (s[i] != a[i]) {
        count++;
      }
    }
    cout << count << endl;
  }
}
