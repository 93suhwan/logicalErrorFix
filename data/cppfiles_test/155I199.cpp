#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int T = 1, n, m, k;
int a[N];
int b[N];
int main() {
  scanf("%d", &T);
  while (T--) {
    int n;
    string s;
    int t = 1;
    scanf("%d", &n);
    vector<int> zero;
    vector<int> one;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &a[i]);
    }
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0')
        zero.push_back(a[i]);
      else
        one.push_back(a[i]);
    }
    sort(zero.begin(), zero.end());
    sort(one.begin(), one.end());
    for (int i = 0; i < zero.size(); i++) mp[zero[i]] = t++;
    for (int i = 0; i < one.size(); i++) mp[one[i]] = t++;
    for (int i = 0; i < N; i++)
      if (a[i] != 0) printf("%d ", mp[a[i]]);
    puts("");
  }
  return 0;
}
