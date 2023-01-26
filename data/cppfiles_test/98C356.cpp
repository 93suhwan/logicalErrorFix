#include <bits/stdc++.h>
using namespace std;
int n, T;
void file() {}
int main() {
  file();
  scanf("%d", &T);
  while (T--) {
    char ch[70];
    scanf("%s", &ch);
    string ss = ch;
    char ch1[70];
    int le = ss.size();
    scanf("%s", &ch1);
    string s1 = ch1;
    int ll = s1.size();
    map<char, int> mp;
    for (int i = 0; i < le; i++) {
      mp[ss[i]] = i + 1;
    }
    int ans = 0;
    for (int i = 1; i < ll; i++) {
      ans += abs(mp[s1[i]] - mp[s1[i - 1]]);
    }
    printf("%d\n", ans);
  }
}
