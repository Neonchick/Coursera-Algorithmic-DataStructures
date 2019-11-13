#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int> &numbers) {
    int max_1 = 0,max_2=-1;
    int n = numbers.size();

    for (int i = 0; i < n; ++i) 
        if (numbers[i]>numbers[max_1])
    		max_1=i;
	for (int i = 0; i < n; ++i) 
        if (i!=max_1 && (max_2==-1 || numbers[i]>numbers[max_2]))
    		max_2=i;
    return (long long)numbers[max_1]*numbers[max_2];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    std::cout << MaxPairwiseProduct(numbers);
    return 0;
}
