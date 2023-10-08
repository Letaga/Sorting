// Lab_1_Sorting.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <algorithm>
using namespace std;


int* FillingM(int* My, int l);
int* SimpSamp(int* Mv, int l);
int* SimpBabble(int* Mass, int l);
int* SimpInsert(int* Mass, int l);
int* BinInsert(int* Mass, int l);
int* Sheiker(int* Mass, int l);
int* Shell(int* Mass, int l);
int* Pyramid(int* Mass, int l);
void PiramFill(int* Mass, int l, int i, double *sp);
void QuickS(int* Mass, int l, int* sp);

// ======================
int main()
{
    setlocale(LC_ALL, "");


    int lmass;
    cout << "Введите размерность массива: ";
    cin >> lmass;
    int* MVoz = new int[lmass];
    int* MYb = new int[lmass];
    int* MRand = new int[lmass];
    int* Temp = new int[lmass];

    for (int i = 0; i < lmass; i++)
        MVoz[i] = MRand[i] = i + 1;
    FillingM(MYb, lmass);
    random_shuffle(&MRand[0], &MRand[lmass]);
    for (int i = 0; i < lmass; i++)
        Temp[i] = MRand[i];

    cout << "\nМетод, Массив\t\t|Возр.\t\t|Убыв.\t\t|Ранд.\t\n";

    // =======================  SORTING  =======================
    //----------------- Сортировка простой выборкой --------------
    cout << "\nПростой выбор\t\t|";

    SimpSamp(MVoz, lmass);
    SimpSamp(MYb, lmass);
    SimpSamp(Temp, lmass);

    //----------------- Сортировка простого обмена (пузырёк) --------------
    FillingM(MYb, lmass);
    for (int i = 0; i < lmass; i++)
        Temp[i] = MRand[i];
    cout << "\nПростой обмен\t\t|";
    SimpBabble(MVoz, lmass);
    SimpBabble(MYb, lmass);
    SimpBabble(Temp, lmass);

    //----------------- Сортировка простой вставки --------------
    FillingM(MYb, lmass);
    for (int i = 0; i < lmass; i++)
        Temp[i] = MRand[i];

    cout << "\nПростая вставка\t\t|";

    SimpInsert(MVoz, lmass);
    SimpInsert(MYb, lmass);
    SimpInsert(Temp, lmass);


    //----------------- Сортировка бинарной вставки --------------
    FillingM(MYb, lmass);
    for (int i = 0; i < lmass; i++)
        Temp[i] = MRand[i];

    cout << "\nБинарная вставка\t|";
    BinInsert(MVoz, lmass);
    BinInsert(MYb, lmass);
    BinInsert(Temp, lmass);


    //----------------- Шейкер сортировка --------------
    cout << "\nШейкер сортировка\t|";
    FillingM(MYb, lmass);
    for (int i = 0; i < lmass; i++)
        Temp[i] = MRand[i];

    Sheiker(MVoz, lmass);
    Sheiker(MYb, lmass);
    Sheiker(Temp, lmass);

    //----------------- Сортировка Шелла --------------
    cout << "\nСортировка Шелла\t|";
    FillingM(MYb, lmass);
    for (int i = 0; i < lmass; i++)
        Temp[i] = MRand[i];

    Shell(MVoz, lmass);
    Shell(MYb, lmass);
    Shell(Temp, lmass);


    //----------------- Пирамидальная сортировка --------------
    cout << "\nПирамидальная\t\t|";
    FillingM(MYb, lmass);
    for (int i = 0; i < lmass; i++)
        Temp[i] = MRand[i];

    Pyramid(MVoz, lmass);
    Pyramid(MYb, lmass);
    Pyramid(Temp, lmass);

    //----------------- Быстрая сортировка --------------
    cout << "\nБыстрая сортировка\t|";
    FillingM(MYb, lmass);
    for (int i = 0; i < lmass; i++)
        Temp[i] = MRand[i];
    
    int sp[2] = {0};//sp[0] - number of comparisons, sp[1] - number of permutations
    QuickS(MVoz, lmass, sp);
    if (sp[0] >= 10000 && sp[1] >= 10000)
    {
        cout << "s=" << sp[0] << " p=" << sp[1] << "|";
    }
    else
        cout << "s=" << sp[0] << " p=" << sp[1] << "\t|";
    sp[0] = sp[1] = 0;
    
    QuickS(MYb, lmass, sp);
    if (sp[0] >= 10000 && sp[1] >= 10000)
    {
        cout << "s=" << sp[0] << " p=" << sp[1] << "|";
    }
    else
        cout << "s=" << sp[0] << " p=" << sp[1] << "\t|";
    sp[0] = sp[1] = 0;
    
    QuickS(Temp, lmass, sp);
    if (sp[0] >= 10000 && sp[1] >= 10000)
    {
        cout << "s=" << sp[0] << " p=" << sp[1] << "|";
    }
    else
        cout << "s=" << sp[0] << " p=" << sp[1] << "\t|";

    delete[] MVoz;
    delete[] MYb;
    delete[] Temp;
    delete[] MRand;
    return 0;
}
// ======================


int* FillingM(int* My, int l)
{
    int i;
    for (i = 0; i < l; i++)
        My[i] = l - i;
    return My;
}

// ============ SORTING ==============
int* SimpSamp(int* Mass, int l)
{
    int s = 0, p = 0; //s - number of comparisons, p - number of permutations
    int buf = 0, imax = 0;
    for (int i = 0; i < l - 1; i++)
    {
        imax = i;
        for (int j = i + 1; j < l; j++)
        {
            s++;
            if (Mass[imax] > Mass[j])
                imax = j;
        }
        if (i != imax)
        {
            buf = Mass[i];
            Mass[i] = Mass[imax];
            Mass[imax] = buf;
            p++;
        }
    }
    cout << "s=" << s << " p=" << p << "\t|";
    return 0;
}

int* SimpBabble(int* Mass, int l)
{
    int buf = 0, s = 0, p = 0; //s - number of comparisons, p - number of permutations
    for (int i = 0; i < l - 1; i++)
    {
        for (int j = l-1; j > i; j--)
        {
            s++;
            if (Mass[j-1] > Mass[j])
            {
                p++;
                buf = Mass[j-1];
                Mass[j-1] = Mass[j];
                Mass[j] = buf;
            }
        }
    }
    if (p >= 10000)
    {
        cout << "s=" << s << " p=" << p << "|";
    }
    else
        cout << "s=" << s << " p=" << p << "\t|";
    
    return 0;
}

int* SimpInsert(int* Mass, int l)
{
    int buf = 0, j, s = 0, p = 0, c = 0; //s - number of comparisons, p - number of permutations
    for (int i = 0; i < l; i++)
    {
        j = i;
        buf = Mass[i];
        c = 0;
        while (j > 0 && buf < Mass[j - 1])
        {
            Mass[j] = Mass[j - 1];
            j--;
            s++;
            c++;
        }
        if (c == 0)
            s++;
        Mass[j] = buf;
        p++;
    }
    if (p >= 10000)
    {
        cout << "s=" << s << " p=" << p << "|";
    }
    else
        cout << "s=" << s << " p=" << p << "\t|";
    return 0;
}

int* BinInsert(int* Mass, int l)
{
    int j, left, right, buf, mid, s = 0, p = 0; //s - number of comparisons, p - number of permutations
    for (int i = 1; i < l; i++)
    {
        left = 0;
        right = i - 1;
        buf = Mass[i];
        do
        {
            mid = (left + right) / 2;
            s++;
            if (Mass[mid] < buf) 
                left = mid + 1;
            else right = mid - 1;
        }while (left <= right);
        for (int j = i - 1; j >= left; j--)
        {
            p++;
            Mass[j + 1] = Mass[j];
        }
        Mass[left] = buf;
    }

    if (p >= 10000 && s >= 10000)
    {
        cout << "s=" << s << " p=" << p << "|";
    }
    else
        cout << "s=" << s << " p=" << p << "\t|";
    return 0;
}

int* Sheiker(int* Mass, int l)
{
    int left = 1, right = l - 1, edge = l - 1, buf = 0, s = 0, p = 0; //s - number of comparisons, p - number of permutations
    while (left <= right)
    {
        for (int i = right; i >= left; i--)
        {
            s++;
            if (Mass[i - 1] > Mass[i])
            {
                buf = Mass[i - 1];
                Mass[i - 1] = Mass[i];
                Mass[i] = buf;
                edge = i;
                p++;
            }
        }
        left = edge + 1;
        for (int i = 0; i < right; i++)
        {
            s++;
            if (Mass[i - 1] > Mass[i])
            {
                buf = Mass[i - 1];
                Mass[i - 1] = Mass[i];
                Mass[i] = buf;
                edge = i;
                p++;
            }
        }
        right = edge - 1;
    }

    if (p >= 10000 && s >= 10000)
    {
        cout << "s=" << s << " p=" << p << "|";
    }
    else
        cout << "s=" << s << " p=" << p << "\t|";
    return 0;
}

int* Shell(int* Mass, int l)
{
    int s = 0, p = 0, c = 0; //s - number of comparisons, p - number of permutations
    for (int step = log2(l); step >= 1; step = log2(step))
    {
        int buf = 0, j;
        for (int i = 0; i < l; i += step)
        {
            j = i;
            buf = Mass[i];
            while (j > 0 && buf < Mass[j - step])
            {
                Mass[j] = Mass[j - step];
                j -= step;
                s++;
                c++;
            }
            if (c == 0)
                s++;
            Mass[j] = buf;
            p++;
        }
    }

    if (p >= 10000 && s >= 10000)
    {
        cout << "s=" << s << " p=" << p << "|";
    }
    else
        cout << "s=" << s << " p=" << p << "\t|";
    return 0;
}

int* Pyramid(int* Mass, int l)
{
    double sp[2] = {0}; //sp[0] - number of comparisons, sp[1] - number of permutations
    int buf;

    for (int i = l / 2; i >= 0; i--)
    {
        PiramFill(Mass, l, i, sp);
    }
    for (int i = l - 1; i >= 0; i--)
    {
        sp[1]++;
        buf = Mass[0];
        Mass[0] = Mass[i];
        Mass[i] = buf;
        PiramFill(Mass, i, 0, sp);
    }

    if (sp[0] >= 10000 && sp[1] >= 10000)
    {
        cout << "s=" << sp[0] << " p=" << sp[1] << "|";
    }
    else
        cout << "s=" << sp[0] << " p=" << sp[1] << "\t|";
    return 0;
}
void PiramFill(int* Mass, int l, int i, double* sp)
{
    int iParent = i, buf;
    while (true)
    {
        int iChild = 2 * i + 1;
        if (iChild < l)
        {
            sp[0]++;
            if (Mass[iChild] > Mass[iParent])
                iParent = iChild;
        }
        iChild++;
        if (iChild < l)
        {
            sp[0]++;
            if (Mass[iChild] > Mass[iParent])
                iParent = iChild;
        }
        if (iParent == i)
        {
            break;
        } 
        else 
        {
            sp[1]++;
            buf = Mass[i];
            Mass[i] = Mass[iParent];
            Mass[iParent] = buf;
            i = iParent;
        }
    }
}

void QuickS(int* Mass, int l, int* sp) 
{
    int left = 0, right = l - 1, buf, mid = Mass[l / 2], c;

    do {
        c = 0;
        while (Mass[left] < mid) 
        {
            sp[0]++; c++;
            left++;
        }
        if (c != 0)
        {
            sp[0]++;
            c = 0;
        }
        while (Mass[right] > mid) 
        {
            c++; sp[0]++;
            right--;
        }
        if (c != 0)
        {
            sp[0]++;
            c = 0;
        }
        sp[0]++;
        if (left <= right) {
            if (left != right)
            {
                buf = Mass[left];
                Mass[left] = Mass[right];
                Mass[right] = buf;
                sp[1]++;
            }
            left++;
            right--;
        }
    } while (left <= right);

    if (right > 0) {
        QuickS(Mass, right + 1, sp);
    }
    if (left < l) {
        QuickS(&Mass[left], l - left, sp);
    }
}

