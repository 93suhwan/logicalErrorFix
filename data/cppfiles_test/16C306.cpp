#include <bits/stdc++.h>
using namespace std;
void solution() {
  int n;
  string s;
  cin >> n >> s;
  string temp = s;
  sort(temp.begin(), temp.end());
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != temp[i]) count++;
  }
  cout << count << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solution();
  }
  return 0;
}
