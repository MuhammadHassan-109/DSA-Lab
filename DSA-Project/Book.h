#pragma once
#include <string>
using namespace std;

struct Book {
    int    id;
    string title;
    string author;
    string genre;
    int    viewCount;
    float  totalRating;
    int    ratingCount;
};
