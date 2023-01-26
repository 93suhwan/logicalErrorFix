#include <bits/stdc++.h>
using namespace std;
string cal(string &s) {
  int n = s.size();
  string ans = "";
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      string a = "1";
      return a;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '9') {
      ans += s[i];
      return ans;
    }
  }
  for (int i = 1; i < n; i++) {
    if (s[i] == '2') {
      string a = s.substr(i - 1, 2);
      ans += a;
      return ans;
    }
  }
  for (int i = 1; i < n; i++) {
    if (s[0] == '2' && s[i] == '1') {
      string a = "21";
      return a;
    }
    if (s[0] == '2' && s[i] == '5') {
      string a = "25";
      return a;
    }
    if (s[0] == '2' && s[i] == '7') {
      string a = "27";
      return a;
    }
    if (s[0] == '2' && s[i] == '2') {
      string a = "22";
      return a;
    }
  }
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '3') {
      a1++;
    }
    if (s[i] == '5') {
      a2++;
    }
    if (s[i] == '7') {
      a3++;
    }
    if (s[i] == '1') {
      a4++;
    }
  }
  if (a1 >= 2) {
    string a = "33";
    return a;
  }
  if (a2 >= 2) {
    string a = "55";
    return a;
  }
  if (a3 >= 2) {
    string a = "77";
    return a;
  }
  vector<int> v1, v5, v3, v7;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      v1.push_back(i);
    }
    if (s[i] == '5') {
      v5.push_back(i);
    }
    if (s[i] == '3') {
      v3.push_back(i);
    }
    if (s[i] == '7') {
      v7.push_back(i);
    }
  }
  for (int i = 0; i < v1.size(); i++) {
    for (int j = 0; j < v5.size(); j++) {
      if (i < j) {
        string a = "15";
        return a;
      }
    }
  }
  for (int i = 0; i < v3.size(); i++) {
    for (int j = 0; j < v5.size(); j++) {
      if (i < j) {
        string a = "35";
        return a;
      }
    }
  }
  for (int i = 0; i < v5.size(); i++) {
    for (int j = 0; j < v1.size(); j++) {
      if (i < j) {
        string a = "51";
        return a;
      }
    }
  }
  for (int i = 0; i < v5.size(); i++) {
    for (int j = 0; j < v7.size(); j++) {
      if (i < j) {
        string a = "57";
        return a;
      }
    }
  }
  for (int i = 0; i < v7.size(); i++) {
    for (int j = 0; j < v5.size(); j++) {
      if (i < j) {
        string a = "75";
        return a;
      }
    }
  }
  string a = "111";
  return a;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string b = cal(s);
    cout << b.size() << endl;
    cout << b << endl;
  }
  return 0;
}
