
#include <algorithm>
#include <chrono>
#include <iostream>
#include <list>
#include <random>
using namespace std;

vector<int> vectorToSort;

int attempts = 0;

void Options();
void GenerateList(int size);
void PrintList();
void PrintList(long time);

//The Sorting Algorithms
void BubbleSort();
void SelectionSort(int length, int position);
void QuickSort(int low, int high);

//Functions used in the sorting algoritms
int Partition(int low, int high);
int findSmallest(int start, int end);
int listSize = 0;


int main(int argc, char* argv[])
{
    cout <<  "Welcome!" << endl << "Please Select the size of the list you want to sort: ";
    int size;
    cin >> size;
    GenerateList(size);
    listSize = size;
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
        vectorToSort.push_back(rand() % 10000);
    }
    cout << "List Generated:" << endl;
}

/**
 * \brief Prints the list to the console
 */
void PrintList()
{
    for (int i : vectorToSort)
    {
        cout << i << " ";
    }
    cout << endl << endl;
    
}
/**
 * \brief Prints the list to the console
 * \param time The time it took to sort the list in milliseconds
 */
void PrintList(long time)
{
    for (int i : vectorToSort)
    {
        cout << i << " ";
    }
    cout << endl << endl;
    cout << "Time Taken: " << time << " milliseconds" << endl;

}

/**
 * \brief Options menu for the user to select the sorting algorithm
 */
void Options()
{
    int choice;
    cout << "Please select the sorting algorithm you want to use:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Selection Sort" << endl;
    cout << "3. Quick Sort" << endl;
    cout << "4. Print Current List" << endl;
    cout << "5. Exit" << endl;
    cin >> choice;
    auto start = std::chrono::high_resolution_clock::now();
    switch (choice)
    {
        case 1:
            {
                BubbleSort();
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
                PrintList(duration.count());
            }
            break;
        case 2:
            {
                SelectionSort(listSize, 0);
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
                PrintList(duration.count());
            }
            break;
        case 3:
            {
                QuickSort(0, listSize-1);
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
                PrintList(duration.count());
            }
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
    if (vectorToSort.empty() || vectorToSort.size() == 1)
    {
        cout << "List is empty or already sorted!" << endl;
        return;
    }
    
    bool swapped;
    int size = vectorToSort.size(); // Store the size of the vector

    do {
        swapped = false;
        for (int i = 0; i < size - 1; ++i) {
            if (vectorToSort[i] > vectorToSort[i + 1]) {
                std::swap(vectorToSort[i], vectorToSort[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
    cout << "List Sorted!" << endl;
}

void SelectionSort(int length, int position)
{
    int minpos;
    if (position == length)
    {
        //base case
        return;
    }
    minpos = findSmallest(position, length-1);
    if (minpos !=position)
    {
        swap(vectorToSort[position], vectorToSort[minpos]);
    }
    SelectionSort(length, position+1);
}

void QuickSort(int low, int high)
{
    auto start = std::chrono::high_resolution_clock::now();
    //Base Case
    if (low>=high)
    {
        return;
    }
    else
    {
        int pivot = Partition(low, high);
        QuickSort(low, pivot-1);
        QuickSort(pivot+1, high);
    }
}

/**
 * \brief Partitions the array
 * \param low low index
 * \param high high index
 * \return 
 */
int Partition(int low, int high)
{
    int pivot = vectorToSort[low];
    
    int count = 0;
    for (int i = low+1; i<=high; i++)
    {
        if (vectorToSort[i] < pivot)
        {
            count++;
        }
    }
    int pivIndex = low + count;
    swap(vectorToSort[pivIndex], vectorToSort[low]);

    int i = low;
    int j = high;
    while (i < pivIndex && j > pivIndex) {
 
        while (vectorToSort[i] <= pivot) {
            i++;
        }
 
        while (vectorToSort[j] > pivot) {
            j--;
        }
 
        if (i < pivIndex && j > pivIndex) {
            swap(vectorToSort[i++], vectorToSort[j--]);
        }
    }
    return pivIndex;
}

/**
 * \brief returns the smallest element from start to end
 * \param start start point
 * \param end end point
 * \return 
 */
int findSmallest(int start, int end)
{
    int minPos;
    if (start == end)
    {
        return start;
    }
        minPos = findSmallest(start+1, end);
        if (vectorToSort[start] < vectorToSort[minPos])
        {
            minPos = start;
        }
    return minPos;
}





