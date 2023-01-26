#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
const long long int N = 100005;
const long long int M = 200005;
char mc;
void run() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long int count(string s) {
  long long int ctt = 0;
  for (auto ch : s) {
    if (ch == mc) {
      ctt++;
    }
  }
  return ctt;
}
void solve() {
  long long int n = 0;
  cin >> n;
  vector<char> l = {'a', 'b', 'c', 'd', 'e'};
  string s;
  vector<string> words;
  for (long long int i = 0; i < n; i++) {
    cin >> s;
    words.push_back(s);
  }
  long long int maxct = 0;
  for (auto c : l) {
    mc = c;
    sort(words.begin(), words.end(), [](const string& x, const string& y) {
      return count(x) == count(y) ? x.size() < y.size() : count(x) > count(y);
    });
    long long int i = 0;
    long long int length = 0;
    long long int ct = 0;
    long long int tl = 0;
    while (i < words.size()) {
      ct += count(words[i]);
      tl += words[i].size();
      if (ct <= tl - ct) {
        ct -= count(words[i]);
        tl -= words[i].size();
      } else {
        length++;
      }
      i++;
    }
    maxct = max(maxct, length);
  }
  cout << maxct << "\n";
}
signed main() {
  run();
  long long int q;
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
