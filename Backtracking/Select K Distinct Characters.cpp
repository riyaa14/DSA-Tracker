#include <iostream>
#include <set>
#include <string>

using namespace std;

// forming all possible K length words
// void printKlengthWord(set<char> &unique, int k, string& per, int i){
//     if(i == unique.size()){ 
//         for(char ch : per) {
//             if(ch == '.') return;
//         }
//         cout << per << endl;
//         return;
//     }
    
//     // goes into one of the boxes
//     for(int j=0; j<k; j++){
//         if(per[j] == '.'){
//             auto it = unique.begin();
//             advance(it, i);
//             per[j] = *(it);
//             printKlengthWord(unique, k, per, i+1);
//             per[j] = '.';
//         }
//     }
    
//     // doesn't go into any of the boxes
//     printKlengthWord(unique, k, per, i+1);
    
//     return;
    
// }

// selecting K chars - 1
void printKlengthWord1(int i, string& ustr, int k, string per, int pos){
    
    if(i == ustr.length()){
        if(pos == k)
            cout << per << endl;
        return;
    }
    
    // letter chooses to take up the box 
    string add = "";
    add += ustr[i];
    printKlengthWord(i+1 ,ustr, k, per+add, pos+1);
    
    // letter chooses to leave the box
    printKlengthWord(i+1 ,ustr, k, per, pos);
    
    return;
    
}

// selecting K chars - 2
void printKlengthWord2(int i, string& ustr, int k, string per, int pos){
    
    if(pos == k+1){ 
        cout << per << endl;
        return;
    }
    
    // box selects one letter
    for(int j=i; j<ustr.length(); j++){
        string add = "";
        add += ustr[j];
        printKlengthWord(j+1 ,ustr, k, per + add, pos+1);
    }
    
    return;
    
}



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

    string per = "";
    
    printKlengthWord1(0 ,ustr, k, per, 0);
    cout << endl;
    printKlengthWord2(0 ,ustr, k, per, 0);

    return 0;
}
