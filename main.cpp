#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

const int MAX = 1000000;

void merge(vector<int>& int_list, vector<int> left, vector<int> right) {

    int i = 0;
    int j = 0;

    while(i < left.size() || j < right.size()) {

        if(i == left.size()) {
            int_list[i+j] = right[j];
            j++;
        }

        else if(j == right.size()) {
            int_list[i+j] = left[i];
            i++;
        }

        else if(left[i] < right[j]) {
            int_list[i+j] = left[i];
            i++;
        }

        else {
            int_list[i+j] = right[j];
            j++;
        }
    }
}

void merge_sort(vector<int>& int_list) {

    if(int_list.size() <= 1) return;

    vector<int>::iterator midpoint = int_list.begin() + int_list.size()/2;
    vector<int> left(int_list.begin(), midpoint);
    vector<int> right(midpoint, int_list.end());

    merge_sort(left);
    merge_sort(right);
    merge(int_list, left, right);
}

int main() {

    srand(time(NULL));
    vector<int> int_list;

    for(int i = 0; i < MAX; i++) {
        int_list.push_back(rand() % 1000000);
    }

    merge_sort(int_list);

    for(int i = 0; i < int_list.size(); i++) {
        cout << int_list[i] << endl;
    }

    return 0;
}
