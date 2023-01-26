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
    int n, x;
    cin >> n;
    vector<int> a;
    deque<int> odd, even;
    for (int i = 0; i < n; i++) {
      cin >> x;
      a.push_back(x);
      x % 2 == 0 ? even.push_back(i) : odd.push_back(i);
    }
    int sz1 = even.size();
    int sz2 = odd.size();
    if (abs(sz1 - sz2) > 1)
      cout << -1 << "\n";
    else {
      int cnt = 0;
      long long int tot = 0;
      while (even.size() > 0 and odd.size() > 0) {
        int x = even.front();
        int y = odd.front();
        even.pop_front();
        odd.pop_front();
        tot += max(abs(x - y) - cnt - 1, 0);
        cnt++;
      }
      cout << tot << "\n";
    }
  }
}
