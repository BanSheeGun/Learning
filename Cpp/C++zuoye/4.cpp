#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    std::vector<int> v1;
    std::vector<int> v2; 
    for (int i = 1; i <= 10; ++i)
        v1.push_back(i);
    for (int i = 11; i >= 3; --i)
        v2.push_back(i);
    std::vector<int> v;
    v.resize(19); 
    merge(v1.begin(), v1.begin() + 10, v2.begin(), v2.begin() + 9, v.begin());
    std::vector<int>::iterator itor1; 
    for (itor1 = v.begin(); itor1 != v.end(); ++itor1)
        printf("%d ", *itor1);
    printf("\n");
    sort(v.begin(), v.end());
    for (itor1 = v.begin(); itor1 != v.end(); ++itor1)
        printf("%d ", *itor1);
    printf("\n");
    return 0;
}