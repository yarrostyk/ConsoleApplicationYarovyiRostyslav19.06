#include <iostream>
#include <fstream>

using namespace std;

//int main()
//{
//    ifstream fin("numbers.txt");
//    ofstream fout("stats.txt");
//
//    if (!fin || !fout) {
//        cerr << "we have a problem!" << endl;
//    }
//
//    int count = 0;
//    double sum = 0;
//    int numbers[100];
//
//    while (fin >> numbers[count]) {
//        sum += numbers[count];
//
//        if (numbers[count] % 2 == 0) {
//            fout << "even: " << numbers[count] << endl;
//        }
//
//        fout << "--------------------------------------------------" << endl;
//
//        if (numbers[count] % 2 != 0) {
//            fout << "odd: " << numbers[count] << endl;
//        }
//
//        count++;
//
//        if (count >= 100) {
//            break;
//        }
//        
//    }
//
//    double total1 = numbers[0];
//    for (int i = 1; i < count; i++) {
//        if (numbers[i] > total1) {
//            total1 = numbers[i];
//        }
//    }
//
//    double total2 = numbers[0];
//    for (int i = 1; i < count; i++) {
//        if (numbers[i] < total2) {
//            total2 = numbers[i];
//        }
//    }
//
//    double average = sum / count;
//
//    fout << "count: " << count << endl;
//    fout << "sum: " << sum << endl;
//    fout << "avarage: " << average << endl;
//    fout << "max: " << total1 << endl;
//    fout << "min: " << total2 << endl;
//
//    fin.close();
//    fout.close();
//
//    return 0;
//}




// Додаткове завдання

int is_simple(int n) {
	if (n < 2) {
		return 0;
	}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return 0;
		}
		return 1;
	}
}

void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	ifstream fin("numbers.txt");
	ofstream fout("sorted.txt");

	if (!fin || !fout) {
		cerr << "We have a problem!" << endl;
	}

	int arr[1000];
	int count = 0;

	while (fin >> arr[count]) {
		count++;
	}

	cout << "Simple numbers:\n";
	for (int i = 0; i < count; i++) {
		if (is_simple(arr[i]) == 1) {
			cout << arr[i] << " ";
		}
	}
	cout << endl;

	int k;
	cout << "Enter k: ";
	cin >> k;

	for (int i = 0; i < count; i++) {
		if (arr[i] % k == 0) {
			cout << arr[i] << " ";
		}
	}
	cout << endl;

	bubbleSort(arr, count);

	fout << "Sorted numbers:\n";
	for (int i = 0; i < count; i++) {
		fout << arr[i] << " ";
	}
	fout << endl;

	fin.close();
	fout.close();

    cout << "---" << endl;

	return 0;
}