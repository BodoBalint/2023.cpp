#include <iostream>
#include <vector>
#include <algorithm>
#include <random>


using namespace std;

int main1() {
    vector<string> fruits{
            "melon", "strawberry", "raspberry", "apple", "banana", "walnut", "lemon"
    };
    auto it = std::find_if(fruits.begin(), fruits.end(), [](const string &s) {
        return s.find("berry") != string::npos;
    });
    cout << (it != fruits.end()) << endl;
    return 0;
}

int main2() {
    vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bool it = all_of(numbers.begin(), numbers.end(), [](int n) {
        return n % 2 == 0; //(x & 1 == 0)
    });
    cout << it << endl;
    return 0;
}

int main3() {
    vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::for_each(numbers.begin(), numbers.end(), [](int &n) {
        n *= 2;
    });
    for (auto n: numbers) {
        cout << n << " ";
    }
    return 0;
}

int main4() {
    vector<string> months{
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };
    long n = std::count_if(months.begin(), months.end(), [](const string &s) {
        return s.length() == 5;
    });
    cout << n;
    return 0;
}

int main5() {
    vector<float> numbers{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    sort(numbers.begin(), numbers.end(), [](float a, float b) {
        return a > b;
    });
    for (auto n: numbers) {
        cout << n << " ";
    }
    cout << endl;
    sort(numbers.begin(), numbers.end(), greater());
    for (auto n: numbers) {
        cout << n << " ";
    }
    return 0;
}

int main6() {
    vector<pair<string, float>> months{
            {"January",-20},
            {"February",-3},
            {"March",3},
            {"April",5},
            {"May",15},
            {"June",20},
            {"July",25},
            {"August",25},
            {"September",18},
            {"October",15},
            {"November",6},
            {"December", -10},
    };
    sort(months.begin(), months.end(), [](const pair<string, float> &a, const pair<string, float> &b) {
        return a.second > b.second;
    });
    for (const pair<string, float> &m: months) {
        cout << m.first << " " << m.second << endl;
    }
    return 0;
}

int main7() {
    vector<float> numbers{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    sort(numbers.begin(), numbers.end(), [](float a, float b) {
        return abs(a) < abs(b);
    });
    for (auto n: numbers) {
        cout << n << " ";
    };
    return 0;
}

int main8() {
    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };
    for_each(months.begin(), months.end(), [](string &s) {
        s[0] = tolower(s[0]);
    });
    for (auto s: months) {
        cout << s << " ";
    }

    return 0;
}

int main() {
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    std::shuffle(abc.begin(), abc.end(), std::random_device());
    cout << abc << endl;

    for_each(months.begin(), months.end(), [](string &s) {
        s[0] = tolower(s[0]);
    });

    char inv[256]={0};
    for_each(abc.begin(), abc.end(), [&abc,&inv](char c) {
        inv[toupper(c)] = abc.find(c);
        inv[tolower(c)] = abc.find(c);
    });
    sort(months.begin(), months.end(), [&inv](const string &a, const string &b) {
        return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), [&inv](char c, char d) {
            return inv[c] < inv [d];
        });
    });

    for (string s: months) {
        cout << s << " ";
    }

    return 0;
}