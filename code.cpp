// C++ program to illustrate how to read data
// from a text file
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class dataType {
    public:
        string name;
        T value;
        dataType(string theName, T theValue){
            name = theName;
            value = theValue;
        }
        
        T get(){
            return value;
        }
};



int main() {

    // Open the text file named "input.txt"
    ifstream file("input.txt");

    // Check if the file is successfully opened
    if (!file.is_open()) {
        cerr << "Error opening the file!";
        return 1;
    }

    // String variable to store the read data
    string s;
    string inputText = "";

    // Read each line of the file and print it to the
    // standard output stream till the whole file is
  	// completely read
    while (getline(file, s)){
        inputText += s;
    }
    
    cout << inputText;
    
    dataType<int> ints[0] = {};
    dataType<string> strings[0] = {};
    dataType<bool> bools[0] = {};
    
    // Create a string to track text
    string currentText = "";
    for(int i = 0; i < inputText.size(); i++){
        currentText += inputText[i];
        //cout << currentText + "\n";
        
        if(inputText.substr(i, 2) == "##"){
            cout << "\nvariable found";
            
            for(int j = i; j < inputText.size(); j++){
                if(inputText[j] == '='){
                    cout << "\nInitialization found";
                    break;
                }
            }
        }
        
        if(i - 1 > 0 && inputText.substr(i - 1, 2) == ":)"){
            currentText = "";
        }
    }

    // Close the file
    file.close();
    return 0;
}
