/**/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> scores;

int askInt(string message){

    int val;
    while(true){
        printf("%s: ", message.c_str());
        cin >> val;

        if(!cin.fail()){
            cin.clear();
            break;
        } 

        cin.clear();
        cin.ignore(10000, '\n');
        printf("Type a whole number! (1,2,3...)\n");
    }

    return val;
}

// I can just use a reference to get the count out
int countPerfect(int &count){

    int perfect = 0;
    for(count = 0; count < 20; count++){
        int score = askInt("Enter a score 0 - 100 (or -1 to quit)");

        if(score == -1)
            break;

        if(score < 0 || score > 100){
            printf("Invalid score!\n");
            count--;
            continue;
        }
        
        if(score == 100)
            perfect++;
        scores.emplace_back(score);

    }

    return perfect;
}

int main(){

    int scoreCount;
    int perfectScores = countPerfect(scoreCount);
    

    printf("\nThe %d scores you entered include %d perfect score", scoreCount, perfectScores);
    if(perfectScores == 1)
        printf(".\n");
    else
        printf("s.\n");

    //for(int i = 0; i < scoreCount; i++){ // just proving scores were stored
    //    printf("%d\n", scores[i]);
    //}

    return 0;

}