#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, f, g, n, m, k, t, x, h, w, p, q, y;
string str = "", s1 = "", s2 = "";
long long mod = 1e9 + 7;
const int N = 200009;
void solve() {
  cin >> str;
  string deleted = "";
  set<char> used;
  vector<long long> freq(26, 0);
  vector<long long> indx(26, 0);
  for (int i = str.size() - 1; i >= 0; i--) {
    char ch = str[i];
    freq[ch - 'a']++;
    if (!used.count(ch)) {
      deleted.push_back(ch);
      used.insert(ch);
      indx[ch - 'a'] = used.size();
    }
  }
  bool flag = true;
  reverse(deleted.begin(), deleted.end());
  vector<long long> original_amounts(26, 0);
  int len = 0;
  for (int i = 0; i < 26; i++) {
    if (freq[i]) original_amounts[i] = freq[i] / indx[i];
    if (freq[i] % indx[i]) flag = false;
    len += original_amounts[i];
  }
  string answer = str.substr(0, len);
  if (flag) {
    cout << "-1\n";
    return;
  }
  string pas = "";
  used.clear();
  int amount = deleted.size();
  for (int i = 0; i < amount; i++) {
    for (char ch : answer) {
      if (!used.count(ch)) pas.push_back(ch);
    }
    used.insert(deleted[i]);
  }
  if (pas != str) {
    cout << "-1\n";
  } else
    cout << answer << " " << deleted << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  int cases = 1;
  cin >> cases;
  while (cases--) solve();
  return 0;
}
