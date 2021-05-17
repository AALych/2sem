#include<vector>
#include<chrono>
#include<random>
#include<iostream>
#include<algorithm>
#include<cassert>
#include<fstream>

using namespace std;
using namespace std::chrono;

constexpr int max_value = 100000;

//символ "&" позволяет менять непосредственно ту переменную, которая передана в функцию
//как питоновский объект
//это замена указателя в современном c++
void bubble_sort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
        return;
}

void choices(vector<int>& arr, int size){
	for (int startIndex = 0; startIndex < size - 1; ++startIndex)
	{
		int smallestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex){
			if (arr[currentIndex] < arr[smallestIndex])
				smallestIndex = currentIndex;
		}
		std::swap(arr[startIndex], arr[smallestIndex]);
	}
	return;
}

void Insert(int* arr,int n){
	for(int i=1;i<n;i++){
		for(int j=i; j>0 && arr[j-1]>arr[j];j--){
			int tmp=arr[j-1];
			arr[j-1]=arr[j];
			arr[j]=tmp;
		}
	}
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


//это магическая строчка
//благодаря этому функция может принимать аргумент произвольного типа
//название для конкретно этого типа вы придумываете сами (я назвал его SortFunction)
template<typename SortFunction>
int benchmark(SortFunction f, uint64_t n) {

    auto v = generate_random_vector(n);

    auto start = steady_clock::now();
    //время засекается внутри этого блока
    f(v);
    auto finish = steady_clock::now();

    //это проверка на то, верно ли проведена сортировка
    //в случае ошибки программа падает с сообщением "assertion failed"
    assert(is_sorted(begin(v), end(v)));

    //возвращаем время работы в мс
    return duration_cast<milliseconds>(finish - start).count();
}

int main() {
    double time = 0;
    ofstream fout("Bubble_sort00.csv", ios_base::out);
    //fout << "iteration,time\n";

    for (int i = 1; i < 100; ++i){
        fout << 100*i << "," << (0 + benchmark(bubble_sort, 100*i)) << "\n";
        cout << "N = " << i*100 << " done" << endl;
    }
    fout.close(); // закрываем файл
    time = 0;

    return 0;
}
