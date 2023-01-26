#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void solve() {
  long long int T = 1;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    long long ans = 0;
    if (s2[0] == '1') {
      if (s1[0] == '0')
        ans++;
      else {
        if (s1[1] == '1') {
          s1[1] == '0';
          ans++;
        }
      }
    }
    if (s2[n - 1] == '1') {
      if (s1[n - 1] == '0')
        ans++;
      else {
        if (s1[n - 2] == '1') {
          s1[n - 2] == '0';
          ans++;
        }
      }
    }
    long long ans1 = 0, ans2 = 0;
    for (long long int i = 1; i < (long long int)(n - 1); i++) {
      if (s2[i] == '1') {
        if (s1[i] == '0')
          ans1++;
        else {
          if (s1[i - 1] == '1') {
            s1[i - 1] == '0';
            ans1++;
          } else if (s1[i + 1] == '1') {
            s1[i + 1] == '0';
            ans1++;
          }
        }
      }
    }
    for (long long int i = 1; i < (long long int)(n - 1); i++) {
      if (s2[i] == '1') {
        if (s1[i] == '0')
          ans2++;
        else {
          if (s1[i + 1] == '1') {
            s1[i + 1] == '0';
            ans2++;
          } else if (s1[i - 1] == '1') {
            s1[i - 1] == '0';
            ans2++;
          }
        }
      }
    }
    cout << (max(ans1, ans2)) + ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto start1 = high_resolution_clock::now();
  solve();
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
  return 0;
}
