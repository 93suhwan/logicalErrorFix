#include <bits/stdc++.h>
using namespace std;
const long long int MAX = 1e5 + 10;
const long long int INF = 2e18;
void solve(int t) {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  int two = 0, three = 0, five = 0, seven = 0;
  int first, second;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' ||
        s[i] == '9') {
      cout << 1 << endl << (int)(s[i] - '0') << endl;
      return;
    }
    if (s[i] == '2') {
      if (i) {
        first = s[0] - '0';
        second = 2;
      }
      two++;
    }
    if (s[i] == '3') {
      if (three) {
        first = 3;
        second = 3;
      }
      three++;
    }
    if (s[i] == '5') {
      if (i) {
        first = s[0] - '0';
        second = 5;
      }
      five++;
    }
    if (s[i] == '7') {
      if (seven) {
        first = 7;
        second = 7;
      }
      seven++;
      if (two) {
        first = 2;
        second = 7;
      }
      if (five) {
        first = 5;
        second = 7;
      }
    }
  }
  cout << 2 << endl;
  cout << first * 10 + second << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) solve(i);
  return 0;
}
