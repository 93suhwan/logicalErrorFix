#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  string s1, s2;
  long long n1, n2, num1 = 0, num2 = 0;
  cin >> s1;
  cin >> n1;
  if (n1 > 0) {
    for (int i = 0; i < n1; i++) {
      s1 += '0';
    }
    for (int i = 0; i < s1.size(); i++) {
      num1 *= 10;
      num1 += s1[i] - 48;
    }
  } else {
    for (int i = 0; i < s1.size(); i++) {
      num1 *= 10;
      num1 += s1[i] - 48;
    }
  }
  cin >> s2;
  cin >> n2;
  if (n2 > 0) {
    for (int i = 0; i < n2; i++) {
      s2 += '0';
    }
    for (int i = 0; i < s2.size(); i++) {
      num2 *= 10;
      num2 += s2[i] - 48;
    }
  } else {
    for (int i = 0; i < s2.size(); i++) {
      num2 *= 10;
      num2 += s2[i] - 48;
    }
  }
  if (num1 > num2)
    cout << '>' << endl;
  else if (num1 < num2)
    cout << '<' << endl;
  else
    cout << '=' << endl;
  return 0;
}
