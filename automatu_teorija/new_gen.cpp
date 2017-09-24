///Ronalds Rundans rr11043
///Formalas gramatikas papildus md
///Programma izdruka kopa 216018 dazadas simbolu virknes
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream fout;
    fout.open("out.txt",ios::out);
    int arr[10]={0,0,0,0,0,0,0,0,0,0};
    int i=0,k=0,m=0,n=0,o=0,p=0,q=0,r=0,s=0,j=0,sum=0, num=0;
    char c1[3]="ab";
    char c2[6]="ab+-*";
    char c[11];
    c[10]=0;
    ///Visi iespejamas simbolu virknes tiek generetas ar cikliem
    ///Ciklos veidotie skaitli glabajas masiva arr, kas norada
    ///kuru simbolu no masiviem c1(ja tas bus simbols masiva c[9]pozicijai) un parejie no c2
    ///jaiekope masiva c, pirms tas tiks izdrukats
    ///Piemeram arr[0] glabajas "1" un masiva c[0] tiks iekopets c[0]=c2[arr[0]], kas bus simbols "b"
    ///Ja bus arr[0] bus "0" un arr[1]="1", tad masiva c[0] bus simbols "a" un c[1] bus simbols"b"

    for(j=0;j<3;j++)///pos 9 (katrs for cikls atbilst simbola pozicijai masivam c), piem., sis atbild par c[9]
    {
        arr[9]=j;
        for(s=0;s<6;s++)///pos 8
        {
            arr[8]=s;
            for(r=0;r<6;r++)///pos 7
            {
                arr[7]=r;
                for(q=0;q<6;q++)///pos 6
                {
                    arr[6]=q;
                    for(p=0;p<6;p++)///pos 5
                    {
                        arr[5]=p;
                        for(o=0;o<6;o++)///pos 4
                        {
                            arr[4]=o;
                            for(n=0;n<6;n++) ///pos 3
                            {
                                arr[3]=n;
                                for(m=0;m<6;m++)   ///pos 2
                                {
                                    arr[2]=m;
                                    for(k=0;k<6;k++)    ///pos 1
                                    {
                                        arr[1]=k;
                                        for(i=0;i<2;i++)///pos 0
                                        {
                                            arr[0]=i;

                                            ///pos 0
                                            c[0]=c1[arr[0]];///te bus tikai "a" un "b" simboli

                                            ///pos1
                                            sum=0;///ar so mainigo sum un nakamajiem if nosacijumiem
                                            ///kontrole to lai nedruka simbolus
                                            ///"+","-","*" un "/0" blakus vienu otram
                                            ///simboli ir ar sadam vertibam
                                            ///"a"=0, "b"=1, "+"=2, "-"=3, "*"=4,"/0"=5
                                            ///t.i. simbolus pozicijas no masiva c2
                                            if (arr[1]>1)
                                            {
                                                sum=sum+2;
                                            }
                                            if (arr[1]==5)
                                            {
                                                sum=sum+2;
                                            }
                                            if (arr[2]>1 )
                                            {
                                                sum=sum+2;
                                            }
                                            ///"/0" druka tikai tad, ja nakamais simbols ari ir "/0"(beigu simbols)
                                            if (arr[2]==5 && arr[1]==5 )c[1]=c2[arr[1]];
                                            else if (sum<4)c[1]=c2[arr[1]];///drikst izpildities tikai 1 nosacijums no ieprieksejiem if
                                            else continue;///izlaiz, ja sanak "a++a", "---" un tml.nederigas virknes

                                            ///pos2
                                            sum=0;
                                            if (arr[2]>1)
                                            {
                                                sum=sum+2;
                                            }
                                            if (arr[2]==5)
                                            {
                                                sum=sum+2;
                                            }
                                            if (arr[3]>1)
                                            {
                                                sum=sum+2;
                                            }
                                            if (arr[3]==5 && arr[2]==5) c[2]=c2[arr[2]];
                                            else if (sum<4)c[2]=c2[arr[2]];
                                            else continue;

                                            ///pos3
                                            sum=0;
                                            if (arr[3]>1)
                                            {
                                                sum=sum+2;
                                            }
                                            if (arr[3]==5)
                                            {
                                                sum=sum+2;
                                            }
                                            if (arr[4]>1)
                                            {
                                                sum=sum+2;
                                            }
                                            if (arr[4]==5 && arr[3]==5)c[3]=c2[arr[3]];
                                            else if (sum<4)c[3]=c2[arr[3]];
                                            else continue;

                                             ///pos4

                                            sum=0;
                                            if (arr[4]>1)
                                            {
                                                sum=sum+2;
                                            }
                                            if (arr[4]==5)
                                            {
                                                sum=sum+2;
                                            }
                                            if (arr[5]>1)
                                            {
                                                sum=sum+2;
                                            }
                                            if (arr[5]==5 && arr[4]==5)c[4]=c2[arr[4]];
                                            else if (sum<4)c[4]=c2[arr[4]];
                                            else continue;

                                             ///pos5
                                            sum=0;
                                            if (arr[5]>1)
                                            {
                                                sum=sum+2;
                                            }
                                            if (arr[5]==5)
                                            {
                                                sum=sum+2;
                                            }
                                            if (arr[6]>1)
                                            {
                                                sum=sum+2;
                                            }
                                            if (arr[6]==5 && arr[5]==5)c[5]=c2[arr[5]];
                                            else if (sum<4)c[5]=c2[arr[5]];
                                            else continue;

                                                ///pos6
                                            sum=0;
                                            if (arr[6]>1)
                                            {
                                                sum=sum+2;
                                            }
                                            if (arr[6]==5)
                                            {
                                                sum=sum+2;
                                            }
                                            if (arr[7]>1)
                                            {
                                                sum=sum+2;
                                            }
                                            if (arr[7]==5 && arr[6]==5) c[6]=c2[arr[6]];
                                            else if (sum<4)c[6]=c2[arr[6]];
                                            else continue;

                                                ///pos7
                                            sum=0;
                                            if (arr[7]>1)
                                            {
                                                sum=sum+2;
                                            }
                                            if (arr[7]==5)
                                            {
                                                sum=sum+2;
                                            }
                                            if (arr[8]>1)
                                            {
                                                sum=sum+2;
                                            }
                                            if (arr[8]==5 && arr[7]==5) c[7]=c2[arr[7]];
                                            else if (sum<4)c[7]=c2[arr[7]];
                                            else continue;

                                            ///pos8
                                            sum=0;
                                            if (arr[8]>1)
                                            {
                                                sum=sum+2;
                                            }
                                            if (arr[8]==5)
                                            {
                                                sum=sum+2;
                                            }
                                            if(arr[9]==2)
                                            {
                                                sum=sum+2;
                                            }
                                            if (arr[9]==2 && arr[8]==5)c[8]=c2[arr[8]];
                                            else if (sum<4)c[8]=c2[arr[8]];///ja (nak) pos ir"/0" un pats a vai b
                                            else continue;

                                            ///pos9
                                            c[9]=c1[arr[9]];
                                            num++;
                                            fout<<"c="<<c<<" n="<<num<<endl;///izdrukasana, num ir kartas skaitlis
                                        }///pos 0
                                    }///pos 1
                                }///pos 2
                            }///pos 3
                        }///pos 4
                    }///pos 5
                }///pos 6
            }///pos 7
        }///pos 8
    }///pos 9
    return 0;
}

