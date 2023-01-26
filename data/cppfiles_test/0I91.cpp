#include <bits/stdc++.h>
using namespace std;
bool compare(string &s1, string &s2) {
  bool ans = true;
  int len = s1.size();
  for (int i = 0; i < len; i++) {
    if (i & 1) {
      ans &= (s1[i] >= s2[i]);
      if (ans == false) {
        return ans;
      }
    } else {
      ans &= (s1[i] <= s2[i]);
      if (ans == false) {
        return ans;
      }
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  unordered_map<string, int> ch;
  int n, m;
  cin >> n >> m;
  vector<string> vec(n);
  for (int i = 0; i < n; i++) {
    vec[i].resize(m);
    cin >> vec[i];
    ch[vec[i]] = i + 1;
  }
  sort(vec.begin(), vec.end(), compare);
  for (int i = 0; i < n; i++) {
    cout << ch[vec[i]] << " ";
  }
  return 0;
}
