#include<iostream>
#include<tuple>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<numeric>

typedef std::tuple<std::vector<Sales_data>::sizetype,
                   std::vector<Sales_data>::const_iterator,
                   std::vector<Sales_data>::const_iterator>
                   matchs;

typedef std::pair<std::vector<Sales_data>::size_type,
                  std::pair
