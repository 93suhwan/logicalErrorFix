#include <bits/stdc++.h>
using namespace std;
pair<int, char> last[26];
int num[26];
string make(string s, string seq) {
  string t = "";
  for (int i = 0; i < seq.length(); i++) {
    t += s;
    string p = "";
    for (int j = 0; j < s.length(); j++)
      if (s[j] != seq[i]) p += s[j];
    s = p;
  }
  return t;
}
int main() {
  int T;
  for (cin >> T; T--;) {
    string t;
    cin >> t;
    memset(num, 0, sizeof(num));
    for (int i = 0; i < 26; i++)
      last[i] = make_pair(t.length() + 1, char('a' + i));
    for (int i = 0; i < t.length(); i++) {
      last[t[i] - 'a'].first = i;
      num[t[i] - 'a']++;
    }
    sort(last, last + 26);
    string seq;
    int total = 0;
    for (int i = 0; i < 26 && last[i].first < t.length(); i++) {
      seq += last[i].second;
      total += num[last[i].second - 'a'] / (i + 1);
    }
    string s = t.substr(0, total);
    if (make(s, seq) == t)
      cout << s << " " << seq << endl;
    else
      cout << -1 << endl;
  }
}
