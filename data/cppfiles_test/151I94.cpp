#include <bits/stdc++.h>
template <typename T>
T power(T a, T b) {
  T ans = 1;
  for (long long int i = 0; i < b; i++) {
    ans *= a;
  }
  return ans;
}
using namespace std;
void solve() {
  long long int q;
  cin >> q;
  vector<long long int*> v, start;
  unordered_map<long long int, vector<long long int*>> um;
  for (long long int i = 0; i < q; i++) {
    long long int num;
    cin >> num;
    if (num == 1) {
      long long int x;
      cin >> x;
      if (um.find(x) == um.end()) {
        long long int* temp = new long long int;
        *temp = x;
        v.push_back(temp);
        um[x] = start;
        um[x].push_back(temp);
      } else {
        v.push_back(um[x][0]);
      }
    } else {
      long long int x, y;
      cin >> x;
      cin >> y;
      if (x == y) break;
      if (um.find(x) != um.end()) {
        if (um.find(y) == um.end()) {
          long long int* temp = new long long int;
          *temp = y;
          um[y] = start;
          um[y].push_back(temp);
          for (long long int j = 0; j < um[x].size(); j++) *um[x][j] = y;
          um[y].insert(um[y].end(), (um[x]).begin(), (um[x]).end());
          um.erase(um.find(x));
        } else {
          for (long long int j = 0; j < um[x].size(); j++) *um[x][j] = y;
          um[y].insert(um[y].end(), (um[x]).begin(), (um[x]).end());
          um.erase(um.find(x));
        }
      }
    }
  }
  for (long long int i = 0; i < v.size(); i++) {
    cout << *v[i] << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
