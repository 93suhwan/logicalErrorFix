#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int test;
  cin >> test;
  while (test--) {
    long long int i, j, k, n, temp, count = 0, ans = 0, sum = 0;
    cin >> n;
    string s;
    cin >> s;
    long long int cnt[9];
    memset(cnt, 0, sizeof(cnt));
    for (i = 0; i < n; i++) {
      cnt[s[i] - '1']++;
    }
    long long int primes[] = {2, 3, 5, 7};
    long long int ok[] = {1, 4, 6, 8, 9};
    bool flag = false;
    for (auto e : ok) {
      if (cnt[e - 1]) {
        flag = true;
        ans = e;
        break;
      }
    }
    if (flag) {
      cout << 1 << "\n" << ans << "\n";
    } else {
      for (auto e : primes) {
        if (cnt[e - 1] > 1) {
          flag = true;
          ans = e;
          break;
        }
      }
      if (flag) {
        cout << 2 << "\n" << ans << ans << "\n";
      } else {
        long long int first_2, last_2, first_3, last_3, first_5, last_5,
            first_7, last_7;
        first_2 = first_5 = first_7 = first_3 = last_5 = last_7 = last_3 =
            last_2 = -1;
        for (i = 0; i < n; i++) {
          if (s[i] == '2') {
            first_2 = i;
            break;
          }
        }
        for (i = n - 1; i >= 0; i--) {
          if (s[i] == '2') {
            last_2 = i;
            break;
          }
        }
        for (i = 0; i < n; i++) {
          if (s[i] == '3') {
            first_3 = i;
            break;
          }
        }
        for (i = n - 1; i >= 0; i--) {
          if (s[i] == '3') {
            last_3 = i;
            break;
          }
        }
        for (i = 0; i < n; i++) {
          if (s[i] == '5') {
            first_5 = i;
            break;
          }
        }
        for (i = n - 1; i >= 0; i--) {
          if (s[i] == '5') {
            last_5 = i;
            break;
          }
        }
        for (i = 0; i < n; i++) {
          if (s[i] == '7') {
            first_7 = i;
            break;
          }
        }
        for (i = n - 1; i >= 0; i--) {
          if (s[i] == '7') {
            last_7 = i;
            break;
          }
        }
        if (first_2 < last_5 and first_2 >= 0) {
          cout << 2 << "\n"
               << "25"
               << "\n";
          continue;
        }
        if (first_2 < last_7 and first_2 >= 0) {
          cout << 2 << "\n"
               << "27"
               << "\n";
          continue;
        }
        if (first_3 < last_2 and first_3 >= 0) {
          cout << 2 << "\n"
               << "32"
               << "\n";
          continue;
        }
        if (first_3 < last_5 and first_3 >= 0) {
          cout << 2 << "\n"
               << "35"
               << "\n";
          continue;
        }
        if (first_5 < last_2 and first_5 >= 0) {
          cout << 2 << "\n"
               << "52"
               << "\n";
          continue;
        }
        if (first_7 < last_5 and first_7 >= 0) {
          cout << 2 << "\n"
               << "75"
               << "\n";
          continue;
        }
        if (first_7 < last_2 and first_7 >= 0) {
          cout << 2 << "\n"
               << "72"
               << "\n";
          continue;
        }
        if (first_5 < last_7 and first_5 >= 0) {
          for (i = first_5 + 1; i < last_7; i++) {
            if (s[i] == '3') {
              flag = true;
              break;
            }
          }
          if (flag) {
            cout << 3 << "\n"
                 << "537"
                 << "\n";
            continue;
          }
        }
        if (first_5 < last_3 and first_5 >= 0) {
          for (i = first_5 + 1; i < last_3; i++) {
            if (s[i] == '7') {
              flag = true;
              break;
            }
          }
          if (flag) {
            cout << 3 << "\n"
                 << "573"
                 << "\n";
            continue;
          }
        }
      }
    }
  }
  return 0;
}
