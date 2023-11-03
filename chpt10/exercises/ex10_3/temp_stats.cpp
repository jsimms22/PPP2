#include<algorithm>
#include "temps.h"

bool cmp(Reading& i, Reading& j) { return (i.temp < j.temp); }

double mean(std::vector<Reading>& r)
// simply averaging function
{
    double m = 0.0;
    for (Reading element : r) {
        m += element.temp;
    }
    m /= (double)r.size();
    return m;
}

double median(std::vector<Reading>& r)
// sorts vector, then uses indices to identify the mean
{
    std::sort(r.begin(), r.end(), cmp);
    if (r.size() % 2 == 1) {
        return r[(r.size()/2)].temp;
    } else {
        return ( (r[(r.size()/2)].temp + r[((r.size()/2)-1)].temp) / 2 );
    }
}