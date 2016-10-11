#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#define Participate 6
#define HasCar 7
#define DriverWilling 8
#define HowMany 12
#define Drive? 14
#define PickUp?

using namespace std;

class CSVRow
{
    public:
        std::string const& operator[](std::size_t index) const
        {
            return m_data[index];
        }

        std::size_t size() const
        {
            return m_data.size();
        }

       void readNextRow(std::istream& str)
        {
            std::string         line;
            std::getline(str, line);

            std::stringstream   lineStream(line);
            std::string         cell;

            m_data.clear();
            while(std::getline(lineStream, cell, ','))
            {
                m_data.push_back(cell);
            }
        }

        std::vector<std::string>    m_data;

};

std::istream& operator>>(std::istream& str, CSVRow& data)
{
    data.readNextRow(str);
    return str;
}

void ParseDriverAndPassanger(vector<vector<string> >& origin_data, vector<vector<string> >& Driver, vector<vector<string> >& Passangers){
    for(size_t i = 0; i < origin_data.size(); i++){
        if(origin_data[i][HasCar] == "га" && origin_data[i][DriverWilling] == "дИвт" && origin_data[i][] ){

        }
    }
}


int main()
{
    ifstream file("PickUp.csv");

    CSVRow row;

    vector<vector<string> > origin_data;

    while(file >> row)
    {
        origin_data.push_back(row.m_data);//read the origin data
    }

    origin_data.erase(origin_data.begin()); //clean the header

    vector<vector<string> > Driver;
    vector<vector<string> > Passanger;
    ParseDriverAndPassanger(origin_data, Driver, Passanger);

}
