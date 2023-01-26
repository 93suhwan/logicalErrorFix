#include<bits/stdc++.h>
#define ll long long
#define lld long double
#define pb push_back
#define mup unordered_map
#define pf push_front
#define fr first
#define sc second
#define CODER ios_base::sync_with_stdio(0)  ;
#define p_b pop_back
#define p_f pop_front
#define NO cout << "NO" << endl ;
#define No cout << "No" << endl ;
#define YES cout << "YES" << endl ;
#define Yes cout << "Yes" << endl ;

using namespace std ;

    const ll N = 1e5 + 1 ;
    const int INF = 1e9 + 7 ;

ll n , m , cnt , ans , sum , l , r , a , x , k , b , c , y , z ;
deque < pair < ll , ll > > pr ;
set < ll > st ;
map < ll , ll > mp ;

void vkoshp()
{
    cin >> n ;
    pr.clear() ;
    st.clear() ;
    mp.clear() ;
    for (ll i = 1 ; i <= n ; i ++ )
        st.insert(i) ;
    for (ll i = 0 ; i < n ; i ++ )
    {
        cin >> a >> b ;
        if (a == b)
        {
            cout << a << " " << b << " " << a << endl ;
            st.erase(a) ;
            continue ;
        }
        pr.pb({b , a}) ;
    }
    sort(pr.begin() , pr.end()) ;
    for (auto i : pr)
    {
        cout << i.sc << " " << i.fr << " " << *st.begin() << endl ;
        st.erase(*st.begin()) ;
    }
}

main ()
{
    CODER
    int t = 1 ;
    cin >> t ;
    while ( t -- )
    {
        vkoshp() ;
    }
}
///MaaN Studios
