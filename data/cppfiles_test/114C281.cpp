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
    memset(numC, 0, sizeof(numC));
    int x;
    cin >> x;
    int ara[x];
    for (int i = 0; i < x; i++) {
      int temp;
      cin >> ara[i];
      numC[ara[i]]++;
    }
    sort(ara, ara + x);
    int count = 0;
    int mid = x / 2;
    int flag = 0;
    for (int i = 1; i < x; i++) {
      for (int j = 0; j < i; j++) {
        if (ara[i] != ara[j] && numC[ara[i] % ara[j]] == 0) {
          cout << ara[i] << " " << ara[j] << "\n";
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
