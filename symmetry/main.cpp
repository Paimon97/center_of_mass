#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;



//using Point = pair<int,int>;
//using Edge = pair<int,int>;

class Point
{
private:
    int x,
        y,
        z;

  //  int point[3] = {x,y,z};

public:
    Point(void)
    {
        x=y=z=0;
    }

    int GetX(){return x;}
    int GetY(){return y;}
    int GetZ(){return z;}

    void SetXYZ(int nx,int ny,int nz)
    {
        x = nx;
        y = ny;
        z = nz;
    }
};

class arrayPoint
{
    int n; // количество точек в многоугольнике
    vector <Point> mp; // массив точек Point

    public:
    // конструктор без параметров
    arrayPoint(void);

    // конструктор с 2 параметрами, которые получает массив точек CMyPoint
    arrayPoint(int n, vector<Point> mp);

    // методы доступа
    Point GetPoint(int index); // возвращает точку
    void AddPoint(int nx, int ny,int nz); // добавляет точку

};




//как point считываются из example

istream& operator>>(istream& s,int p[3] )
{
    s>>p[0]>>p[1]>>p[2];
    return s;
}


    int main(int argc, char* argv[])
    {
        if (argc != 2)  //argc - количество параметров передаваемых в main
        {
            /* если argc != 2 мы не указали example
             укажи параметры командной строки*/
            cerr << "Usage: hello-geom filename"<<endl;
            return 1;
        }

        //argv - это массив указателей на строки
        // ifstream - файловый ввод

        ifstream f(argv[1]);// f - первая строка, тоесть имя файла

        /*fail() - определяет, соответствует ли
     введенное значение значению, определенному в переменной f.*/
        if (f.fail())
        {
            //если fail = true файл не получается найти
            cerr<<"Failed to open input fail. Don't find the file"<<endl;
            return 1;
        }

        // pointCout количество точек

        int pointCout;
        f>>pointCout;//побитовый сдвиг вправо

        if (f.fail())
        {
            // если fail = true  не правильный формат
            cerr<<"Failed to open input fail'"<<argv[1]<<"'has invalid format"<<endl;
            return 1;
        }

        // константная переменная определяющая максимальное количество ребер
        const int MaxPoint = 100000;

        // проверка количества ребер
        if (pointCout<0 || pointCout > MaxPoint)
        {
            cerr<< "Too many point";
            return 1;
        }

        // контейнер pointNumbers. Создание ассоциативного массива. int-ключ
        map<,int> pointNumbers;
        vector<Point> points;// объявляем вектор пар points

        // функция по считыванию данных из файла и записи в map
        auto readPoint = [&]()
        {
             p;
            f >> p;

            auto it = pointNumbers.find(p);// находит элемент по ключу p и записывает в it
            if (it == pointNumbers.end())//сравнивает it с последним элементом контейнера
            {   // если true то присваевается тот же номер
                int n = pointNumbers[p] = pointNumbers.size();// n- текущий элемент
                //p.push_back(p);//записывает в последний элемент массива
                return n;
            }
            else
            {
                return it->second;
            }
        };


//        using Edges = vector<Edge>;//создает вектор ребер
//        vector<Edge> edges;


        for (int i = 0; i<pointCout;++i)
        {
            //цикл присваевает номера точкам ребер
            int p1 = readPoint();
            //int p2 = readPoint();
            //edges.push_back({p1,p2});
            //cout << i << "::" <<  <<"---"<< edges[iedge].second << endl;
        }
    /*
        PointSersh(pointNumbers,edges,points);
        return 0;
        */
    }

