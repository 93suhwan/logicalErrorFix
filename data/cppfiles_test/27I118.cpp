#include <bits/stdc++.h>
using namespace std;
template <typename T>
void debug(vector<T> item) {
  for (auto& i : item) {
    cout << i << " ";
  }
  cout << endl;
}
bool search(string& s, string& t, int i, int j) {
  int ssz = s.size();
  int tsz = t.size();
  while (i < ssz && j <= tsz) {
    if (j == tsz) i += 2;
    if (s[i] == t[j]) {
      i++;
      j++;
    } else {
      i += 2;
    }
  }
  return j == tsz && i == ssz;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    string t;
    cin >> s >> t;
    int ssz = s.size();
    int tsz = t.size();
    bool found = false;
    for (int i = 0; i < ssz; ++i) {
      if (found) break;
      if (s[i] == t[0]) {
        found = found || search(s, t, i, 0);
      }
    }
    if (found) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
