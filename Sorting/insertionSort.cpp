#include <iostream>
#include <vector>

using namespace std;

vector<int> insertionSort(vector<int> numbers, bool ascending=true) {
    // IF size of numbers only 1
    if (numbers.size() < 2)
        return numbers;
    
    int temp = 0;
    int i = 0;
    for (int j = 1; j < numbers.size(); j++) {
        i = j - 1;
        temp = numbers[j];
        if (ascending) {
            while(i >= 0 && numbers[i] > temp) {
                numbers[i+1] = numbers[i]; 
                i--;
            }
            numbers[i + 1] = temp;
        } else {
            while(i >= 0 && numbers[i] < temp) {
                numbers[i+1] = numbers[i]; 
                i--;
            }
            numbers[i + 1] = temp;
        }
    }
    return numbers;
}

int main() 
{ 
  vector<int> numbers{5,6,4,3,1,0};
  vector<int> sorted = insertionSort(numbers);
  for(int i = 0; i < sorted.size(); i++)
    cout << sorted[i] << endl;
    
  return 0;
} 
