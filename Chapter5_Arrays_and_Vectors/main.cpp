// Chapter6 Example.cpp : Defines the entry point for the console application.
//
#include <string> 
#include <iostream>

using namespace std;

int const MAX_ROWS = 10;

//
// We will print out the students of the class along with the scores.
// Uses parallel arrays; ie, student[i]'s grade is in grade[i].
//
// Inputs:
//		students[]	- array that holds the students' names
//		grades[]	- array that holds the students' grades
//		size		- size of the arrays 
//
// Returns:
//		None.		
//
void print_student_scores(string students[], double grades[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "student[" << i << "] Name: " << students[i] << "\t grade: " << grades[i] << endl;
    }
}
//
// Get the statistics of the students' grades: max, min, average
//
// Inputs:
//		grades[]	- array that holds the students' grades
//		size		- size of the arrays 
//		max			- the highest grade (by ref)
//		min			- the lowest grade (by ref)
//		avg			- the grade average (by ref)
//
// Returns (by reference):
//		max			- the highest grade
//		min			- the lowest grade
//		avg			- the grade average
//
void get_array_stats(double arry[], int size, int& max, int& min, double& avg)
{
    //
    // simple search for max / min and computing average
    //
    max = arry[0];
    min = arry[0];
    int sum = arry[0];
    for (int i = 1; i < size; i++)
    {
        int curNum = arry[i];
        //cout << "array[" << i << "] ==" << curNum;
        if (curNum < min)
            min = arry[i];
        if (arry[i] > max)
            max = arry[i];
        sum += arry[i];
    }
    avg = sum / size;
}

int main(int argc, char* argv[])
{
    string students[MAX_ROWS] =
            {
                    { "Homer" },
                    { "Marge" },
                    { "Bart" },
                    { "Lisa" },
                    { "Maggie" }
            };

    int current_size = 5;
    double scores[MAX_ROWS];
    //
    // set test scores
    //
    for (int i = 0; i < current_size; i++)
    {
        scores[i] = i * 10;
    }
    //
    // add a student and grade
    //
    students[current_size] = "Peter";
    scores[current_size] = 95;
    current_size++;
    //
    // get array stats...
    //
    int max = 0;
    int min = 100;
    double avg = 0;
    get_array_stats(scores, current_size, max, min, avg);
    print_student_scores(students, scores, current_size);
    //
    // print score stats
    //
    cout << endl << "score statistics : " << endl;
    cout << endl << "Max score:     " << max << endl;
    cout << "Min score:     " << min << endl;
    cout << "Average score: " << avg << endl;
    // 
    // what happens if we access array element 11?
    //
    students[11] = "Jonny Quest";
    students[12] = "Speed Racer";
    students[13] = "Kimba";
    students[14] = "Huell Howser";
    students[15] = "Babe";
    //
    // how do vectors work?
    //

    return 0;
}
