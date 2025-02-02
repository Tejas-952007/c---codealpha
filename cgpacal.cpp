// this is program assign from @code-alpha for
// date-2/1/2025
// author -> Tejas s ingle
// subject-this program purpose calculate the cgpa(c++ programing domain)


#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
using namespace std;

// Function to calculate GPA and CGPA
void calculateCGPA() {
    // Map to store grade points for each grade
    map<string, double> gradePoints = {
        {"A+", 4.0}, {"A", 4.0}, {"A-", 3.7},
        {"B+", 3.3}, {"B", 3.0}, {"B-", 2.7},
        {"C+", 2.3}, {"C", 2.0}, {"C-", 1.7},
        {"D+", 1.3}, {"D", 1.0}, {"F", 0.0}
    };

    int numCourses;
    double totalCredits = 0, totalGradePoints = 0;ssssssssss

    // Input: Number of courses
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    // Vector to store course details
    vector<pair<double, string>> courses;

    // Input course details
    for (int i = 0; i < numCourses; i++) {
        double creditHours;
        string grade;

        cout << "\nCourse " << i + 1 << ":\n";
        cout << "Enter credit hours: ";
        cin >> creditHours;
        cout << "Enter grade (e.g., A, B+, C-): ";
        cin >> grade;

        // Validate grade input
        while (gradePoints.find(grade) == gradePoints.end()) {
            cout << "Invalid grade! Please enter a valid grade: ";
            cin >> grade;
        }

        // Store course details
        courses.push_back({creditHours, grade});

        // Calculate total credits and grade points
        totalCredits += creditHours;
        totalGradePoints += creditHours * gradePoints[grade];
    }

    // Display individual course grades
    cout << "\nCourse Details:\n";
    for (int i = 0; i < numCourses; i++) {
        cout << "Course " << i + 1 << " - Credits: " << courses[i].first
             << ", Grade: " << courses[i].second << endl;
    }

    // Calculate and display GPA
    if (totalCredits == 0) {
        cout << "\nNo credits entered. Cannot calculate GPA.\n";
    } else {
        double gpa = totalGradePoints / totalCredits;
        cout << fixed << setprecision(2);
        cout << "\nTotal Credits: " << totalCredits << endl;
        cout << "Total Grade Points: " << totalGradePoints << endl;
        cout << "GPA for the semester: " << gpa << endl;
    }
}

int main() {
    cout << "===== CGPA Calculator =====\n";
    calculateCGPA();
    return 0;
}