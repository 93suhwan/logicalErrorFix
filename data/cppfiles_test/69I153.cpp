//////////////////////////////////////////////////////////////////
//                                                              //
//                                                              //
//                                                              //
//                       CODE BY ILHOM_45                       //
//                                                              //
//                                                              //
//                                                              //
//////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
#define ll long long
#define yes cout << "YES" << "\n" ;
#define no cout << "NO" << "\n" ;
#define pb push_back
#define fi first
#define se second
using namespace std;
template < typename T, typename M >
istream& operator >> ( istream& in, pair < T, M > & pr )
{
    in >> pr.first >> pr.second ;

    return in ;
}

template < typename T, typename M >
ostream& operator << ( ostream& out, const pair < T, M > & pr)
{
    out << pr.first << ' ' << pr.second;

    return out;
}

template < typename T, typename M >
pair < T, M > operator+( const pair < T, M >& p1, const pair < T, M >& p2 )
{
    return make_pair ( p1.first + p2.first, p1.second + p2.second ) ;
}
bool prostoechislo ( unsigned ll k )
{
    for ( unsigned ll j = 2 ; j * j <= k ; j ++ )
        if ( k % j == 0 ) return 0 ;
    return 1 ;
}
int stepen ( ll a, ll b )
{
    if ( b == 0 )return 1 ;
    if ( b % 2 == 0 ) return stepen ( a, b / 2 ) * stepen ( a, b / 2 ) ;
    else return a * stepen ( a, b - 1 ) ;
}
vector < ll > v ;
int main()
{
    ios_base::sync_with_stdio( 0 ) ;
    cin.tie( 0 ) ;
    cout.tie( 0 ) ;
    ll k = 1 ;
    for ( int i = 0 ; i <= 64 ; i ++ )
    {
        v.pb ( k ) ;
        k = k * 2 ;
    }
    ll t ;
    cin >> t ;
    while ( t -- )
    {
        ll n ;
        cin >> n ;
        ll f, ans = 1e9 ;
        f = n ;
        string s1 ;
        while ( f > 0 )
        {
            s1.pb ( ( f % 10 ) + '0' ) ;
            f = f / 10 ;
        }
        reverse ( s1.begin(), s1.end() ) ;
        for ( ll i = 0 ; i <= 64 ; i ++ )
        {
            ll res = v [ i ] ;
            string s ;
            while ( res > 0 )
            {
                s.pb ( ( res % 10 ) + '0' ) ;
                res = res / 10 ;
            }
            ll kl = 0 ;
            reverse ( s.begin(), s.end() ) ;
             for ( int l = 0 ; l < s1.size() ; l ++ )
             {
                 if ( s1 [ l ] == s [ kl ] )
                     kl ++ ;
             }
             ans = min ( ans , ( ( s1.size() - kl ) + ( s.size() - kl ) ) ) ;
        }
        cout << ans << "\n" ;
    }
}
