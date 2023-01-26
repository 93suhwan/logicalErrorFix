#include <bits/stdc++.h>
using namespace std;
int maxcolor(string s) {
  int n = s.size();
  int arr[26] = {0};
  for (int i = 0; i < s.size(); i++) {
    int k = s[i] - 'a';
    arr[k]++;
  }
  int count = 0;
  int second = 0;
  for (int i = 0; i < 26; i++) {
    if (arr[i] == 1) {
      count++;
    } else if (arr[i] >= 2) {
      second++;
    }
  }
  int ans = (count / 2) + (second);
  return ans;
}
int main() {
  long long testcase;
  cin >> testcase;
  while (testcase--) {
    string s;
    cin >> s;
    int ans = maxcolor(s);
    cout << ans << endl;
  }
  return 0;
}
