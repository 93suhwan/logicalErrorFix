#include <bits\stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        long long n;
		set<long long> s;
        cin >> n;
		for(long long i=1; i<100000;i++){
			if(i*i < n)
				s.insert(i*i);
			if(i*i*i < n)
				s.insert(i*i*i);
		}
		cout << s.size() << endl;
        
    }
    return 0;
}