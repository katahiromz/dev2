#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm> // std::sort
#include <functional> // std::greater

void sort_int_array(void)
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
}

void sort_string_vector(void)
{
    std::vector<std::string> vec;

    vec.push_back("def");
    vec.push_back("abc");
    vec.push_back("ghi");

    for (auto& str : vec) printf(" '%s'", str.c_str());
    printf("\n");

    // in normal order
    std::sort(vec.begin(), vec.end());

    for (auto& str : vec) printf(" '%s'", str.c_str());
    printf("\n");

    // in reverse order
    std::sort(vec.begin(), vec.end(), std::greater<std::string>());

    for (auto& str : vec) printf(" '%s'", str.c_str());
    printf("\n");

    // in normal order
    std::sort(vec.begin(), vec.end(), [](const std::string& a, const std::string& b){
        return a < b;
    });

    for (auto& str : vec) printf(" '%s'", str.c_str());
    printf("\n");
}

int main(int argc, char **argv)
{
    sort_int_array();
    sort_string_vector();
    return 0;
}
