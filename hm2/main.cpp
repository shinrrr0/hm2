#include <iostream>
#include <array>
#include <windows.h>

using namespace std;

template<typename type>
void print_arr(type*& arr, int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<typename type>
type* create_empty_arr(type type_example, int len) {
    type* tmp = new type[len];
    return tmp;
}

template<typename type>
void gen_arr_values(type*& arr, int& len) {
    for (int i = 0; i < len; i++) {
        cout << "¬ведите число: ";
        cin >> arr[i];
    }
}

template<typename type1, typename type2>
void insert_to(type1*& arr, type2 insert_val, int insert_to, int& len) {
    len += 1;
    cout << len;
    type1* tmp = new type1[5];
    cout << "_" << sizeof(tmp) / sizeof(tmp[0]) << "_";
    for (int i = 0; i < insert_to; i++) {
        tmp[i] = arr[i];
    }
   
    tmp[insert_to] = insert_val;
    
    for (int i = insert_to + 1; i < len; i++) {
        tmp[i] = arr[i - 1];
    }    
    swap(tmp, arr);
    delete[] tmp;
}

template<typename type1, typename type2>
void insert_arr_to(type1*& arr, int& len, type2*& arr1, int& len1, int insert_to) {
    type1* tmp = new type1[len + len1];
    for (int i = 0; i < insert_to; i++) {
        tmp[i] = arr[i];
    }
    for (int i = insert_to; i < insert_to + len1 + 1; i++) {
        tmp[i] = arr1[i - insert_to];
    }
    for (int i = insert_to + len1; i < len + len1; i++) {
        tmp[i] = arr[i - len1];
    }

    swap(tmp, arr);
    len += len1;
    delete[] tmp;
}


template<typename type1, typename type2>
void append(type1*& arr, type2 insert_val, int& len) {
    type1* tmp = new type1[len + 1];
    for (int i = 0; i < len; i++) {
        tmp[i] = arr[i];
    }
    tmp[len] = insert_val;
    swap(tmp, arr);
    len += 1;
    delete[] tmp;
}

template<typename type1>
void deleteend(type1*& arr, int& len) {
    type1* tmp = new type1[len - 1];
    for (int i = 0; i < len - 1; i++) {
        tmp[i] = arr[i];
    }
    swap(tmp, arr);
    len -= 1;
    delete[] tmp;
}

template<typename type1, typename type2>
void appstart(type1*& arr, type2 insert_val, int& len) {
    len += 1;
    type1* tmp = new type1[len + 1];
    tmp[0] = insert_val;
    for (int i = 0; i < len; i++) {
        tmp[i + 1] = arr[i];
    }
    swap(tmp, arr);
    delete[] tmp;
}

template<typename type1>
void deletestart(type1*& arr, int& len) {
    type1* tmp = new type1[len - 1];
    for (int i = 0; i < len - 1; i++) {
        tmp[i] = arr[i + 1];
    }
    swap(tmp, arr);
    len -= 1;
    delete[] tmp;
}

template<typename type>
void cut_off(type*& arr, int new_len, int& len) {
    type* tmp = new type[new_len];
    for (int i = 0; i < new_len; i++) {
        tmp[i] = arr[i];
    }
    swap(tmp, arr);
    len = new_len;
    delete[] tmp;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int len = 4;
    auto arr = create_empty_arr(1, len);
    gen_arr_values(arr, len);
    print_arr(arr, len);
    insert_to(arr, -12, 2, len);
    print_arr(arr, len);
    append(arr, -1, len);
    print_arr(arr, len);
    appstart(arr, -2, len);
    print_arr(arr, len);
    cut_off(arr, 3, len);
    print_arr(arr, len);

    int len1 = 3;
    double* arr1 = new double[len1] {1.1, 2.1, 3.1};
    insert_arr_to(arr, len, arr1, len1, 1);
    print_arr(arr, len);

    deleteend(arr, len);
    print_arr(arr, len);
    deletestart(arr, len);
    print_arr(arr, len);
    return 0;
}
