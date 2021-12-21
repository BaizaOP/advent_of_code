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

vi update (vi popu) {
    vi new_popu;
    vi new_creatures;
    for(int i = 0; i < popu.size(); i++) {
        popu[i]--;
        if(popu[i] < 0) {
            popu[i] = 6;
            new_creatures.pb(8);
        }
        new_popu.pb(popu[i]);
    }
    if(new_creatures.size() > 0) {
        for(int i = 0; i < new_creatures.size(); i++) {
            new_popu.pb(new_creatures[i]);
        }
    }
    return new_popu;
}

int main() {
    ifstream fin("file.in");
    int a; char c;
    vi popu; //short for population
    fin >> a; popu.pb(a);
    while(fin >> c >> a) {
        popu.pb(a);
    }
    for(int i = 0; i < 80; i++) { 
        popu = update(popu);
    }
    cout << popu.size() << endl;
    return 0;
}

