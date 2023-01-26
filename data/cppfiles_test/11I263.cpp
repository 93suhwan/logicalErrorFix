#include <bits/stdc++.h>
using namespace std;
int tc;
long long n;
vector<string> s;
int bar(int i, char c) {
  int yes = 0;
  int no = 0;
  for (int j = 0; j < s[i].size(); j++) {
    if (s[i][j] == c) {
      yes++;
    } else {
      no++;
    }
  }
  return yes - no;
}
void foo() {
  cin >> n;
  s.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  string chars = "abcde";
  long long cur_max = 0;
  for (int i = 0; i < 5; i++) {
    vector<int> v;
    v.resize(n);
    for (int j = 0; j < n; j++) {
      v[j] = bar(j, chars[i]);
    }
    sort(v.begin(), v.end(), greater<int>());
    long long count = 1;
    long long val = v[0];
    for (int j = 1; j < n; j++) {
      if (val + v[j] <= 0) break;
      val += v[j];
      count++;
    }
    cur_max = max(cur_max, count);
  }
  cout << cur_max << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> tc;
  while (tc--) {
    foo();
  }
}
