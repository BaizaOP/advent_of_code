#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

vl update (vl popu) {
    vl new_popu(9, 0);
    for(int i = 0; i < popu.size(); i++) {
        if(i == 0) {
            new_popu[6] += popu[i];
            new_popu[8] += popu[i];
        } else {
            new_popu[i-1] += popu[i];
        }
    }
    return new_popu;
}

ll count_popu(vl popu) {
    ll count = 0;
    for(int i = 0; i < popu.size(); i++) {
        count += popu[i];
    }
    return count;
}

int main() {
    ifstream fin("file.in");
    int a; char c;
    vl popu(9, 0); //short for population
    fin >> a; popu[a]++;
    while(fin >> c >> a) {
        popu[a]++;
    }
    for(int i = 0; i < 256; i++) {
        popu = update(popu);
    }
    cout << count_popu(popu) << endl;
    return 0;
}

