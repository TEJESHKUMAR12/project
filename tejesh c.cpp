#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

void shuffleQuestions(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int randIndex = rand() % size;
        int temp = arr[i];
        arr[i] = arr[randIndex];
        arr[randIndex] = temp;
    }
}

int main()
{
    string questions[] =
    {
        "What is the capital of Telangana?",
        "What is the national song of INDIA?",
        "Who is the Prime Minister of India?",
        "What is the capital of India?",
        "Which city is known as the Silicon Valley of India?",
        "What is the national flower of India?"
    };

    string options[][4] =
    {
        {"Madhyapradesh", "UP", "AP", "Hyderabad"},
        {"Vande Mataram", "Sare Jahan se Accha", "National Anthem", "Chak de India"},
        {"Donald Trump", "Narendra Modi", "Joe Biden", "K.A.Paul"},
        {"New Delhi", "Mumbai", "Chennai", "Kolkata"},
        {"Bangalore", "Hyderabad", "Chennai", "Pune"},
        {"Lotus", "Rose", "Sunflower", "Tulip"}
    };

    int correctAnswers[] = {4, 1, 2, 1, 1, 1};
    int score = 0;
    int userAnswer;
    char playAgain = 'y';

    srand(time(0));

    cout << "Welcome to the Quiz!" << endl;
    cout << "Answer the following questions by entering the option number (1–4)." << endl;

    while (playAgain == 'y' || playAgain == 'Y')
        {
        score = 0;
        int questionOrder[] = {0, 1, 2, 3, 4, 5};
        shuffleQuestions(questionOrder, 6);

        for (int i = 0; i < 6; i++)
            {
            cout << "\nQuestion " << i + 1 << ": " << questions[questionOrder[i]] << endl;
            for (int j = 0; j < 4; j++)
            {
                cout << j + 1 << ". " << options[questionOrder[i]][j] << endl;
            }

            bool validInput = false;
            int timer = 10;
            while (!validInput && timer > 0)
                {
                cout << "Your answer (1-4): ";
                cin >> userAnswer;
                if (userAnswer >= 1 && userAnswer <= 4)
                 {
                    validInput = true;
                }
            else
                {
                    cout << "Invalid input! Please choose a number between 1 and 4." << endl;
                }
                sleep(1);
                if (timer > 0)
                 {
                    timer--;
                }
            }

            if (validInput && userAnswer == correctAnswers[questionOrder[i]])
                {
                cout << "Correct!" << endl;
                score++;
            }
            else if (!validInput)
                {
                cout << "Time's up! The correct answer was option " << correctAnswers[questionOrder[i]] << ": "
                     << options[questionOrder[i]][correctAnswers[questionOrder[i]] - 1] << "." << endl;
            }
            else
                {
                cout << "Wrong answer. The correct answer was option " << correctAnswers[questionOrder[i]] << ": "
                     << options[questionOrder[i]][correctAnswers[questionOrder[i]] - 1] << "." << endl;
            }
        }

        cout << "\nQuiz completed!" << endl;
        cout << "Your total score: " << score << " out of 6" << endl;
        cout << "Would you like to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thank you for playing the quiz! Goodbye!" << endl;

    return 0;
}
