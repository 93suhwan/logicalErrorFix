#include <bits/stdc++.h>
using namespace std;
int n, p[30];
string s;
string cz(string a, string b) {
  string ans = a;
  for (int i = 0; i < b.length(); i++) {
    char t = b[i];
    string temp;
    for (int j = 0; j < a.length(); j++) {
      if (a[j] != t) temp += a[j];
    }
    a = temp;
    ans += a;
  }
  return ans;
}
int main() {
  cin >> n;
  while (n--) {
    cin >> s;
    string a, b;
    for (int i = 0; i <= 29; i++) p[i] = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
      char t = s[i];
      int flag = 1;
      for (int j = 0; j < b.length(); j++) {
        if (b[j] == t) {
          flag = 0;
          break;
        }
      }
      if (flag) b += t;
      p[t - 'a' + 1]++;
    }
    for (int i = 0; i * 2 < b.length(); i++) {
      char r = b[i];
      b[i] = b[b.length() - 1 - i], b[b.length() - 1 - i] = r;
    }
    int flag = 1, len = 0;
    for (int i = 0; i < b.length(); i++) {
      int t = i + 1;
      if (p[b[i] - 'a' + 1] % t != 0) {
        flag = 0;
        break;
      }
      len += p[b[i] - 'a' + 1] / t;
    }
    if (flag == 0) {
      cout << "-1\n";
      continue;
    }
    for (int i = 0; i < len; i++) a += s[i];
    string ans = cz(a, b);
    if (ans == s)
      cout << a << " " << b << endl;
    else
      cout << "-1\n";
  }
  return 0;
}
