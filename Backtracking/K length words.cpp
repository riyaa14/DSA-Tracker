
#include <iostream>
#include <set>
#include <string>

using namespace std;

// forming all possible K length words - 1
void printKlengthWord(set<char> &unique, int k, string& per, int i){
    if(i == unique.size()){ 
        for(char ch : per) {
            if(ch == '.') return;
        }
        cout << per << endl;
        return;
    }
    
    // goes into one of the boxes
    for(int j=0; j<k; j++){
        if(per[j] == '.'){
            auto it = unique.begin();
            advance(it, i);
            per[j] = *(it);
            printKlengthWord(unique, k, per, i+1);
            per[j] = '.';
        }
    }
    
    // doesn't go into any of the boxes
    printKlengthWord(unique, k, per, i+1);
    
    return;
    
}

// forming all possible K length words - 1



int main() {
    string str;
    getline(cin, str);

    int k;
    cin >> k;

    set<char> unique;
    string ustr = "";
    for (char ch : str) {
        if (unique.find(ch) == unique.end()) {
            unique.insert(ch);
            ustr += ch;
        }
    }

    string per(k, '.');
    
    printKlengthWord(unique, k, per, 0);

    return 0;
}
