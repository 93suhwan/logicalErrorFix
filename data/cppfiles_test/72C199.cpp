#include <bits/stdc++.h>
using namespace std;
const int maxn = 200009;
vector<int> a;
string in;
int k;
string build(string s, vector<char> ch, int ind, bool bigger) {
  char nw = s[ind];
  if (ind == s.size()) return s;
  string tmp;
  if (bigger) {
    for (char c = '0'; c <= '9'; ++c) {
      bool check = true;
      for (int i = 0; i < ch.size() && check; ++i)
        if (ch[i] == c) check = false;
      if (check == false) {
        s[ind] = c;
        tmp = build(s, ch, ind + 1, 1);
        if (tmp != "-1") return tmp;
        s[ind] = nw;
      } else {
        if (ch.size() == k) continue;
        ch.push_back(c);
        s[ind] = c;
        tmp = build(s, ch, ind + 1, 1);
        s[ind] = nw;
        if (tmp != "-1") return tmp;
        ch.pop_back();
      }
    }
  } else {
    for (char c = nw; c <= '9'; ++c) {
      bool check = true;
      for (int i = 0; i < ch.size() && check; ++i)
        if (ch[i] == c) check = false;
      if (check == true) {
        if (ch.size() == k) continue;
        ch.push_back(c);
        s[ind] = c;
        if (c == nw)
          tmp = build(s, ch, ind + 1, 0);
        else
          tmp = build(s, ch, ind + 1, 1);
        if (tmp != "-1") return tmp;
        s[ind] = nw;
        ch.pop_back();
      } else {
        s[ind] = c;
        if (c == nw)
          tmp = build(s, ch, ind + 1, 0);
        else
          tmp = build(s, ch, ind + 1, 1);
        s[ind] = nw;
        if (tmp != "-1") return tmp;
      }
    }
  }
  return "-1";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> in >> k;
    vector<char> v;
    cout << build(in, v, 0, 0) << endl;
  }
  return 0;
}
