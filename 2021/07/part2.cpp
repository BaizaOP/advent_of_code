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

vi get_input(ifstream& fin) {
    vi input;
    int a; char b;
    fin >> a; input.pb(a);
    while(fin >> b >> a) input.pb(a);
    return input;
}

int find_max(vi pos) {
    sort(all(pos));
    reverse(all(pos));
    return pos[0];
}

ll calc_dist(ll a, ll b) {
    ll n = abs(a - b) + 1;
    ll a0 = min(a, b);
    ll an = max(a, b);
    ll dist = n * (an - a0) * 0.5; // sum of arithmetic series, math class coming in clutch lol
    return dist;
}


ll get_total_dist (ll destination, vi pos) {
    ll total_dist = 0;
    for(int i = 0; i < pos.size(); i++) {
        total_dist += calc_dist(destination, pos[i]);
    }
    return total_dist;
}

int main() {
    ifstream fin("file.in");
    vi pos = get_input(fin);
    ll min_dist = 100'000'000'000;
    int min_index = -1;
    for(int i = 0; i < find_max(pos); i++){
        ll total_dist = get_total_dist(i, pos);
        if (min_dist > total_dist) {
            min_dist = total_dist;
            min_index = i;
        }
    }

    cout << min_dist << " with index of " << min_index << endl;
    return 0;
}

