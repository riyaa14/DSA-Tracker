// C++ program to print all Alpha-Numeric Abbreviations
// of a String
#include <bits/stdc++.h>
#include<string>
using namespace std;

// **************** APPROACH 1 *********************

void printComb(string str, int code, int i, string out){
    
    if(i>=str.length()) {
        cout << out << endl;
        return;
    }
    
    // print letter
    printComb(str, 1, i+1, out + str[i]);
    
    // print code
    int c = code, j = 1;
    // j = length of string which is replaced by code
    for(j=1; i+j <= str.length(); j++){
        
        if(i+j == str.length()) {
		printComb(str, 1, i+j+1, out + to_string(code)); 
		continue;
	}
        
        printComb(str, 1, i+j+1, out + to_string(code) + str[i+j]);
        
        code++;
    }
    
    return;
}

// *************** APPROACH 2 *********************

void printComb2(string str, int code, int i, string out){
    
    if(i>=str.length()) {
        if(code > 0) out += to_string(code);
        cout << out << endl;
        return;
    }
    
    // print letter
    if(code!=0) printComb2(str, 0, i+1, out + to_string(code) + str[i]);
    else printComb2(str, 0, i+1, out + str[i]);
    
    // print code
    printComb2(str, code+1, i+1, out);
    
    return;
}

// driver function
int main()
{
	string str;
	cin >> str;
	printComb(str, 1, 0, "");
	printComb2(str, 0, 0, "");
	return 0;
}
