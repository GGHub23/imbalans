#include<iostream>  
#include<Windows.h>  
#include<iomanip>  
#include<cmath>  
#include<string>  




//аккаунты  
bool isAdmin = false;
int userCount = 2;
std::string* loginArr = new std::string[userCount]{ "admin","user" };
std::string* passArr = new std::string[userCount]{ "admin","user" };

//склад  
int size = 10;
int* IDArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];
//Касса
double cash = 7520.0;
double cashMoney{};
double webMoney{};
//чек
int checkSize = 1;
std::string* nameCheckArr = new std::string[checkSize];
int* countCheckArr = new int[checkSize];
double* priceCheckArr = new double[checkSize];
double* totalPriceCheckArr = new double[checkSize];

void Start();
bool Login();
bool IsNumber(std::string);
void CreateStaticStorage();
void ShowAdminMenu();
void ShowUserMenu();
void ShowStorage(int mode = 0);
void RefillProduct();
void Getline(std::string& stringname);
int Getid(int mode = 0);
void RemoveProduct();
void ChangePrice();
void ChangeStorage();

void AddNewProduct();
void EditProduct();
void DeleteProduct();

void ChangeEmployee();
void AddNewEmployee();
void EditEmployee();
void DeleteEmployee();
void Selling();
void AddNewCheckSize();

template<typename Arr>
void FillStorage(Arr staticArr[], Arr dynamicarr[], int staticSize);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Start();
    setlocale(LC_ALL, "ru");
    delete[]loginArr;
    delete[]passArr;
    delete[]IDArr;
    delete[]nameArr;
    delete[]countArr;
    delete[]priceArr;
    delete[]totalPriceCheckArr;
    delete[]nameCheckArr;
    delete[]countCheckArr;
    delete[]priceCheckArr;

    return(0);



}

void Start() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "\t\t ИМБАланс  \n\n";
    if (Login() == true)
    {
        if (isAdmin == true)
        {
            std::string choose;
            while (true)
            {
                std::cout << "1 - Использовать готовый склад" << "\n" << "2 - Создать склад" << "\n" << "Ввод : ";
                Getline(choose);
                if (choose == "1") {
                    CreateStaticStorage();
                    break;

                }
                else if (choose == "2")
                {
                    //динамический склад  
                    break;
                }
                else {
                    std::cout << "\n\nОшибка ввода\n\n";
                }
            }

            ShowAdminMenu();
        }
        else
        {
            CreateStaticStorage();
        }
    }
    else
    {
        std::cerr << "LoginErr\n";
    }
}

bool Login() {
    std::string login, pass;
    while (true)
    {
        std::cout << "Введите логин:";
        Getline(login);
        std::cout << "Введите пароль:";
        Getline(pass);
        if (login == loginArr[0] && pass == passArr[0])
        {
            std::cout << "Авторизация пользователя:" << loginArr[0] << '\n';
            isAdmin = true;
            return true;
        }

        for (int i = 1; i < userCount; i++) {
            if (login == loginArr[i] && pass == passArr[i])
            {
                std::cout << "Авторизация пользователя:" << loginArr[i] << "\n";
                isAdmin = false;
                return true;
            }

        }
        system("cls");
        std::cout << "Неверный логин или пароль\n\n";
    }
}

void CreateStaticStorage()
{
    const int TempSize = 10;
    int TempId[TempSize]{ 1,2,3,4,5,6,7,8,9,10 };
    std::string TempName[TempSize]
    {
        "Шейх",
        "Стандарт",
        "ГГ сердечку",
        "Dorime(со вкусом прощения)",
        "Имба на кислом молоке(акция)",
        "Любой вкус(не крафтовый)",
        "Крафтовый вкус",
        "Типичное утро студента", "Работа,работа", "Имба из бабушки"
    };
    int TempCount[TempSize]{ 9,50,3,1,5,16,49,78,2,6 };
    double TempPrice[TempSize]{ 10000.0,990.0,2000.0,1500.0,100.0,200.0,1600.0,200.0,990.0,3600.0 };
    FillStorage(TempId, IDArr, TempSize);
    FillStorage(TempName, nameArr, TempSize);
    FillStorage(TempCount, countArr, TempSize);
    FillStorage(TempPrice, priceArr, TempSize);

}

void ShowAdminMenu()
{
    std::string choose;
    while (true)
    {
        system("cls");
        std::cout << "\n" << "1 - начать продажу \n";
        std::cout << "2 - показать склад \n";
        std::cout << "3 - пополнить склад \n";
        std::cout << "4 - списать со склада \n";
        std::cout << "5 - изменить цену \n";
        std::cout << "6 - изменить склад \n";
        std::cout << "7 - изменение сотрудников \n";
        std::cout << "8 - отчёт о прибыли \n";
        std::cout << "0 - закрыть смену \n";
        std::cout << "\nВвод: ";
        Getline(choose);
        if (choose == "1")
        {
            Selling();
        }
        else if (choose == "2")
        {
            ShowStorage();
        }
        else if (choose == "3")
        {
            RefillProduct();
        }
        else if (choose == "4")
        {
            RemoveProduct();
        }
        else if (choose == "5")
        {
            ChangePrice();
        }
        else if (choose == "6")
        {
            ChangeStorage();
        }
        else if (choose == "7")
        {
            ChangeEmployee();
        }
        else if (choose == "8")
        {

        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "\n Ошибка ввода \n";
            Sleep(500);
        }
    }

}

void ShowUserMenu()
{
    std::string choosestr;
    while (true)
    {
        system("cls");
        std::cout << "\n1 - начать продажу \n";
        std::cout << "2 - показать склад \n";
        std::cout << "3 - пополнить склад \n";
        std::cout << "4 - списать со склада \n";
        std::cout << "5 - изменить цену \n";
        std::cout << "8 - отчёт о прибыли \n";
        std::cout << "0 - закрыть смену \n";
        std::cout << "Ввод: ";
        Getline(choosestr);
        if (choosestr == "1")
        {

        }
        else if (choosestr == "2")
        {

        }
        else if (choosestr == "3")
        {

        }
        else if (choosestr == "4")
        {

        }
        else if (choosestr == "5")
        {

        }
        else if (choosestr == "6")
        {

        }
        else if (choosestr == "7")
        {

        }
        else if (choosestr == "8")
        {

        }
        else if (choosestr == "0")
        {
            break;
        }
        else
        {
            std::cout << "\n Ошибка ввода \n";
            Sleep(500);
        }

    }
}

void ShowStorage(int mode)
{
    system("cls");
    if (mode == 0)
    {
        std::cout << "\nID\t" << std::left << std::setw(25) << "Название\t" << "Кол-во\t" << "Цена\n";

        for (int i = 0; i < size; i++)
        {
            std::cout << IDArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << countArr[i] << "\t" << priceArr[i] << "\n";
        }
        std::cout << "\n\n";
    }
    else if (mode == 1)
    {
        std::cout << "\nID\t" << std::left << std::setw(25) << "Название\t" << "Кол-во\n";

        for (int i = 0; i < size; i++)
        {
            std::cout << IDArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << countArr[i] << "\n";
        }
        std::cout << "\n\n";
    }
    else if (mode == 2)
    {
        std::cout << "\nID\t" << std::left << std::setw(25) << "Название\t" << "Цена\n";

        for (int i = 0; i < size; i++)
        {
            std::cout << IDArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << priceArr[i] << "\n";
        }
        std::cout << "\n\n";
    }
    else if (mode == 3)
    {
        std::cout << "\nID\t" << std::left << std::setw(25) << "Название\t" << "\n";

        for (int i = 0; i < size; i++)
        {
            std::cout << IDArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << "\n";
        }
        std::cout << "\n\n";
    }
    else
    {
        std::cerr << "\nMenuModeError\n";
    }
    system("pause");

}

void RefillProduct()
{
    std::string choose, chooseCount;
    int id = 0, count;

    while (true)
    {
        std::cout << "1 - начать\n" << "0 - отмена\n\nВвод: ";
        Getline(choose);
        if (choose == "1")
        {
            ShowStorage(1);
            id = Getid();
            while (true)
            {
                std::cout << "Введите кол-во товара для пополнения: ";
                Getline(chooseCount);
                if (IsNumber(chooseCount))
                {
                    count = std::stoi(chooseCount);
                    if (count > 0 && count <= 1000)
                    {
                        countArr[id - 1] += count;
                        std::cout << "\n\nТовар успешно пополнен";
                        Sleep(800);
                        break;
                    }
                    else
                    {
                        std::cout << "\nНекорректное айди\n";
                    }
                }
                {
                    std::cout << "\nОшибка Ввода\n";
                }
            }
        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "\nОшибка ввода\n";
        }

    }

}

void Getline(std::string& stringname)
{
    std::getline(std::cin, stringname, '\n');
}

int Getid(int mode)
{
    std::string stringid;
    int result{};
    int currentSize = 0;
    if (mode == 1)
    {
        currentSize = userCount;
    }
    else if (mode == 0)
    {
        currentSize = size;
    }
    while (true)
    {
        std::cout << "Введите ID товара: ";
        Getline(stringid);
        if (IsNumber(stringid))
        {
            result = std::stoi(stringid);
            if (result > 0 && result <= currentSize)
            {
                return result;
            }
            else
            {
                std::cout << "\nНекорректное айди\n";
            }
        }
        else
        {
            std::cout << "\nОшибка Ввода\n";
        }
    }
}

void RemoveProduct()
{
    std::string choose, chooseCount;
    int id = 0, count;

    while (true)
    {
        std::cout << "1 - начать\n" << "0 - отмена\n\nВвод: ";
        Getline(choose);
        if (choose == "1")
        {
            ShowStorage(1);
            id = Getid();
            while (true)
            {
                std::cout << "Введите кол-во товара для списания: ";
                Getline(chooseCount);
                if (IsNumber(chooseCount))
                {
                    count = std::stoi(chooseCount);
                    if (count >= 0 && count <= countArr[id - 1])
                    {
                        countArr[id - 1] -= count;
                        std::cout << "\n\nТовар успешно списан";
                        Sleep(800);
                        break;
                    }
                    else
                    {
                        std::cout << "\nНекорректное айди\n";
                    }
                }
                {
                    std::cout << "\nОшибка Ввода\n";
                }
            }
        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "\nОшибка ввода\n";
        }

    }

}

void ChangePrice()
{
    std::string choose, choosePrice;
    int id = 0;
    double price;

    while (true)
    {
        std::cout << "1 - начать\n" << "0 - отмена\n\nВвод: ";
        Getline(choose);
        if (choose == "1")
        {
            ShowStorage(2);
            id = Getid();
            while (true)
            {
                std::cout << "Введите кол-во товара для пополнения: ";
                Getline(choosePrice);
                if (IsNumber(choosePrice))
                {
                    price = std::stoi(choosePrice);
                    if (price > 0 && price <= 10000.0)
                    {
                        priceArr[id - 1] += price;
                        std::cout << "\n\nЦена успешно изменнеа";
                        Sleep(800);
                        break;
                    }
                    else
                    {
                        std::cout << "\nНекорректное айди\n";
                    }
                }
                {
                    std::cout << "\nОшибка Ввода\n";
                }
            }
        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "\nОшибка ввода\n";
        }

    }

}

void ChangeStorage()
{
    system("cls");
    std::string choose;
    while (true)
    {
        std::cout << "1 - добавление нового товара\n" << "2 - редактирования\n3 - Удаление товара\n0 - Отмена\n Ввод: ";
        Getline(choose);
        if (choose == "1")
        {
            AddNewProduct();
        }
        else if (choose == "2")
        {
            EditProduct();
        }
        else if (choose == "3")
        {
            DeleteProduct();
        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "\nОшибка ввода\n";
        }


    }
}

void AddNewProduct()
{
    std::string choose, nameStr, priceStr, countStr;
    while (true)
    {
        system("cls");
        std::cout << "1 - начать\n" << "0 - отмена\n\nВвод: ";
        Getline(choose);
        if (choose == "1")
        {
            int* tempID = new int[size];
            int* tempCount = new int[size];
            double* tempPrice = new double[size];
            std::string* tempName = new std::string[size];

            for (int i = 0; i < size; i++)
            {
                tempID[i] = IDArr[i];
                tempCount[i] = countArr[i];
                tempPrice[i] = priceArr[i];
                tempName[i] = nameArr[i];
            }
            delete[]IDArr;
            delete[]nameArr;
            delete[]countArr;
            delete[]priceArr;

            size++;
            
            IDArr = new int[size];
            countArr = new int[size];
            priceArr = new double[size];
            nameArr = new std::string[size];
            for (int i = 0; i < size - 1; i++)
            {
                IDArr[i] = tempID[i];
                countArr[i] = tempCount[i];
                priceArr[i] = tempPrice[i];
                nameArr[i] = tempName[i];
            }

            while (true)
            {
                std::cout << "Введите название нового товара: ";
                Getline(nameStr);
                if (nameStr.size() <= 60 && nameStr.size() > 1)
                {
                    nameArr[size - 1] = nameStr;
                    break;
                }
                else
                {
                    std::cout << "\nОшибка ввода\n";
                }
            }

            while (true)
            {
                std::cout << "Введите кол-во нового товара: ";
                Getline(countStr);
                if (IsNumber(countStr))
                {
                    if (std::stoi(countStr) >= 0 && std::stoi(countStr) <= 1000)
                    {
                        countArr[size - 1] = std::stoi(countStr);
                        break;
                    }
                }
                else
                {
                    std::cout << "\nОшибка ввода\n";
                }
            }

            while (true)
            {
                std::cout << "Введите цену нового товара: ";
                Getline(priceStr);
                if (IsNumber(priceStr))
                {
                    if (std::stod(priceStr) >= 0 && std::stod(priceStr) <= 10000.0)
                    {
                        priceArr[size - 1] = std::stod(priceStr);
                        break;
                    }
                }
                else
                {
                    std::cout << "\nОшибка ввода\n";
                }
            }

            IDArr[size - 1] = size;

            std::cout << IDArr[size - 1] << "\t" << std::left << std::setw(30) << nameArr[size - 1] << "\t"
                << countArr[size - 1] << "\t" << priceArr[size - 1] << "\n\n";

            delete[] tempCount;
            delete[] tempID;
            delete[] tempName;
            delete[] tempPrice;

            Sleep(2000);
        }
        else if (choose == "2")
        {

        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "\nОшибка ввода\n";
        }
    }
}

void EditProduct()
{
    std::string choose, newName;
    int id{};
    while (true)
    {
        system("cls");
        ///
        std::cout << "1-начать\n 0 - отмена \n \n ВВод :";
        Getline(choose);
        if (choose == "1")
        {
            ShowStorage(3);
            id = Getid();
            while (true)
            {
                std::cout << "Введите название нового товара: ";
                Getline(newName);
                if (newName.size() <= 60 && newName.size() > 1)
                {
                    nameArr[id - 1] = newName;
                    break;
                }
                std::cout << "\nОшибка ввода. От 2 до 60 символов\n";
            }
            std::cout << "\nНазвание измененно\n";
            Sleep(2000);
        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "\nОшибка ввода\n";
        }


    }
}

void DeleteProduct()
{
    std::string choose;
    int id;
    while (true)
    {
        system("cls");
        std::cout << "1 - начать\n" << "0 - отмена\n\nВвод: ";
        Getline(choose);
        if (choose == "1")
        {
            ShowStorage();
            int* tempID = new int[size];
            int* tempCount = new int[size];
            double* tempPrice = new double[size];
            std::string* tempName = new std::string[size];

            for (int i = 0; i < size; i++)
            {

                tempID[i] = IDArr[i];
                tempCount[i] = countArr[i];
                tempPrice[i] = priceArr[i];
                tempName[i] = nameArr[i];

            }
            delete[]IDArr;
            delete[]nameArr;
            delete[]countArr;
            delete[]priceArr;

            size--;

            IDArr = new int[size];
            countArr = new int[size];
            priceArr = new double[size];
            nameArr = new std::string[size];

            id = Getid();

            for (int i = 0, j = 0; i < size, j < size + 1; i++, j++)
            {
                if (j == id - 1)
                {
                    j++;
                    IDArr[i] = tempID[i];
                    countArr[i] = tempCount[j];
                    priceArr[i] = tempPrice[j];
                    nameArr[i] = tempName[j];
                }
                else
                {
                    IDArr[i] = tempID[i];
                    countArr[i] = tempCount[j];
                    priceArr[i] = tempPrice[j];
                    nameArr[i] = tempName[j];
                }
            }

            std::cout << "\nТовар удалён\n";


            
            delete[] tempCount;
            delete[] tempID;
            delete[] tempName;
            delete[] tempPrice;

            Sleep(2000);
        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "\nОшибка ввода\n";
        }
    }

}

void ChangeEmployee()
{
    std::string choose;
    while (true)
    {
        system("cls");
        std::cout << "1 - добавление нового сотрудника\n" << "2 - редактирования\n3 - Удаление сотрудника\n0 - Отмена\n Егор: ";
        Getline(choose);
        if (choose == "1")
        {
            AddNewEmployee();
        }
        else if (choose == "2")
        {
            ChangeEmployee();
        }
        else if (choose == "3")
        {
            DeleteEmployee();
        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "\nОшибка Егора\n";
        }


    }
}
void EditEmployee()
{
}

void AddNewEmployee()
{
    std::string choose, newLogin, newPass,priceStr,nameStr,countStr;
    while (true)
    {
        system("cls");
        std::cout << "1 - начать\n" << "0 - отмена\n\nЕгор: ";
        Getline(choose);
        if (choose == "1")
        {
            std::string *tempLogin = new std::string[userCount];
            std::string *tempPass = new std::string[userCount];

            for (int i = 0; i < userCount; i++)
            {
                tempLogin[i] = loginArr[i];
                tempPass[i] = passArr[i];

            }
            delete[]loginArr;
            delete[]passArr;


            userCount++;

            loginArr = new std::string[userCount];
            passArr = new std::string[userCount];


            for (int i = 0; i < userCount- 1; i++)
            {
                loginArr[i] = tempLogin[i];
                passArr[i] = tempPass[i];
            }
            ///тута всё
            while (true)
            {
                std::cout << "Введите название нового товара: ";
                Getline(nameStr);
                if (nameStr.size() <= 60 && nameStr.size() > 1)
                {
                    nameArr[size - 1] = nameStr;
                    break;
                }
                else
                {
                    std::cout << "\nОшибка ввода\n";
                }
            }

            while (true)
            {
                std::cout << "Введите кол-во нового товара: ";
                Getline(countStr);
                if (IsNumber(countStr))
                {
                    if (std::stoi(countStr) >= 0 && std::stoi(countStr) <= 1000)
                    {
                        countArr[size - 1] = std::stoi(countStr);
                        break;
                    }
                }
                else
                {
                    std::cout << "\nОшибка ввода\n";
                }
            }

            while (true)
            {
                std::cout << "Введите цену нового товара: ";
                Getline(priceStr);
                if (IsNumber(priceStr))
                {
                    if (std::stod(priceStr) >= 0 && std::stod(priceStr) <= 10000.0)
                    {
                        priceArr[size - 1] = std::stod(priceStr);
                        break;
                    }
                }
                else
                {
                    std::cout << "\nОшибка ввода\n";
                }
            }

            IDArr[size - 1] = size;

            std::cout << IDArr[size - 1] << "\t" << std::left << std::setw(30) << nameArr[size - 1] << "\t"
                << countArr[size - 1] << "\t" << priceArr[size - 1] << "\n\n";



            Sleep(2000);
        }
        else if (choose == "2")
        {

        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "\nОшибка ввода\n";
        }
    }
}

void DeleteEmployee()
{

}

void Selling()
{
    std::string choose, chooseID, chooseCount;
    bool isFirst = true;
    int id{}, count{};
    while (true)
    {
        system("cls");
        std::cout << "1 - начать новую продажу\n0 - отмена\nВвод:";
        Getline(choose);
        if (choose == "1")
        {
            isFirst = true;
            delete[]totalPriceCheckArr;
            delete[]nameCheckArr;
            delete[]countCheckArr;
            delete[]priceCheckArr;

            checkSize = 1;

            totalPriceCheckArr = new double[checkSize];
            countCheckArr = new int[checkSize];
            priceCheckArr = new double[checkSize];
            nameCheckArr = new std::string[checkSize];
            while (true)
            {
                system("cls");
                ShowStorage();
                std::cout << "Введите ID товара или 'exit' для завершения покупок\n\nВвод: ";
                Getline(chooseID);
                if (chooseID == "exit")
                {
                    break;
                }

                else if (IsNumber(chooseID))
                {
                    id = std::stoi(chooseID);
                    if (id > 0 && id <= size)
                    {
                        std::cout << "Введите кол-во " << nameArr[id - 1] << " для покупки: ";
                        Getline(chooseCount);
                        if (IsNumber(chooseCount))
                        {
                            count = std::stoi(chooseCount);
                            if (count >= 0 && count <= countArr[id - 1])
                            {
                                if (isFirst)
                                {
                                    AddNewCheckSize();
                                    nameCheckArr[checkSize - 1] = nameArr[id - 1];
                                    countCheckArr[checkSize - 1] = count;
                                    priceCheckArr[checkSize - 1] = priceArr[id - 1];
                                    totalPriceCheckArr[checkSize - 1] = count * priceArr[id - 1];
                                    isFirst = false;
                                }
                                else
                                {
                                    AddNewCheckSize();
                                    nameCheckArr[checkSize - 1] = nameArr[id - 1];
                                    countCheckArr[checkSize - 1] = count;
                                    priceCheckArr[checkSize - 1] = priceArr[id - 1];
                                    totalPriceCheckArr[checkSize - 1] = count * priceArr[id - 1];
                                }
                            }
                            else
                            {
                                std::cout << "Ошибка кол-ва \n";
                                Sleep(1000);
                            }
                        }


                        else
                        {
                            std::cout << "\nОшибка ввода\n";
                            Sleep(1000);
                        }
                    }
                    else
                    {
                        std::cout << "\nОшибка ID\n";
                        Sleep(1000);
                    }

                }

                else if (choose == "0")
                {
                    break;
                }
                else
                {
                    std::cout << "\nОшибка ввода\n";
                    Sleep(1000);
                }
                //принт чека

            }


        }
    }
}

void AddNewCheckSize()
{
    int* tempCount = new int[size];
    double* tempTotalPrice = new double[checkSize];
    double* tempPrice = new double[size];
    std::string* tempName = new std::string[size];

    for (int i = 0; i < checkSize; i++)
    {
        tempTotalPrice[i] = totalPriceCheckArr[i];
        tempCount[i] = countCheckArr[i];
        tempPrice[i] = priceCheckArr[i];
        tempName[i] = nameCheckArr[i];
    }
    delete[]totalPriceCheckArr;
    delete[]nameCheckArr;
    delete[]countCheckArr;
    delete[]priceCheckArr;

    checkSize++;

    totalPriceCheckArr = new double[checkSize];
    countCheckArr = new int[checkSize];
    priceCheckArr = new double[checkSize];
    nameCheckArr = new std::string[checkSize];
    for (int i = 0; i < checkSize - 1; i++)
    {
        totalPriceCheckArr[i] = tempTotalPrice[i];
        countCheckArr[i] = tempCount[i];
        priceCheckArr[i] = tempPrice[i];
        nameCheckArr[i] = tempName[i];
    }

    delete[] tempCount;
    delete[] tempTotalPrice;
    delete[] tempName;
    delete[] tempPrice;



}





bool IsNumber(std::string string)
{
    for (int i = 0; i < string.size(); i++) {
        if (!std::isdigit(string[i])) {
            return false;
        }
    }
    return true;
}

template<typename Arr>
void FillStorage(Arr staticArr[], Arr dynamicArr[], int staticSize)
{
    for (int i = 0; i < staticSize; i++)
    {
        dynamicArr[i] = staticArr[i];
    }

}

