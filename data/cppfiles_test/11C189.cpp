#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  int te;
  cin >> te;
  while (te--) {
    int n;
    cin >> n;
    vector<string> v;
    for (int j = 0; j < n; j++) {
      string second;
      cin >> second;
      v.push_back(second);
    }
    vector<int> ve[5];
    int a[5];
    for (int j = 0; j < 5; j++) a[j] = 0;
    for (int j = 0; j < n; j++) {
      int b[5] = {0};
      b[0] = 0, b[1] = 0, b[2] = 0, b[3] = 0, b[4] = 0;
      for (int i = 0; i < v[j].size(); i++) {
        int x = (int)(v[j][i] - 'a');
        a[x]++;
        b[x]++;
      }
      for (int i = 0; i < 5; i++) {
        ve[i].push_back(b[i]);
      }
    }
    int count = 0;
    for (int j = 0; j < 5; j++) {
      int mx = 0;
      vector<int> check;
      for (int i = 0; i < n; i++) {
        mx = 0;
        for (int k = 0; k < 5; k++) {
          if (k != j) mx = mx + ve[k][i];
        }
        check.push_back(ve[j][i] - mx);
      }
      sort(check.begin(), check.end());
      int sum = 0;
      int count1 = 0;
      int indx = check.size() - 1;
      while (sum + check[indx] > 0 && indx >= 0) {
        count1++;
        sum = sum + check[indx];
        indx--;
      }
      count = max(count, count1);
    }
    cout << count << endl;
  }
}
