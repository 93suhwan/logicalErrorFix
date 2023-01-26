#include <bits/stdc++.h>
using namespace std;
class test {
 public:
  float a;
  int b, c;
};
bool comp(test x, test y) { return x.a > y.a; }
bool compe(pair<int, int> a, pair<int, int> b) {
  return (a.first - a.second) < (b.first - b.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<string> arr;
    for (int i = 0; i < n; i++) {
      string a;
      cin >> a;
      arr.push_back(a);
    }
    int ans = 0;
    for (int j = 0; j <= 4; j++) {
      char ch = 'a' + j;
      vector<test> mp;
      for (auto it : arr) {
        string x = it;
        int total = 0;
        int countchar = 0;
        for (int i = 0; i < x.length(); i++) {
          if (x[i] == ch) {
            countchar++;
          }
          total++;
        }
        float a = total;
        float b = countchar;
        mp.push_back({(b / a), countchar, total - countchar});
      }
      sort(mp.begin(), mp.end(), comp);
      int words = 0;
      int total = 0;
      int charcount = 0;
      vector<pair<int, int>> p;
      for (auto it : mp) {
        if (it.b > it.c) {
          words++;
          charcount += it.b;
          total += it.c;
        } else {
          p.push_back({it.c, it.b});
        }
      }
      sort(p.begin(), p.end(), compe);
      for (auto it : p) {
        charcount += it.second;
        total += it.first;
        if (charcount <= total) {
          break;
        }
        words++;
      }
      ans = max(words, ans);
    }
    cout << ans << endl;
  }
}
