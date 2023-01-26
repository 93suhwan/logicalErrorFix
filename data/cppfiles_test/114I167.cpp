#include <bits/stdc++.h>
using namespace std;
vector<int> getNum(int x, int p) {
  vector<int> x1;
  while (x) {
    x1.insert(x1.begin(), x % 10);
    x = x / 10;
  }
  for (int i = 0; i < p; i++) {
    x1.push_back(0);
  }
  return x1;
}
int countDigit(int x) {
  int cou = 0;
  while (x) {
    x = x / 10;
    cou++;
  }
  return cou;
}
int numC[1000001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    set<int, greater<int>> disT;
    for (int i = 0; i < x; i++) {
      int temp;
      cin >> temp;
      disT.insert(temp);
      numC[temp]++;
    }
    int count = 0;
    int mid = x / 2;
    int flag = 0;
    for (auto i = disT.begin(); i != disT.end(); i++) {
      auto k = i;
      k++;
      for (auto j = k; j != disT.end(); j++) {
        if (*i != *j && numC[*i % *j] == 0) {
          cout << *i << " " << *j << "\n";
          count++;
          if (count == mid) {
            flag = 1;
            break;
          }
        }
      }
      if (flag) {
        break;
      }
    }
  }
}
