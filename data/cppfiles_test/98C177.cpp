#include <bits/stdc++.h>
using namespace std;
pair<char, int> a[27];
int val[100];
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
      a[i + 1].first = s[i], a[i + 1].second = i + 1;
    string b;
    cin >> b;
    int f = 0;
    for (int i = 0; i < b.size(); i++) {
      for (int j = 1; j <= 26; j++)
        if (b[i] == a[j].first) f++, val[f] = a[j].second;
    }
    int sum = 0;
    for (int i = 2; i <= f; i++) sum += (abs(val[i] - val[i - 1]));
    cout << sum << endl;
  }
}
