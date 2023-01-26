#include <bits/stdc++.h>
using namespace std;
int test, sum;
string t, str, s;
map<char, int> tot, seg;
vector<int> v;
bool solve(char c) {
  sum += seg[c];
  int x = sum;
  string temp;
  vector<int> pos;
  if (t.size() == 0) return false;
  for (int i = t.size() - 1; i >= 0; i--) {
    if (x == 0) break;
    temp += t[i];
    x--;
  }
  reverse(temp.begin(), temp.end());
  for (int i = 0; i < temp.size(); i++)
    if (temp[i] == c) pos.push_back(i);
  for (int i = 0; i < v.size(); i++) {
    if (count(temp.begin(), temp.end(), v[i]) != seg[v[i]]) return false;
  }
  for (int i = 0; i < pos.size(); i++) {
    if (pos[i] > str.size()) return false;
    str.insert(pos[i], 1, c);
  }
  int y = t.size();
  if (str == temp) {
    t.erase(y - sum);
    return true;
  }
  return false;
}
int main() {
  scanf("%d", &test);
  while (test--) {
    str.clear();
    s.clear();
    tot.clear();
    seg.clear();
    t.clear();
    v.clear();
    sum = 0;
    cin >> t;
    if (t.size() == 0) {
      printf("-1\n");
      continue;
    }
    for (int i = t.size() - 1; i >= 0; i--)
      if (count(s.begin(), s.end(), t[i]) == 0) s += t[i];
    int n = s.size();
    for (int i = 0; i < t.size(); i++) {
      tot[t[i]]++;
    }
    int cnt = 0;
    bool vld = 1;
    for (auto x : s) {
      if (n - cnt == 0) {
        vld = 0;
        break;
      }
      seg[x] = tot[x] / (n - cnt);
      if (seg[x] < 1 || seg[x] * (n - cnt) != tot[x]) {
        vld = 0;
        break;
      }
      cnt++;
    }
    if (!vld) {
      printf("-1\n");
      continue;
    }
    bool b = 1;
    for (int i = 0; i < s.size(); i++) {
      b = solve(s[i]);
      if (!b) break;
      v.push_back(s[i]);
    }
    if (b) {
      printf("%s ", str.c_str());
      reverse(v.begin(), v.end());
      for (auto x : v) printf("%c", x);
      printf("\n");
    } else
      printf("-1\n");
  }
  return 0;
}
