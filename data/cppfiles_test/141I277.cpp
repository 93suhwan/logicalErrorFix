#include <bits/stdc++.h>
using namespace std;
string is_two(string &s, long long num, int j) {
  if (j - 1 > 0 && s[j - 1] != '0') {
    string temp = "";
    temp.push_back(s[j - 1]);
    temp.push_back(s[j]);
    stringstream geek(temp);
    long long x = 0;
    geek >> x;
    if (x - num <= 18) {
      ostringstream str1;
      str1 << (x - num);
      string geek = str1.str();
      return geek;
    }
  }
  return "";
}
string is_one(string &s, long long num, int j) {
  char temp = (int)s[j] - 48;
  if (temp - num < 0) return "";
  ostringstream str1;
  str1 << (temp - num);
  string geek = str1.str();
  return geek;
}
void solve() {
  string a;
  string s;
  cin >> a >> s;
  s = "0" + s;
  ;
  long long i = a.length() - 1, j = s.length() - 1;
  string answer = "";
  while (j >= 0) {
    char temp = '0';
    if (i >= 0) temp = a[i];
    if (temp != '0') {
      long long num = (int)temp - 48;
      string two = is_two(s, num, j);
      if (two != "") {
        answer = two + answer;
        j = j - 2;
        --i;
        continue;
      }
    }
    long long num = (int)temp - 48;
    string one = is_one(s, num, j);
    if (one == "") {
      cout << "-1\n";
      return;
    } else {
      answer = one + answer;
      --j;
    }
    --i;
  }
  int k = 0;
  while (answer[k] == '0') ++k;
  string temp = "";
  while (k < answer.length()) {
    temp.push_back(answer[k]);
    ++k;
  }
  if (temp == "")
    cout << "0\n";
  else
    cout << temp << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) solve();
}
