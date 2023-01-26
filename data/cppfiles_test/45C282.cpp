#include <bits/stdc++.h>
using namespace std;
long long solve(string text, string anagram) {
  vector<int> bit(text.size() + 10, 0);
  vector<int> v[200];
  auto add = [&](int pos, int value) {
    while (pos < bit.size()) {
      bit[pos] += value;
      pos += pos & -pos;
    }
  };
  auto query = [&](int pos, int sum = 0) {
    while (pos > 0) {
      sum += bit[pos];
      pos -= pos & -pos;
    }
    return sum;
  };
  text = '#' + text;
  anagram = '#' + anagram;
  for (int i = 1; i < anagram.size(); i++) {
    v[anagram[i]].push_back(i);
  }
  for (int i = 1; i < 200; i++) {
    reverse(v[i].begin(), v[i].end());
  }
  long long ans = 0;
  for (int i = 1; i < text.size(); i++) {
    int was = v[text[i]].back();
    v[text[i]].pop_back();
    int cur_pos = was + query(was);
    ans += cur_pos - i;
    add(1, 1);
    add(was, -1);
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1), odds, evens;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] & 1)
        odds.push_back(i);
      else
        evens.push_back(i);
    }
    string s;
    for (int i = 1; i <= n; i++) {
      if (a[i] & 1)
        s += '1';
      else
        s += '0';
    }
    const long long inf = 1e18;
    long long ans = inf;
    if (abs(int(odds.size()) - int(evens.size())) > 1) {
      cout << -1 << '\n';
      continue;
    } else {
      int k = odds.size() - evens.size();
      string t0;
      for (int i = 1; i <= n; i++) {
        if (i & 1)
          t0 += '0';
        else
          t0 += '1';
      }
      string t1;
      for (int i = 1; i <= n; i++) {
        if (i & 1)
          t1 += '1';
        else
          t1 += '0';
      }
      if (k == 0) {
        ans = min(ans, solve(s, t0));
        ans = min(ans, solve(s, t1));
      } else {
        if (k > 0) {
          ans = min(ans, solve(s, t1));
        } else {
          ans = min(ans, solve(s, t0));
        }
      }
      cout << ans << '\n';
    }
  }
}
