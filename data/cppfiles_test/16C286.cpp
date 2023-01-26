#include <bits/stdc++.h>
using namespace std;
bool comparator(char &p1, char &p2) { return (p2 - p1 > 0); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t > 0) {
    int n;
    cin >> n;
    vector<char> v1;
    vector<char> v2;
    for (int i = 0; i < n; i++) {
      char a;
      cin >> a;
      v1.push_back(a);
      v2.push_back(a);
    }
    sort(v1.begin(), v1.end(), comparator);
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (v1[i] != v2[i]) count++;
    }
    cout << count << '\n';
    t--;
  }
  return 0;
}
