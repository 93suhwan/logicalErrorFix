#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int sum = 0;
  for (int i = 1; i < s.size(); i++) {
    sum += abs(s[i] - s[i - 1]);
  }
  cout << sum;
  return 0;
}
