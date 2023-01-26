#include <bits/stdc++.h>
using namespace std;
bool isValid(string& x, string& y) {
  int found = y.find(x);
  if (found == string::npos) return false;
  for (int i = 0; i < found; ++i) {
    if (y[i] == '0') return false;
  }
  for (int i = found + x.length(); i < y.length(); ++i) {
    if (y[i] == '0') return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  unsigned long long x, y;
  cin >> x >> y;
  bitset<64> b1(x);
  bitset<64> b2(y);
  string xString = b1.to_string();
  string yString = b2.to_string();
  int index = 0;
  while (xString[index] == '0') {
    index++;
  }
  xString = xString.substr(index);
  index = 0;
  while (yString[index] == '0') {
    index++;
  }
  yString = yString.substr(index);
  if (isValid(xString, yString) &&
      (yString.find(xString) == 0 || xString.back() == '1')) {
    cout << "YES\n";
    return 0;
  }
  index = -1;
  for (int i = 0; i < xString.length(); ++i)
    if (xString[i] == '1') index = i;
  string xNoTrailing = xString.substr(0, index + 1);
  if (isValid(xNoTrailing, yString)) {
    cout << "YES\n";
    return 0;
  }
  reverse(xNoTrailing.begin(), xNoTrailing.end());
  if (isValid(xNoTrailing, yString)) {
    cout << "YES\n";
    return 0;
  }
  xString.push_back('1');
  reverse(xString.begin(), xString.end());
  if (isValid(xString, yString)) {
    cout << "YES\n";
    return 0;
  }
  cout << "NO\n";
  return 0;
}
