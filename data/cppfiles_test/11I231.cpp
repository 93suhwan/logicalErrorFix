#include <bits/stdc++.h>
using namespace std;
class test {
 public:
  float a;
  int b, c;
};
bool comp(test x, test y) {
  if (x.a < 0.5) {
    return x.c < y.c;
  }
  return x.a > y.a;
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
      for (auto it : mp) {
        charcount += it.b;
        total += it.c;
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
