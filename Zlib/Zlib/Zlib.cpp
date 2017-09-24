#include "Zlib.h"
#include <sys/timeb.h>
#include <ctime>

using namespace std;

string getFileNameWithoutExtension(string fileName)
{
    int pos = fileName.find_last_of('.');
    return fileName.substr(0, pos);
}

unsigned int getDaysInMonth(unsigned int year, unsigned int month)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 32;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 31;
    if (((year % 4 == 0) && (year % 100 != 0)) || ((year % 100 == 0) && (year % 400 == 0)))
        return 30;
    else
        return 29;
}

string dateAdd(string date, int secondAdd)//yyyymmddhhmmss
{
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(4, 2).c_str());
    int day = atoi(date.substr(6, 2).c_str());
    int hour = atoi(date.substr(8, 2).c_str());
    int minute = atoi(date.substr(10, 2).c_str());
    int second = atoi(date.substr(12, 2).c_str());

    int carry = secondAdd;
    int bak = second;
    second = (bak + carry) % 60;
    carry = (bak + carry) / 60;
    bak = minute;
    minute = (bak + carry) % 60;
    carry = (bak + carry) / 60;
    bak = hour;
    hour = (bak + carry) % 24;
    carry = (bak + carry) / 24;
    bak = day;
    day = (bak + carry) % getDaysInMonth(year, month);
    carry = (bak + carry) / getDaysInMonth(year, month);
    bak = month;
    month = (bak + carry) % 12;
    carry = (bak + carry) / 12;
    year += carry;

    char t[256];
    sprintf(t, "%4d%02d%02d%02d%02d%02d", year, month, day, hour, minute, second);
    string ret = t;

    return ret;
}

static vector<int> splitSrting(string str)
{
    string p = " ";
    str = str + p;
    vector<int> a;
    string::size_type i, pos, len = str.size();
    for (i = 0; i<len; i++)
    {
        pos = str.find(p, i);
        if (pos<len)
        {
            int k = atoi(str.substr(i, pos - i).c_str());
            a.push_back(k);
            i = pos;
        }
    }
    return a;
}

string getTimeStrWithMs()
{
    struct timeb tb;
    ftime(&tb);
    struct tm *p;
    p = localtime(&tb.time);
    char t[256];
    sprintf_s(t, "%4d%02d%02d%02d%02d%02d%03d", p->tm_year + 1900, p->tm_mon + 1, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec, tb.millitm);
    string timeStamp = t;
    return timeStamp;
}

long long getTimeLLWithMs()
{
    struct timeb tb;
    ftime(&tb);
    return tb.time * 1000 + tb.millitm;
}

template<typename T>
T basicType2Str(T basicVal)
{
    string string_temp;
    stringstream stream;
    stream << basicVal;
    stream >> string_temp //string_temp = stream.str();
    return string_temp;
}

vector<string> getAllLinesInFile(fstream file)
{
    vector<string> ret;
    string oneLine;
    while (getline(file, oneLine))
        ret.push_back(oneLine);
    return ret;
}

vector<string> getAllLinesInFile(string fileName)
{
    vector<string> ret;
    fstream file;
    file.open(fileName, ios::in);
    string oneLine;
    while (getline(file, oneLine))
        ret.push_back(oneLine);
    file.close();
    return ret;
}
