// To Debug;
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string reverseString(string &str){
    
	// I     a m     a   S t a r
    // 11 10 9 8 7 6 5 4 3 2 1 0
	
	string temp, toadd;
	int count = 0;

	for(int i = str.length() - 1; i > 0; i--){
		// count = 0;
		if(str[i] == ' '){
			count++;
			if(count >= 2){
				// count = 0;
				continue;
				// count = 0;
			}
			reverse(temp.begin(), temp.end());
			toadd += temp;
			toadd += " ";
			temp = " ";
			// count = 0;
		}
		else{
			temp += str[i];		// temp = Star toadd = Star 
		}
		// count = 0;
	}		
	return toadd;
}

int main() {
    string s = "I am  a Star";
    cout << reverseString(s);
    return 0;
}