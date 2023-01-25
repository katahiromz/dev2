#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm> // std::sort
#include <functional> // std::greater

int main(int argc, char **argv)
{
    int array[] = { 5, 3, 2, 4, 1 };

    for (auto i : array) printf(" %d", i);
    printf("\n");

    // in normal order
    std::sort(std::begin(array), std::end(array));

    for (auto i : array) printf(" %d", i);
    printf("\n");

    // in reverse order
    std::sort(std::begin(array), std::end(array), std::greater<int>());

    for (auto i : array) printf(" %d", i);
    printf("\n");

    // in normal order
    std::sort(std::begin(array), std::end(array), [](int a, int b){
        return a < b;
    });

    for (auto i : array) printf(" %d", i);
    printf("\n");

    return 0;
}
