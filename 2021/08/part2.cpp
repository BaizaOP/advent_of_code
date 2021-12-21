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


int chars_similar(string a, string b);
vector<string> make_list(vector<string> raw);
int to_num(string str, vector<string> order);

int main() {
    ifstream fin("file.in");
    string s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, a, b, c, d;
    char ch;
    int total = 0;
    while(fin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7 >> s8 >> s9 >> s10 >> ch >> a >> b >> c >> d) {
        vector<string> ordered = make_list({s1, s2, s3, s4, s5, s6, s7, s8, s9, s10});
        total += (1000 * to_num(a, ordered));
        total += (100  * to_num(b, ordered));
        total += (10   * to_num(c, ordered));
        total += (1    * to_num(d, ordered));
    }
    cout << total << endl;
    return 0;
}

int chars_similar(string a, string b) {
    vector<char> commons; 
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++) {
            if(a[i] == b[j]) commons.pb(a[i]);
        }
    }
    sort(all(commons));
    auto ip = unique(all(commons));
    commons.resize(distance(commons.begin(), ip));
    return commons.size();
}

vector<string> make_list(vector<string> raw) {
    vector<string> order(10);
    for(int i = 0; i < raw.size(); i++) {
        sort(all(raw[i]));
    }
    sort(raw.begin(), raw.end(), [](const string &l, const string &r) { return l.size()<r.size(); });
    //find 1, 4, 7, 8 (4/10)
    order[1] = raw[0];
    order[7] = raw[1];
    order[4] = raw[2];
    order[8] = raw[9];

    //find 9 (5/10)
    int index9;
    if(chars_similar(raw[6], order[4]) == 4) {
        order[9] = raw[6];
        index9 = 6;
    }
    else if(chars_similar(raw[7], order[4]) == 4) {
        order[9] = raw[7];
        index9 = 7;
    }
    else if(chars_similar(raw[8], order[4]) == 4) {
        order[9] = raw[8];
        index9 = 8;
    }

    int index2, index3, index5;
    //find 2 (6/10)
    if(chars_similar(raw[3], order[9]) == 4) {
        order[2] = raw[3];
        index2 = 3;
    } else if(chars_similar(raw[4], order[9]) == 4) {
        order[2] = raw[4];
        index2 = 4;
    } else if(chars_similar(raw[5], order[9]) == 4) {
        order[2] = raw[5];
        index2 = 5;
    }

    //find 3 (7/10) 
    if(chars_similar(raw[3], order[2]) == 4) {
        order[3] = raw[3];
        index3 = 3;
    } else if(chars_similar(raw[4], order[2]) == 4) {
        order[3] = raw[4];
        index3 = 4;
    } else if(chars_similar(raw[5], order[2]) == 4) {
        order[3] = raw[5];
        index3 = 5;
    }

    //find 5 (8/10)
    if((index2 == 3 && index3 == 4) || (index2 == 4 && index3 == 3)) index5 = 5;
    else if((index2 == 4 && index3 == 5) || (index2 == 5 && index3 == 4)) index5 = 3;
    else if((index2 == 3 && index3 == 5) || (index2 == 5 && index3 == 3)) index5 = 4;
    order[5] = raw[index5];

    //find 6 (9/10)
    int index6;
    if(index9 == 6) {
        if(chars_similar(order[5], raw[7]) == 5) index6 = 7;
        else if(chars_similar(order[5], raw[8]) == 5) index6 = 8;
        else cout << "SOMETHING WENT TERRIBLY WRONG WHEN TRYING TO FIND INDEX 6" << endl;
    } else if (index9 == 7) {
        if(chars_similar(order[5], raw[6]) == 5) index6 = 6; 
        else if(chars_similar(order[5], raw[8]) == 5) index6 = 8;
        else cout << "SOMETHING WENT TERRIBLY WRONG WHEN TRYING TO FIND INDEX 6" << endl;
    } else if (index9 == 8) {
        if(chars_similar(order[5], raw[6]) == 5) index6 = 6; 
        else if(chars_similar(order[5], raw[7]) == 5) index6 = 7;
        else cout << "SOMETHING WENT TERRIBLY WRONG WHEN TRYING TO FIND INDEX 6" << endl;
    }
    order[6] = raw[index6];
    
    //find 0 (10/10)
    int index0; 
    if((index6 == 6 && index9 == 7) || (index6 == 7 && index9 == 6)) index0 = 8;
    else if((index6 == 7 && index9 == 8) || (index6 == 8 && index9 == 7)) index0 = 6;
    else if((index6 == 6 && index9 == 8) || (index6 == 8 && index9 == 6)) index0 = 7;
    order[0] = raw[index0];
    
    return order;
}

int to_num(string str, vector<string> order) {
    sort(all(str));
    for(int i = 0; i < order.size(); i++) {
        if(str == order[i]) return i;
    }
    cout << "SOMETHING WENT WRONGO!!!!!!!!" << endl;
    return -1;
}
