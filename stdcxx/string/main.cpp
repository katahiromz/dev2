#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>

size_t get_length(const std::string& str)
{
    printf("str: '%s'\n", str.c_str());
    return str.size();
}

int main(int argc, char **argv)
{
    std::string str = "test";
    printf("%s\n", str.c_str());
    get_length(str);
    str += '#';
    str += "123";
    printf("%d\n", (int)str.find('#'));
    get_length(str);
    str.clear();
    get_length(str);
    size_t ich = str.find('#');
    if (ich == str.npos)
        printf("not found\n");
    else
        printf("ich: %d\n", (int)ich);
    return 0;
}
