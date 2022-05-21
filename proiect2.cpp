#include <iostream>
#include <string.h>
#include <conio.h>
#include <limits.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

int main()
{
    int n = 0, i, x, min = INT_MAX, max = INT_MIN, opt, p, q, j, o, z, g = 0 ,h, l = 0;
    
    struct vapor
    {
        char nume[20];
        char tip[20];
        int lungime;
        int an;
        float pret;
    }v[100], aux;
    
    ifstream f("vapor.txt");
    f >> n;
    f.get();
    
    for(i = 1; i <= n; i++)
            {
               f.get(v[i].nume,20);
               f.get();
               f.get(v[i].tip,20);
               f.get();
               f >> v[i].lungime;
               f.get();
               f >> v[i].an;
               f.get();
               f >> v[i].pret;
               f.get();
            }
            f.close();
    
    do
    {
        system("CLS");
        cout << "Meniu" << endl;
        cout << "_______________________________________________________________________" << endl;
        cout << "1. Adaugare vapor" << endl;
        cout << "2. Stergere vapoare dintr-un anumit an" << endl;
        cout << "3. Stergerea vapoarelor mai vechi de 5 ani" << endl;
        cout << "4. Afisarea celui mai scump vapor" << endl;
        cout << "5. Afisarea celui mai ieftin vapor" << endl;
        cout << "6. Stergerea tuturor vapoarelor de pescuit" << endl;
        cout << "7. Afisarea vapoarelor de croaziera" << endl;
        cout << "8. Afisarea celui mai mare vapor" << endl;
        cout << "9. Afisarea celui mai mare vapor de marfa" << endl;
        cout << "10. Afisarea celui mai mare vapor de pescuit" << endl;
        cout << "11. Afisarea celui mai nou vapor de croaziera" << endl;
        cout << "12. Afisarea celui mai ieftin vapor de pescuit" << endl;
        cout << "13. Iesire" << endl;
        cout << "_______________________________________________________________________" << endl;
        cout << "Introduceti optiunea: ";
        cin >> opt;
        
        if (opt == 1)
        {
               n++;
               cin.get();
               cout << "Numele vaporului: ";
               cin.get(v[n].nume,20);
               cin.get();
               cout << "Tipul vaporului: ";
               cin.get(v[n].tip,20);
               cin.get();
               cout << "Lungimea vaporului: ";
               cin >> v[n].lungime;
               cin.get();
               cout << "Anul fabricatiei: ";
               cin >> v[n].an;
               cin.get();
               cout << "Pretul vaporului: ";
               cin >> v[n].pret;
               cin.get();
        }
        
        if (opt == 2)
        {
            cout << "Introduceti anul dupa care sa se stearga vapoarele: ";
            cin >> x;
                 for (i=1; i<=n; i++)
                    if (v[i].an == x)
                        {
                            for(j = i; j < n; j++)
                            v[j] = v[j + 1];
                    n--;
                    i--;
                        }
            cout << "Apasati o tasta pentru a continua...";
            getch();
        }
        
        if (opt == 3)
        {
            for (i = 1; i <= n; i++)
                if (v[i].an < 2013)
                {
                v[i] = v[i+1];
                i--;
                n--;
                }
            cout << "Au fost sterse vapoarele mai vechi de 5 ani. Apasati o tasta pentru a continua...";
            getch();
        }
        
        if (opt == 4)
        {
            max = INT_MIN;
            for (i = 1; i <= n; i++)
                if (v[i].pret > max)
                {
                    max = v[i].pret;
                    p = i;
                }
                cout << "Cel mai scump vapor: " << v[p].nume << " " << v[p].tip << " " << v[p].lungime << " " << v[p].an << " " << v[p].pret << endl;
                cout << "Apasati o tasta pentru a continua...";
                getch();
        }
        
        if (opt == 5)
        {
            min = INT_MAX;
            for (i = 1; i <= n; i++)
                if (v[i].pret < min)
                {
                    min = v[i].pret;
                    q = i;
                }
                cout << "Cel mai ieftin vapor: " << v[q].nume << " " << v[q].tip << " " << v[q].lungime << " " << v[q].an << " " << v[q].pret << endl;
                cout << "Apasati o tasta pentru a continua...";
                getch();
        }
        
        if (opt == 6)
        {
            for (i = 1; i <= n; i++)
                if (strstr(v[i].tip,"pescuit") != NULL)
                {
                v[i] = v[i + 1];
                n--;
                i--;
                }
            cout << "Vapoarele de pescuit au fost sterse. Apasati o tasta pentru a continua...";
            getch();
        }
        
        if (opt == 7)
        {
            for (i = 1; i <= n; i++)
                if (strstr(v[i].tip,"croaziera") != NULL)
                cout << v[i].nume << " " << v[i].tip << " " << v[i].lungime << " " << v[i].an << " " << v[i].pret << endl;
            cout << "Apasati o tasta pentru a continua...";
            getch();
        }
        
        if (opt == 8)
        {
            max = INT_MIN;
            for (i = 1; i <= n; i++)
                if (v[i].lungime > max)
                {
                    max = v[i].lungime;
                    o = i;
                }
                cout << "Vaporul cel mai mare: " << v[o].nume << " " << v[o].tip << " " << v[o].lungime << " " << v[o].an << " " << v[o].pret << endl;
            cout << "Apasati o tasta pentru a continua...";
            getch();
        }
        
        if (opt == 9)
        {
            max = INT_MIN;
            for (i = 1; i <= n; i++)
                if (strcmp(v[i].tip,"marfa") == 0 && v[i].lungime > max)
                        {
                            z = i;
                            max = v[i].lungime;
                        }
                cout << "Vaporul de marfa cel mai mare: " << v[z].nume << " " << v[z].tip << " " << v[z].lungime << " " << v[z].an << " " << v[z].pret << endl;
            cout << "Apasati o tasta pentru a continua...";
            getch();
        }
        
        if (opt == 10)
        {
            max = INT_MIN;
            for (i = 1; i <= n; i++)
                if (strcmp(v[i].tip,"pescuit") == 0 && v[i].lungime > max)
                {
                        g = i;
                        max = v[i].lungime;
                }
                if(g != 0)
                {
                cout << "Cel mai mare vapor de pescuit: " << v[g].nume << " " << v[g].tip << " " << v[g].lungime << " " << v[g].an << " " << v[g].pret << endl;
            cout << "Apasati o tasta pentru a continua...";
                }
                else
                cout << "Nu exista vapoare de pescuit!";
            getch();
        }
        
        if (opt == 11)
        {
            max = INT_MIN;
            for (i = 1; i <= n; i++)
                if (strcmp(v[i].tip,"croaziera") == 0 && v[i].an > max)
                {
                h = i;
                max = v[i].an;
                }
                cout << "Cel mai nou vapor de croaziera: " << v[h].nume << " " << v[h].tip << " " << v[h].lungime << " " << v[h].an << " " << v[h].pret << endl;
                cout << "Apasati o tasta pentru a continua...";
                getch();
        }
        
        if (opt == 12)
        {
            max = INT_MIN;
            for (i = 1; i <= n; i++)
                if (strcmp(v[i].tip,"pescuit") == 0 && v[i].pret > max)
                    {
                        l = i;
                        max = v[i].pret;
                    }
                    if(l != 0)
                    {
                cout << "Cel mai ieftin vapor de pescuit: " << v[l].nume << " " << v[l].tip << " " << v[l].lungime << " " << v[l].an << " " << v[l].pret << endl;
                cout << "Apasati o tasta pentru a continua...";
                    }
                    else
                    cout << "Nu exista vapoare de pescuit!";
                getch();
        }
    }//de la do
    
    while (opt >= 1 && opt <= 12);
    ofstream y("vapor.txt");
    y << n << endl;
    
    for (i = 1; i <= n; i++)
    {
        y << v[i].nume << endl;
        y << v[i].tip <<endl;
        y << v[i].lungime << endl;
        y << v[i].an << endl;
        y << v[i].pret << endl;
    }
    y.close();

return 0;
}
