#include <bits/stdc++.h>
using namespace std;
pair<vector<char>, bool> solve(set<char> useddigits, int k, string n) {
  if (n.length() == 0) {
    return {{}, true};
  }
  if (useddigits.find(n[0]) != useddigits.end()) {
    pair<vector<char>, bool> remainder =
        solve(useddigits, k, n.substr(1, n.size() - 1));
    if (remainder.second) {
      remainder.first.insert(remainder.first.begin(), n[0]);
      return remainder;
    }
  }
  if (k == 0) {
    for (char d : useddigits) {
      if (d == n[0]) {
        pair<vector<char>, bool> remainder =
            solve(useddigits, k, n.substr(1, n.size() - 1));
        if (remainder.second) {
          remainder.first.insert(remainder.first.begin(), d);
          return remainder;
        }
      } else if (d > n[0]) {
        char small = *min_element(useddigits.begin(), useddigits.end());
        vector<char> ans(n.size(), small);
        ans[0] = d;
        return {ans, true};
      }
    }
  } else if (k == 1) {
    set<char> copy = useddigits;
    copy.insert(n[0]);
    pair<vector<char>, bool> remainder = solve(copy, k - 1, n);
    return remainder;
    useddigits.insert(n[0] + 1);
    char small = *min_element(useddigits.begin(), useddigits.end());
    vector<char> ans(n.size(), small);
    ans[0] = n[0] + 1;
    return {ans, true};
  }
  return {{}, false};
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    string n;
    int k;
    cin >> n >> k;
    vector<char> digits;
    set<char> useddigits;
    int i = 0;
    while (useddigits.size() < k - 1 && i < n.size()) {
      digits.push_back(n[i]);
      useddigits.insert(n[i]);
      i++;
    }
    if (i >= n.size()) {
      for (char j : digits) {
        cout << j;
      }
      cout << endl;
    } else {
      vector<char> remainder =
          solve(useddigits, 1, n.substr(i, n.size() - i)).first;
      for (char j : digits) {
        cout << j;
      }
      for (char j : remainder) {
        cout << j;
      }
      cout << endl;
    }
  }
}
