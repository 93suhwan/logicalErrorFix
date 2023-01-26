#include <bits/stdc++.h>
using namespace std;
int INF = 0x3f3f3f3f;
long long LINF = 0x3f3f3f3f3f3f3f3f;
int dy[]{-1, 1, 0, 0};
int dx[]{0, 0, -1, 1};
int k;
string n;
string solve1() {
  string ret = string(n.length(), '9');
  for (char a = '8'; a >= '0'; a--) {
    string t = string(n.length(), a);
    if (t >= n) ret = t;
  }
  return ret;
}
string solve2() {
  string ret = solve1();
  for (char a = '0'; a <= '8'; a++) {
    for (char b = a + 1; b <= '9'; b++) {
      bool flag = true;
      for (int i = (0); i < (n.length()); ++i) {
        if (n[i] < b) {
          string t = n;
          if (t[i] < a)
            t[i] = a;
          else
            t[i] = b;
          for (int j = (i + 1); j < (n.length()); ++j) t[j] = a;
          if (t < ret) ret = t;
        }
        if (n[i] != a && n[i] != b) {
          flag = false;
          break;
        }
      }
      if (flag) {
        return n;
      }
    }
  }
  return ret;
}
string solve3() {
  while (1) {
    set<char> s;
    for (auto& e : n) {
      s.insert(e);
    }
    if (s.size() <= k) return n;
    s.clear();
    for (int i = 0;; i++) {
      s.insert(n[i]);
      if (s.size() > k) {
        int p = i;
        while (n[p] == '9') --p;
        n[p]++;
        for (int j = (p + 1); j < (n.length()); ++j) n[j] = '0';
        break;
      }
    }
  }
}
void solve() {
  cin >> n >> k;
  if (k == 1)
    cout << solve1() << '\n';
  else if (k == 2)
    cout << solve2() << '\n';
  else
    cout << solve3() << '\n';
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TC;
  cin >> TC;
  while (TC--) {
    solve();
  }
  return 0;
}
