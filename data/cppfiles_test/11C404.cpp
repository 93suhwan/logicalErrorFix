#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    vector<vector<int>> a(5);
    for (int k = 0; k < 5; k++) {
      char temp = char('a' + k);
      for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < s[i].size(); j++) {
          if (s[i][j] == temp) {
            count++;
          }
        }
        a[k].push_back(2 * count - s[i].size());
      }
      sort(a[k].begin(), a[k].end());
    }
    int ans = 0;
    for (int i = 0; i < 5; i++) {
      int size = a[i].size();
      int result = 0, sum = 0;
      for (int j = size - 1; j >= 0; j--) {
        sum += a[i][j];
        if (sum > 0) {
          result++;
        } else {
          break;
        }
      }
      ans = max(ans, result);
    }
    cout << ans << endl;
  }
  return 0;
}
