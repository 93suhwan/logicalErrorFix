#include <bits/stdc++.h>
using namespace std;
long long int mymax(long long int a, long long int b) {
  if (a > b) {
    return a;
  } else
    return b;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    int ab = 0, ba = 0;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == 'a' && s[i + 1] == 'b') {
        ab++;
      } else if (s[i] == 'b' && s[i + 1] == 'a') {
        ba++;
      }
    }
    if (ab == ba) {
      cout << s << endl;
    } else {
      if (ab > ba) {
        int i = n - 1;
        while (s[i] == 'b') {
          s[i] = 'a';
          i--;
        }
        cout << s << endl;
      } else {
        int i = n - 1;
        while (s[i] == 'a') {
          s[i] = 'b';
          i--;
        }
        cout << s << endl;
      }
    }
  }
}
