#ifndef TEMPS_H
#define TEMPS_H

#include<vector>

struct Reading
{
    double temp;
};

bool cmp(Reading& i, Reading& j);

double mean(std::vector<Reading>& r);

double median(std::vector<Reading>& r);

#endif