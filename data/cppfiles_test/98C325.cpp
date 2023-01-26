#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    string s;
    cin >> s;
    vector<int> v(26);
    for (int i = 0; i < s.size(); i++) {
      v[s[i] - 97] = i + 1;
    }
    string s1;
    cin >> s1;
    int b = v[s1[0] - 97];
    int ans = 0;
    for (int i = 1; i < s1.size(); i++) {
      ans += abs(b - v[s1[i] - 97]);
      b = v[s1[i] - 97];
    }
    printf("%d\n", ans);
  }
}
