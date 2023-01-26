#include <bits/stdc++.h>
using namespace std;
long long counter(string str, int x) {
  int n = str.size();
  for (int i = 0; i < n; i++) {
    if (str[i] == 'X') {
      str[i] = (char)('0' + x);
    }
  }
  if (str == "0") {
    return 1;
  }
  if (str.size() == 1) {
    return 0;
  }
  if (str.size() == 2) {
    if (str == "25" || str == "50" || str == "75")
      return 1;
    else
      return 0;
  }
  if (str[n - 1] != '0' && str[n - 1] != '_' && str[n - 1] != '5') {
    return 0;
  }
  long long last = 1;
  if (str[n - 1] == '_') {
    if (str[n - 2] == '2' || str[n - 2] == '5' || str[n - 2] == '7' ||
        str[n - 2] == '0') {
      last = 1;
    } else if (str[n - 2] == '_') {
      last = 4;
    } else {
      last = 0;
    }
  } else if (str[n - 1] == '5' || str[n - 1] == '0') {
    if (str[n - 2] == '_') {
      last = 2;
    } else if (str[n - 1] == '5' && (str[n - 2] == '2' || str[n - 2] == '7')) {
      last = 1;
    } else if (str[n - 1] == '0' && (str[n - 2] == '0' || str[n - 2] == '5')) {
      last = 1;
    } else
      last = 0;
  }
  long long count = last;
  for (int i = 0; i < n - 2; i++) {
    if (str[i] == '_') {
      if (i == 0)
        count *= 9;
      else
        count *= 10;
    }
  }
  if (str[0] == '0') return 0;
  return count;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  string str;
  cin >> str;
  bool hasX = false;
  for (int i = 0; i < str.size(); i++) hasX = hasX || str[i] == 'X';
  if (!hasX)
    cout << counter(str, 0) << "\n";
  else {
    long long total = 0;
    for (int i = 0; i < 10; i++) {
      total += counter(str, i);
    }
    cout << total << "\n";
  }
}
