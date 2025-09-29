#include <iostream>
#include <string>
using namespace std;

int green_duration = 20;
int yellow_duration = 3;
int red_duration = 80;
int cycle_duration = green_duration + yellow_duration + red_duration;

int offset_duration = 25;

string currentlampcolor(const int &input) {
    int currentcolor = (input - offset_duration) % cycle_duration;
    
    string lampcolor;
    
    if (currentcolor >= 0 && currentcolor < green_duration){
         lampcolor = "merah";
    }
    else if (currentcolor >= green_duration && currentcolor < green_duration + yellow_duration){
        lampcolor = "kuning";
    }
    else {
        lampcolor = "hijau";
    }
    
    return lampcolor;
}
int main() {
    int second;
    cout << "Masukkan detik: ";
    cin >> second;
    string lamp = currentlampcolor(second);
    cout << "Lampu sekarang berwarna " << lamp;

}
