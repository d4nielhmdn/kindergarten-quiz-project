// kindergarten_quiz.cpp
// SECTION 6: INTERACTIVE C++ PROGRAM
// Group Members: Den (Lead & Git), Danial (Logic), Kenneth (UI/Content)

#include <iostream>
#include <string>
using namespace std;

// ===== FUNCTION DECLARATIONS (KENNETH) =====
void displayWelcomeMessage();                           // KENNETH
string askQuestion(string letter, string options[4]);    // KENNETH
void displayResult(bool isCorrect);                      // KENNETH
void displayGoodbyeMessage();                            // KENNETH

// ===== FUNCTION DECLARATIONS (DANIAL) =====
bool checkAnswer(string userAnswer, string correctOption); // DANIAL

// ===== MAIN PROGRAM CONTROLLER (DEN) =====
int main()
{
    // ===== QUIZ DATA (DEN) =====
    string letters[] = {"A", "B", "C", "D", "E"}; // DEN sets up letters

    // KENNETH: Provides the content for the options
    string options[5][4] = {
        {"Apple", "Ball", "Cat", "Dog"},       // Correct: A
        {"Ant", "Ball", "Cup", "Duck"},        // Correct: B
        {"Fish", "Banana", "Cat", "Egg"},      // Correct: C
        {"Dog", "Apple", "Elephant", "Fan"},   // Correct: D
        {"Car", "Fish", "Eagle", "Banana"}     // Correct: E
    };

    // DANIAL: Correct answer keys for each question
    string correctChoices[] = {"a", "b", "c", "a", "c"};

    int totalQuestions = 5; // DEN
    int score = 0;          // DEN tracks the score

    // KENNETH: Welcome message
    displayWelcomeMessage();

    // DEN: Controls quiz loop
    for (int i = 0; i < totalQuestions; i++)
    {
        // KENNETH: Ask question and get user input
        string userAnswer = askQuestion(letters[i], options[i]);

        // DANIAL: Check if answer is correct
        bool isCorrect = checkAnswer(userAnswer, correctChoices[i]);

        // DEN: Update score
        if (isCorrect) score++;

        // KENNETH: Display result
        displayResult(isCorrect);
    }

    // DEN & KENNETH: Final score output
    cout << "\nQuiz over! Your final score is: " << score << "/" << totalQuestions << endl;

    // KENNETH: Goodbye message
    displayGoodbyeMessage();

    return 0;
}

// ===== USER INTERFACE & CONTENT (KENNETH) =====
void displayWelcomeMessage()
{
    cout << "\n🌈 Welcome to the Fun Alphabet Quiz! 🌈" << endl;
    cout << "Choose the correct option by typing A, B, C, or D." << endl;
    cout << "Let's begin!\n" << endl;
}

string askQuestion(string letter, string options[4])
{
    string answer;
    cout << "Which of these starts with '" << letter << "'?\n";
    cout << "A) " << options[0] << "\n";
    cout << "B) " << options[1] << "\n";
    cout << "C) " << options[2] << "\n";
    cout << "D) " << options[3] << "\n";
    cout << "Your choice (A/B/C/D): ";
    cin >> answer;
    return answer;
}

void displayResult(bool isCorrect)
{
    if (isCorrect)
        cout << "✅ Correct! Great job!\n" << endl;
    else
        cout << "❌ Oops! Try the next one!\n" << endl;
}

void displayGoodbyeMessage()
{
    cout << "🎉 Thanks for playing! See you next time! 👋" << endl;
}

// ===== CORE LOGIC (DANIAL) =====
bool checkAnswer(string userAnswer, string correctOption)
{
    // Helper lambda to trim spaces
    auto trim = [](string &str) {
        str.erase(0, str.find_first_not_of(" \t\n\r"));
        str.erase(str.find_last_not_of(" \t\n\r") + 1);
    };

    // Trim inputs
    trim(userAnswer);
    trim(correctOption);

    if (userAnswer.empty()) return false;

    // Convert both to lowercase
    for (char &c : userAnswer) c = tolower(c);
    for (char &c : correctOption) c = tolower(c);

    // Validate input is one of a,b,c,d
    if (userAnswer != "a" && userAnswer != "b" &&
        userAnswer != "c" && userAnswer != "d") {
        cout << "⚠️ Please choose only A, B, C, or D!\n";
        return false;
    }

    // Check if the choice matches
    return userAnswer == correctOption;
}