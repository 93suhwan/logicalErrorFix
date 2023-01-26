#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> vet(n);
  for (int &x : vet) cin >> x;
  int l = 0, r = n - 1;
  while (l < n - 1 && vet[l] < vet[l + 1]) l++;
  while (r >= 1 && vet[r] < vet[r - 1]) r--;
  l++;
  r = n - r;
  if (l % 2 || r % 2)
    cout << "Alice";
  else
    cout << "Bob";
}
