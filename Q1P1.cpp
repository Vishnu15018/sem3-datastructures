#include <iostream>

using namespace std;

//  TIME COMPLEXITY O(n²)

int function1(int arr[], int arr_length, int m1, int m2){
    if(m2 < m1){
        m1 += m2;
        m2 = m1 - m2;
        m1 = m1 - m2;
    }
    int sum = 0, count = 0;
    for(int i = 0; i < arr_length; i++){
        sum = 0;
        for(int j = i; j < arr_length; j++){
            sum += arr[j];
            if(sum >= m1 && sum <= m2){
                count += 1;
            }
        }
    }
    return count;
}

int main(){
    int m1, m2;
    int arr[10];
    
    cout << "Question - 1 Algorithm - 1";
    cout << endl << "Enter the values of m1 and m2 (space separated): ";
    cin >> m1 >> m2;
    if(m2 < m1){
        m1 += m2;
        m2 = m1 - m2;
        m1 = m1 - m2;
    }

    int arr_length = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < arr_length; i++)
        arr[i] = rand() % (101) - 50;

    cout << endl << "Array: ";
    for(int i = 0; i < arr_length; i++)
        cout << arr[i] << " ";
    cout << endl << endl << "No. of sums in the range " << m1 << "-" << m2 << " = " << function1(arr, arr_length, m1, m2);
    return 0;
}