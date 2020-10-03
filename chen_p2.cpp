#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]){
    using namespace std;
    if(argc != 3){
        cerr << "Usage: ./chen_p2 <Gate configuration> <input string>";
        return 0;
    }

    string gate(argv[1]);
    string inputStr(argv[2]);

    char g1c[] = {'L', 'C', 'R'};
    int g1i = (gate[0] == 'L')? 0:((gate[0] == 'C')? 1:2);
    cout << gate;
    char destination;
    for(int i = 0; i < inputStr.length(); i++){
        char gate1Dir = g1c[g1i];
        g1i += (inputStr[i] == '0')? -1 : 1;
        g1i = (g1i % 3 + 3) % 3;
        gate[0] = g1c[g1i];

        switch(gate1Dir){
            case 'L':
                destination = (gate[1] == 'L')?'B':'C';
                gate[1] = (gate[1] == 'L'? 'R': 'L');
                break;
            case 'C':
                destination = (gate[2] == 'L')?'C':'D';
                gate[2] = (gate[2] == 'L'? 'R': 'L');
                break;
            case 'R':
                destination = (gate[3] == 'L')?'D':'E';
                gate[3] = (gate[3] == 'L'? 'R': 'L');
                break;
        }
        cout << "->" << gate;
    }
    cout << " " << destination << endl;
}
