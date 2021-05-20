#include <iostream>
#include <string>
#include <vector>
#include "algorithm"
using namespace std;


template <typename T>
T** AllocateDynamicArray(int nRows, int nCols)
{
    T** dynamicArray;

    dynamicArray = new T * [nRows];
    for (int i = 0; i < nRows; i++)
        dynamicArray[i] = new T[nCols];

    return dynamicArray;
}

template <typename T>
void FreeDynamicArray(T** dArray)
{
    delete[] * dArray;
    delete[] dArray;
}

template <typename T>
void print(T** dArray, int process_number, int resource_type)
{
    for (int i = 0; i < process_number; i++)
    {
        for (int j = 0; j < resource_type; j++) { cout << dArray[i][j] << " "; }
        cout << "\n";

    }
}

template <typename T>
void initializer(T** dArray, int process_number, int resource_type, const string& type_s)
{
    for (int i = 0; i < process_number; i++)
    {
        cout << "P" << i << " " << type_s << endl;
        for (int j = 0; j < resource_type; j++) { cin >> dArray[i][j]; }

    }
}

template <typename T>
string is_safe(T** allocation_mat, T** need_matrix, int avilable[], int process_number, int resource_type)
{
    int* work = avilable;
    string counter;
    int* counter_p = new int[process_number]; for (int i = 0; i < process_number; i++) { counter_p[i] = 0; }


    for (int f_counter = 0; f_counter < process_number; f_counter++)
    {

        for (int i = 0; i < process_number; i++) {


            if (counter_p[i] == 0) {
                int s_counter = 0;

                for (int j = 0; j < resource_type; j++) {

                    if (need_matrix[i][j] <= work[j]) {
                        s_counter++;
                    }

                    if (s_counter == resource_type) {

                        counter_p[i] = 1;
                        for (int m = 0; m < resource_type; m++)
                        {
                            work[m] += allocation_mat[i][m];
                        }
                        counter += "P" + to_string(i) + ",";

                    }
                }
            }
        }
    }
    bool flag = true;
    for (int i = 0; i < process_number; i++) { if (counter_p[i] == 0) { flag = false; break; } }
    counter = counter.substr(0, counter.size() - 1);

    if (flag) { counter = "Yes , Safe state<" + counter + ">"; }
    else (counter = "NO Safe");


    return counter;

}

template <typename T>
int check_req(T** allocation_mat, T** need_matrix, int avilable[], int process_number, int resource_type, int r_arr[], int r_p_number)
{

    bool flag = true;



    for (int i = 0; i < resource_type; i++)
    {
        if (r_arr[i] > need_matrix[r_p_number][i])
        {
            flag = false;
        }
    } //checking need

    for (int i = 0; i < resource_type; i++)
    {
        if (r_arr[i] > avilable[i])
        {
            flag = false;
        }
    } //checking available



    if (!flag)
    {
        cout << "No , Not Safe Request" << endl;
    }
    else

    {

        for (int i = 0; i < resource_type; i++)
        {
            need_matrix[r_p_number][i] -= r_arr[i];
            allocation_mat[r_p_number][i] += r_arr[i];
            avilable[i] -= r_arr[i];
        }


        string safe_string = is_safe(allocation_mat, need_matrix, avilable, process_number, resource_type);

        if (safe_string[0] == 'Y') {
            safe_string.erase(3, 13);

            safe_string.insert(3, " request can be granted with safe state , Safe state");

            safe_string.insert(56, "P" + to_string(r_p_number) + "req,");
        }
        else {
            safe_string = "NO Safe";
        }
        cout << safe_string << endl;
    }




    return 0;
}


void print_credits()
{
    int rows = 5;
    for (int i = rows; i >= 1; --i)
    {
        for (int space = 0; space < rows - i; ++space)
            cout << "  ";

        for (int j = i; j <= 2 * i - 1; ++j)
            cout << "* ";

        for (int j = 0; j < i - 1; ++j)
            cout << "* ";

        cout << endl;
    }


    cout << "CSE ASU 2022 - Computer and System Department " << endl;
    cout << "Banker's Algorithm Assignment" << endl;
    cout << "Mohamed Fathi Mohamed Razzk" << endl;
    cout << "Code : 16X0103" << endl;
    cout << "Sec : 4" << endl;




    for (int i = 1, k = 0; i <= rows; ++i, k = 0)
    {
        for (int t = 1; t <= rows - i; ++t)
        {
            cout << "  ";
        }

        while (k != 2 * i - 1)
        {
            cout << "* ";
            ++k;
        }
        cout << endl;
    }

}


void help()
{

    cout << " Welcome to that Simple instructions  " << endl;
    cout << " #If you wanna safe state Enter operation as \" safe \"  " << endl;
    cout << " #If you wanna request Enter operation as \" request \"  " << endl;
    cout << " #If you wanna Need Matrix Enter operation as \" print_need_matrix \"  " << endl;
    cout << " #If you wanna Allocation Matrix Enter operation as \" print_allocation_matrix \"  " << endl;
    cout << " #If you wanna Max Matrix Enter operation as \" print_max_matrix \"  " << endl;
    cout << " #If you wanna All Matrix *_* Enter operation as \" print_all \"  " << endl;
    cout << " #If you wanna start fresh Enter operation as \" new \"  " << endl;
    cout << " #If you wanna exit program  Enter operation as \" exit \"  " << endl;



}


int main()
{



    print_credits();



jump:
    int process_number;
    cout << "Please Enter the Number of Process" << endl;
    cin >> process_number;

    int resource_type;
    cout << "Please Enter the Number of Recourse type" << endl;
    cin >> resource_type;

    int** allocation_mat = AllocateDynamicArray<int>(process_number, resource_type);  // allocation matriex
    cout << "Please Enter the Resource Allocation in Order For each Process" << endl;
    initializer(allocation_mat, process_number, resource_type, "Allocation");

    int** max_matrex = AllocateDynamicArray<int>(process_number, resource_type);  // max_matrex matriex
    cout << "Please Enter the Resource Max in Order For each Process" << endl;
    initializer(max_matrex, process_number, resource_type, "Resource Max");

    int* avilable = new int[resource_type];                           //avilable allocation
    cout << "Please Enter the Resource Avilable in Order " << endl;
    for (int i = 0; i < resource_type; i++) { cin >> avilable[i]; }


    int** need_matrix = AllocateDynamicArray<int>(process_number, resource_type);  // max_matrex matriex
    for (int i = 0; i < process_number; i++) {
        for (int j = 0; j < resource_type; j++) { need_matrix[i][j] = max_matrex[i][j] - allocation_mat[i][j]; }
    }

    int r_p_number;
    int* r_arr = new int[resource_type];


    string operation;

    cout << "########## For Help and Instructions  Write #help as operation #############" << endl;

    while (true) {

        cout << "Please Enter Operation" << endl;
        cin >> operation;
        transform(operation.begin(), operation.end(), operation.begin(), ::tolower);

        if (operation == "safe") { cout << is_safe(allocation_mat, need_matrix, avilable, process_number, resource_type) << endl; }

        else if (operation == "request")
        {
            cout << "Please Enter Process Number" << endl;
            cin >> r_p_number;
            cout << "Please Enter Request Allocation in Order " << endl;
            for (int i = 0; i < resource_type; i++) { cin >> r_arr[i]; }

            check_req(allocation_mat, need_matrix, avilable, process_number, resource_type, r_arr, r_p_number);


        }
        else if (operation == "print_need_matrix") { print(need_matrix, process_number, resource_type); }
        else if (operation == "print_allocation_matrix") { print(allocation_mat, process_number, resource_type); }
        else if (operation == "print_max_matrix") { print(max_matrex, process_number, resource_type); }
        else if (operation == "new") { goto jump; }
        else if (operation == "exit") { goto exitt; }
        else if (operation == "help") { help(); }
        else if (operation == "print_all")

        {
            cout << " #-------- Allocation Matrix --------#  " << endl;
            print(allocation_mat, process_number, resource_type);
            cout << " #----------------------------#  " << endl;

            cout << " #-------- Max Matrix --------#  " << endl;
            print(max_matrex, process_number, resource_type);
            cout << " #----------------------------#  " << endl;

            cout << " #-------- Need Matrix --------#  " << endl;
            print(need_matrix, process_number, resource_type);
            cout << " #----------------------------#  " << endl;


        }






        else { cout << "Please Check Operation Name "; }
    }

exitt:
    FreeDynamicArray<int>(allocation_mat);
    FreeDynamicArray<int>(max_matrex);
    FreeDynamicArray<int>(need_matrix);

    return 0;
}