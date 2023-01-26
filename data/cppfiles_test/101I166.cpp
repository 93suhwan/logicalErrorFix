#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  freopen("out.txt", "w", stdout);
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto& i : vec) {
      cin >> i;
    }
    string s;
    cin >> s;
    vector<int> red;
    vector<int> blue;
    for (int i = 0; i < n; i++)
      if (s[i] == 'R')
        red.push_back(vec[i]);
      else
        blue.push_back(vec[i]);
    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end());
    bool flag = true;
    for (int i = 1; i <= blue.size(); i++) {
      if (blue[i - 1] < i) {
        flag = false;
        break;
      }
    }
    int k = blue.size();
    for (int j = 1; j <= red.size(); j++) {
      if (red[j - 1] > k + j) {
        flag = false;
        break;
      }
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
