#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
vector<int> V1;
vector<int> V2;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int num[maxn];
    for (int i = 0; i < n; i++) cin >> num[i];
    string s;
    cin >> s;
    V1.clear();
    V2.clear();
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'B')
        V1.push_back(num[i]);
      else if (s[i] == 'R')
        V2.push_back(num[i]);
    }
    sort(V1.begin(), V1.end());
    sort(V2.begin(), V2.end());
    int flag = 1;
    for (int i = 0; i < V1.size(); i++) {
      if (V1[i] < i + 1) {
        flag = 0;
        break;
      }
    }
    int Len = V2.size();
    for (int i = 0; i < V2.size(); i++) {
      if (V2[i] > (n - Len + i + 1)) {
        flag = 0;
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
