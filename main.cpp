
//  Created by Ayomide Isinkaye on 4/4/24.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a structure to represent a quiz question
struct Question {
    string questionText;
    vector<string> options;
    int correctOption;
};

// Function to display a question and its options
void displayQuestion(const Question& q) {
    cout << q.questionText << endl;
    for (int i = 0; i < q.options.size(); ++i) {
        cout << i + 1 << ". " << q.options[i] << endl;
    }
}

// Function to check if the user's answer is correct
bool isCorrectAnswer(const Question& q, int userAnswer) {
    return userAnswer == q.correctOption;
}

int main() {
    // Define quiz questions
    vector<Question> quiz = {
        {"When was Huston-Tillotson founded?", {"1875", "1715", "1934", "1650"}, 1},
        {"What is the largest planet in our solar system?", {"Mercury", "Venus", "Jupiter", "Mars"}, 3},
        {"Who wrote 'Romeo and Juliet'?", {"William Shakespeare", "Charles Dickens", "Jane Austen", "Mark Twain"}, 1},
        {"Who i sthe current president/CEO of Huston-Tillotson University?", {"Dr. Melvis X. Williams", "Dr. Melvin K. Wales", "Dr. Melva K. Wallace", "Dr. Zelda K. Wallace"}, 3},
        {"How many seasons does the United States have each year?", {"5", "4", "2", "3"}, 2},
    };

    // Display each question and get user's answers
    int score = 0;
    for (const Question& q : quiz) {
        displayQuestion(q);
        cout << "Enter the answer of your choice(1-" << q.options.size() << "): ";
        int userAnswer;
        cin >> userAnswer;
        if (isCorrectAnswer(q, userAnswer)) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Incorrect. The correct answer is: " << q.options[q.correctOption - 1] << endl;
        }
        cout << endl;
    }

    // Display final score
    cout << "Quiz completed. Your score: " << score << "/" << quiz.size() << endl;

    return 0;
}

