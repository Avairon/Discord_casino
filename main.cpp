#include <iostream>
#include <random>
#include <string>
#include <map>
#include <vector>

using std::cout;
using std::string;
using std::map;
using std::vector;

map <int, string> start_arab(){
    map <int, string> arab_out;
    
    arab_out[0] = "Приз 100 рублей!";
    arab_out[1] = "Приз 150 рублей!";
    arab_out[2] = "Приз 200 рублей!";
    arab_out[3] = "Приз 250 рублей!";
    arab_out[4] = "Приз 300 рублей!";
    arab_out[5] = "СУПЕРПРИЗ! Награда 500 рублей!";
    
    return arab_out;
}

map <int, string> start_bitch(){
    map <int, string> bitch_out;
    
    bitch_out[0] = "Приз 10 рублей!";
    bitch_out[1] = "Приз 20 рублей!";
    bitch_out[2] = "Приз 30 рублей!";
    bitch_out[3] = "Приз 50 рублей!";
    bitch_out[4] = "Приз 70 рублей!";
    bitch_out[5] = "СУПЕРПРИЗ 100 рублей!";
    
    return bitch_out;
}

vector<int> chances_buff_gen(int* chances){
    vector<int> chances_buff;
        chances_buff.push_back(chances[0]);
        chances_buff.push_back(chances[0] + chances[1]);
        chances_buff.push_back(chances[0] + chances[1] + chances[2]);
        chances_buff.push_back(chances[0] + chances[1] + chances[2] + chances[3]);
        chances_buff.push_back(chances[0] + chances[1] + chances[2] + chances[3] + chances[4]);
        chances_buff.push_back(chances[0] + chances[1] + chances[2] + chances[3] + chances[4] + chances[5]);
    return chances_buff;
}

int roll(int* chances, int luck_input){
    int chances_buff[6];
    
    for(int i = 0; i <= 5; i++) chances_buff[i] = chances_buff_gen(chances)[i];
    
    int luck_output = 0;
    
    if(luck_input >= 0 and luck_input < chances_buff[0]) luck_output = 0;
    if(luck_input >= chances_buff[0] and luck_input < chances_buff[1]) luck_output = 1;
    if(luck_input >= chances_buff[1] and luck_input < chances_buff[2]) luck_output = 2;
    if(luck_input >= chances_buff[2] and luck_input < chances_buff[3]) luck_output = 3;
    if(luck_input >= chances_buff[3] and luck_input < chances_buff[4]) luck_output = 4;
    if(luck_input >= chances_buff[4] and luck_input < chances_buff[5]) luck_output = 5;   
    
    return luck_output;
}    

int main()
{
    setlocale(LC_ALL, "Russian");
    
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    //std::uniform_int_distribution<> distr(0, 30); // define the range
    
    map <int, string> nag_arab;
    map <int, string> nag_bitch;
    
    nag_arab = start_arab();
    nag_bitch = start_bitch();
    
    
    
    int chances_arab[6] = {14, 6, 4, 3, 2, 1};
    int chances_bitch[6] = {12, 7, 5, 4, 3, 2}; //{12, 7, 5, 3, 2, 1};
    
    /*DEBUG
    for(int i = 0; i <= 5; i++) cout << chances_buff[i] << "\n";
    
    cout << "\n"; cout << "\n";
    */
    
    int choose = 0;
    
    cout << "Награды нашей рулетки!\n";
    cout << "\n";
    
    cout << "Награды наноказика\n";
    for (int i = 0; i <= 5; i++) cout << nag_bitch[i] << " шанс: " << chances_bitch[i] * 100 / chances_buff_gen(chances_bitch)[5] << "%\n";
    cout << "\n";
    
    cout << "Награды АААРАБСКОГО казино\n";
    for (int i = 0; i <= 5; i++) cout << nag_arab[i] << " шанс: " << chances_arab[i] * 100 / chances_buff_gen(chances_arab)[5] << "%\n";
    cout << "\n";
    cout << "\n";
    
    cout << "Выберите казино\n 1 - наноказик\n 2 - АААРАБСКОЕ казино\n";
    std::cin >> choose;
    
    int buff[3] = {0, chances_buff_gen(chances_bitch)[5], chances_buff_gen(chances_arab)[5]};
    
    std::uniform_int_distribution<> distr(0, buff[choose]); // define the range
    int luck_input = distr(gen);
    
    switch(choose){
        case(1):
            cout << nag_bitch[roll(chances_bitch, luck_input)];
            break;
        case(2):
            cout << nag_arab[roll(chances_arab, luck_input)];
            break;
        default:
            cout << "Неверный ввод! Перезапустите код";
            break;
    }
}























