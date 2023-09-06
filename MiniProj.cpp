#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Question
{
    string questionText;
    vector<string> options;
    char correctAnswer;
};
char askQuestion(const Question& q)
{
    cout << q.questionText << endl;
    for (size_t i = 0; i < q.options.size(); ++i)
    {
        cout << static_cast<char>('A' + i) << ") " << q.options[i] << endl;
    }
    char userAnswer;
    cout << "Enter your answer (A, B, C, or D): ";
    cin >> userAnswer;
    return toupper(userAnswer);
}
bool isCorrect(const Question& q, char userAnswer)
{
    return (userAnswer == q.correctAnswer);
}
int main()
{
    vector<Question> quiz;
    Question q1 = {"What is the capital of France?",
                   {"A) London", "B) Berlin", "C) Madrid", "D) Paris"},
                   'D'};
    quiz.push_back(q1);

    Question q2 = {"Which planet is known as the Red Planet?",
                   {"A) Venus", "B) Mars", "C) Jupiter", "D) Saturn"},
                   'B'};
    quiz.push_back(q2);
    int score = 0;
    cout << "Welcome to the Quiz Game!" << endl;
    for (const Question& question : quiz)
    {
        char userAnswer = askQuestion(question);

        if (isCorrect(question, userAnswer))
        {
            cout << "Correct!" << endl;
            score++;
        } else
        {
            cout << "Incorrect. The correct answer is " << question.correctAnswer << "." << endl;
        }
        cout << endl;
    }
    cout << "Quiz completed! Your score: " << score << "/" << quiz.size() <<endl;
    return 0;
}
