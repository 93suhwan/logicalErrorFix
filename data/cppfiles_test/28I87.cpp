#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int mxx = 200005;
long long int dx[] = {0, 1, 0, -1};
long long int dy[] = {1, 0, -1, 0};
long long int dxx[] = {0, 1, 0, -1, 1, 1, -1, -1};
long long int dyy[] = {1, 0, -1, 0, 1, -1, 1, -1};
bool cmp(long long int a, long long int b) { return a > b; }
void solve() {
  string s, t;
  cin >> s >> t;
  int len = s.size();
  int ten = t.size();
  if (ten > len || ten == len and s != t) {
    cout << "No\n";
    return;
  }
  if (s == t) {
    cout << "Yes\n";
    return;
  }
  int x = 0;
  int y = 0;
  queue<int> v[30], v1[30];
  for (int i = 0; i < len; i++) {
    v[s[i] - 'a' + 1].push(i + 1);
    v1[s[i] - 'a' + 1].push(i + 1);
  }
  int last = 0, ck = 0;
  for (int i = 0; i < ten; i++) {
    int ok = 0;
    if (last % 2 == 0) {
      if (v[t[i] - 'a' + 1].size() == 0) break;
      while (v[t[i] - 'a' + 1].size()) {
        if (v[t[i] - 'a' + 1].front() % 2 == 0 ||
            v[t[i] - 'a' + 1].front() < last)
          v[t[i] - 'a' + 1].pop();
        else {
          last = v[t[i] - 'a' + 1].front(), ok = 1, v[t[i] - 'a' + 1].pop();
          break;
        }
      }
      if (ok == 0) {
        ck = 1;
        break;
      }
    } else {
      if (v[t[i] - 'a' + 1].size() == 0) break;
      while (v[t[i] - 'a' + 1].size()) {
        if (v[t[i] - 'a' + 1].front() % 2 == 1 ||
            v[t[i] - 'a' + 1].front() < last)
          v[t[i] - 'a' + 1].pop();
        else {
          last = v[t[i] - 'a' + 1].front(), ok = 1, v[t[i] - 'a' + 1].pop();
          break;
        }
      }
      if (ok == 0) {
        ck = 1;
        break;
      }
    }
  }
  if (ck == 0) {
    cout << "Yes\n";
    return;
  }
  last = 1, ck = 0;
  for (int i = 0; i < ten; i++) {
    int ok = 0;
    if (last % 2 == 0) {
      if (v1[t[i] - 'a' + 1].size() == 0) break;
      while (v1[t[i] - 'a' + 1].size()) {
        if (v1[t[i] - 'a' + 1].front() % 2 == 0 ||
            v1[t[i] - 'a' + 1].front() < last)
          v1[t[i] - 'a' + 1].pop();
        else {
          last = v1[t[i] - 'a' + 1].front(), ok = 1, v1[t[i] - 'a' + 1].pop();
          break;
        }
      }
      if (ok == 0) {
        ck = 1;
        break;
      }
    } else {
      if (v1[t[i] - 'a' + 1].size() == 0) break;
      while (v1[t[i] - 'a' + 1].size()) {
        if (v1[t[i] - 'a' + 1].front() % 2 == 1 ||
            v1[t[i] - 'a' + 1].front() < last)
          v1[t[i] - 'a' + 1].pop();
        else {
          last = v1[t[i] - 'a' + 1].front(), ok = 1, v1[t[i] - 'a' + 1].pop();
          break;
        }
      }
      if (ok == 0) {
        ck = 1;
        break;
      }
    }
  }
  if (ck == 0) {
    cout << "Yes\n";
    return;
  }
  cout << "No\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
