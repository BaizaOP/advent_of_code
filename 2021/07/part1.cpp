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

ll get_total_dist (ll destination, vi pos) {
    ll total_dist = 0;
    for(int i = 0; i < pos.size(); i++) {
        total_dist += abs(destination - pos[i]);
    }
    return total_dist;
}

int main() {
    ifstream fin("file.in");
    vi pos = get_input(fin);
    ll min_dist = 100'000'000'000;
    for(int i = 0; i < find_max(pos); i++){
        ll total_dist = get_total_dist(i, pos);
        if (min_dist > total_dist) {
            min_dist = total_dist;
        }
    }

    cout << min_dist << endl;
    return 0;
}

