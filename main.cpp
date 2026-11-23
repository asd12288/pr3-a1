#include <iostream>

class Score
{

public:
    int points;

    Score(int n) : points(n)
    {
    }

    Score operator+(const Score &other) const
    {
        return Score(points + other.points);
    }

    Score operator==(const Score &other) const
    {
        return Score(other.points);
    }
};

int main()
{
    Score first(20);
    Score second(30);

    Score total = first + second;

    Score total2 = total;

    std::cout << total.points;

    std::cout << total2.points;
    return 0;
}