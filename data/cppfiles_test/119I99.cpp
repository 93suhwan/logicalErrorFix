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
    deque<int> dq;
    int x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      dq.push_back(x);
    }
    sort(dq.begin(), dq.end());
    int Max = 0, Min = INT_MAX;
    while (dq.size() > 1) {
      int p = dq.front();
      int q = dq.back();
      dq.pop_front();
      dq.pop_back();
      int m = (p + q);
      if (m % 2 == 1) {
        if ((m + 1) / 2 > Max) Max = (m + 1) / 2;
        if (m / 2 < Min) Min = m / 2;
      } else {
        if (m / 2 > Max) Max = m / 2;
        if (m / 2 < Min) Min = m / 2;
      }
    }
    if (!dq.empty()) {
      if (dq.back() > Max) Max = dq.back();
      if (dq.back() < Min) Min = dq.back();
    }
    cout << Max - Min << endl;
  }
}
