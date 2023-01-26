#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, m, j;
  string s;
  map<string, int> ma;
  pair<string, int> p;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> s;
    for (j = 0; j < m; j++) {
      if (j % 2 == 0) s[j] = 155 - s[j];
    }
    ma[s] = i + 1;
  }
  map<string, int>::iterator itr;
  int arr[n];
  i = 1;
  for (itr = ma.begin(); itr != ma.end(); itr++) {
    arr[n - i] = (*itr).second;
    i++;
  }
  for (i = 0; i < n; i++) cout << arr[i] << " ";
  return 0;
}
