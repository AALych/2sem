#include <iostream>
#include <fstream>
#include <chrono>

void sort(int *arr, int size){
	for(int i=1;i<size;i++){
		for(int j=i; j>0 && arr[j-1]>arr[j];j--){
			int tmp=arr[j-1];
			arr[j-1]=arr[j];
			arr[j]=tmp;}
    };
}

vector<int> generate_random_vector(uint64_t n) {

    vector<int> ret(n);

    //это математически строгий и надежный способ генерировать случайные числа
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, max_value);

    for (int i = 0; i < n; ++i) {
        ret[i] = dist(gen);
    }

    return ret;
}

int main() {
        std::ofstream fout("Insert.csv");
        for (int N = 1024; N < 43100; N += 1024) {
                std::cout << "N = " << N << std::endl;
                int* arr = new int[N];
                for (int i = 0; i < N; i++) {
                        arr[i] = i;
                }

                auto start = std::chrono::high_resolution_clock::now();
                sort(arr, N);
                auto end = std::chrono::high_resolution_clock::now();
                auto nsec = end - start;
                fout << nsec.count() << std::endl;
                std::cout << "N = " << N << " done" << std::endl;
		delete[] arr;
        }
        fout.close();
        return 0;
}
