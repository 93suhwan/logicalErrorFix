#include <bits/stdc++.h>
using namespace std;
void gen(vector<char>& v) {
  int n = v.size();
  int c = 1;
  for (int i = 0; i < n; i++) {
    cout << v[i];
  }
  cout << endl;
  for (int i = 1; i < n / 2 && c < n / 2; i++) {
    for (int j = n / 2; j < n - 1 && c <= n / 2; j++) {
      vector<char> temp = v;
      swap(temp[i], temp[j]);
      c++;
      for (int i = 0; i < temp.size(); i++) {
        cout << temp[i];
      }
      cout << endl;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t) {
    int n;
    cin >> n;
    vector<char> v(2 * n, ')');
    for (int i = 0; i < n; i++) {
      v[i] = '(';
    }
    gen(v);
    t--;
  }
}
