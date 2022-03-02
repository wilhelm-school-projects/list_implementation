#include "Sorted_List.h"
#include <iostream>

using namespace std;

int main()
{
    Sorted_List first{1,22, 2, 300, -6, 8};
    Sorted_List second{};
    second = std::move(Sorted_List{99, 10, 22});
    second.print_all();
    return 0;
}