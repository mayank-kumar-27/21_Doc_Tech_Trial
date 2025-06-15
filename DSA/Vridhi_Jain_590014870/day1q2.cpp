#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;

   
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n]; 

    cout << "Enter " << n << " elements:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    cout << "Sum of array elements = " << sum << endl;

    return 0;
}
