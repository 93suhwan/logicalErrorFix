#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int useless = 0; useless < t; useless++) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    set<int> srt;
    bool dp_all = true;
    bool dp_two = false;
    srt.insert(a[0]);
    for (int i = 1; i < n; i++) {
      srt.insert(a[i]);
      if (a[i] != *prev(srt.end())) {
        bool tmp = dp_all;
        dp_all = dp_two;
        dp_two = tmp;
      }
    }
    if (dp_all)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
