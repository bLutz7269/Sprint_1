#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <math.h>

//#include <filesystem>
/*
system();//outputs to the terminal can be used to execute other files


"SE_1/Image/" + images[i];

*/
using namespace std;

int key_gen(int len){
    srand(time(NULL));
    int num = 0;

    for(int i = 0; i < len; i++){ 
        num += (rand() % 10) * pow(10,i);
    }
    return num;
}

void create_file(string name){
    ofstream file;
    file.open(name);
    file << "Number,Description,Data,Key" << endl;
    file.close();
}

int get_max_num(string in){
    string fileData, num, desc = "de", data = "da", key = "k";

    fstream file;
    int max_num = 1;

    file.open(in);
    getline(file, fileData);
    while(!file.eof()){
        if(getline(file, num, ',')){
            max_num ++;
            getline(file, desc, ',');
            getline(file, data, ',');
            getline(file, key);
        }
    }

    return max_num;
}

void encryption(){//Number,Description,Data,Key
    fstream file;
    string in, fileData = " ", desc = "de", data = "da", key = "k";
    int number = 0, maxNum = 0;

    cin.ignore();
    cout << "Welcome to Encryption, enter a file name(.txt) to encrypt to: ";
    getline(cin, in);
    file.open(in);
    

    if(fileData == "Number,Description,Data,Key"){
        cout << "Existing File" << endl;
        getline(file, fileData);
    }
    else{
        
        cout << "New File" << endl;
        file.close();
        create_file(in);
        file.open(in);
        getline(file, fileData);
    }

    cin.ignore();
    cout << "Enter a description: ";
    getline(cin, desc);

    cin.ignore();
    cout << "Enter the data: ";
    getline(cin, data);
    
    number = get_max_num(in);

    key = to_string(key_gen(desc.length()));
    for(int i = 0; i < key.length(); i++)
        data[i] = (key[i] ^ data[i]);

    //cout << "Encrypted: " << data;

    if(fileData == "Number,Description,Data,Key"){
        file << number << "," << desc <<"," << data << "," << key << endl;
    }
    else{
        file.close();
        file.open(in);
        file << number << "," << desc <<"," << data << "," << key << endl;
    }


    
    file.close();
}

void decryption(){//Number,Description,Data,Key
    fstream file;
    string in,fileData, num, desc, data, key;
    int number = -1;
    cout << "Welcome to Decryption, enter a file name(.txt) to decrypt: ";
    cin >> in;
    file.open("data.txt");
    getline(file, fileData);
    cout << fileData << endl;
    while((atoi(num.c_str()) != number) && (!file.eof())){
        if(getline(file, num, ',')){
            getline(file, desc, ',');
            getline(file, data, ',');
            getline(file, key);
            cout << "Number: " << num << " Description: " << desc << endl;
        }
    }
    file.close();
    cout << endl;
    file.open(in);

    cout << "Enter the number to decrypt: ";
    cin >> number;
    cout << endl;
    getline(file, fileData);

    for (int i = 0; i < number; i++){
        getline(file, num, ',');
        getline(file, desc, ',');
        getline(file, data, ',');
        getline(file, key);
    }

    for(int i = 0; i < key.length(); i++)
        data[i] = (key[i] ^ data[i]);

    cout << "The data is: " << data << endl << endl;
    
    file.close();
}

void view_file(){
    fstream file;
    string in;
    cout << "Welcome to View_file, enter a file name(.txt) to view: ";
    cin >> in;

}


int main(){
    /*fstream p, i;
    string in;
    
    cout << "UI\n" << "enter i to start: ";
    cin >> in;

    if (in == "i"){
        p.open("prng_service.txt", ofstream::out | ofstream::trunc);
        p << "run";
        p.close();

        system("./PRNG");

        p.open("prng_service.txt");
        string input;
        getline(p,input);
        p.close();

        i.open("image_service.txt", ofstream::out | ofstream::trunc);
        i << input;
        i.close();
        cout << "rand in UI: " << input << endl;

        system("./IS");

        p.open("image_service.txt");
        getline(p,input);
        p.close();

        cout << "path in UI: " << input << endl;
    }*/

    int in = 0;
    cout << "Welcome to Data Safe" << endl;
    while(in != 3){
        cout << "What operation do you want to select?" << "\n1.Encryption\n2.Decryption\n3.Exit"<< endl;
        cin >> in;

        if (in == 1)
            encryption();
        else if (in == 2)
            decryption();
        else if(in == 3);
        else{
            cout << endl << "Input Error" << endl << endl;
        }
    }
    


    return 0;
}
