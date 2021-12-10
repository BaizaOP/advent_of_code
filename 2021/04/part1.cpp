#include <bits/stdc++.h>
using namespace std;

// my competitive programming boilerplate... for some reason
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
typedef vector<vvi> vvvi; // 3d eggsdee

//protos
vi parse_bingo_calls(string calls);
vvvi parse_tables(ifstream& is);
void show_bingo_table (vvi bingo_table);
void print_tables (vvvi bingo_tables);
/* vpi check_rows (vvi bingo_table); */
/* vpi check_cols (vvi bingo_table); */
bool check_rows (vvi bingo_table);
bool check_cols (vvi bingo_table);
void insert_bingo (vvi& table, int call);
/* bool check_diags (vvi bingo_table); // diags dont count LOL */
long long sum_all_unmarked(vvi bingo);

int main() {
    /* ifstream fin ("sample.in"); */
    ifstream fin ("file.in");
    string calls; getline(fin, calls);
    vi nums = parse_bingo_calls(calls);
    /* for(int i : nums) cout << i << endl; */

    vvvi bingo = parse_tables(fin);
    vvvi initial_bingo = bingo; 
    print_tables(bingo);

    /* for(int i = 0; i < bingo.size(); i++) { */
    /*     for(int j = 0; j < nums.size(); j++) { */
    /*         insert_bingo (bingo[i], nums[j]); */
    /*     } */ 

    /* } */
    for(int i = 0; i < nums.size(); i++) {
        for(int j = 0; j < bingo.size(); j++) {
            insert_bingo (bingo[j], nums[i]);
            /* vpi rows = check_rows(bingo[j]); */
            /* vpi cols = check_cols(bingo[j]); */
            /* if(rows.size() > 0) { */
            /*     show_bingo_table (bingo[j]); */
            /*     for(pi p : rows) printf("(%d, %d) ", p.F, p.S); */
            /*     return 0; */
            /* } else if (cols.size() > 0) { */
            /*     show_bingo_table (bingo[j]); */
            /*     for(pi p : cols) printf("(%d, %d) ", p.F, p.S); */
            /*     return 0; */
            /* } */
            if(check_rows(bingo[j]) || check_cols(bingo[j])) {
                cout << sum_all_unmarked(bingo[j]) * nums[i] << endl;
                j = 10000000;
                i = 10000000;
                return 0;
            }
        }
    }

    return 0;
}

vi parse_bingo_calls(string calls) {
    calls.pb(','); 
    vi nums; 
    string num = "";
    for(int i = 0; i < calls.size(); i++) {
        if(calls[i] ==  ',') {
            nums.pb(stoi(num));
            num = "";
        } else {
            num.pb(calls[i]);
        }
    } 
    return nums;
}

vvvi parse_tables(ifstream& is) {
    vvvi bingo_tables = {};
    vvi bingo_table = {};
    vi row = {};
    int n;
    int counter = 0;
    while (is >> n) {
        row.push_back(n);
        counter++;
        /* if(counter == 25) { */
        /*     bingo_table.pb(row); */
        /*     row = {}; */
        /*     counter = 0; */
        /* } else */
        if(counter % 5 == 0) {
            bingo_table.pb(row);
            row = {};
            if(counter == 25) {
                bingo_tables.pb(bingo_table);
                bingo_table = {};
                counter = 0; 
            }
        }
    }
    return bingo_tables;
}
void show_bingo_table (vvi bingo_table) {
    for(vi b : bingo_table) {
        for(int i : b) {
            cout << i << ' ';
        }
        cout << endl;
    }
}

void print_tables (vvvi bingo_tables) {
    for(vvi a : bingo_tables) {
        cout << "---\n";
        show_bingo_table(a);
        cout << "---\n";
    }
}

/* vpi check_rows (vvi bingo_table) { */
/*     for(int i = 0; i < 5; i++) { */
/*         int sum = 0; */
/*         for(int j = 0; j < 5; j++) { */
/*             sum += bingo_table[i][j]; */
/*         } */
/*         /1* if(i == 0) cout << sum << endl; *1/ */
/*         if(sum == -5) */
/*             return {mp(i, 0), mp(i, 1), mp(i, 2), mp(i, 3), mp(i, 4)}; */
/*     } */
/*     return {}; */
/* } */

/* vpi check_cols (vvi bingo_table) { */
/*     for(int i = 0; i < 5; i++) { */
/*         int sum = 0; */
/*         for(int j = 0; j < 5; j++) { */
/*             sum += bingo_table[j][i]; */
/*         } */
/*         /1* if(i == 0) cout << sum << endl; *1/ */
/*         if(sum == -5) */
/*             return {mp(0, i), mp(1, i), mp(2, i), mp(3, i), mp(4, i)}; */
/*     } */
/*     return {}; */
/* } */

bool check_rows (vvi bingo_table) {
    for(int i = 0; i < 5; i++) {
        int sum = 0;
        for(int j = 0; j < 5; j++) {
            sum += bingo_table[i][j];
        }
        /* if(i == 0) cout << sum << endl; */
        if(sum == -5)
            return true;
    }
    return false;
}

bool check_cols (vvi bingo_table) {
    for(int i = 0; i < 5; i++) {
        int sum = 0;
        for(int j = 0; j < 5; j++) {
            sum += bingo_table[j][i];
        }
        /* if(i == 0) cout << sum << endl; */
        if(sum == -5)
            return true;
    }
    return false;
}

// haha diags dont count
/* bool check_diags (vvi bingo_tables) { */
/*     int down_right = 0; */
/*     int down_left = 0; */
/*     for(int i = 0; i < 5; i++) { */
/*         down_right += bingo_tables[i][i]; */
/*         down_left += bingo_tables[i][4-i]; */
/*     } */
/*     /1* cout << down_right << " - " << down_left << endl; *1/ */
/*     if(down_right == -5 || down_left == -5) return true; */
/*     return false; */
/* } */

void insert_bingo (vvi& table, int call) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(table[i][j] == call) {
                table[i][j] = -1;
            }
        }
    }
}

long long sum_all_unmarked(vvi bingo){
    long long sum = 0;
    for(int i = 0; i < bingo.size(); i++) {
        for(int j = 0; j < bingo[0].size(); j++) {
            if(bingo[i][j] != -1) sum += bingo[i][j];
        }
    }
    return sum;
}
