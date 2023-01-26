#include <bits/stdc++.h>
using namespace std;
string remove(string s, char a) {
  int n = s.size();
  string res = "";
  for (int i = 0; i < n; i++) {
    if (s[i] != a) res += s[i];
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    set<char> a;
    stack<char> st;
    map<char, int> m;
    for (int i = n - 1; i >= 0; i--) {
      if (a.find(s[i]) == a.end()) st.push(s[i]);
      a.insert(s[i]);
      m[s[i]]++;
    }
    string del = "";
    while (!st.empty()) {
      del += st.top();
      st.pop();
    }
    int cnt = 0;
    for (int i = 0; i < del.size(); i++) {
      int k = m[del[i]] / (i + 1);
      cnt += k;
    }
    string str = "";
    for (int i = 0; i < cnt; i++) {
      str += s[i];
    }
    string rem = str;
    string k = str;
    for (int i = 0; i < del.size(); i++) {
      string p = remove(rem, del[i]);
      k += p;
      rem = p;
    }
    if (k == s)
      cout << str << " " << del << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
