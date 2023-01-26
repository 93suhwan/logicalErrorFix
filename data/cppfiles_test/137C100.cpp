#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long N = 1000000007;
int findLastIndex(string& str, char x) {
  int index = -1;
  for (int i = 0; i < str.length(); i++)
    if (str[i] == x) index = i;
  return index;
}
int Substr(string s2, string s1) {
  int counter = 0;
  int i = 0;
  for (; i < s1.length(); i++) {
    if (counter == s2.length()) break;
    if (s2[counter] == s1[i]) {
      counter++;
    } else {
      if (counter > 0) {
        i -= counter;
      }
      counter = 0;
    }
  }
  return counter < s2.length() ? -1 : i - counter;
}
int isSubstring(string s1, string s2) {
  int M = s1.length();
  int N = s2.length();
  for (int i = 0; i <= N - M; i++) {
    int j;
    for (j = 0; j < M; j++)
      if (s2[i + j] != s1[j]) break;
    if (j == M) return i;
  }
  return -1;
}
void func() {
  ll x, y;
  cin >> x >> y;
  string s1, s2;
  while (x > 0) {
    s1 += (char)(48 + x % 2);
    x /= 2;
  }
  while (y > 0) {
    s2 += (char)(48 + y % 2);
    y /= 2;
  }
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());
  string str1 = s1.substr(0, findLastIndex(s1, '1') + 1);
  string str1rev = string(str1.rbegin(), str1.rend());
  string str2 = s1 + (char)(49);
  string str2rev = string(str2.rbegin(), str2.rend());
  if (s1.compare(s2) == 0) {
    cout << "YES\n";
    return;
  }
  string sx = "";
  int count = 0, res;
  res = isSubstring(str1, s2);
  if (res != -1) {
    sx = s2.substr(0, res) + s2.substr(res + str1.length());
    count = 0;
    for (int i = 0; i < sx.length(); i++) {
      count += (sx[i] == '0');
    }
    if (count == 0) {
      cout << "YES\n";
      return;
    }
  }
  res = isSubstring(str2, s2);
  if (res != -1) {
    sx = s2.substr(0, res) + s2.substr(res + str2.length());
    count = 0;
    for (int i = 0; i < sx.length(); i++) {
      count += (sx[i] == '0');
    }
    if (count == 0) {
      cout << "YES\n";
      return;
    }
  }
  res = isSubstring(str1rev, s2);
  if (res != -1) {
    sx = s2.substr(0, res) + s2.substr(res + str1rev.length());
    count = 0;
    for (int i = 0; i < sx.length(); i++) {
      count += (sx[i] == '0');
    }
    if (count == 0) {
      cout << "YES\n";
      return;
    }
  }
  res = isSubstring(str2rev, s2);
  if (res != -1) {
    sx = s2.substr(0, res) + s2.substr(res + str2rev.length());
    count = 0;
    for (int i = 0; i < sx.length(); i++) {
      count += (sx[i] == '0');
    }
    if (count == 0) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    func();
  }
  return 0;
}
