#include <bits/stdc++.h>
using namespace std;
bool lefts(string s, string s1, long long i, long long j) {
  if (j == s1.length() - 1) {
    return true;
  } else {
    if (i > 0 && s[i - 1] == s1[j + 1]) {
      return lefts(s, s1, i - 1, j + 1);
    } else {
      return false;
    }
  }
}
bool helper(string s, string s1, long long i, long long j) {
  if (j == s1.length() - 1) {
    return true;
  } else {
    if (i < s.length() - 1 && s[i + 1] == s1[j + 1]) {
      return helper(s, s1, i + 1, j + 1);
    } else {
      if (i > 0 && s[i - 1] == s1[j + 1]) {
        return lefts(s, s1, i - 1, j + 1);
      } else {
        return false;
      }
    }
  }
}
int main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    string s, s1;
    cin >> s >> s1;
    std::vector<long long> v;
    for (long long i = 0; i < s.length(); i++) {
      if (s[i] == s1[0]) {
        v.push_back(i);
      }
    }
    bool ans = false;
    for (long long i = 0; i < v.size(); i++) {
      if (helper(s, s1, v[i], 0) == true) {
        ans = true;
        break;
      }
    }
    if (ans) {
      cout << "yes"
           << "\n";
    } else {
      cout << "No"
           << "\n";
    }
  }
}
