#include "floor.h"
#include <exception>
#include <iostream>
#include <array>
#include <string>

Floor::Floor() // constructor
{
    tab = new string[LENGTH];
    for (int i = 0; i < LENGTH; i++)
        tab[i] = ' ';
    Snows = 0;
}

Floor::~Floor() //destructor
{
    delete[] tab;
}

void Floor::displayFloor() //print
{
    for (int i = 0; i < LENGTH; i++)
    {
        cout << tab[i];
        cout << endl;
    }
}

void Floor::addSnowman()
{
    if (Snows == 3)
    {
        cout << "You can put only three snowmans under the tree... [ENTER]" << endl;
        getchar();
        getchar();
    }
    else
    {

        enum numpath
        {
            Hat,
            Nose,
            LeftEye,
            RightEye,
            LeftArm,
            RightArm,
            Torso,
            Base

        };

        system("Color XY"); // X for the Background, Y for the text color
        cout << "       ///////////***** Inventory *****\\\\\\\\\\\\\n"
             << endl;
        cout << "\nID\tHats\tNoses\tEyes\tArms\tTorsos\tBases\n"
             << "[1]" << '\t' << "_===_" << '\t' << "," << '\t' << "." << '\t' << " " << '\t' << " : " << '\t' << " : "
             << "\n";

        cout << "\n[2]" << '\t' << " ___ \n\t....." << '\t' << "." << '\t' << "o" << '\t' << "\\" << '\t' << "] [" << '\t' << "\" \""
             << "\n";
        cout << "[3]" << '\t' << "  _\n\t /_\\" << '\t' << "_" << '\t' << "O" << '\t' << "<" << '\t' << "> <" << '\t' << "___"
             << "\n";
        cout << "[4]" << '\t' << " ___\n\t(_*_)" << '\t' << " " << '\t' << "-" << '\t' << "/" << '\t' << "   " << '\t' << "   " << endl;
        cout << "\n"
             << endl;
        cout << "Enter numbers to creat a snowman\n"
             << endl;
        int snowman;
        cin >> snowman;

        //Check if input isn't valid.
        if (snowman < 11111111 || snowman > 44444444)
        {
            //__throw_invalid_argument("Error! Not a valid input");
            __throw_out_of_range("Error! not a valid input");
        }
        else
        {
            array<int, 8> arr = {};
            //check if the numbers are valid
            for (int i = 0; i < 8; i++)
            {
                if (snowman % 10 > 4 || snowman % 10 < 1)
                {
                    __throw_out_of_range("Error! Not a valid input");
                }
                arr.at(7 - i) = snowman % 10;
                snowman = snowman / 10;
            }

            // strings arrays to access each component.
            const array<string, 5> hats = {"", "_===_", " ___\n .....", "  _  \n  /_\\ \n", " ___\n (_*_)\n"};
            const array<string, 5> noses = {"", ",", ".", "_", " "};
            const array<string, 5> Lefteye = {"", ".", "o", "O", "-"};
            const array<string, 5> Righteye = {"", ".", "o", "O", "-"};
            const array<string, 5> LeftArmTop = {"", " ", "\\", " ", " "};
            const array<string, 5> Leftarm = {"", "<", " ", "/", " "};
            const array<string, 5> RightArmTop = {"", " ", "/", " ", " "};
            const array<string, 5> Rightarm = {"", ">", " ", "\\", " "};
            const array<string, 5> torsos = {"", " : ", "] [", "> <", "   "};
            const array<string, 5> bases = {"", " : ", "\" \"", "___", "   "};

            //string hats = " " + hat.at(arr.at(H));
            string face = LeftArmTop.at(arr.at(LeftArm)) + "(" + Lefteye.at(arr.at(LeftEye)) + noses.at(arr.at(Nose)) + Righteye.at(arr.at(RightEye)) + ")" + RightArmTop.at(arr.at(LeftArm));
            string torsosy = Leftarm.at(arr.at(LeftArm)) + "(" + torsos.at(arr.at(Torso)) + ")" + RightArmTop.at(arr.at(LeftArm));
            string basesy = " (" + bases.at(arr.at(Base)) + ")";

            string Tophat = "    ";
            string Lowhat = "";
            switch (arr.at(Hat))
            {
            case 1:
                Lowhat = "_===_";
                break;
            case 2:
                Tophat = " ___";
                Lowhat = ".....";
                break;
            case 3:
                Tophat = " _";
                Lowhat = "/_\\";
                break;
            case 4:
                Tophat = " ___";
                Lowhat = "(_*_)";
                break;
            default:
                break;
            }

            tab[0] += string(6, ' ') + Tophat + string(6, ' ');
            tab[1] += string(6, ' ') + Lowhat + string(5, ' ');
            tab[2] += string(5, ' ') + face + string(4, ' ');
            tab[3] += string(5, ' ') + torsosy + string(4, ' ');
            tab[4] += string(5, ' ') + basesy + string(5, ' ');

            // tab[0] += string(6, ' ') + hats + string(6, ' ');
            // tab[1] += string(6, ' ') + face + string(6, ' ');
            // tab[2] += string(6, ' ') + torsos + string(6, ' ');
            // tab[3] += string(6, ' ') + bases + string(6, ' ');

            // tab[0] += string(6, ' ') + '_' + string(3, ' ') + '_' + string(9, ' ');
            // tab[1] += string(5, '  ') + "((\\o/))" + string(8, ' ');
            // tab[2] += '.' + string(5, '-') + "//" + '^' + "\\\\" + string(5, '-') + '.' + string(3, ' ');
            // tab[3] += '|' + string("") + "/ | | \\" + string(4, ' ') + '|' + string(3, ' ');
            // tab[4] += '|' + string(6, ' ') + "| |" + string(6, ' ') + '|' + string(3, ' ');
            // tab[5] += '\'' + string(6, '-') + string(3, '=') + string(6, '-') + '\'' + string(3, ' ');

            // string snowstring = " " + hat.at(arr.at(H)) +
            //                     highLA.at(arr.at(X)) + "(" + lEye.at(arr.at(L)) + nose.at(arr.at(N)) + rEye.at(arr.at(R)) + ")" + highRA.at(arr.at(Y)) + "\n" +
            //                     lowLA.at(arr.at(X)) + "(" + torso.at(arr.at(T)) + ")" + lowRA.at(arr.at(Y)) + "\n (" +
            //                     base.at(arr.at(B)) + ")";
            Snows++;
        }
    }
}

void Floor::exportFloor(string card)
{
    fstream file; // use for file
    file.open(card, ios::app);
    for (int i = 0; i < LENGTH; i++)
    {
        file << tab[i] << endl;
    }
    file.close();
}
