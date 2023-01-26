#include <bits/stdc++.h>
using namespace std;
vector<string> v;
string init(long long num) {
  string s;
  if (num == 0) {
    s = '0';
    return 0;
  }
  while (num) {
    s = (char)(num % 10 + '0') + s;
    num /= 10;
  }
  return s;
}
int judge(string tmp, string s) {
  int i = 0, j = 0, sum = 0;
  while (i < tmp.size() && j < s.size()) {
    if (tmp[i] == s[j]) {
      i++;
      j++;
      sum++;
    } else {
      j++;
    }
  }
  int ans = j - sum + s.size() - j + tmp.size() - i;
  return ans;
}
int main() {
  int t;
  cin >> t;
  long long num = 1;
  for (int i = 0; i <= 60; i++) {
    v.push_back(init(num));
    num <<= 1;
  }
  while (t--) {
    string s;
    cin >> s;
    int ans = 100;
    for (int i = 0; i < v.size(); i++) {
      ans = min(judge(v[i], s), ans);
    }
    cout << ans << endl;
  }
  return 0;
}
