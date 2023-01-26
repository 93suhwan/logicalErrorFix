#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool solve(ll inA, ll inB);
string decimalToBinaryStr(ll number);
string removeLeadingZero(string b);
string reverseString(string str);
bool findStringWithLeadingOne(string s, string f, bool isReverse);
int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  ll a, b;
  cin >> a >> b;
  if (solve(a, b))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
bool solve(ll inA, ll inB) {
  string inAStr = decimalToBinaryStr(inA);
  string inBStr = decimalToBinaryStr(inB);
  cout << inAStr << endl;
  cout << inBStr << endl;
  int posEnd = inAStr.size() - 1;
  string inAStrTst = inAStr;
  string reverse = reverseString(inAStrTst);
  if (findStringWithLeadingOne(inBStr, inAStrTst, false) == true ||
      findStringWithLeadingOne(inBStr, reverse, true) == true)
    return true;
  inAStrTst = removeLeadingZero(inAStr);
  reverse = reverseString(inAStrTst);
  if (findStringWithLeadingOne(inBStr, inAStrTst, false) == true ||
      findStringWithLeadingOne(inBStr, reverse, true) == true)
    return true;
  return false;
}
bool findStringWithLeadingOne(string s, string f, bool isReverse) {
  int idx = s.find(f);
  if (idx == string::npos) return false;
  int left = 0;
  int right = 0;
  for (int i = 0; i < idx; i++) {
    if (s[i] == '0') return false;
  }
  for (int i = idx + f.size(); i < s.size(); i++) {
    if (s[i] == '0') return false;
  }
  if (left != 0 && right == 0 && !isReverse) return false;
  if (left == 0 && right != 0 && isReverse) return false;
  return true;
}
string decimalToBinaryStr(ll number) {
  string out;
  if (number == 0) out = "0";
  while (number > 0) {
    out = ((number % 2LL == 0) ? "0" : "1") + out;
    number /= 2LL;
  }
  return out;
}
string removeLeadingZero(string b) {
  string out;
  int posStart = 0;
  int posEnd = b.size() - 1;
  while (b[posStart] == '0') {
    posStart++;
  }
  while (b[posEnd] == '0') {
    posEnd--;
  }
  if (posEnd < posStart)
    out = "0";
  else
    out = b.substr(posStart, posEnd - posStart + 1);
  return out;
}
string reverseString(string num) {
  int n = num.length();
  string out = num;
  for (int i = 0; i < n / 2; i++) {
    swap(out[i], out[n - i - 1]);
  }
  return out;
}
string performOperation(string num, bool addOne) {
  string out;
  if (addOne) {
    out = num + "1";
  }
  reverseString(num);
  return removeLeadingZero(num);
}
