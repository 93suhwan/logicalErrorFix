#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    map<long long, long long> found;
    cin >> n >> k;
    string s = to_string(n);
    long long cnt = 0;
    long long lasttochange = -1;
    long long firstforoccur = -1;
    long long change = -1;
    char min = '9';
    char f = '*';
    for (long long i = 0; i < s.size(); i++) {
      if (!found[s[i]]) {
        cnt++;
        if (cnt == k) firstforoccur = i;
        if (cnt > k) {
          change = i;
          break;
        }
        if (s[i] < min) min = s[i];
      }
      char assign = s[i] + 1;
      while (assign > s[i]) {
        if (found[assign]) {
          lasttochange = i;
          f = assign;
          break;
        }
        if (assign >= '9') {
          break;
        }
        assign++;
      }
      found[s[i]]++;
    }
    if (change == -1)
      cout << s << '\n';
    else {
      char assign = s[change] + 1;
      bool can = false;
      while (assign > s[change]) {
        if (found[assign]) {
          s[change] = assign;
          can = true;
          for (long long i = change + 1; i < s.size(); i++) s[i] = min;
          break;
        }
        if (assign >= '9') {
          break;
        }
        assign++;
      }
      if (!can) {
        if (firstforoccur >= lasttochange) {
          if (s[firstforoccur] == min) min = s[firstforoccur] + 1;
          if (found[s[firstforoccur] + 1]) min = '0';
          s[firstforoccur]++;
          for (long long i = firstforoccur + 1; i < s.size(); i++) {
            s[i] = min;
          }
        } else {
          if (found[s[lasttochange]] == 1) {
            min = '0';
          }
          s[lasttochange] = f;
          for (long long i = lasttochange + 1; i < s.size(); i++) {
            s[i] = min;
          }
        }
      }
      cout << s << '\n';
    }
  }
  return 0;
}
