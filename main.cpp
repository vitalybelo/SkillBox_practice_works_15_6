#include <iostream>
#include <vector>
using namespace std;

void printArray (vector<int>& array);
bool entryDataArray (vector<int>& array);

int main() {
    setlocale(LC_ALL, "Russian_Russia.1251");

    vector<int> array;
    while (entryDataArray(array)) {

        if (array.size() < 5) {
            cout << "��� 5-�� �������� :: ";
        } else {
            cout << "����� ������� = " << array[4] << " :: ";
        }
        printArray(array);
    };
    cout << "���������� ���������\n";
    return 0;
}

/**
 * ������� � ������ �������� �������
 * @param array - ������ �������� ��� �����������
 */
void printArray (vector<int>& array) {
    cout << "{";
    for (int i: array) cout << i << ",";
    cout << "}\n";
}

/**
 * ���� ������ � ������. ������ ��������� �������� ��������
 * �� ������ ����� � ������� ������� ������ �������� �������
 * ������ ����������, � ����� ������ ����������� �� �����������
 * @param array - ����������� �� ������ ����������
 * @return - ������ ��� ���� ���������� ���������
 */
bool entryDataArray (vector<int>& array) {
    int inputValue;
    cout << "����: ";
    do {
        cin >> inputValue;
        if (inputValue >= 0) {
            if (array.empty() || array[array.size() - 1] <= inputValue) {
                array.push_back(inputValue);
            } else {
                for (auto iter = array.begin(); iter < array.end(); iter++)
                    if (inputValue <= *iter) {
                        array.insert(iter,1,inputValue);
                        break;
                    }
            }
        }
    } while (inputValue >= 0);
    return (inputValue != -2);
}
