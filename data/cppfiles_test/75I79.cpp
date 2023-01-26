#include <bits/stdc++.h>
using namespace std;
void print(vector<int> v) {
  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;
}
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  int myMax = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    myMax = max(myMax, v[i]);
  }
  if (myMax == v[0] || myMax == v.back()) {
    cout << "Alice\n";
    return 0;
  }
  vector<int> v1 = {v[0]};
  for (int i = 1; i < v.size(); i++) {
    if (v[i] <= v1.back()) {
      break;
    }
    v1.push_back(v[i]);
  }
  vector<int> v2 = {v.back()};
  for (int i = v.size() - 2; i >= 0; i--) {
    if (v[i] <= v1.back()) {
      break;
    }
    v2.push_back(v[i]);
  }
  if (v1.size() % 2 == 1 || v2.size() % 2 == 1) {
    cout << "Alice\n";
    return 0;
  }
  cout << "Bob";
  return 0;
}
