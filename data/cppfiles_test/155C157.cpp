#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> music(n);
  for (long long i = 0; i < n; i++) cin >> music[i].first, music[i].second = i;
  string s;
  cin >> s;
  sort((music).begin(), (music).end());
  long long start = n;
  for (long long i = n - 1; i >= 0; i--) {
    if (s[music[i].second] == '1') {
      music[i].first = start;
      start--;
    }
  }
  for (long long i = n - 1; i >= 0; i--) {
    if (s[music[i].second] == '0') {
      music[i].first = start;
      start--;
    }
  }
  for (long long i = n - 1; i >= 0; i--) {
    swap(music[i].first, music[i].second);
  }
  sort((music).begin(), (music).end());
  for (long long i = 0; i < n; i++) cout << music[i].second << " ";
  cout << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
