#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int vis[26], e, cnt, rep[26], book[26];
bool mem[N];
string ptr, str;
bool check(string s) {
  string cmp = s;
  for (int i = 0; i < ptr.size(); i++) {
    string ad = "";
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == ptr[i]) mem[j] = true;
      if (mem[j] == false) ad += s[j];
    }
    cmp += ad;
  }
  if (cmp == str)
    return true;
  else
    return false;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    memset(rep, 0, sizeof(rep));
    memset(book, 0, sizeof(book));
    ptr = "";
    cin >> str;
    e = 1;
    char ch = str[str.size() - 1];
    for (int i = str.size() - 2; i >= 0; i--) {
      if (str[i] != ch) break;
      e++;
    }
    for (int i = str.size() - 1; i >= 0; i--) {
      mem[i] = false;
      if (vis[str[i] - 'a'] == 0) ptr += str[i], cnt++;
      vis[str[i] - 'a']++;
    }
    if (vis[ch - 'a'] % e != 0) {
      for (int i = e - 1; i >= 1; i--) {
        if (vis[ch - 'a'] % i == 0) {
          e = vis[ch - 'a'] / i;
          break;
        }
      }
    } else
      e = vis[ch - 'a'] / e;
    if (cnt != e) {
      puts("-1");
      continue;
    }
    for (int i = 0; i < ptr.size(); i++) {
      rep[ptr[i] - 'a'] = vis[ptr[i] - 'a'] / e;
      e--;
    }
    string ans = "";
    for (int i = 0; i < str.size(); i++) {
      if (book[str[i] - 'a'] + 1 > rep[str[i] - 'a']) break;
      ans += str[i];
      book[str[i] - 'a']++;
    }
    reverse(ptr.begin(), ptr.end());
    if (check(ans)) {
      cout << ans << ' ' << ptr << endl;
    } else
      puts("-1");
  }
  return 0;
}
