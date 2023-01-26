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
  int s_len = ssz - i - 1;
  int t_len = tsz - j - 1;
  if (t_len > s_len) return false;
  if (j == tsz && i >= ssz) return true;
  if (i >= ssz) return false;
  if (s[i] == t[j]) {
    bool a = search(s, t, i + 1, j + 1);
    bool b = search(s, t, i + 2, j);
    return a || b;
  } else {
    return search(s, t, i + 2, j);
  }
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
        cout << s << " " << t << " " << i << endl;
        found = found || search(s, t, i + 1, 1);
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
