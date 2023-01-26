#include <bits/stdc++.h>
using namespace std;
int string_compare(string s1, string pow) {
  int ctr1 = 0, ctr = 0;
  int rem = 0;
  while (ctr1 < s1.size() && ctr < pow.size()) {
    if (s1[ctr1] == pow[ctr])
      ctr++;
    else
      rem++;
    ctr1++;
  }
  if (ctr == pow.size())
    rem = rem + s1.size() - ctr1;
  else if (ctr1 == s1.size())
    rem = rem + pow.size() - ctr;
  return rem;
}
string convert_string(int n) {
  string s;
  while (n) {
    s.push_back(n % 10 + '0');
    n /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
int main() {
  string power2[31];
  for (int i = 0; i < 31; i++) {
    power2[i] = convert_string(pow(2, i));
  }
  int t;
  cin >> t;
  while (t--) {
    set<int> ans;
    string s;
    cin >> s;
    for (int i = 0; i < 31; i++) {
      ans.insert(string_compare(s, power2[i]));
    }
    cout << *(ans.begin()) << endl;
  }
}
