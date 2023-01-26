#include <bits/stdc++.h>
using namespace std;
long double PI = acosl(-1);
bool compare_int(int a, int b) { return (a > b); }
bool compare_string(string a, string b) { return a.size() < b.size(); }
bool compare_pair(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.second == b.second)
    return a.first < b.first;
  else
    return (a.second > b.second);
}
bool cmp(pair<string, int> x, pair<string, int> y) {
  return (x.second < y.second);
}
void NA() {
  printf("NO\n");
  exit(0);
}
void YA() {
  printf("YES\n");
  exit(0);
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x, tot = 0;
    for (int i = 0; i < n; i++) {
      cin >> x;
      tot += x;
    }
    tot % n == 0 ? cout << 0 : cout << 1;
    cout << "\n";
  }
}
