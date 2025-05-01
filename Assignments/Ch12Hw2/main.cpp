/*8. replaceSubstring Function
Write a function named replaceSubstring. The function should accept three C-string or string object arguments. 
Let’s call them string1, string2, and string3. It should search string1 for all occurrences of string2. 
When it finds an occurrence of string2, it should replace it with string3. For example, suppose the three arguments have the following values:

string1:          "the dog jumped over the fence"
string2:          "the"
string3:          "that"

With these three arguments, the function would return a string object with the value "that dog jumped over that fence". 
*/

#include <iostream>
#include <string>

using namespace std;

string replaceSubstring(string str, string find, string replace){

    string result;
    bool match;

    for(int i = 0; i < str.length(); i++){

        if(str[i] == find[0]){
            for(int j = 0; j < find.length(); j++){
                if(str[i + j] != find[j]){
                    match = false;
                    break;
                }
                match = true;
            }

            if(!match){
                result += str[i];
                continue;
            } else {
                result += replace;
                i += find.length() - 1;
            }
        } else {
            result += str[i];
        }
    }

    return result;
}

int main(){

    string main, toFind, replacement;

    printf("Enter the main string: ");
    getline(cin, main);
    printf("Enter the substring to be replaced: ");
    getline(cin, toFind);
    printf("Enter the string that will replace %s: ", toFind.c_str());
    getline(cin, replacement);

    main = replaceSubstring(main, toFind, replacement);
    printf("The new string is: %s", main.c_str());

    return 0;
}