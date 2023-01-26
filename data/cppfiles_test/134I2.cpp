#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long, long long>& a, pair<long long, long long>& b) {
  return a.second > b.second;
}
bool is_palindrome(string s) {
  for (long long i = 0, j = s.size() - 1; i <= j; i++, j--) {
    if (s[i] != s[j]) return false;
  }
  return true;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (auto& i : a) {
    cin >> i;
  }
  vector<long long> first;
  vector<long long> second;
  for (long long i = 0; i < n; i++) {
    if (i % 2 == 0) {
      first.push_back(a[i]);
    } else {
      second.push_back(a[i]);
    }
  }
  sort(first.begin(), first.end());
  sort(second.begin(), second.end());
  if (first[0] == second[0]) {
    cout << 0 << '\n';
    ;
  } else {
    if (first[0] == 1) {
      for (long long i = 1; i < second.size(); i++) {
        if (second[i] % second[0] != 0) {
          cout << 0 << '\n';
          ;
          return;
        }
      }
      for (long long i = 0; i < first.size(); i++) {
        if (first[i] % second[0] == 0) {
          cout << 0 << '\n';
          ;
          return;
        }
      }
      cout << second[0] << '\n';
      ;
      return;
    }
    if (second[0] == 1) {
      for (long long i = 1; i < first.size(); i++) {
        if (first[i] % first[0] != 0) {
          cout << 0 << '\n';
          ;
          return;
        }
      }
      for (long long i = 0; i < second.size(); i++) {
        if (second[i] % first[0] == 0) {
          cout << 0 << '\n';
          ;
          return;
        }
      }
      cout << first[0] << '\n';
      ;
      return;
    }
    long long flag = 0;
    for (long long i = 1; i < first.size(); i++) {
      if (first[i] % first[0] != 0) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      for (long long i = 1; i < second.size(); i++) {
        if (second[i] % second[0] != 0) {
          cout << 0 << '\n';
          ;
          return;
        }
      }
      for (long long i = 0; i < first.size(); i++) {
        if (first[i] % second[0] == 0) {
          cout << 0 << '\n';
          ;
          return;
        }
      }
      cout << second[0] << '\n';
      ;
      return;
    } else {
      long long f = 0;
      for (long long i = 0; i < second.size(); i++) {
        if (second[i] % first[0] == 0) {
          f = 1;
          break;
        }
      }
      if (f) {
        for (long long i = 1; i < second.size(); i++) {
          if (second[i] % second[0] != 0) {
            cout << 0 << '\n';
            ;
            return;
          }
        }
        for (long long i = 0; i < first.size(); i++) {
          if (first[i] % second[0] == 0) {
            cout << 0 << '\n';
            ;
            return;
          }
        }
        cout << second[0] << '\n';
        ;
        return;
      } else {
        cout << first[0] << '\n';
        ;
        return;
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
