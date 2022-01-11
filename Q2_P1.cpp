#include <iostream>
#include <string>

using namespace std;

long int time_stn(string time){
    int tt[3] = {0, 0, 0};
    int last_index = 0, filled = 0;
    for (int i = 0; i <= time.length(); i++)
        if (time[i] == ':' || i == time.length()){
            tt[filled] += stoi(time.substr(last_index, i - last_index));
            filled += 1;
            last_index = i + 1;
        }
    long int value = tt[0] * 3600 + tt[1] * 60 + tt[2];
    return value;
}
string time_nts(long int time){
    string tt[3] = {"", "", ""};
    time = time % 86400;
    tt[0] += to_string(time / 3600);
    time = time % 3600;
    tt[1] += to_string(time / 60);
    time = time % 60;
    tt[2] += to_string(time);
    for (int i = 0; i < 3; i++)
        if (tt[i].length() == 1){
            tt[i] = tt[i] + tt[i];
            tt[i].at(0) = '0';
        }
    string str = tt[0] + ":" + tt[1] + ":" + tt[2];
    return str;
}

struct Shuttle{
    string name = "Shuttle";
    string boarding_time = "23:59:59";
    string travelling_time = "23:59:59";
};

int main(){
    //  Structure declaration
    int no_of_shuttles = 5;
    Shuttle shuttles[no_of_shuttles];

    //  Structure initialisation
    for (int i = 0; i < no_of_shuttles; i++)
        shuttles[i].name = shuttles[i].name + "-" + to_string(1 + i);
    shuttles[0].boarding_time = "7:00:00";
    shuttles[0].travelling_time = "00:18:00";
    shuttles[1].boarding_time = "7:10:00";
    shuttles[1].travelling_time = "00:7:00";
    shuttles[2].boarding_time = "8:36:00";
    shuttles[2].travelling_time = "00:15:00";
    shuttles[3].boarding_time = "8:40:00";
    shuttles[3].travelling_time = "00:25:00";
    shuttles[4].boarding_time = "9:00:00";
    shuttles[4].travelling_time = "00:27:00";

    //  Printing shuttles
    cout << endl << "LIST OF SHUTTLES" << endl;
    cout << "Shuttle    |" << "Boarding-Time  |" << "Travelling-TIme" << endl;
    for (int i = 0; i < no_of_shuttles; i++)
        cout << shuttles[i].name << "  |" << shuttles[i].boarding_time << "        |" << shuttles[i].travelling_time << endl;

    //  Accepting input
    string arrival_time;
    int found = 0;
    string least_wait[3];
    least_wait[2] = "23:59:00"; least_wait[1] = "23:59:00";
    cout << endl
         << "Enter arrival time: ";
    cin >> arrival_time;
    for (int i = 0; i < no_of_shuttles; i++)
    {
        long int b_t = time_stn(shuttles[i].boarding_time);
        long int t_t = time_stn(shuttles[i].travelling_time);
        long int a_t = time_stn(arrival_time);
        long int l_w = time_stn(least_wait[1]);
        if (b_t >= a_t){
            if (b_t < l_w){
                least_wait[0] = shuttles[i].name;
                least_wait[1] = shuttles[i].boarding_time;
                least_wait[2] = time_nts(b_t - a_t);
                found += 1;
            }
        }
    }
    if(found != 0){
        cout << endl << "Least Waiting" << endl;
        cout << "\tName: " << least_wait[0] << endl;
        cout << "\tBoarding Time: " << least_wait[1] << endl;
        cout << "\tWaiting Time: " << least_wait[2] << endl;  
    }
    else
        cout << endl << "No shuttle found" << endl << endl;
}