#include <iostream>
#include <random>
#include <string>
#include <map>
#include <vector>

using std::cout;
using std::string;
using std::map;
using std::vector;

int chances_arab[6] = {14, 6, 4, 3, 2, 1};
int chances_bitch[6] = {12, 7, 5, 4, 3, 2}; //{12, 7, 5, 3, 2, 1};

std::random_device rd; // obtain a random number from hardware
std::mt19937 gen(rd());

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

int buff[3] = {0, chances_buff_gen(chances_bitch)[5], chances_buff_gen(chances_arab)[5]};

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

class member{
private:
    int money;
    int rolls;
    
    map <int, int> arab_prices;
    map <int, int> bitch_prices;
    
public:
    member(){};
    member(int Rolls, int Money){
        rolls = Rolls;
        money = Money;
    }
    void begin(){
        arab_prices[0] = 100;
        arab_prices[1] = 150;
        arab_prices[2] = 200;
        arab_prices[3] = 250;
        arab_prices[4] = 300;
        arab_prices[5] = 500;
    
        bitch_prices[0] = 10;
        bitch_prices[1] = 20;
        bitch_prices[2] = 30;
        bitch_prices[3] = 40;
        bitch_prices[4] = 50;
        bitch_prices[5] = 100;
    }
    void roll_arab(){
        if(rolls > 0){
            rolls-=1;
            std::uniform_int_distribution<> distr(0, buff[2]); // define the range
            int luck_input = distr(gen);
        
            cout << "Вы выйграли: " << arab_prices[roll(chances_arab, luck_input)] << " рублей!\n";
            money += arab_prices[roll(chances_arab, luck_input)];
        }
        else{
            cout << "У вас нет круток в АААРАБСКОЕ казино!";
        }
        
    }
    void roll_bitch(){
        if(rolls > 0){
            rolls-=1;
            std::uniform_int_distribution<> distr(0, buff[1]); // define the range
            int luck_input = distr(gen);
        
            cout << "Вы выйграли: " << arab_prices[roll(chances_bitch, luck_input)] << " рублей!\n";
            money += bitch_prices[roll(chances_bitch, luck_input)];
        }
        else{
            cout << "У вас нет круток в наноказик!";
        }
    }
    void info(){
        cout << "Награды нашей рулетки!\n";
        cout << "\n";
    
        cout << "Награды наноказика\n";
        for (int i = 0; i <= 5; i++) cout << bitch_prices[i] << " рублей, шанс: " << chances_bitch[i] * 100 / chances_buff_gen(chances_bitch)[5] << "%\n";
        cout << "\n";
    
        cout << "Награды АААРАБСКОГО казино\n";
        for (int i = 0; i <= 5; i++) cout << arab_prices[i] << " рублей, шанс: " << chances_arab[i] * 100 / chances_buff_gen(chances_arab)[5] << "%\n";
        cout << "\n";
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    
    int choose = 0;
    
    
    member user = *new member(1, 0);
    user.begin();
    
    cout << "Выберите казино\n 1 - наноказик\n 2 - АААРАБСКОЕ казино\n";
    std::cin >> choose;
    
    
    
    switch(choose){
        case(1):
            user.roll_bitch();
            break;
        case(2):
            user.roll_arab();
            break;
        default:
            user.info();
            break;
    }
}























