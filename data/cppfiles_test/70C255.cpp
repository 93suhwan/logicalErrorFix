#include <bits/stdc++.h>
using namespace std;
int findnum(string str, char c) {
  if (str.find(c) != std::string::npos)
    return 1;
  else
    return 0;
}
string reverseStr(string str) {
  int n = str.length();
  for (int i = 0; i < n / 2; i++) swap(str[i], str[n - i - 1]);
  return str;
}
int acount(string str, char c) {
  int l = str.length();
  int co = 0;
  for (int i = 0; i < l; i++) {
    if (str[l - 1 - i] == c) {
      int j = 0;
      while (str[l - 1 - i - j] == c) {
        co += 1;
        j = j + 1;
      }
      return co;
      break;
    } else {
      continue;
    }
  }
}
int frequency(string str, char c) {
  int count = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == c) {
      count += 1;
    } else {
      continue;
    }
  }
  return count;
}
string conversion(string str1, string str2) {
  int m, n;
  m = str2.length();
  n = str1.length();
  string str3 = str1;
  for (int i = 0; i < m; i++) {
    str3.erase(remove(str3.begin(), str3.end(), str2[i]), str3.end());
    str1 += str3;
  }
  return str1;
}
int main() {
  long long n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    int l;
    l = str.length();
    string str1, str2;
    for (int i = 0; i < l; i++) {
      if (findnum(str2, str[l - i - 1]) == 0) {
        str2 += str[l - i - 1];
      } else {
        continue;
      }
    }
    str2 = reverseStr(str2);
    int m;
    m = str2.length();
    int count2 = 0;
    for (int i = 0; i < m; i++) {
      count2 += (frequency(str, str2[i])) / (i + 1);
    }
    for (int i = 0; i < count2; i++) {
      str1 += str[i];
    }
    if (conversion(str1, str2) != str) {
      cout << -1 << endl;
    } else {
      cout << str1 << " " << str2 << endl;
    }
  }
}
