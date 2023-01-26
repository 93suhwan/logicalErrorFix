#include <bits/stdc++.h>
using namespace std;
int n, k, a[100];
void afficher(int a[], int n) {
  cout << "Affichage" << endl;
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << "Fin" << endl;
}
void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int d = n - k - 1, f = n - k;
  int score = 0;
  for (int j = 0; j < k; j++) {
    fflush(stdout);
    score += a[d--] / a[f++];
  }
  for (int i = 0; i < n - k - k; i++) {
    score += a[i];
  }
  d = n - k - 1, f = n - 1;
  int score_ = 0;
  for (int j = 0; j < k; j++) {
    fflush(stdout);
    score_ += a[d--] / a[f--];
  }
  for (int i = 0; i < n - k - k; i++) {
    score_ += a[i];
  }
  cout << min(score, score_) << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
