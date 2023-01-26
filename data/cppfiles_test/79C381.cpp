#include <bits/stdc++.h>
using namespace std;
bool prime[100];
pair<int, int> check(string s) {
  string ans = "";
  for (auto ch : s) {
    if (ch == '1' || ch == '4' || ch == '6' || ch == '8' || ch == '9') {
      ans += ch;
      return {1, stoi(ans)};
    }
  }
  for (int i = 0; i < s.length() - 1; i++) {
    for (int j = 1; j < s.length(); j++) {
      int currNo = (s[i] - '0') * 10 + (s[j] - '0');
      if (!prime[currNo]) {
        ans += s[i];
        ans += s[j];
        return {2, stoi(ans)};
      }
    }
  }
  return {-1, -1};
}
int main() {
  for (int i = 2; i < 100; i++) {
    prime[i] = true;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        prime[i] = false;
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    string d;
    cin.ignore();
    cin >> d;
    auto ans = check(d);
    cout << ans.first << "\n" << ans.second << "\n";
  }
  return 0;
}
