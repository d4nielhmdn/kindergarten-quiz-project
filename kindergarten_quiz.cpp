// kindergarten_quiz.cpp
// SECTION 6: INTERACTIVE C++ PROGRAM
// Group Members: Den (Lead & Git), Danial (Logic), Kenneth (UI/Content)

#include <iostream>
#include <string>
#include <thread>
#include <vector>      // For flexible lists of words
#include <random>      // For modern, high-quality randomness
#include <algorithm>   // To shuffle the words
#include <chrono>

using namespace std;

struct Word {
    string text;
    char startingLetter;
};

// The main list of all possible words for the quiz.
// Kenneth can easily add more words here!
vector<Word> wordBank = {
    {"Apple", 'A'}, {"Ant", 'A'}, {"Alligator", 'A'}, {"Airplane", 'A'},
    {"Ball", 'B'}, {"Banana", 'B'}, {"Bird", 'B'}, {"Boat", 'B'},
    {"Cat", 'C'}, {"Car", 'C'}, {"Cup", 'C'}, {"Cow", 'C'},
    {"Dog", 'D'}, {"Duck", 'D'}, {"Dolphin", 'D'}, {"Desk", 'D'},
    {"Eagle", 'E'}, {"Egg", 'E'}, {"Elephant", 'E'}, {"Ear", 'E'},
    {"Fish", 'F'}, {"Fan", 'F'}, {"Frog", 'F'}
};

// ===== FUNCTION DECLARATIONS (KENNETH) =====
void displayWelcomeMessage();                           // KENNETH
string askQuestion(string letter, string options[4]);    // KENNETH
void displayResult(bool isCorrect);                      // KENNETH
void displayGoodbyeMessage();                            // KENNETH

void typeText(const string &text, int delay = 40) { // delay in ms per character
    for (char c : text) {
        cout << c << flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    cout << endl;
}

// ===== FUNCTION DECLARATIONS (DANIAL) =====
bool checkAnswer(string userAnswer, string correctOption); // DANIAL

// ===== MAIN PROGRAM CONTROLLER (DEN) =====
int main()
{
    // [ADDED] Setup for the high-quality random number generator.
    std::random_device rd;
    std::mt19937 generator(rd());

    // ===== QUIZ DATA (DEN) =====
    string letters[] = {"A", "B", "C", "D", "E"}; // DEN sets up letters

    int totalQuestions = 5; // DEN
    int score = 0;          // DEN tracks the score

    // KENNETH: Welcome message
    displayWelcomeMessage();

    // DEN: Controls quiz loop
    for (int i = 0; i < totalQuestions; i++)
    {
        // [CHANGE 2] The core logic inside the loop is replaced with this dynamic version.
        // === START OF NEW DYNAMIC QUESTION LOGIC ===
        char currentLetter = letters[i][0];

        // 1. Create separate lists for correct words and incorrect "distractors".
        vector<Word> possibleCorrectWords;
        vector<Word> possibleDistractors;
        for (const auto& word : wordBank) {
            if (word.startingLetter == currentLetter) {
                possibleCorrectWords.push_back(word);
            } else {
                possibleDistractors.push_back(word);
            }
        }

        // Safety Check
        if (possibleCorrectWords.empty() || possibleDistractors.size() < 3) {
            cout << "Error: Not enough words in bank for letter '" << currentLetter << "'!" << endl;
            continue;
        }

        // 2. Pick ONE random correct word.
        std::shuffle(possibleCorrectWords.begin(), possibleCorrectWords.end(), generator);
        string theCorrectWord = possibleCorrectWords[0].text;

        // 3. Pick THREE random incorrect words.
        std::shuffle(possibleDistractors.begin(), possibleDistractors.end(), generator);
        string options[4] = {
            theCorrectWord,
            possibleDistractors[0].text,
            possibleDistractors[1].text,
            possibleDistractors[2].text
        };

        // 4. Shuffle the final options to randomize the answer position.
        std::shuffle(options, options + 4, generator);

        // 5. Find where the correct answer landed and store its choice ('a', 'b', etc.).
        string correctChoice;
        for (int j = 0; j < 4; j++) {
            if (options[j] == theCorrectWord) {
                correctChoice = 'a' + j;
                break;
            }
        }

        // KENNETH: Ask question (this part stays the same, but uses the new dynamic `options`)
        string userAnswer = askQuestion(letters[i], options);

        // DANIAL: Check answer (this part stays the same, but uses the new dynamic `correctChoice`)
        bool isCorrect = checkAnswer(userAnswer, correctChoice);

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
    typeText("\n🌈 Welcome to the Fun Alphabet Quiz! 🌈");
    typeText("Choose the correct option by typing A, B, C, or D.");
    typeText("Let's begin!\n");
}

string askQuestion(string letter, string options[4])
{
    string answer;
    typeText("Which of these starts with '" + letter + "'?");
    typeText("A) " + options[0]);
    typeText("B) " + options[1]);
    typeText("C) " + options[2]);
    typeText("D) " + options[3]);
    typeText ( "Your choice ( A / B / C / D ): ");
    cin >> answer;
    cout << endl;
    return answer;
}

void displayResult(bool isCorrect)
{
    if (isCorrect)
        typeText("✅ Correct! Great job!\n");
    else
        typeText("❌ Oops! Try the next one!\n");
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
