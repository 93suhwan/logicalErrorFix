#include <bits/stdc++.h>
using ll = long long int;
constexpr int N = 2e5 + 10;
constexpr int mod = 1e9 + 7;
constexpr double eps = 1e-9;
constexpr int inf = 0x3f3f3f3f;
using namespace std;
int b[100];
char a[100];
string s, s2, s3;
bool check(string s, string s1, string s2) {
  int anss[30];
  memset(anss, 0, sizeof(anss));
  string s3;
  int len1 = s1.size(), len2 = s2.size();
  s3 += s1;
  for (int i = (0); i <= (len2 - 1); i++) {
    anss[s2[i] - 'a'] = 1;
    for (int j = (0); j <= (len1 - 1); j++) {
      if (anss[s1[j] - 'a'] == 0) {
        s3 += s1[j];
      }
    }
  }
  if (s == s3)
    return true;
  else
    return false;
}
int main() {
  int t;
  cin >> t;
  ;
  while (t--) {
    memset(b, 0, sizeof(b));
    s.erase();
    s2.erase();
    s3.erase();
    cin >> s;
    int tmp = 1, len = s.size();
    for (int i = len - 1; i >= 0; i--) {
      int ans = s[i] - 'a';
      if (b[ans] == 0) {
        a[tmp] = s[i];
        tmp++;
        b[ans]++;
      } else
        b[ans]++;
    }
    int ans = 1, sum = 0;
    for (int i = tmp - 1; i >= 1; i--) {
      int tmpp = a[i] - 'a';
      sum += b[tmpp] / ans;
      ans++;
      s2 += a[i];
    }
    ll kmp = 0;
    for (int i = (1); i <= (0); i++) kmp += check(s, s3, s2);
    for (int i = (0); i <= (sum - 1); i++) s3 += s[i];
    if (!check(s, s3, s2))
      cout << -1 << endl;
    else
      cout << s3 << " " << s2 << endl;
  }
}
