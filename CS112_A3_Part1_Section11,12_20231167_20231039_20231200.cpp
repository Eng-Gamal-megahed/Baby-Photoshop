// File: CS112_A3_Part1_Section11,12_20231167_20231039_20231200.cpp
// Purpose: The program do a variety of filters on images.
// Version: 2.3
// Authors:
// -Gamal Megahed Sayed Mohamed (20231039) (eng.gamalmegahed@gmail.com), Section 12 , Did Filter_1 , Filter_4 , Filter_7.
// -Mostafa Ehab Mostafa Akl (20231167) (mostafaehabakl@gmail.com) , Section 12 , Did Filter_2 , Filter_5 , Filter_8.
// -Walid Adel Mordy Rohyem (20231200) (khattabadel112005@gmail.com), Section 11 , Did Filter_3 . Filter_6.
//=================================================================================================================================
#include <iostream>
#include <limits>
#include <cstdlib>
#include <string>
#include <cstdio>
#include "Image_Class.h"
using namespace std;
string SYSTEM_COLOR;
string RESET_COLOR = "\033[0m";
string BOLD = "\033[1;37m";
string RED = "\033[1;31m";
string BLUE = "\033[1;34m";
string YELLOW = "\033[1;33m";
string WHITE = "\033[1;37m";
string GREEN = "\033[1;32m";
string CYAN = "\033[1;36m";
string PURPLE = "\033[1;35m";

int get_int(const string &);
string color();
Image Gamal_gray_scale(string);
Image Gamal_Merge_Images(string);
Image Gamal_Darken_and_Lighten_Image(string);
Image Black_and_White(string);
Image Flip_Image(string);
Image Crop_Images(string);
Image Rotate_Image(string);
Image Invert_Image(string);
string get_image(string);
Image Frame_image(string);
Image Gamal_detect_edges(string);
Image Gamal_sunlight(string);
bool valid_exe(string);
// string saveBefore(bool);
bool unsaved_image = false;
Image saved_image;

int main()
{
    system("chcp 65001"); // Set the console code page to UTF-8
    string Gamal_Khatab_Mostafa_filename;
    int choice; // Welcome message
    cout << BOLD << "🤩🥰❤ Ahllan Ya User Ya Habyby ❤🥰🤩\n"
         << RESET_COLOR;
    SYSTEM_COLOR = color();
    cout << "===========================================================\n";
    cout << "===========================================================\n";

    // get the Gamal_Khatab_Mostafa_filename or image name from the user.
    Gamal_Khatab_Mostafa_filename = get_image(SYSTEM_COLOR + "Enter the file(image) you want to do filters on:" + RESET_COLOR);

    while (true)
    { // let the user choose the filter he wants
        cout << SYSTEM_COLOR << "Which filter do you want?\n0) Load a new image.\n1) Grayscale Conversion.\n2) Black and White.\n3) Invert Image.\n4) Merge Images.\n5) Flip Image.\n6) Rotate Image.\n7) Darken and Lighten Image.\n8) Crop Images. \n9) Frame \n10) Detect Edges\n13) Natural Sunlight\n19) Save the image.\n20) Exit\n"
             << RESET_COLOR;
        choice = get_int("Enter your choice: "); // Check the validation of the input
        while (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9 && choice != 10 && choice != 13 && choice != 19 && choice != 20)
        {
            cout << RED << "Invalid input! PLease, Follow the instructions.\n"
                 << RESET_COLOR;
            cout << SYSTEM_COLOR << "Which filter do you want?\n0) Load a new image.\n1) Grayscale Conversion.\n2) Black and White.\n3) Invert Image.\n4) Merge Images.\n5) Flip Image.\n6) Rotate Image.\n7) Darken and Lighten Image.\n8) Crop Images.\n9) Frame \n10) Detect Edges\n13) Natural Sunlight\n19) Save the image.\n20) Exit\n"
                 << RESET_COLOR;
            choice = get_int("Enter your choice: ");
        }
        if (choice == 0)
        { // let the user choose if he wants to save the image on the same file or diffrent file
            if (unsaved_image)
            {
                bool flag = true;
                string ch;
                while (flag)
                { // and add new changes on the image and save them too
                    cout << SYSTEM_COLOR << "Do you want to save your changes on the last image:\n1)Yes\n2)No" << RESET_COLOR;
                    cin >> ch;
                    if (ch == "1")
                    {
                        char c;
                        cout << SYSTEM_COLOR << "Do you want to save changes in the same image?\n"
                             << "a)Yes\n"
                             << "b)No\n"
                             << RESET_COLOR;
                        cin >> c;
                        while (c != 'a' && c != 'b') // Check the validation of the input
                        {
                            cout << RED << "invalid choice\n"
                                 << RESET_COLOR;
                            cout << SYSTEM_COLOR << "Do you want to save changes in the same image?\n"
                                 << "a)Yes\n"
                                 << "b)No\n"
                                 << RESET_COLOR;
                            cin >> c;
                        }
                        if (c == 'a') // Save the changes
                        {
                            string new_filename = Gamal_Khatab_Mostafa_filename, old_filename = "saved.jpg";
                            ;
                            remove(Gamal_Khatab_Mostafa_filename.c_str());
                            rename(old_filename.c_str(), new_filename.c_str());
                            system(Gamal_Khatab_Mostafa_filename.c_str());
                        }
                        else if (c == 'b') // Don`t save the changes
                        {
                            string new_filename, old_filename = "saved.jpg";
                            ;
                            cout << "Pls enter image name to store new image\n";
                            cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                            cin >> new_filename;
                            while (!valid_exe(new_filename)) // Check if he insrted a valid extension
                            {
                                cout << RED << "Invalid extention, please follow the instructions\n"
                                     << RESET_COLOR;
                                cout << SYSTEM_COLOR << "Pls enter image name to store new image\n";
                                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                                cin >> new_filename;
                            }
                            rename(old_filename.c_str(), new_filename.c_str());
                            system(new_filename.c_str());
                        }

                        flag = false;
                    }
                    else if (ch == "2")
                    { // Insert a Gamal_Khatab_Mostafa_filename or image that he wants to apply the filter on.
                        Gamal_Khatab_Mostafa_filename = get_image(SYSTEM_COLOR + "Enter the file(image) you want to do filters on: " + RESET_COLOR);
                        flag = false;
                    }
                    else // ask him to restart ar repeat this stage again ( Invalid iput )
                    {
                        cout << RED << "Invalid choice, please follow the instructions\n"
                             << RESET_COLOR;
                    }
                }
            }
            else
            {
                Gamal_Khatab_Mostafa_filename = get_image(SYSTEM_COLOR + "Enter the file(image) you want to do filters on:" + RESET_COLOR);
            }
            unsaved_image = false;
        } // Now let the user choose the ideal filter to apply it
        else if (choice == 1)
        {
            remove("saved.jpg");
            Gamal_gray_scale(Gamal_Khatab_Mostafa_filename);
        }
        else if (choice == 2)
        {
            remove("saved.jpg");
            Black_and_White(Gamal_Khatab_Mostafa_filename);
        }
        else if (choice == 3)
        {
            remove("saved.jpg");
            Invert_Image(Gamal_Khatab_Mostafa_filename);
        }
        else if (choice == 4)
        {
            remove("saved.jpg");
            Gamal_Merge_Images(Gamal_Khatab_Mostafa_filename);
        }
        else if (choice == 5)
        {
            remove("saved.jpg");
            Flip_Image(Gamal_Khatab_Mostafa_filename);
        }
        else if (choice == 6)
        {
            remove("saved.jpg");
            Rotate_Image(Gamal_Khatab_Mostafa_filename);
        }
        else if (choice == 7)
        {
            remove("saved.jpg");
            Gamal_Darken_and_Lighten_Image(Gamal_Khatab_Mostafa_filename);
        }
        else if (choice == 8)
        {
            remove("saved.jpg");
            Crop_Images(Gamal_Khatab_Mostafa_filename);
        }
        else if (choice == 9)
        {
            remove("saved.jpg");
            Frame_image(Gamal_Khatab_Mostafa_filename);
        }
        else if (choice == 10)
        {
            remove("saved.jpg");
            Gamal_detect_edges(Gamal_Khatab_Mostafa_filename);
        }
        else if (choice == 13)
        {
            remove("saved.jpg");
            Gamal_sunlight(Gamal_Khatab_Mostafa_filename);
        }
        else if (choice == 19)
        {
            char c; // ask him if he wants to save these canges on the image or change it, too
            cout << SYSTEM_COLOR << "Do you want to save changes in the same image?\n"
                 << "a)Yes\n"
                 << "b)No\n"
                 << RESET_COLOR;
            cin >> c; // Check the validation of the input
            while (c != 'a' && c != 'b')
            {
                cout << RED << "invalid choice\n"
                     << RESET_COLOR;
                cout << SYSTEM_COLOR << "Do you want to save changes in the same image?\n"
                     << "a)Yes\n"
                     << "b)No\n"
                     << RESET_COLOR;
                cin >> c;
            }
            if (c == 'a') // save the changes on thesame image
            {
                string new_filename = Gamal_Khatab_Mostafa_filename, old_filename = "saved.jpg";
                ;
                remove(Gamal_Khatab_Mostafa_filename.c_str());
                rename(old_filename.c_str(), new_filename.c_str());
                system(Gamal_Khatab_Mostafa_filename.c_str());
            }
            else if (c == 'b')
            {
                string new_filename, old_filename = "saved.jpg";
                ;
                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                cin >> new_filename;
                while (!valid_exe(new_filename))
                {
                    cout << RED << "Invalid extention, please follow the instructions\n"
                         << RESET_COLOR;
                    cout << SYSTEM_COLOR << "Pls enter image name to store new image\n";
                    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                    cin >> new_filename;
                }
                rename(old_filename.c_str(), new_filename.c_str());
                system(new_filename.c_str());
            }
            unsaved_image = false;
        }
        else if (choice == 20)
        {
            if (unsaved_image)
            {
                bool flag = true;
                string ch;
                while (flag)
                { // if he wants to save these changes on the last image or not
                    cout << SYSTEM_COLOR << "Do you want to save your changes on the last image:\n1)Yes\n2)No" << RESET_COLOR;
                    cin >> ch;
                    if (ch == "1")
                    {
                        char c;
                        cout << SYSTEM_COLOR << "Do you want to save changes in the same image?\n"
                             << "a)Yes\n"
                             << "b)No\n"
                             << RESET_COLOR;
                        cin >> c; // Check the validation of the input
                        while (c != 'a' && c != 'b')
                        {
                            cout << RED << "invalid choice\n"
                                 << RESET_COLOR;
                            cout << SYSTEM_COLOR << "Do you want to save changes in the same image?\n"
                                 << "a)Yes\n"
                                 << "b)No\n"
                                 << RESET_COLOR;
                            cin >> c;
                        }
                        if (c == 'a')
                        {
                            string new_filename = Gamal_Khatab_Mostafa_filename, old_filename = "saved.jpg";
                            ;
                            remove(Gamal_Khatab_Mostafa_filename.c_str());
                            rename(old_filename.c_str(), new_filename.c_str());
                            system(Gamal_Khatab_Mostafa_filename.c_str());
                        }
                        else if (c == 'b')
                        {
                            string new_filename, old_filename = "saved.jpg";
                            ;
                            cout << "Pls enter image name to store new image\n";
                            cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                            cin >> new_filename;
                            while (!valid_exe(new_filename)) // Check if the exetension is valid or not
                            {
                                cout << RED << "Invalid extention, please follow the instructions\n"
                                     << RESET_COLOR;
                                cout << SYSTEM_COLOR << "Pls enter image name to store new image\n";
                                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                                cin >> new_filename;
                            }
                            rename(old_filename.c_str(), new_filename.c_str());
                            system(new_filename.c_str());
                        }
                        unsaved_image = false;
                        flag = false;
                    }
                    else if (ch == "2")
                    {
                        remove("saved.jpg");
                        cout << SYSTEM_COLOR << "Thanks for using the program! 🥰" << RESET_COLOR;
                        return 0;
                    }
                    else // restart again
                    {
                        cout << RED << "Invalid choice, please follow the instructions\n"
                             << RESET_COLOR;
                    }
                }
            }
            else
            { // end the program
                remove("saved.jpg");
                cout << SYSTEM_COLOR << "Thanks for using the program! 🥰" << RESET_COLOR;
                return 0;
            }
        }
        else // restart this stage again invalid input
        {
            cout << RED << "Invalid choice, please follow the instructions\n"
                 << RESET_COLOR;
        }
        cout << "===========================================================\n";
        cout << "===========================================================\n";
    }
    return 0;
}
//===================================================================================================================

string get_image(string message = "")
{ // get the image name and check its validation
    string image_name;
    cout << message;
    cin >> image_name;
    Image image;
    while (true)
    { // Check its validation
        try
        {
            image.loadNewImage(image_name);
            break;
        }
        catch (invalid_argument)
        {
            cout << RED << "Please enter a valid photo \n"
                 << RESET_COLOR;
            cin >> image_name;
        }
    }
    return image_name;
}
int get_int(const string &message = "")
{
    int num = 0;
    cout << SYSTEM_COLOR << message << RESET_COLOR;
    cin >> num;
    while (cin.fail())
    {
        cout << RED << "Invalid Input! Please, follow the instructions\n"
             << RESET_COLOR;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << message << RESET_COLOR;
        cin >> num;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return num;
}
string color()
{
    int color;
    string player_color;
    cout << BOLD << "Chose system color \n(1) Blue\n(2) Yellow\n(3) White\n(4) Green\n(5) Cyan\n(6) Purple\n"
         << RESET_COLOR;
    color = get_int();
    while (color != 1 && color != 2 && color != 3 && color != 4 && color != 5 && color != 6)
    {
        cout << RED << "Invalid color. Please choose again\n"
             << RESET_COLOR;
        cout << BOLD << "Chose system color \n(1) Blue\n(2) Yellow\n(3) White\n(4) Green\n(5) Cyan\n(6) Purple\n"
             << RESET_COLOR;
        color = get_int();
    }
    if (color == 1)
        player_color = BLUE;
    else if (color == 2)
        player_color = YELLOW;
    else if (color == 3)
        player_color = WHITE;
    else if (color == 4)
        player_color = GREEN;
    else if (color == 5)
        player_color = CYAN;
    else
        player_color = PURPLE;
    return player_color;
}
//==========================================================================================================================
Image Rotate_Image(string Gamal_Khatab_Mostafa_filename)
{
    Image khattab_image(Gamal_Khatab_Mostafa_filename);
    int angle; // Insert the angle
    cout << SYSTEM_COLOR << "Enter the Angle ( 90 , 180 , 270 ,360): " << RESET_COLOR;
    angle = get_int();
    // Check its validation
    while (cin.fail() || (angle != 90 && angle != 180 && angle != 270 && angle != 360))
    {
        cout << RED << "Invalid input! Plaese, Follow the instructions." << RESET_COLOR << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << SYSTEM_COLOR << "Enter the Angle ( 90 , 180 , 270 , 360 ): " << RESET_COLOR;
        cin >> angle;
    }
    if (angle == 90)
    { // you have to replace between the height and the width of the origin image

        Image khattab_image2(khattab_image.height, khattab_image.width);
        for (int i = 0; i < khattab_image.width; i++)
        { // rows
            for (int j = 0; j < khattab_image.height; j++)
            { // columns
                for (int k = 0; k < 3; k++)
                { // channels
                    khattab_image2(khattab_image.height - j - 1, i, k) = khattab_image(i, j, k);
                }
            }
        }
        khattab_image2.saveImage("saved.jpg");
    }
    else if (angle == 180)
    {
        // Load the original image
        Image khattab_image2(khattab_image.width, khattab_image.height); // Create a new image with the same dimensions

        // Iterate over the original image pixels and copy them to the rotated image with adjusted coordinates
        for (int i = 0; i < khattab_image.width; i++)
        {
            for (int j = 0; j < khattab_image.height; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    // Copy pixel from original image to rotated image with adjusted coordinates for 180-degree rotation
                    khattab_image2(khattab_image.width - i - 1, khattab_image.height - j - 1, k) = khattab_image(i, j, k);
                }
            }
        }

        khattab_image2.saveImage("saved.jpg");
    }
    else if (angle == 270)
    {                                                                    // Load the original image
        Image khattab_image2(khattab_image.height, khattab_image.width); // Create a new image with swapped dimensions

        // Iterate over the original image pixels and copy them to the rotated image with swapped coordinates
        for (int i = 0; i < khattab_image.width; i++)
        {
            for (int j = 0; j < khattab_image.height; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    // Copy pixel from original image to rotated image with swapped coordinates
                    khattab_image2(j, khattab_image.width - i - 1, k) = khattab_image(i, j, k);
                }
            }
        }
        khattab_image2.saveImage("saved.jpg");
    }
    else if (angle == 360)
    { // output the image with the same attributes
        Image khattab_image2(khattab_image.width, khattab_image.height);
        for (int i = 0; i < khattab_image.width; i++)
        {
            for (int j = 0; j < khattab_image.height; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    khattab_image2(i, j, k) = khattab_image(i, j, k);
                }
            }
        }

        khattab_image2.saveImage("saved.jpg");
    }

    unsaved_image = true;
    return khattab_image;
}
//===========================================================================================

bool valid_exe(string exe)
{
    // (.png, .jpeg, .jpg, .bmp)
    string validexet[]{".jpg", ".png", ".jpeg", ".bmp"}; // valid exetension
    for (int i = 0; i < exe.size(); i++)
    {
        if (exe[i] == '.')
        {
            string exet = exe.substr(i);
            for (string str : validexet)
            {
                if (str == exet)
                    return true;
            }
        }
    }
    return false;
}

Image Invert_Image(string Gamal_Khatab_Mostafa_filename)
{

    Image khattab_image(Gamal_Khatab_Mostafa_filename); // to invert the image i have to subtract the current value of the color from 255

    for (int i = 0; i < khattab_image.width; i++)
    {
        for (int j = 0; j < khattab_image.height; j++)
        {
            unsigned int avg = 0;
            for (int k = 0; k < 3; k++)
            { // subtract the channels`values from 255 to invert them
                khattab_image(i, j, k) = 255 - khattab_image(i, j, k);
            }
        }
    }

    khattab_image.saveImage("saved.jpg");

    unsaved_image = true;
    return khattab_image;
}
//=================================================================================================================
Image Gamal_gray_scale(string Gamal_filename)
{

    Image Gamal_image(Gamal_filename);

    // loop for the columns
    for (int Gamal_i = 0; Gamal_i < Gamal_image.width; ++Gamal_i)
    {
        for (int Gamal_j = 0; Gamal_j < Gamal_image.height; ++Gamal_j)
        {
            unsigned int Gamal_average = 0;
            // loop for the columns
            for (int Gamal_k = 0; Gamal_k < 3; ++Gamal_k)
            {
                Gamal_average += Gamal_image(Gamal_i, Gamal_j, Gamal_k);
            } // first get the average
            Gamal_average /= 3;
            for (int Gamal_k = 0; Gamal_k < 3; Gamal_k++)
            {
                Gamal_image(Gamal_i, Gamal_j, Gamal_k) = Gamal_average;
            }
        }
    }

    Gamal_image.saveImage("saved.jpg");
    unsaved_image = true;
    return Gamal_image;
}
//====================================================================================================================
Image Gamal_Merge_Images(string Gamal_frst_photo)
{
    string Gamal_scnd_photo, Gamal_merged_name;

    Gamal_scnd_photo = get_image(SYSTEM_COLOR + "Pls enter second image name : "); // read the second image from the user

    Image Gamal_frst(Gamal_frst_photo), Gamal_scnd(Gamal_scnd_photo);
    int Gamal_min_width = min(Gamal_frst.width, Gamal_scnd.width);
    int Gamal_min_height = min(Gamal_frst.height, Gamal_scnd.height);
    Image Gamal_merged(Gamal_min_width, Gamal_min_height);
    for (int Gamal_i = 0; Gamal_i < Gamal_min_width; ++Gamal_i)
    {
        for (int Gamal_j = 0; Gamal_j < Gamal_min_height; ++Gamal_j)
        {

            Gamal_merged(Gamal_i, Gamal_j, 0) = (Gamal_frst(Gamal_i, Gamal_j, 0) + Gamal_scnd(Gamal_i, Gamal_j, 0)) / 2;
            Gamal_merged(Gamal_i, Gamal_j, 1) = (Gamal_frst(Gamal_i, Gamal_j, 1) + Gamal_scnd(Gamal_i, Gamal_j, 1)) / 2;
            Gamal_merged(Gamal_i, Gamal_j, 2) = (Gamal_frst(Gamal_i, Gamal_j, 2) + Gamal_scnd(Gamal_i, Gamal_j, 2)) / 2;
        }
    }

    Gamal_merged.saveImage("saved.jpg");
    //        system(Gamal_merged_name.c_str());
    //    }
    unsaved_image = true;
    return Gamal_merged;
}
//====================================================================================================================
Image Gamal_Darken_and_Lighten_Image(string Gamal_filename)
{
    //    string Gamal_filename;
    //    Gamal_filename = get_image(SYSTEM_COLOR + "Pls enter colored image name: ");
    Image Gamal_image(Gamal_filename);
    char Gamal_choice1, Gamal_choice2;
    cout << SYSTEM_COLOR << "What do you want to do ?\n"
         << "a)Lighten Image\n"
         << "b)Darken Image\n"
         << "choice:";
    cin >> Gamal_choice1;
    while (Gamal_choice1 != 'a' && Gamal_choice1 != 'b')
    {
        cout << RED << "invalid choice, please follow the instructions\n"
             << RESET_COLOR;
        cout << SYSTEM_COLOR << "What do you want to do ?\n"
             << "a)Lighten Image\n"
             << "b)Darken Image\n"
             << "choice:";
        cin >> Gamal_choice1;
    }
    for (int Gamal_i = 0; Gamal_i < Gamal_image.width; ++Gamal_i)
    {
        for (int Gamal_j = 0; Gamal_j < Gamal_image.height; ++Gamal_j)
        {
            if (Gamal_choice1 == 'a')
            {
                Gamal_image(Gamal_i, Gamal_j, 0) = min(Gamal_image(Gamal_i, Gamal_j, 0) * 2, 255);
                Gamal_image(Gamal_i, Gamal_j, 1) = min(Gamal_image(Gamal_i, Gamal_j, 1) * 2, 255);
                Gamal_image(Gamal_i, Gamal_j, 2) = min(Gamal_image(Gamal_i, Gamal_j, 2) * 2, 255);
            }
            else if (Gamal_choice1 == 'b')
            {
                Gamal_image(Gamal_i, Gamal_j, 0) = Gamal_image(Gamal_i, Gamal_j, 0) / 2;
                Gamal_image(Gamal_i, Gamal_j, 1) = Gamal_image(Gamal_i, Gamal_j, 1) / 2;
                Gamal_image(Gamal_i, Gamal_j, 2) = Gamal_image(Gamal_i, Gamal_j, 2) / 2;
            }
        }
    }

    Gamal_image.saveImage("saved.jpg");
    //        system(Gamal_filename.c_str());
    //    }
    unsaved_image = true;
    return Gamal_image;
}
//=====================================================================================================================
Image Black_and_White(string Mustafa_filename)
{

    // Take image.
    Image Mustafa_image(Mustafa_filename);

    for (int i = 0; i < Mustafa_image.width; ++i)
    {
        for (int j = 0; j < Mustafa_image.height; ++j)
        {
            unsigned int Mustafa_average = 0; // Initialize average value

            for (int k = 0; k < 3; ++k)
            {
                // Take the average to know if the color of the pixel is dark of light.
                Mustafa_average += Mustafa_image(i, j, k); // Accumulate pixel values
            }

            Mustafa_average /= 3; // Calculate average

            for (int k = 0; k < 3; ++k)
            {
                // change every light pixel to wight.
                if (Mustafa_average > 127)
                {
                    Mustafa_image(i, j, k) = 255;
                }
                // change every dark pixel to black.
                else if (Mustafa_average <= 127)
                {
                    Mustafa_image(i, j, k) = 0;
                }
            }
        }
    }
    Mustafa_image.saveImage("saved.jpg");
    unsaved_image = true;
    return Mustafa_image;
}
//====================================================================================================================
Image Flip_Image(string Mustafa_filename)
{
    string choice;
    // take from the user the image name.
    Image Mustafa_image(Mustafa_filename);
    // make an image with the same width and height.
    Image Mustafa_image2(Mustafa_image.width, Mustafa_image.height);
    // know if the user want to continue by doing other operations or not.
    while (true)
    {
        cout << SYSTEM_COLOR << "What kind of flip do you want: \n1)Vertical flip\n2)Horizontal flip\n3)Exit" << RESET_COLOR << endl;
        cin >> choice;
        if (choice == "1")
        {
            for (int i = 0; i < Mustafa_image2.width; ++i)
            {
                for (int j = 0; j < Mustafa_image2.height; ++j)
                {
                    for (int k = 0; k < 3; ++k)
                    {
                        // swap every pixel with its opposite in the height.
                        Mustafa_image2(i, (j), k) = Mustafa_image(i, (Mustafa_image.height - j - 1), k); // Accumulate pixel values
                    }
                }
            }
            Mustafa_image2.saveImage("saved.jpg");
            unsaved_image = true;
            break;
        }
        else if (choice == "2")
        {
            for (int i = 0; i < Mustafa_image2.width; ++i)
            {
                for (int j = 0; j < Mustafa_image2.height; ++j)
                {
                    for (int k = 0; k < 3; ++k)
                    {
                        // swap every pixel with its opposite in the width.
                        Mustafa_image2(i, j, k) = Mustafa_image(Mustafa_image.width - i - 1, j, k); // Accumulate pixel values
                    }
                }
            }
            Mustafa_image2.saveImage("saved.jpg");
            unsaved_image = true;
            break;
        }
        else if (choice == "3")
        {
            break;
        }
        else
        {
            cout << RED << "Please, enter a valid input." << RESET_COLOR;
        }
    }
    return Mustafa_image;
}
//======================================================================================================================
Image Crop_Images(string Mustafa_filename)
{
    //    string Mustafa_filename;
    int width, height, x, y;
    // take from the user the image name.
    //    Mustafa_filename = get_image(SYSTEM_COLOR + "Please, enter the image name to crop it:\n" + RESET_COLOR);
    Image Mustafa_image(Mustafa_filename);
    while (true)
    {
        // take from the user the (X) coordinates.
        cout << SYSTEM_COLOR << "Please, enter the first coordinates of the starting point to crop the image (x):" << RESET_COLOR << endl;
        cin >> x;
        // take from the user the (Y) coordinates
        cout << SYSTEM_COLOR << "Please, enter the second coordinates of the starting point to crop the image (y):" << RESET_COLOR << endl;
        cin >> y;
        // take from the user the image width.
        cout << SYSTEM_COLOR << "Please, enter the colored image width:" << RESET_COLOR << endl;
        cin >> width;
        // take from the user the image height.
        cout << SYSTEM_COLOR << "Please, enter the colored image height:" << RESET_COLOR << endl;
        cin >> height;
        // check if the dimensions is correct
        if ((x + width > Mustafa_image.width) && (y + height > Mustafa_image.height))
        {
            cout << RED << "The dimensions is not valid to crop,please try again." << RESET_COLOR << endl;
        }
        else
        {
            break;
        }
    }
    Image Mustafa_image2(width, height);
    for (int i = x; i < x + Mustafa_image2.width; ++i)
    {
        for (int j = y; j < y + Mustafa_image2.height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                // copy the selected peace of the image to the new one.
                Mustafa_image2(i - x, j - y, k) = Mustafa_image(i, j, k); // Accumulate pixel values
            }
        }
    }
    Mustafa_image2.saveImage("saved.jpg");
    unsaved_image = true;
    return Mustafa_image;
}

Image Gamal_detect_edges(string image_name)
{
    // Load an image
    Image Gamal_image(image_name);

    // Create an instance for the output image
    Image Gamal_output_image(Gamal_image.width, Gamal_image.height);

    char Gamal_choice;
    // Prompt user to choose mood
    cout << SYSTEM_COLOR << "Which mood do you want?\n"
         << "a)🔥🔥 Fire Mood 🔥🔥\n"
         << "b)🥱🥱 Simple Mood 🥱🥱\n"
         << "Enter choice :";
    cin >> Gamal_choice;

    // Validate user input
    while (Gamal_choice != 'a' && Gamal_choice != 'b')
    {
        // Invalid choice, ask again
        cout << RED << "Invalid choice, please follow the instructions!\n"
             << SYSTEM_COLOR
             << "Which mood do you want?\n"
             << "a)🔥🔥 Fire Mood 🔥🔥\n"
             << "b)🥱 🥱 Simple Mood 🥱 🥱\n"
             << "Enter choice :";
        cin >> Gamal_choice;
    }

    if (Gamal_choice == 'a')
    {
        // Fire mood selected
        // Loop through each pixel in the image
        for (int y = 1; y < Gamal_image.height - 1; ++y)
        {
            for (int x = 1; x < Gamal_image.width - 1; ++x)
            {
                // Calculate horizontal gradient
                int gx = -Gamal_image(x - 1, y - 1, 0) + Gamal_image(x + 1, y - 1, 0) - Gamal_image(x - 1, y, 0) + Gamal_image(x + 1, y, 0) - Gamal_image(x - 1, y + 1, 0) + Gamal_image(x + 1, y + 1, 0);

                // Calculate vertical gradient
                int gy = -Gamal_image(x - 1, y - 1, 0) - Gamal_image(x, y - 1, 0) - Gamal_image(x + 1, y - 1, 0) + Gamal_image(x - 1, y + 1, 0) + Gamal_image(x, y + 1, 0) + Gamal_image(x + 1, y + 1, 0);

                // Calculate gradient magnitude
                int magnitude = sqrt(pow(gx, 2) + pow(gy, 2));

                // Apply thresholding to obtain binary edges
                unsigned char edgeValue = (magnitude > 100) ? 255 : 0;

                // Set the pixel value in the output image
                if (edgeValue == 255)
                {
                    // Set color for edges in fire mood
                    Gamal_output_image(x, y, 0) = edgeValue;
                    Gamal_output_image(x, y, 1) = 50;
                    Gamal_output_image(x, y, 2) = 0;
                }
                else
                {
                    // Set color for non-edges in fire mood
                    Gamal_output_image(x, y, 0) = edgeValue;
                    Gamal_output_image(x, y, 1) = edgeValue;
                    Gamal_output_image(x, y, 2) = edgeValue;
                }
            }
        }
    }

    if (Gamal_choice == 'b')
    {
        // Simple mood selected
        // Loop through each pixel in the image
        for (int y = 1; y < Gamal_image.height - 1; ++y)
        {
            for (int x = 1; x < Gamal_image.width - 1; ++x)
            {
                // Calculate horizontal gradient
                int gx = -Gamal_image(x - 1, y - 1, 0) + Gamal_image(x + 1, y - 1, 0) - Gamal_image(x - 1, y, 0) + Gamal_image(x + 1, y, 0) - Gamal_image(x - 1, y + 1, 0) + Gamal_image(x + 1, y + 1, 0);

                // Calculate vertical gradient
                int gy = -Gamal_image(x - 1, y - 1, 0) - Gamal_image(x, y - 1, 0) - Gamal_image(x + 1, y - 1, 0) + Gamal_image(x - 1, y + 1, 0) + Gamal_image(x, y + 1, 0) + Gamal_image(x + 1, y + 1, 0);

                // Calculate gradient magnitude
                int magnitude = sqrt(pow(gx, 2) + pow(gy, 2));

                // Apply thresholding to obtain binary edges
                unsigned char edgeValue = (magnitude > 100) ? 0 : 255;

                // Set the pixel value in the output image
                Gamal_output_image(x, y, 0) = edgeValue;
                Gamal_output_image(x, y, 1) = edgeValue;
                Gamal_output_image(x, y, 2) = edgeValue;
            }
        }
    }

    // Save the output image
    Gamal_output_image.saveImage("saved.jpg");
    unsaved_image = true;
    return Gamal_output_image;
}

Image Gamal_sunlight(string Gamal_Khatab_Mostafa_filename)
{
    // Create a new image with the same dimensions as the input image
    Image Gamal_image(Gamal_Khatab_Mostafa_filename);
    Image Gamal_output_image(Gamal_image.width, Gamal_image.height);

    // Loop through each pixel in the image
    for (int j = 0; j < Gamal_image.height; ++j)
    {
        for (int i = 0; i < Gamal_image.width; ++i)
        {
            // Get the original RGB values
            int red = Gamal_image(i, j, 0);
            int green = Gamal_image(i, j, 1);
            int blue = Gamal_image(i, j, 2);

            // Increase red and green channels while reducing blue channel
            int yellow_red = red + 50;     // Increase red channel
            int yellow_green = green + 50; // Increase green channel
            int yellow_blue = blue - 20;   // Decrease blue channel

            // Ensure RGB values are within the valid range [0, 255]
            yellow_red = min(255, max(0, yellow_red));
            yellow_green = min(255, max(0, yellow_green));
            yellow_blue = min(255, max(0, yellow_blue));

            // Set the modified RGB values to the output image
            Gamal_output_image(i, j, 0) = yellow_red;
            Gamal_output_image(i, j, 1) = yellow_green;
            Gamal_output_image(i, j, 2) = yellow_blue;
        }
    }
    Gamal_output_image.saveImage("saved.jpg");
    unsaved_image = true;
    return Gamal_output_image;
}

Image Frame_image(string khattab_filename)
{

    Image khattab_image(khattab_filename);
    cout << "Which Frame you want.\n(1)Frame1\n(2)Frame2\n(3)Frame3: ";
    int choice;
    cin >> choice;
    while (cin.fail() || (choice != 1 && choice != 2 && choice != 3))
    {
        cout << "Invalid input! Please, Follow the instructions." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Which Frame you want.\n(1)Frame1\n(2)Frame2\n(3)Frame3: ";
        cin >> choice;
    }
    if (choice == 1)
    {
        { // The first frame
            for (int i = 0; i < 20; ++i)
            { // Putting a frame from the left hand side in blue
                for (int j = 0; j < khattab_image.height; ++j)
                {
                    khattab_image(i, j, 0) = 0;
                    khattab_image(i, j, 1) = 0;
                    khattab_image(i, j, 2) = 255;
                }
            }
            for (int i = khattab_image.width - 1; i > khattab_image.width - 21; --i)
            {
                for (int j = 0; j < khattab_image.height; ++j)
                {
                    khattab_image(i, j, 0) = 0;
                    khattab_image(i, j, 1) = 0;
                    khattab_image(i, j, 2) = 255;
                }
            }
            for (int i = 0; i < khattab_image.width - 1; ++i)
            {
                for (int j = 0; j < 20; ++j)
                {
                    khattab_image(i, j, 0) = 0;
                    khattab_image(i, j, 1) = 0;
                    khattab_image(i, j, 2) = 255;
                }
            }
            for (int i = 0; i < khattab_image.width - 1; ++i)
            {
                for (int j = khattab_image.height - 1; j > khattab_image.height - 21; --j)
                { // Initialize average value
                    khattab_image(i, j, 0) = 0;
                    khattab_image(i, j, 1) = 0;
                    khattab_image(i, j, 2) = 255;
                }
            }
        }
    }
    //===================================================================================
    else if (choice == 2)
    {

        for (int i = 0; i < 20; ++i)
        {
            for (int j = 0; j < khattab_image.height; ++j)
            { // Initialize average value
                khattab_image(i, j, 0) = 0;
                khattab_image(i, j, 1) = 0;
                khattab_image(i, j, 2) = 255;
            }
        }
        for (int i = khattab_image.width - 1; i > khattab_image.width - 21; --i)
        {
            for (int j = 0; j < khattab_image.height; ++j)
            { // Initialize average value
                khattab_image(i, j, 0) = 0;
                khattab_image(i, j, 1) = 0;
                khattab_image(i, j, 2) = 255;
            }
        }
        for (int i = 0; i < khattab_image.width - 1; ++i)
        {
            for (int j = 0; j < 20; ++j)
            { // Initialize average value
                khattab_image(i, j, 0) = 0;
                khattab_image(i, j, 1) = 0;
                khattab_image(i, j, 2) = 255;
            }
        }
        for (int i = 0; i < khattab_image.width - 1; ++i)
        {
            for (int j = khattab_image.height - 1; j > khattab_image.height - 21; --j)
            { // Initialize average value
                khattab_image(i, j, 0) = 0;
                khattab_image(i, j, 1) = 0;
                khattab_image(i, j, 2) = 255;
            }
        }
        //=========================================================================================

        for (int i = 20; i < 22; ++i)
        {
            for (int j = 20; j < khattab_image.height - 21; ++j)
            { // Initialize average value
                khattab_image(i, j, 0) = 255;
                khattab_image(i, j, 1) = 255;
                khattab_image(i, j, 2) = 255;
            }
        }
        for (int i = khattab_image.width - 21; i > khattab_image.width - 23; --i)
        {
            for (int j = 20; j < khattab_image.height - 21; ++j)
            { // Initialize average value
                khattab_image(i, j, 0) = 255;
                khattab_image(i, j, 1) = 255;
                khattab_image(i, j, 2) = 255;
            }
        }
        for (int i = 20; i < khattab_image.width - 21; ++i)
        {
            for (int j = 20; j < 22; ++j)
            { // Initialize average value
                khattab_image(i, j, 0) = 255;
                khattab_image(i, j, 1) = 255;
                khattab_image(i, j, 2) = 255;
            }
        }
        for (int i = 20; i < khattab_image.width - 21; ++i)
        {
            for (int j = khattab_image.height - 21; j > khattab_image.height - 23; --j)
            { // Initialize average value
                khattab_image(i, j, 0) = 255;
                khattab_image(i, j, 1) = 255;
                khattab_image(i, j, 2) = 255;
            }
        }

        //======================================================================================
        for (int i = 25; i < 28; ++i)
        {
            for (int j = 25; j < khattab_image.height - 26; ++j)
            { // Initialize average value
                khattab_image(i, j, 0) = 255;
                khattab_image(i, j, 1) = 255;
                khattab_image(i, j, 2) = 255;
            }
        }
        for (int i = khattab_image.width - 26; i > khattab_image.width - 29; --i)
        {
            for (int j = 25; j < khattab_image.height - 26; ++j)
            { // Initialize average value
                khattab_image(i, j, 0) = 255;
                khattab_image(i, j, 1) = 255;
                khattab_image(i, j, 2) = 255;
            }
        }
        for (int i = 25; i < khattab_image.width - 26; ++i)
        {
            for (int j = 25; j < 28; ++j)
            { // Initialize average value
                khattab_image(i, j, 0) = 255;
                khattab_image(i, j, 1) = 255;
                khattab_image(i, j, 2) = 255;
            }
        }
        for (int i = 25; i < khattab_image.width - 26; ++i)
        {
            for (int j = khattab_image.height - 26; j > khattab_image.height - 29; --j)
            { // Initialize average value
                khattab_image(i, j, 0) = 255;
                khattab_image(i, j, 1) = 255;
                khattab_image(i, j, 2) = 255;
            }
        }
    }
    //=======================================================================================
    else
    {

        for (int i = 0; i < 20; ++i)
        {
            for (int j = 0; j < khattab_image.height; ++j)
            { // Initialize average value
                khattab_image(i, j, 0) = 0;
                khattab_image(i, j, 1) = 0;
                khattab_image(i, j, 2) = 255;
            }
        }
        for (int i = khattab_image.width - 1; i > khattab_image.width - 21; --i)
        {
            for (int j = 0; j < khattab_image.height; ++j)
            { // Initialize average value
                khattab_image(i, j, 0) = 0;
                khattab_image(i, j, 1) = 0;
                khattab_image(i, j, 2) = 255;
            }
        }
        for (int i = 0; i < khattab_image.width - 1; ++i)
        {
            for (int j = 0; j < 20; ++j)
            { // Initialize average value
                khattab_image(i, j, 0) = 0;
                khattab_image(i, j, 1) = 0;
                khattab_image(i, j, 2) = 255;
            }
        }
        for (int i = 0; i < khattab_image.width - 1; ++i)
        {
            for (int j = khattab_image.height - 1; j > khattab_image.height - 21; --j)
            { // Initialize average value
                khattab_image(i, j, 0) = 0;
                khattab_image(i, j, 1) = 0;
                khattab_image(i, j, 2) = 255;
            }
        }
        //======================================================================================
        for (int i = 20; i < 23; ++i)
        {
            for (int j = 0; j < khattab_image.height; ++j)
            { // Initialize average value
                khattab_image(i, j, 0) = 255;
                khattab_image(i, j, 1) = 255;
                khattab_image(i, j, 2) = 255;
            }
        }
        for (int i = khattab_image.width - 21; i > khattab_image.width - 24; --i)
        {
            for (int j = 0; j < khattab_image.height; ++j)
            { // Initialize average value
                khattab_image(i, j, 0) = 255;
                khattab_image(i, j, 1) = 255;
                khattab_image(i, j, 2) = 255;
            }
        }
        for (int i = 0; i < khattab_image.width - 1; ++i)
        {
            for (int j = 20; j < 23; ++j)
            { // Initialize average value
                khattab_image(i, j, 0) = 255;
                khattab_image(i, j, 1) = 255;
                khattab_image(i, j, 2) = 255;
            }
        }
        for (int i = 0; i < khattab_image.width - 1; ++i)
        {
            for (int j = khattab_image.height - 21; j > khattab_image.height - 24; --j)
            { // Initialize average value
                khattab_image(i, j, 0) = 255;
                khattab_image(i, j, 1) = 255;
                khattab_image(i, j, 2) = 255;
            }
        }
        //======================================================================================
        for (int i = 25; i < 28; ++i)
        {
            for (int j = 25; j < khattab_image.height - 26; ++j)
            { // Initialize average value
                khattab_image(i, j, 0) = 255;
                khattab_image(i, j, 1) = 255;
                khattab_image(i, j, 2) = 255;
            }
        }
        for (int i = khattab_image.width - 26; i > khattab_image.width - 29; --i)
        {
            for (int j = 25; j < khattab_image.height - 26; ++j)
            { // Initialize average value
                khattab_image(i, j, 0) = 255;
                khattab_image(i, j, 1) = 255;
                khattab_image(i, j, 2) = 255;
            }
        }
        for (int i = 25; i < khattab_image.width - 26; ++i)
        {
            for (int j = 25; j < 28; ++j)
            { // Initialize average value
                khattab_image(i, j, 0) = 255;
                khattab_image(i, j, 1) = 255;
                khattab_image(i, j, 2) = 255;
            }
        }
        for (int i = 25; i < khattab_image.width - 26; ++i)
        {
            for (int j = khattab_image.height - 26; j > khattab_image.height - 29; --j)
            { // Initialize average value
                khattab_image(i, j, 0) = 255;
                khattab_image(i, j, 1) = 255;
                khattab_image(i, j, 2) = 255;
            }
        }
    }
    khattab_image.saveImage("saved.jpg");
    unsaved_image = true;
    return khattab_image;
}
