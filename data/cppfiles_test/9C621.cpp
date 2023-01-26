#include <bits/stdc++.h>
using namespace std;
struct Interval {
  int start, end;
};
bool compareInterval(Interval i1, Interval i2) { return (i1.start < i2.start); }
long long int maxy(long long int a, long long int b) {
  if (b >= a) return b;
  return a;
}
long long int li[200003];
long long int ri[200003];
int main() {
  int t;
  long long int i, j, k, n;
  cin >> t;
  while (t > 0) {
    string s;
    cin >> s;
    unordered_map<char, int> umap;
    for (i = 0; i < s.length(); i++) {
      umap[s[i]] = umap[s[i]] + 1;
    }
    int one = 0;
    for (auto x : umap) {
      if (x.second == 1) {
        one++;
      }
    }
    int ans = 0;
    ans = one / 2;
    int two = 0;
    for (auto x : umap) {
      if (x.second > 1) {
        two++;
      }
    }
    ans = ans + two;
    cout << ans << endl;
    t--;
  }
  return 0;
}
