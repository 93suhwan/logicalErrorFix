#include <bits/stdc++.h>
using namespace std;
const int NMAX = 2e5;
pair<int, int> v[1 + NMAX];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i].second;
    cin.get();
    char ch;
    ch = cin.get();
    int i = 1;
    while (ch != '\n' && ch != EOF) {
      if (ch == 'B')
        v[i].first = 0;
      else
        v[i].first = 1;
      ch = cin.get();
      i++;
    }
    sort(v + 1, v + n + 1);
    bool flag = true;
    for (int i = 1; i <= n; i++) {
      if (v[i].first == 0 && v[i].second < i)
        flag = false;
      else if (v[i].first == 1 && v[i].second > i)
        flag = false;
    }
    if (flag == true)
      cout << "YES";
    else
      cout << "NO";
    cout << "\n";
  }
  return 0;
}
