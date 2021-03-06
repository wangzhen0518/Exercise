// vect3.cpp -- using STL functions
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

struct Review
{
    std::string title;
    int price;
    int rating;
};

bool operator<(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2);
bool worseThan(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2);
bool FillReview(Review &rr);
void ShowReview(const std::shared_ptr<Review> &rr);
int main()
{
    using namespace std;

    vector<shared_ptr<Review>> books;
    Review temp;
    while (FillReview(temp))
        books.push_back(shared_ptr<Review>(new Review(temp)));
    if (books.size() > 0)
    {
        cout << "Thank you. You entered the following "
             << books.size() << " ratings:\n"
             << "Rating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end());
        cout << "Sorted by title:\nRating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end(), worseThan);
        cout << "Sorted by rating:\nRating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), ShowReview);

        random_shuffle(books.begin(), books.end());
        cout << "After shuffling:\nRating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), ShowReview);
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
    // cin.get();
    return 0;
}

bool operator<(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2)
{
    if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool worseThan(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2)
{
    if (r1->rating > r2->rating ||
        (r1->rating == r2->rating && r1->title < r2->title))
        return true;
    else
        return false;
}

bool FillReview(Review &rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, rr.title);
    if (rr.title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if (!std::cin)
        return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    std::cout << "Enter book price: ";
    std::cin >> rr.price;
    if (!std::cin)
        return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const std::shared_ptr<Review> &rr)
{
    std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price << std::endl;
}
