
#include <algorithm>
#include <iostream>
#include <list>
#include <random>
using namespace std;

list<int> listToSort;

void Options();
void GenerateList(int size);
void PrintList();

void BubbleSort();
void MergeSort();
void QuickSort();
bool IsSorted();

int main(int argc, char* argv[])
{
    cout <<  "Welcome!" << endl << "Please Select the size of the list you want to sort: ";
    int size;
    cin >> size;
    GenerateList(size);
    Options();
    return 0;
}

/**
 * \brief Generates a list with integers ranging from 0 to 10000
 * \param size The amount of elements to generate
 */
void GenerateList(int size)
{
    for (int i = 0; i < size; i++)
    {
        listToSort.push_back(rand() % 10000);
    }
    cout << "List Generated:" << endl;
}

void PrintList()
{
    for (int i : listToSort)
    {
        cout << i << " ";
    }
    cout << endl << endl;
}

/**
 * \brief Options menu for the user to select the sorting algorithm
 */
void Options()
{
    int choice;
    cout << "Please select the sorting algorithm you want to use:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Merge Sort" << endl;
    cout << "3. Quick Sort" << endl;
    cout << "4. Print Current List" << endl;
    cout << "5. Exit" << endl;
    cin >> choice;
    switch (choice)
    {
        case 1:
            BubbleSort();
            break;
        case 2:
            MergeSort();
            break;
        case 3:
            QuickSort();
            break;
        case 4:
            PrintList();
            Options();
            break;
        case 5:
            exit(0);
        default:
            Options();
    }
}

/**
 * \brief Bubble Sort algorithm
 */
void BubbleSort()
{
    //Base Case
    if (listToSort.empty() || listToSort.size() == 1)
    {
        cout << "List is already sorted!" << endl;
        return;
    }
    
    bool swapped;
    do {
        swapped = false;
        auto it1 = listToSort.begin();
        auto it2 = std::next(it1);
        while (it2 != listToSort.end()) {
            if (*it1 > *it2) {
                std::swap(*it1, *it2);
                swapped = true;
            }
            ++it1;
            ++it2;
        }
    } while (swapped);
    cout << "List Sorted!" << endl;
    PrintList();
}

void MergeSort()
{
    
}

void QuickSort()
{
    
}

bool IsSorted()
{
    return is_sorted(listToSort.begin(), listToSort.end());
}



