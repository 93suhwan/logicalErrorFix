#include"bits/stdc++.h"
using namespace std;

#define int long long
const int INF_MAX=1e18;

int flr (int a, int b) {
    int val = a / b;
    while (val * b > a) val--;
    return val;
}

void Solve() {
    int n, k; 
    cin >> n >> k;
    int ara[n+10];
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    sort (ara + 1, ara + n + 1);
    int pre[n + 10] = {0};
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + ara[i];
    }
    int ans = INF_MAX;
    for(int i = 0; i < n; i++){
        int init = k - pre[n - i] + ara[1];
        init = flr (init , (i + 1));
        ans = min (ans, max (0LL, ara[1] - init) + i);
    }
    cout << ans << "\n";

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int Test = 1;
    cin>>Test;
    while (Test--){
        Solve();
    }
    return 0;
}
