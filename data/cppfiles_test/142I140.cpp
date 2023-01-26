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
    
    ll Max_1, Max_2;

    Data (ll Max_1 = -OO, ll Max_2 = -OO){
        this -> Max_1 = Max_1, this -> Max_2 = Max_2;
    }

    void Add_Data(ll num){
        if(num >= Max_1) Max_2 = Max_1, Max_1 = num;
        else if(num >= Max_2) Max_2 = num;
    }

    bool operator < (const Data& d) const {
        return Max_2 > d.Max_2;
    }

};

void Solve(){
    int m, n;
    cin >> m >> n;
    vector < Data > vert(m), hori(n);
    for(int i = 0; i < m; i++){
        for(int j = 0, p_ij; j < n && cin >> p_ij; j++){
            hori[j].Add_Data(p_ij);
            vert[i].Add_Data(p_ij);
        }
    }
    ll Max_F = OO, Max_S = -OO, Max_with_out_last_coloumn = OO;
    for(int i = 0; i < n; i++){
        Max_F = min(Max_F, hori[i].Max_1);
        if(i < n - 1) Max_with_out_last_coloumn = min(Max_with_out_last_coloumn, hori[i].Max_1);
    }
    for(int i = 0; i < m; i++){
        Max_S = max(Max_S, vert[i].Max_2);
    }
    if(m <= n - 1) cout << Max_F << "\n";
    else cout << min(Max_S, Max_with_out_last_coloumn) << "\n";
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