#include<bits/stdc++.h>
using namespace std;
#define int long long

int g[200001][19];
int n;
bool check(int l){
    int k = log2(l);
    for (int i = 0; i + l <= n; i++){
        if (__gcd(g[i][k], g[i + l - (1 << k)][k]) > 1) return true;
    }
    return false;
}
void solve(){
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n < 3){
        cout << n << endl;
        return;
    }
    int b[n - 1];
    for (int i = 0; i < n - 1; i++) b[i] = a[i + 1] - a[i];
    n--;
    int Max = log2(n);
    for (int i = 0; i < n; i++){
        g[i][0] = abs(b[i]);
    }
    for (int i = 1; i <= Max; i++){
        int L = 1 << i;
        for (int j = 0; j + L <= n; j++){
            g[j][i] = __gcd(g[j][i - 1], g[j + L / 2][i - 1]);
        }
    }
    if (!check(1)){
        cout << 1 << endl;
        return;
    }
    int left = 1, right = n + 1;
    while (left != right - 1){
        int mid = (left + right) / 2;
        if (check(mid)) left = mid;
        else right = mid;
    }
    cout << left + 1 << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
}