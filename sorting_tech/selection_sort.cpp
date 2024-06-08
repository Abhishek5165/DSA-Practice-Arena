// O(N2), (where N = size of the array), for the best, worst, and average cases.

// Space Complexity = O(1)

#include <bits/stdc++.h>
void selectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        int mini = i;

        for (int j = i + 1; j < n; j++)
        {

            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        swap(arr[i], arr[mini]);
    }
}

// Advantages of Selection Sort Algorithm

Simple and easy to understand.Works well with small datasets.

    // Disadvantages of the Selection Sort Algorithm

    Selection sort has a time complexity of
    O(n ^ 2) in the worst and average case.Does not work well on large datasets.

    // Does not preserve the relative order of items with equal keys which means it is not stable.

    // Frequently Asked Questions on Selection Sort

    Q1.Is Selection Sort Algorithm stable
    ?

    The default implementation of the Selection Sort Algorithm is not stable.However,
    it can be made stable.Please see the stable Selection Sort for details.

        Q2.Is Selection Sort Algorithm in
        - place
    ?

    Yes,
    Selection Sort Algorithm is an in - place algorithm, as it does not require extra space.
