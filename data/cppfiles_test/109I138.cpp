#include <bits/stdc++.h>
using namespace std;
int stringSum(string str) {
  string temp = "";
  int sum = 0;
  for (char ch : str) {
    if (isdigit(ch))
      temp += ch;
    else {
      sum += atoi(temp.c_str());
      temp = "";
    }
  }
  return sum + atoi(temp.c_str());
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int sum = 0;
    cout << sum << endl;
  }
}
