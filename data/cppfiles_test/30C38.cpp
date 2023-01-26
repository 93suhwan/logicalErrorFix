#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, i, j, k = 0, f, x, y, z, ans;
  long long t;
  cin >> t;
  while (t--) {
    m = 0, i = 0, j = 0, f = 0, x = 0, y = 0, z = 0, ans = 0;
    string s, s1 = "", s2 = "", s3 = "", s4 = "";
    cin >> n >> s;
    vector<char> v;
    x = n / 2;
    if (n % 2 == 0) x--;
    for (i = 0; i <= x; i++) {
      if (s[i] != s[n - i - 1]) {
        v.push_back(s[i]);
        v.push_back(s[n - i - 1]);
      }
    }
    if (v.empty()) {
      cout << "0\n";
      continue;
    }
    j = n - 1;
    i = 0;
    while (i <= j) {
      if (s[i] != s[j]) {
        if (s[i] == v[0])
          j++;
        else if (s[j] == v[0])
          i--;
        else {
          s1.push_back(s[i]);
          s2.push_back(s[j]);
        }
        ans++;
      } else {
        s1.push_back(s[i]);
        s2.push_back(s[j]);
      }
      i++;
      j--;
    }
    reverse(s2.begin(), s2.end());
    s1 += s2;
    s2 = s1;
    reverse(s2.begin(), s2.end());
    j = n - 1;
    i = 0;
    while (i <= j) {
      if (s[i] != s[j]) {
        if (s[i] == v[1])
          j++;
        else if (s[j] == v[1])
          i--;
        else {
          s3.push_back(s[i]);
          s4.push_back(s[j]);
        }
        f++;
      } else {
        s3.push_back(s[i]);
        s4.push_back(s[j]);
      }
      i++;
      j--;
    }
    reverse(s4.begin(), s4.end());
    s3 += s4;
    s4 = s3;
    reverse(s4.begin(), s4.end());
    if (s1 == s2 && s3 == s4)
      ans = min(ans, f);
    else if (s1 != s2 && s3 == s4)
      ans = f;
    else if (s1 != s2 && s3 != s4)
      ans = -1;
    cout << ans << "\n";
  }
  return 0;
}
