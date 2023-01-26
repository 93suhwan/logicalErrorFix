#include<bits/stdc++.h>
using namespace std;
#include<cstring>
#include<cstdio>
#include<vector>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
            tree_order_statistics_node_update> indexed_set;
 
 
#define ll long long
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
 
// 48-57 -> 0-9
// 65-90 -> A-Z
// 97-122 -> a-z
// void fun(int arr[])   // SAME AS void fun(int *arr)
// void print(string &s)
// void print(string *ptr){cout<<*ptr<<"\n";}
// __gcd    // greatest common divisor
// for (auto i = g1.begin(); i != g1.end(); ++i)   // cout << *i << " ";
// new_end = remove(v.begin(), v.end(), 20);
// lower = lower_bound(v.begin(), v.end(), 6) - v.begin();   //first element with value >= 6 //works on array,
// upper = upper_bound(v.begin(), v.end(), 6) - v.begin();   //first element with value > 6  //vector & sets
// v.push_back({1,5});    //inputing a pair in vector
// vector<tuple<int,int,int>> v;   //defining a vector with 3 attributes
                                   //get<i>(t): Returns the i'th element of the tuple t
// for(auto x:v) cout<<x<<" ";    //shorter way to iterate through the vector
// string a="abcdefgh"; b.substr(3,4)=cdef;->gives the substring starting at index 3 of length 4  
                        //find(t)->find the index of the 1st occurence of t
// x&-x   //gives the max power of 2 which divides x -> 2^lsd i.e. least significant digit
// cout<<bitset<20>(100);  ->converts 100 in to its binary representation having 20 digits
// int x = min({a, b, c, d});
 
 
////////////////    DATA STRUCTURES     /////////////////////
// Array   // memset(arr,-1,sizeof(arr))->To initialise an array to -1
// Vector  //vector<int> v(5,10);->fill the array with 10 five times    
           //v.insert(v.begin(), 5);->inserts 5 at the beginning(O(n))  
           //v.emplace(v.begin(), 5);->inserts at the beginning    
           //v.emplace_back(20);->Inserts 20 at the end  
           //v.erase(v.begin());->removes the first element    
           //v.erase(v.begin(),v.begin()+3);->erase first 3 elements  
// Set     //It is based on a balanced binary tree with O(log n) times and has all elements distinct
           //set<int> s, s.insert(5), s.count(5), s.erase(5), s.find(5)
           //sorts in ascending order
           //for pair of set use p1=a.begin()->first
// Multiset   //Same as set but can have multiple instances of an element
              //multiset<int> s, s.insert(5), s.count(5), s.erase(5), s.find(5)
              //s.erase(5)//removes all instances of 5 whereas s.erase(s.find(5)) removes only one occurence
// Map      //map<string,int> m, m[it1]=it2, m.count(key), m.erase(key)
            //for(auto x:m) cout<<x.first<<" "<<x.second;->prints keys and values
            // ordered map also supports lower_bound and upper_bound
            // unordered_map uses hashing and has only basic operations
// Deque    //deque<int> d, d.push_back(5), d.push_front(5), d.pop_back(), d.pop_front()
// Stack    //stack<int> s, s.push(5), s.top(), s.pop()
// Queue    //queue<int> q, q.push(3), q.front(), q.pop()
// Priority Queue    //most feactures same as ordered set but is faster than that and uses heap structure
                     //priority_queue<int> q, q.push(3), q.top(), q.pop()
                     //provides the maximum element
                     //priority_queue<int,vector<int>,greater<int>> q->gives minimum element
                     //can't iterate over elements
// Indexed Set      //same features as set but is iterable
                    //indexed_set s, s.insert(2), *s.find_by_order(0)->2, 
                    //s.order_of_key(2)->0, s.order_of_key(0)->0, s.order_of_key(3)->1  If the element
                    // doesn't appear in the set, we get the position that the element would have in the set
 
 
////////////////    RESOURCES    ////////////////////// 
// https://usaco.guide/PAPS.pdf#page=99
// https://usaco.guide/CPH.pdf#page=27
// https://darrenyao.com/usacobook/cpp.pdf#page=12
// https://www.google.com/url?sa=t&source=web&rct=j&url=https://www.geeksforgeeks.org/sieve-of-eratosthenes
// /amp/&ved=2ahUKEwjK1PaXlb70AhVPTmwGHW4sDl8QFnoECAQQAQ&usg=AOvVaw2f79-PNgzkM7KOBS8OmqBm
 
inline namespace FastIO {
	const int BSZ = 1<<15; ////// INPUT
	char ibuf[BSZ]; int ipos, ilen;
	char nc() { // next char
		if (ipos == ilen) {
			ipos = 0; ilen = fread(ibuf,1,BSZ,stdin);
			if (!ilen) return EOF;
		}
		return ibuf[ipos++];
	}
	template<class T> void ri(T& x) { // read int or ll
		char ch; int sgn = 1;
		while (!isdigit(ch = nc())) if (ch == '-') sgn *= -1;
		x = ch-'0'; while (isdigit(ch = nc())) x = x*10+(ch-'0');
		x *= sgn;
	}
}
 
bool sortbysec(const pair<ll,ll> &a,const pair<ll,ll> &b)
{ return (a.second < b.second); }
 
int power(int a){   
    int ans=0;
    while(a>1)
    { a/=2;ans++; }
    return ans;    
}
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("tttt.in", "r", stdin);
    // freopen("tttt.out", "w", stdout);
    int cases;
    cin>>cases;
    while(cases--)
    {
        int n;
        cin>>n;
        if(n%2==0)
        {
            cout<<(n/2)<<" "<<(n/2-1)<<" "<<"1"<<"\n";
        }
        else
        {
            n--;
            int i=3;
            while(n%i==0)
                i+=2;
            cout<<i<<" "<<(n-i)<<" ";
            cout<<"1"<<"\n";
        }
    }
    
    return 0;
}
