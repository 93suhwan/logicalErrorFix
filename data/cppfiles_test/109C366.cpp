#include <bits/stdc++.h>
using namespace std;
long long to_dec(string &s) {
  long long ans = 0;
  for (int i = 0; i < s.size(); i++) {
    ans *= 10;
    ans += (s[i] - '0');
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, count = 0;
    cin >> n;
    string s;
    cin >> s;
    string st = "";
    if (s[s.size() - 1] != '0') {
      st += s[s.size() - 1];
      count = to_dec(st);
      st = "";
    }
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] != '0') {
        st += s[i];
        count = count + 1 + to_dec(st);
        st = "";
      }
    }
    cout << count << endl;
  }
}
