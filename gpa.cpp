#include <iostream>

using namespace std;

string CourseCode[] = {"TICT1114", "TICT1123", "TICT1134", "TICT1142", "TICT1152"};
string subjects[] = {"EICT", "MATHS", "FOCP", "FOWT", "POM"};
int creditsPerSub[] = {4, 3, 4, 2, 2};

string getSubResults[5];
float assignCredits[5];
float FinalCredits[5];
float totalCredits = 0;
float finalGPA;

void function(string getSubResults[5]) {
    for(int i=0; i<5; i++) {
        if(getSubResults[i] == "A+" || getSubResults[i] == "A")
            assignCredits[i] = 4.0;
        else if(getSubResults[i] == "A-")
            assignCredits[i] = 3.7;
        else if(getSubResults[i] == "B+")
            assignCredits[i] = 3.3;
        else if(getSubResults[i] == "B")
            assignCredits[i] = 3.0;
        else if(getSubResults[i] == "B-")
            assignCredits[i] = 2.7;
        else if(getSubResults[i] == "C+")
            assignCredits[i] = 2.3;
        else if(getSubResults[i] == "C")
            assignCredits[i] = 2.0;
        else if(getSubResults[i] == "C-")
            assignCredits[i] = 1.7;
        else if(getSubResults[i] == "D+")
            assignCredits[i] = 1.3;
        else if(getSubResults[i] == "D")
            assignCredits[i] = 1.0;
        else if(getSubResults[i] == "E")
            assignCredits[i] = 0.0;
        else{
            cout << "Please check your input!" << endl;
            break;
        }
    }
}

int main() {

    cout << "\n---Welcome to the GPA Calculator---\n" << endl;

    cout << "Course Code\t" << "Subjects\t" << "Credits" << endl;
    for(int i=0; i<5; i++) {
       cout << CourseCode[i] << "\t" << subjects[i] << "\t\t" << creditsPerSub[i] << endl;
    }
    cout << endl << endl;

    //get subject marks
    for(int i=0; i<5; i++) {
        cout << "Enter your result of " << subjects[i] << ": " << endl;
        cin >> getSubResults[i];
    }

    //find final credits
    function(getSubResults);
    for(int i=0; i<5; i++) {
        FinalCredits[i] = assignCredits[i] * creditsPerSub[i];
        totalCredits += FinalCredits[i];
    }

    cout << endl << endl;
    cout << "Course Code\t" << "Subjects\t" << "Credits\t" << "Your results\t" << "Your credits\t" << "Final Credits" << endl;
    for(int i=0; i<5; i++) {
        cout << CourseCode[i] << "\t" << subjects[i] << "\t\t" << creditsPerSub[i] << "\t\t" << getSubResults[i] << "\t" << assignCredits[i] << "\t\t" << FinalCredits[i] << endl;
    }

    finalGPA = totalCredits / 15.0;

    cout << endl << endl;
    if(finalGPA >= 3.7)
        cout << "You passed in First class \nYour GPA : " << finalGPA << endl;
    else if(finalGPA < 3.7 && finalGPA >= 3.30)
        cout << "You passed in Second class(Upper) \nYour GPA : " << finalGPA << endl;
     else if(finalGPA < 3.30 && finalGPA >= 3.00)
        cout << "You passed in Second class(Lower) \nYour GPA : " << finalGPA << endl;
     else if(finalGPA < 3.0 && finalGPA >= 2.0)
        cout << "Pass \nYour GPA : " << finalGPA << endl;
    else
        cout << "Fail \nYour GPA : " << finalGPA << endl;

    return 0;
}