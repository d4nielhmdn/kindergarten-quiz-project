// kindergarten_quiz.cpp
// SECTION 6: INTERACTIVE C++ PROGRAM
// Group Members: Den (Lead & Git), Danial (Logic), Kenneth (UI/Content)

// ===== DEN'S TASK: SETUP & INTEGRATION =====
// TODO DEN: Include any necessary libraries here.
#include <iostream>
#include <string>
using namespace std;

// ===== FUNCTION DECLARATIONS (The "Table of Contents") =====
// TODO KENNETH: Write these functions to handle user interaction.
void displayWelcomeMessage();
string askQuestion(string letter);
void displayResult(bool isCorrect);
void displayGoodbyeMessage();

// TODO DANIAL: Write this function to handle the core logic.
bool checkAnswer(string userAnswer, string correctAnswer);

// ===== DEN'S TASK: MAIN PROGRAM CONTROLLER =====
int main()
{
    // TODO DEN:
    // 1. Initialize arrays for quiz data (letters and answers).
    string letters[] = {"A", "B", "C", "D", "E"};
    string answers[] = {"Apple", "Ball", "Cat", "Dog", "Elephant"};

    int totalQuestions = 5; // Size of the arrays
    int score = 0;          // Variable to track correct answers

    // 2. Call Kenneth's function to show the welcome message.
    displayWelcomeMessage();

    // 3. Loop through all the questions.
    for (int i = 0; i < totalQuestions; i++)
    {
        // a. Call Kenneth's function to ask a question and get an answer.
        string userAnswer = askQuestion(letters[i]);

        // b. Call Danial's function to check if the answer is correct.
        bool isCorrect = checkAnswer(userAnswer, answers[i]);

        // c. Update the score if the answer was correct.
        if (isCorrect)
        {
            score++;
        }

        // d. Call Kenneth's function to show the result.
        displayResult(isCorrect);
    }

    // 4. After the loop, show the final score.
    // TODO DEN & KENNETH: Collaborate on this output.
    cout << "Quiz over! Your final score is: " << score << "/" << totalQuestions << endl;

    // 5. Call Kenneth's function to show the goodbye message.
    displayGoodbyeMessage();

    return 0;
}

// ===== KENNETH'S TASKS: USER INTERFACE & CONTENT =====
// TODO KENNETH: Write the definitions for these functions.
// Make the output friendly and engaging for children.

void displayWelcomeMessage()
{
    // Example:
    // cout << "🌈 Welcome to the Fun Alphabet Quiz! 🌈" << endl;
    // cout << "Let's see what words you know!" << endl;
}

string askQuestion(string letter)
{
    string answer;
    // Example:
    // cout << "What word starts with the letter " << letter << "? ";
    // cin >> answer;
    return answer;
}

void displayResult(bool isCorrect)
{
    // Example if true:
    // cout << "✅ Correct! You're so smart!" << endl;
    // Example if false:
    // cout << "❌ Oops! Nice try! Let's do the next one." << endl;
}

void displayGoodbyeMessage()
{
    // Example:
    // cout << "Thanks for playing! You did great!" << endl;
}

// ===== DANIAL'S TASKS: CORE PROGRAM LOGIC =====
// TODO DANIAL: Write the definition for this function.
// This function should compare the user's answer to the correct answer.
// Make it robust (e.g., not case-sensitive).

bool checkAnswer(string userAnswer, string correctAnswer)
{
    // Step 1: Convert both userAnswer and correctAnswer to the same case (e.g., lowercase).
    // This way, "Apple" and "apple" are both correct.

    // Step 2: Compare the converted strings.

    // Step 3: Return true if they match, false if they don't.
    return false; // Delete this line when you write your logic.
}