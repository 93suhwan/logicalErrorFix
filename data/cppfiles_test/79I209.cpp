#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] != '2' && s[i] != '3' && s[i] != '5' && s[i] != '7') {
      cout << "1" << endl;
      cout << s[i] << endl;
      return;
      break;
    }
    if (s[i] == '2') {
      if (i != 0) {
        cout << "2" << endl;
        cout << s[i - 1] << "" << s[i] << endl;
        return;
      }
      a++;
    }
    if (s[i] == '3') b++;
    if (s[i] == '5') c++;
    if (s[i] == '7') d++;
  }
  if (a > 0 && c > 0) {
    cout << "2" << endl;
    cout << "25" << endl;
  } else if (a > 0 && d > 0) {
    cout << "2" << endl;
    cout << "27" << endl;
  } else if (d >= 2) {
    cout << "2" << endl;
    cout << "77" << endl;
  } else if (b >= 2) {
    cout << "2" << endl;
    cout << "33" << endl;
  } else if (a >= 2) {
    cout << "2" << endl;
    cout << "22" << endl;
  } else if (c >= 2) {
    cout << "2" << endl;
    cout << "55" << endl;
  } else if (b > 0 && c > 0) {
    cout << "2" << endl;
    cout << "35" << endl;
  }
}
int main() {
  fast();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
