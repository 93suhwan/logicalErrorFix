#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<Pair, null_type,less<Pair>, rb_tree_tag,tree_order_statistics_node_update> 
#define cin(vec) for(auto& i : vec) cin >> i
#define cin_2d(vec, n, m) for(int i = 0; i < n; i++) for(int j = 0; j < m && cin >> vec[i][j]; j++);
#define cout(vec) for(auto& i : vec) cout << i << " "; cout << "\n";
#define cout_2d(vec, n, m) for(int i = 0; i < n; i++, cout << "\n") for(int j = 0; j < m && cout << vec[i][j] << " "; j++);
#define cout_map(mp) for(auto& [f, s] : mp) cout << f << "  " << s << "\n";
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define fixed(n) fixed << setprecision(n)
#define ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define fill(vec, value) memset(vec, value, sizeof(vec));
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define mod_combine(a, b, m) (((a % m) * (b % m)) % m)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << (x) << "\n";
#define fi first
#define se second
#define Pair pair < int, int >
#define ll long long
#define ull unsigned long long
#define Mod  1'000'000'007
#define OO 2'000'000'000
#define EPS 1e-6
#define PI acos(-1)

void AhMeD_HoSSaM(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    #endif
}

struct Data {
    
    ll Max_1, Max_2, store_1, store_2;

    Data (ll Max_1 = -OO, ll Max_2 = -OO, ll store_1 = -1, ll store_2 = -1){
        this -> Max_1 = Max_1, this -> Max_2 = Max_2;
        this -> store_1 = store_1, this -> store_2 = store_2;
    }

    void Add_Data(ll num, ll store){
        if(num > Max_1) Max_2 = Max_1, store_2 = store_1, Max_1 = num, store_1 = store;
        else if(num > Max_2) Max_2 = num, store_2 = store;
    }

    bool operator < (const Data& d) const {
        return Max_2 > d.Max_2;
    }

};

void Solve(){
    int m, n;
    cin >> m >> n;
    vector < Data > vert(m), hori(n);
    vector < bool > vis(m);
    vector < vector < ll > > items(m, vector < ll > (n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n && cin >> items[i][j]; j++){
            hori[j].Add_Data(items[i][j], i);
            vert[i].Add_Data(items[i][j], i);
        }
    }
    ll Max1 = -OO, Max_Sec_vis = -OO, Max_Sec_not_vis = -OO, alpha = OO;
    for(int i = 0; i < n - 1; i++){
        vis[hori[i].store_1] = true;
        alpha = min(alpha, hori[i].Max_1);
    }
    for(int i = 0; i < m; i++){
        if(vis[i]) Max1 = max(Max1, items[i][n - 1]);
        if(vis[i]) Max_Sec_vis = max(Max_Sec_vis, vert[i].Max_2);
        else Max_Sec_not_vis = max(Max_Sec_not_vis, vert[i].Max_2);
    }
    if(m <= n - 1) cout << min(alpha, Max1) << "\n";
    else if(Max_Sec_not_vis > Max_Sec_vis) cout << min(alpha, Max_Sec_not_vis) << "\n";
    else cout << min(alpha, Max_Sec_vis) << "\n";
}

int main(){
    AhMeD_HoSSaM();
    int t = 1;
    cin >> t;
    while(t--)
        Solve();
    Time
    return 0;
} 