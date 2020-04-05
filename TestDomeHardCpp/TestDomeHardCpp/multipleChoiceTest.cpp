#include <iostream>
#include <string>
#include <vector>

class MultipleChoiceTest
{
public:
    MultipleChoiceTest(int qc) : questionsCount(qc), answers(questionsCount, -1) {}
    /*{
        this->questionsCount = questionsCount;
        answers = new int[questionsCount];
        for (int i = 0; i < questionsCount; i++)
        {
            answers[i] = -1;
        }
    }*/
    // If I used above for loop instead of 'vector' then, I needed to define destructor
    //virtual ~MultipleChoiceTest() { std::cout << "Original destroyed" << std::endl; }

    void setAnswer(int questionIndex, int answer)
    {
        answers[questionIndex] = answer;
    }

    int getAnswer(int questionIndex) const
    {
        return answers[questionIndex];
    }

protected:
    int questionsCount;

private:
    std::vector<int> answers;
};

class TimedMultipleChoiceTest : public MultipleChoiceTest
{
public:
    TimedMultipleChoiceTest(int questionsCount)
        : MultipleChoiceTest(questionsCount),
        times(questionsCount, 0) {}
    /*{
        times = new int[questionsCount];
        for (int i = 0; i < questionsCount; i++)
        {
            times[i] = 0;
        }
    }*/
    // If I used above for loop instead of 'vector' then, I needed to define destructor
    //~TimedMultipleChoiceTest() { std::cout << "Timed destroyed" << std::endl; }

    void setTime(int questionIndex, int time)
    {
        times[questionIndex] = time;
    }

    int getTime(int questionIndex) const
    {
        return times[questionIndex];
    }

private:
    std::vector<int> times;
};

#ifndef RunTests
void executeTest()
{
    MultipleChoiceTest test(5);
    for (int i = 0; i < 5; i++)
    {
        test.setAnswer(i, i);
    }

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Question " << i + 1 << ", correct answer: " << test.getAnswer(i) << "\n";
    }
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Test: " << i + 1 << "\n";
        executeTest();
    }
}
#endif