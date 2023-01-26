#include <bits/stdc++.h>
using namespace std;
void rotate(vector<long long int>& vec, int number_of_rotation) {
  reverse(vec.begin(), vec.begin() + number_of_rotation);
  reverse(vec.begin(), vec.begin() + number_of_rotation + 1);
}
string ab(string s) {
  if (s.find("AB") != string::npos) {
    s.erase(s.find("AB"), 2);
    return ab(s);
  }
  return s;
}
string bb(string s) {
  if (s.find("BB") != string::npos) {
    s.erase(s.find("BB"), 2);
    return bb(s);
  }
  return s;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    string n;
    cin >> s;
    cin >> n;
    map<char, int> m;
    for (int i{0}; i < s.length(); i++) {
      m[s[i]] = i;
    }
    long long int sum = 0;
    long long int last = m[n[0]];
    for (int i{0}; i < n.length(); i++) {
      sum += abs(m[n[i]] - last);
      last = m[n[i]];
    }
    cout << sum << endl;
  }
}
