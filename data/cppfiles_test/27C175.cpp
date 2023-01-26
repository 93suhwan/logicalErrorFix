#include <bits/stdc++.h>
using namespace std;
const int PI = 3.1415926535897932384626433832795;
const int mod = 1000000007;
const int MOD = 1000000007;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string number_in_string[50] = {"zero", "one", "two",   "three", "four",
                                     "five", "six", "seven", "eight", "nine"};
clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
bool ok = 0;
string s, t;
vector<int> store_pos[30];
int pos = 0;
int mark_pos[30];
bool odd = 0, even = 0;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  startTime = clock();
  int test;
  cin >> test;
  while (test--) {
    pos = 0;
    for (int i = 0; i <= 'z' - 'a'; i++) store_pos[i].clear();
    cin >> s >> t;
    if (s.size() < t.size()) {
      cout << "NO\n";
      continue;
    }
    for (int i = 0; i <= (int)s.size() - 1; i++)
      store_pos[s[i] - 'a'].push_back(i);
    if (store_pos[t[0] - 'a'].empty()) {
      cout << "NO\n";
      continue;
    }
    if (t.size() == 1) {
      for (int i : store_pos[t[0] - 'a']) {
        if ((s.size() - i) & 1) {
          cout << "YES\n";
          goto gg;
        }
      }
      cout << "NO\n";
      continue;
    }
    odd = 0;
    even = 0;
    for (int i = 0; i <= store_pos[t[0] - 'a'].size() - 1; i++) {
      pos = store_pos[t[0] - 'a'][i];
      if (odd && even) break;
      if (pos % 2 && odd) continue;
      if (pos % 2 == 0 && even) continue;
      if (pos & 1)
        odd = 1;
      else
        even = 1;
      for (int j = 0; j <= 'z' - 'a'; j++) mark_pos[j] = 0;
      for (int j = 1; j <= (int)t.size() - 1; j++) {
        ok = 0;
        if (store_pos[t[j] - 'a'].empty()) break;
        for (int k = mark_pos[t[j] - 'a'];
             k <= store_pos[t[j] - 'a'].size() - 1; k++) {
          if (store_pos[t[j] - 'a'][k] > pos) {
            if ((store_pos[t[j] - 'a'][k] - pos) & 1) {
              pos = store_pos[t[j] - 'a'][k];
              ok = 1;
              mark_pos[t[j] - 'a'] = k + 1;
              break;
            }
          }
        }
        if (!ok) break;
        if (j == (int)t.size() - 1 && (s.size() - pos) & 1) {
          cout << "YES\n";
          goto gg;
        }
      }
    }
    cout << "NO\n";
  gg:
    continue;
  }
  exit(0);
}
