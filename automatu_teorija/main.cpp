#include <iostream>
#include <cstring>
using namespace std;

bool error_check(string);///funcijas deklaracija kludu parbaudei
bool delta(string);///parejas funcijas deklaracija, kurai pados ievadito simbolu virkni
bool check_bbb(string);///funcijas deklaracija  "bbb" parbaudei
bool check_cbc(string);///funcijas deklaracija  "cbc" parbaudei

int main()
{
    bool repeat=1;///nodrosina programmas atkartotu izpildi
    do
    {
        bool state=0;///sakuma stavoklis ir 0, jo nav nekas ievadits(0 stavoklis)
        bool final_state=state;///kamer nav nekas ievadits, sakuma un beigu stavokli sakrit
        string input_string;
        cout << "Enter a string using alfabet sigma={a,b,c}!" << endl;
        cin>>input_string;
        if(error_check(input_string)==1)
        {
            cout << "There was an input error!" << endl;
        }
        else
        {
            //cout << "There was no input error!" << endl;
            cout << "The final state is:" << endl;
            final_state=delta(input_string);///funkcijai delta padod ievadito simblu virkni
            cout <<final_state<< endl;///izdruka automata beigu stavokli
        }
        cout << "Do you want to repeat with a different string-enter 1 or 0 to stop this program!" << endl;
        cin>>repeat;
        cout <<endl;
    }
    while(repeat==1);
    return 0;
}

bool delta(string input_string)
{
///delta funkcija darbojas gandriz identiski XOR funkcijai - iespejami ir 4 (patiesiba kopa ir 12 stavokli:
/// starp 00 un 01 ir vel stavokli:00b un 00bb, un tikai tad seko stavoklis 10;
/// starp 00 un 10 ir vel stavokli:00c un 00cb, un tikai tad seko 01;
/// starp 10 un 11 ir vel stavokli 10c un 10cb un tikai tad seko 11;
/// starp 01 un 11 ir vel stavokli 10b un 10bb un tikai tad seko 11;
///visi iespejamie 12 stavokli ir {00,00b,00bb,10,00c,00cb,01,10c,10cb,01b,01bb,11})
///00-nav ievadits ne"bbb", ne"cbc"(atgriez 0);10-ir tikai "bbb"(atgriez 1);
///01-ir tikai"cbc"(atgriez 1);11-ir gan "bbb", gan "cbc" ievadits(atgriez 0).
///tatad sakuma stavoklis ir 00 un akceptejoso stavoklu kopa ir {01,10,10c,10cb,01b,01bb}.
    if((check_bbb(input_string)!=check_cbc(input_string))&&((check_bbb(input_string)==1)||(check_cbc(input_string)==1)))
    {
        ///ja simbolu virkne nav gan"bbb" gan "cbc" un ja ir vainu "bbb" vai "cbc", tad funkcija atgriez true=1
        return true;
    }
    else return false;///ja neizpildas nosacijums, tad atgriez false=0
}

bool check_bbb(string input_string)///funkcija parbauda - vai input_string satur vardu "bbb"?
{
    for(int i=0;input_string[i]!=0;i++)
    {
        if(input_string[i]=='b')///ja atrod pirmo simbolu "b"jeb stavoklis 00b (vai 01b,ja ieprieks atradas stavokli 01)
        {
            if(input_string[i+1]=='b')///ja nakamais ievaditais simbols ari ir "b" jebstavoklis 00bb (vai 01bb,ja ieprieks atradas stavokli 01b)
            {
                 if(input_string[i+2]=='b')///ja nakamais ievaditais simbols ari ir "b" jeb stavoklis 10 (vai 11,ja ieprieks atradas stavokli 01bb)
                 {
                     return true;///atgriez true, jo simbolu virkne satur "bbb"
                 }
            }///ja kada no apakstavokliem "b" vieta ievaditu "a" vai "c", tad atgrieztos uz sakuma stavokli
        }
    }
    return false;///atgriez false, ja simbolu virkne nesatur "bbb"

}

bool check_cbc(string input_string) ///funkcija parbauda - vai input_string satur vardu "cbc"?
{
    for(int i=0;(input_string[i])!=0;i++)
    {
        if(input_string[i]=='c')///ja atrod pirmo simbolu "c"jeb stavoklis 00c (vai 10c,ja ieprieks atradas stavokli 10)
        {
            if(input_string[i+1]=='b')///ja nakamais ievaditais simbols ir "b" jeb stavoklis 00cb (vai 10cb,ja ieprieks atradas stavokli 10c)
            {
                 if(input_string[i+2]=='c')///ja nakamais ievaditais simbols ir "c" jeb stavoklis 01 (vai 11,ja ieprieks atradas stavokli 10cb)
                 {
                     return true;///atgriez true, jo simbolu virkne satur "cbc"
                 }
            }
        }
    }
    return false;///atgriez false, ja simbolu virkne nesatur "cbc"
};

bool error_check(string input_string)///funkcija ievadito simbolu kludu parbaudei
{
    int i=0;
    while(input_string[i]!=0)
    {
        if(input_string[i]<'a' ||input_string[i]>'c')
        {
            return true; ///ja ievada burtus, kas nav alfabeta sigma, tad atgriez - true="ir kluda"!
        }
        i++;
    }
    return false;///ja nav kludu, tad atgriez - false="nav kludu"!
}
