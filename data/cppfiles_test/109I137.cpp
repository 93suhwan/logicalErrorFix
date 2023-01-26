#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int count1 = 0;
  int count2 = 0;
  string str;
  cin >> str;
  for (int i = 0; i < n; i++) {
    if (str[i] != '0') {
      int x = str[i] - '0';
      count2 += x;
      count1++;
    }
  }
  if (str[n - 1] == '0') {
    cout << (count1 + count2) << endl;
  } else {
    cout << (count1 + count2) - 1 << endl;
  }
  return 0;
}
