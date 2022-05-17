#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;
struct Sluzbuvets
{
    string LastName;
    string Initials;
    string Posada;
    int Year;
    int Fee;
};
void Create(Sluzbuvets* arr, int& size);
void AutoCreate(Sluzbuvets* arr, int& size);
void StartMenu(Sluzbuvets* arr, int& size);
void Print(Sluzbuvets* arr, int& size);
Sluzbuvets* Add(Sluzbuvets* arr, int& size);
Sluzbuvets* Remove(Sluzbuvets* arr, int& size);
void Change(Sluzbuvets* arr, int& size);
void Find(Sluzbuvets* arr, int& size);
void Sort(Sluzbuvets* arr, int& size);

int main()
{
    cout << "Enter list size:"; int size; cin >> size;
    Sluzbuvets* arr = new Sluzbuvets[size];
    StartMenu(arr, size);
    system("pause");
    return 0;
}
void StartMenu(Sluzbuvets* arr, int& size)
{
    bool initialized = false;
    int ch;
    do
    {
        {
            cout << "-------Menu------" << endl;
            cout << "1.Create list" << endl;
            cout << "2.Print list" << endl;
            cout << "3.Add" << endl;
            cout << "4.Remove" << endl;
            cout << "5.Change" << endl;
            cout << "6.Sort" << endl;
            cout << "7.Search" << endl;
            cout << "8.Clear screen" << endl;
            cout << "10.Exit" << endl;
            cout << "-------------------" << endl;
        }
        cout << "Enter you choice: "; cin >> ch;
        switch (ch)
        {

        case 1:
        {
            initialized = true;
            AutoCreate(arr, size);
            break;
        }
        case 2:
        {
            if (!initialized)
                cout << "You try to do operatons with a not initialized array!" << endl;
            else  Print(arr, size);

            break;
        }
        case 3:
        {
            if (!initialized)
                cout << "You try to do operatons with a not initialized array!" << endl;
            else arr = Add(arr, size);
            break;
        }
        case 4:
        {
            if (!initialized)
                cout << "You try to do operatons with a not initialized array!" << endl;
            else arr = Remove(arr, size);
            break;
        }
        case 5:
        {
            if (!initialized)
                cout << "You try to do operatons with a not initialized array!" << endl;
            else Change(arr, size);
            break;
        }
        case 6:
        {
            if (!initialized)
                cout << "You try to do operatons with a not initialized array!" << endl;
            else Sort(arr, size);
            break;
        }
        case 7:
        {
            if (!initialized)
                cout << "You try to do operatons with a not initialized array!" << endl;
            else Find(arr, size);
            break;
        }
        case 8:
        {
            system("cls");
            break;
        }
        default:
            break;
        }
    } while (ch <= 9);
}

void Create(Sluzbuvets* arr, int& size)
{
    for (size_t i = 0; i < size; i++)
    {
        Sluzbuvets sl;
        cout << "Last name: "; cin >> sl.LastName;
        cout << "Initials: "; cin >> sl.Initials;
        cout << "Posada: "; cin >> sl.Posada;
        cout << "Year: "; cin >> sl.Year;
        cout << "Fee: "; cin >> sl.Fee;
        arr[i] = sl;
    }
}

void AutoCreate(Sluzbuvets* arr, int& size)
{
    string InitialVector[] = { "O.I","T.K","L.Y","M.O","J.D","X,Y","O.E","A.I","L.I","K.E","V.V","I.V","A.B","C.D" };
    string LastNames[] = { "Smith","Johnson","Williams","Brown","Jones","Davis","Miller","Wilson","Moore","Taylor","Anderson","Thomas"};
    string posada[] = { "Event-manager","HR ","Brand-manager","PM","Architect","System Admin","TeamLead","Trainee","Junior ","Frontend Dev" };
    for (size_t i = 0; i < size; i++)
    {
        arr[i].Initials = InitialVector[rand() % 14];
        arr[i].LastName = LastNames[rand() % 12];
        arr[i].Fee = (2000 + rand() % 4000); arr[i].Fee -= (arr[i].Fee % 100);
        arr[i].Posada = posada[rand() % 10];
        arr[i].Year = 2000 + rand() % 15;
    }
}

void Print(Sluzbuvets* arr, int& size)
{
    cout << "-----------------------------------------------------------------" << endl;
    cout << "N\t|Last Name     |Initials|Posada        |Fee\t|Year\t|" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << i << "\t|";
        cout << arr[i].LastName << setw(15 - arr[i].LastName.size()) << "|";
        cout << arr[i].Initials << "\t|";
        cout << arr[i].Posada << setw(15 - arr[i].Posada.size()) << "|";
        cout << arr[i].Fee << "\t|";
        cout << arr[i].Year << "\t|";
        cout << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
}

Sluzbuvets* Add(Sluzbuvets* arr, int& size)
{
    Sluzbuvets sl;
    cout << "Last name: "; cin >> sl.LastName;
    cout << "Initials: "; cin >> sl.Initials;
    cout << "Posada: "; cin >> sl.Posada;
    cout << "Year: "; cin >> sl.Year;
    cout << "Fee: "; cin >> sl.Fee;
    Sluzbuvets* arr2 = new Sluzbuvets[size + 1];
    for (size_t i = 0; i < size; i++)
    {
        arr2[i] = arr[i];
    }
    arr2[size] = sl;
    size++;
    return arr2;
}

Sluzbuvets* Remove(Sluzbuvets* arr, int& size)
{
    Sluzbuvets* arr2 = new Sluzbuvets[size - 1];
    cout << "Enter the index of a worker which you want to remove: ";
    int index = 0; cin >> index;
    if (index < size)
    {
        cout << "-----------------------------------------------------------------" << endl;
        cout << "N\t|Last Name     |Initials|Posada        |Fee\t|Year\t|" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cout << index << "\t|";
        cout << arr[index].LastName << setw(15 - arr[index].LastName.size()) << "|";
        cout << arr[index].Initials << "\t|";
        cout << arr[index].Posada << setw(15 - arr[index].Posada.size()) << "|";
        cout << arr[index].Fee << "\t|";
        cout << arr[index].Year << "\t|";
        cout << endl;
        cout << "------------------------------------------------------------------" << endl;

    }
    else cout << "There is no worker with the number " << index << endl;
    bool moved = false;
    for (size_t i = 0; i < size - 1; i++)
    {

        if (i == index)  	moved = true;
        if (moved)	arr2[i] = arr[i + 1];
        else	arr2[i] = arr[i];
    }
    size--;
    return arr2;

}

void Change(Sluzbuvets* arr, int& size)
{
    cout << "Enter the index of a worker which you want to change: ";
    int index = 0; cin >> index;
    if (index < size)
    {
        cout << "-----------------------------------------------------------------" << endl;
        cout << "N\t|Last Name     |Initials|Posada        |Fee\t|Year\t|" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cout << index << "\t|";
        cout << arr[index].LastName << setw(15 - arr[index].LastName.size()) << "|";
        cout << arr[index].Initials << "\t|";
        cout << arr[index].Posada << setw(15 - arr[index].Posada.size()) << "|";
        cout << arr[index].Fee << "\t|";
        cout << arr[index].Year << "\t|";
        cout << endl;
        cout << "-----------------------------------------------------------------" << endl;
        Sluzbuvets sl;
        cout << "Last name: "; cin >> sl.LastName;
        cout << "Initials: "; cin >> sl.Initials;
        cout << "Posada: "; cin >> sl.Posada;
        cout << "Year: "; cin >> sl.Year;
        cout << "Fee: "; cin >> sl.Fee;
        arr[index] = sl;
    }
    else cout << "There is no worker with the number " << index << endl;
}

void Find(Sluzbuvets* arr, int& size)
{
    cout << "Last name ofa worker which u want to find: ";
    string ln; cin >> ln;
    int index = -1;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i].LastName == ln)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        cout << "-----------------------------------------------------------------" << endl;
        cout << "N\t|Last Name     |Initials|Posada        |Fee\t|Year\t|" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cout << index << "\t|";
        cout << arr[index].LastName << setw(15 - arr[index].LastName.size()) << "|";
        cout << arr[index].Initials << "\t|";
        cout << arr[index].Posada << setw(15 - arr[index].Posada.size()) << "|";
        cout << arr[index].Fee << "\t|";
        cout << arr[index].Year << "\t|";
        cout << endl;
        cout << "------------------------------------------------------------------" << endl;

    }
    else
    {
        cout << "Sorry but the worker with last name " << ln << "doe not exist in this company." << endl;
    }
}


void Sort(Sluzbuvets* arr, int& size)
{
    system("cls");
    cout << "---------- Sort -----------" << endl;
    cout << "1.Sort by Last name" << endl;
    cout << "2.Sort by fee" << endl;
    cout << "3.Sort by year" << endl;
    cout << "4.Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice:"; int choice; cin >> choice;
    switch (choice)
    {
    case 1:
    {
        for (size_t i = 0; i < size - 1; i++)
            for (size_t j = 0; j < size - i - 1; j++)
                if (arr[j].LastName > arr[j + 1].LastName)
                    swap(arr[j], arr[j + 1]);
        break;
    }
    case 2:
    {
        for (size_t i = 0; i < size - 1; i++)
            for (size_t j = 0; j < size - i - 1; j++)
                if (arr[j].Fee < arr[j + 1].Fee)
                    swap(arr[j], arr[j + 1]);
        break;
    }
    case 3:
    {
        for (size_t i = 0; i < size - 1; i++)
            for (size_t j = 0; j < size - i - 1; j++)
                if (arr[j].Year < arr[j + 1].Year)
                    swap(arr[j], arr[j + 1]);
        break;
    }
    default:
        return;
    }
}
