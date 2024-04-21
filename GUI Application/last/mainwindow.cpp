// File: CS112_A3_Part3B_Section11,12_20231167_20231039_20231200.cpp
// Purpose: The program do a variety of filters on images.
// Version: 2.3
// Authors:
// -Gamal Megahed Sayed Mohamed (20231039) (eng.gamalmegahed@gmail.com), Section 12 , Did Filter_1 , Filter_4 , Filter_7 , Filter_10 , Filter_13 , Filter_14 , Filter_19 , Filter_20.
// -Mostafa Ehab Mostafa Akl (20231167) (mostafaehabakl@gmail.com) , Section 12 , Did Filter_2 , Filter_5 , Filter_8 , Filter_11 , Filter_15 , Filter_18.
// -Walid Adel Mordy Rohyem (20231200) (khattabadel112005@gmail.com), Section 11 , Did Filter_3 . Filter_6 , Filter_9 , Filter_12 , Filter_16 , Filter_17.
//===================================================================================================================================================================================
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Image_Class.h"
#include <string>
#include <QString>
#include <QFileDialog>
#include <QPixmap>
using namespace std;
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this); // Assuming ui is already set up using Qt Designer
}

// Override the showEvent method
void MainWindow::showEvent(QShowEvent *event) {
    QMainWindow::showEvent(event); // Call base class implementation

    // Load the image into a QPixmap
    QPixmap pixmap("last.jpg");

    // Create a palette to set the background image
    QPalette palette;

    // Set the background image
    palette.setBrush(this->backgroundRole(), QBrush(pixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));

    // Set the palette
    this->setPalette(palette);
}
QString Gamal_Khatab_Mostafa_filename ;

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
    system("saved.jpg");

    return Gamal_image;
}

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
    system("saved.jpg");

    return Mustafa_image;
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
    system("saved.jpg");

    return khattab_image;
}
Image Horizontal_Flip_Image(string Mustafa_filename)
{
    // take from the user the image name.
    Image Mustafa_image(Mustafa_filename);
    // make an image with the same width and height.
    Image Mustafa_image2(Mustafa_image.width, Mustafa_image.height);
    // know if the user want to continue by doing other operations or not.


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

    system("saved.jpg");

    return Mustafa_image;
}
Image Vertical_Flip_Image(string Mustafa_filename)
{
    // take from the user the image name.
    Image Mustafa_image(Mustafa_filename);
    // make an image with the same width and height.
    Image Mustafa_image2(Mustafa_image.width, Mustafa_image.height);
    // know if the user want to continue by doing other operations or not.


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

    system("saved.jpg");

    return Mustafa_image;
}
Image Gamal_Darken_and_Lighten_Image(string Gamal_filename , char Gamal_choice1 )
{

    Image Gamal_image(Gamal_filename);

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
    system("saved.jpg");
    return Gamal_image;
}

Image Rotate_Image(string Gamal_Khatab_Mostafa_filename , int angle)
{
    Image khattab_image(Gamal_Khatab_Mostafa_filename);
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

    system("saved.jpg");

    return khattab_image;
}
Image Frame_image(string khattab_filename , int choice)
{

    Image khattab_image(khattab_filename);


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
    system("saved.jpg");

    return khattab_image;
}
Image Gamal_detect_edges(string image_name  , char Gamal_choice)
{
    // Load an image
    Image Gamal_image(image_name);

    // Create an instance for the output image
    Image Gamal_output_image(Gamal_image.width, Gamal_image.height);


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
    system("saved.jpg");

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
    system("saved.jpg");

    return Gamal_output_image;
}
Image Old_TV(string Mustafa_filename)
{
    srand(time(0));

    Image Mustafa_image(Mustafa_filename);
    for (int r = 0; r < 20000; ++r)
    {
        long randompxlight_x = rand() % (Mustafa_image.width), randompxlight_y = rand() % (Mustafa_image.height), randompxdark_x = rand() % (Mustafa_image.width), randompxdark_y = rand() % (Mustafa_image.height);

        for (int k = 0; k < 3; ++k)
        {
            int X = round(Mustafa_image(randompxlight_x, randompxlight_y, k) * 1.3);
            Mustafa_image(randompxlight_x, randompxlight_y, k) = min(X, 255);
            Mustafa_image(randompxdark_x, randompxdark_y, k) /= 1.3;
        }
    }

    for (int j = 0; j < Mustafa_image.height; j += 8 * 2)
    {
        if ((j + 8) <= Mustafa_image.height)
        {
            for (int l = j; l < j + 8; ++l)
            {
                for (int i = 0; i < Mustafa_image.width; ++i)
                {
                    for (int k = 0; k < 3; ++k)
                    {
                        Mustafa_image(i, l, k) /= 1.3;
                    }
                }
            }
        }
    }
    Mustafa_image.saveImage("saved.jpg");
    system("saved.jpg");

    return Mustafa_image;
}
Image Purple_image(string file_name)
{
    Image khattab_image(file_name); // Creating an instance of the Image class with the provided filename

    for (int i = 0; i < khattab_image.width; ++i)
    {
        for (int j = 0; j < khattab_image.height; ++j)
        {
            for (int k = 0; k < 3; k++)
            { // Looping through the color channels (RGB)
                if (k == 1)
                {
                    khattab_image(i, j, k) *= 0.6; // Modifying the green channel value
                    continue;
                }
                khattab_image(i, j, k); // Performing some operation on the pixel, but not assigned to anything
            }
        }
    }
    khattab_image.saveImage("saved.jpg");
    system("saved.jpg");

    return khattab_image; // Saving the modified image with the provided new name
}
Image Infrared_image(string file_name)
{
    // Create an instance of the Image class with the given filename
    Image khattab_image(file_name);

    // Loop over the columns of the image
    for (int i = 0; i < khattab_image.width; ++i)
    {
        // Loop over the rows of the image
        for (int j = 0; j < khattab_image.height; ++j)
        {
            // Invert the color of each pixel
            khattab_image(i, j, 0) = 255;                          // Set the red component to 255
            khattab_image(i, j, 1) = 255 - khattab_image(i, j, 1); // Invert the green component
            khattab_image(i, j, 2) = 255 - khattab_image(i, j, 2); // Invert the blue component
        }
    }

    khattab_image.saveImage("saved.jpg");
    system("saved.jpg");

    return khattab_image; // Saving the modified image with the provided new name
}
Image Gamal_prison(string filename)
{
    Image Gamal_image(filename);
    Image Gamal_output_image(filename);
    int color = 0;
    for (int i = 30; i < Gamal_image.width - 17; i += 60)
    {
        for (int j = 17; j < Gamal_image.height - 17; j += 1)
        {
            for (int k = 0; k < 3; k++)
            {
                for (int di = -17; di <= 17; di++)
                {
                    for (int dj = -17; dj <= 17; dj++)
                    {
                        Gamal_output_image(i + di, j + dj, k) = 15 * (17 - abs(di));
                    }
                }
            }
        }
    }

    Gamal_output_image.saveImage("saved.jpg");
    system("saved.jpg");

    return Gamal_output_image;
}
Image Gamal_Merge_Images(string filename1 , string filename2)
{
    string Gamal_scnd_photo, Gamal_merged_name;
    Gamal_scnd_photo = filename2;

    Image Gamal_frst(filename1);
    Image temp(Gamal_scnd_photo);

    int new_width = Gamal_frst.width;
    int new_height = Gamal_frst.height;

    double resize_width = double(Gamal_frst.width) / temp.width;
    double resize_height = double(Gamal_frst.height) / temp.height;

    // Resize the second image to match the dimensions of the first image
    Image Gamal_scnd(new_width, new_height);
    for (int i = 0; i < new_width; ++i)
    {
        for (int j = 0; j < new_height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                Gamal_scnd(i, j, k) = temp(int(i / resize_width), int(j / resize_height), k);
            }
        }
    }

    // Merging images by averaging pixel values
    for (int i = 0; i < new_width; ++i)
    {
        for (int j = 0; j < new_height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                // Cast to int here to truncate the result
                Gamal_scnd(i, j, k) = int((Gamal_frst(i, j, k) + Gamal_scnd(i, j, k)) / 2.0);
            }
        }
    }

    Gamal_scnd.saveImage("saved.jpg");
    system("saved.jpg");

    return Gamal_scnd;
}
Image Crop_Images(string Mustafa_filename , int width, int  height, int x, int y)
{

    Image Mustafa_image(Mustafa_filename);
    while (true)
    {
        // take from the user the (X) coordinates.

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
    system("saved.jpg");

    return Mustafa_image;
}

Image Resizing_Images(string Mustafa_filename ,int Mustafa_width, int Mustafa_height)
{


    double resize_width, resize_height;
    Image Mustafa_image(Mustafa_filename);

    Image Mustafa_image2(Mustafa_width, Mustafa_height);
    resize_width = Mustafa_image.width / double(Mustafa_width);
    resize_height = Mustafa_image.height / double(Mustafa_height);

    for (long i = 0; i < Mustafa_image2.width; ++i)
    {
        for (long j = 0; j < Mustafa_image2.height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                Mustafa_image2(i, j, k) = Mustafa_image(round(i * resize_width), round(j * resize_height), k);
            }
        }
    }

    Mustafa_image2.saveImage("saved.jpg");
    system("saved.jpg");

    return Mustafa_image2;
}
Image Blure_image(string file_name , int inten)
{

    // Create an instance of the Image class with the given filename
    Image khattab_image(file_name);

    // Loop over the columns of the image
    for (int i = 0; i < khattab_image.width; ++i)
    {
        // Loop over the rows of the image
        for (int j = 0; j < khattab_image.height; ++j)
        {
            // Initialize variables to store the RGB values
            float khattabR = 0, khattabG = 0, khattabB = 0;

            // Loop over the neighboring pixels
            for (int id = -1 * inten; id <= inten; id++)
            {
                for (int jd = -1 * inten; jd <= inten; jd++)
                {
                    // Check if the pixel is within the bounds of the image
                    if (i + id < 0 || i + id >= khattab_image.width || j + jd < 0 || j + jd >= khattab_image.height)
                        continue;

                    // Accumulate the RGB values
                    khattabR += khattab_image(i + id, j + jd, 0);
                    khattabG += khattab_image(i + id, j + jd, 1);
                    khattabB += khattab_image(i + id, j + jd, 2);
                }
            }
            // Calculate the average RGB values
            khattabR /= (inten * 2 + 1) * (inten * 2 + 1);
            khattabG /= (inten * 2 + 1) * (inten * 2 + 1);
            khattabB /= (inten * 2 + 1) * (inten * 2 + 1);

            // Assign the rounded average RGB values to the current pixel
            khattab_image(i, j, 0) = ceil(khattabR);
            khattab_image(i, j, 1) = ceil(khattabG);
            khattab_image(i, j, 2) = ceil(khattabB);
        }
    }

    khattab_image.saveImage("saved.jpg");
    system("saved.jpg");

    return khattab_image;
}

Image Gamal_oil_painting(string filename , int radius)
{
    Image Gamal_image(filename);
    Image Gamal_output_image(Gamal_image.width, Gamal_image.height);
    for (int i = radius; i < Gamal_image.width - radius; ++i)
    {
        for (int j = radius; j < Gamal_image.height - radius; ++j)
        {
            vector<int> intensityCount(20, 0);
            vector<int> averageR(20, 0);
            vector<int> averageG(20, 0);
            vector<int> averageB(20, 0);

            for (int di = -radius; di <= radius; ++di)
            {
                for (int dj = -radius; dj <= radius; ++dj)
                {
                    int r, g, b;
                    r = Gamal_image(i + di, j + dj, 0);
                    g = Gamal_image(i + di, j + dj, 1);
                    b = Gamal_image(i + di, j + dj, 2);
                    int curIntensity = int(((r + g + b) / 3.0 * 20 / 255.0));
                    intensityCount[curIntensity]++;
                    averageR[curIntensity] += r;
                    averageG[curIntensity] += g;
                    averageB[curIntensity] += b;
                }
            }

            int maxIndex = 0;
            int curMax = intensityCount[0];
            for (int k = 1; k < 20; ++k)
            {
                if (intensityCount[k] > curMax)
                {
                    curMax = intensityCount[k];
                    maxIndex = k;
                }
            }

            int finalR = averageR[maxIndex] / curMax;
            int finalG = averageG[maxIndex] / curMax;
            int finalB = averageB[maxIndex] / curMax;

            // Blend original colors with oil painted colors
            Gamal_output_image(i, j, 0) = (Gamal_image(i, j, 0) + finalR) / 2;
            Gamal_output_image(i, j, 1) = (Gamal_image(i, j, 1) + finalG) / 2;
            Gamal_output_image(i, j, 2) = (Gamal_image(i, j, 2) + finalB) / 2;
        }
    }

    Gamal_output_image.saveImage("saved.jpg");
    system("saved.jpg");

    return Gamal_output_image;
}
Image skew_Images(string Mustafa_filename , double degree)
{
    long double width2;
    const long double Pi = 3.1415926535897932384626433832795;


    Image Mustafa_image(Mustafa_filename);
    width2 = ceil(tan(((degree)*Pi) / 180) * Mustafa_image.height);

    Image Mustafa_image2(Mustafa_image.width + width2, Mustafa_image.height);

    for (long j = 0; j < Mustafa_image.height; ++j)
    {
        for (long i = 0; i < Mustafa_image.width; ++i)
        {
            for (int k = 0; k < 3; ++k)
            {
                Mustafa_image2(abs(width2 + i - (j * (tan(((degree)*Pi) / 180)))), j, k) = Mustafa_image(i, j, k);
            }
        }
    }

    Mustafa_image2.saveImage("saved.jpg");
    system("saved.jpg");

    return Mustafa_image2;
}
Image Gamal_Chess(string filename , int tiles)
{

    float division = 1.0f / tiles;

    // Load the original image
    Image Gamal_image(filename);

    // Create a new image for output
    Image Gamal_output_image(Gamal_image.width, Gamal_image.height);

    for (int i = 0; i < tiles; ++i)
    {
        for (int j = 0; j < tiles; ++j)
        {
            // Calculate the brightness level based on the sub-image position
            int brightness = (i + j) % 2 == 0 ? 0 : 255;

            // Apply brightness adjustment to the sub-image
            int Gamal_width, Gamal_height;
            Gamal_width = (i == tiles - 1) ? Gamal_image.width : (i + 1) * division * Gamal_image.width;
            Gamal_height = (j == tiles - 1) ? Gamal_image.height : (j + 1) * division * Gamal_image.height;
            for (int x = i * division * Gamal_image.width; x < Gamal_width; ++x)
            {
                for (int y = j * division * Gamal_image.height; y < Gamal_height; ++y)
                {
                    for (int c = 0; c < 3; ++c)
                    {
                        Gamal_output_image(x, y, c) = ((Gamal_image(x, y, c) + brightness) / 2);
                    }
                }
            }
        }
    }

    // Save the modified image
    Gamal_output_image.saveImage("saved.jpg");
    system("saved.jpg");

    return Gamal_output_image;
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnGray_clicked()
{
    try
    {
        Gamal_gray_scale("saved.jpg");
    }
    catch (invalid_argument)
    {
        Gamal_gray_scale(Gamal_Khatab_Mostafa_filename.toStdString());
    }
}


void MainWindow::on_btnB_W_clicked()
{
    try
    {
        Black_and_White("saved.jpg");
    }
    catch (invalid_argument)
    {
        Black_and_White(Gamal_Khatab_Mostafa_filename.toStdString());
    }
}


void MainWindow::on_btnInvert_clicked()
{
    try
    {
        Invert_Image("saved.jpg");
    }
    catch (invalid_argument)
    {
        Invert_Image(Gamal_Khatab_Mostafa_filename.toStdString());
    }
}


void MainWindow::on_btnHFlip_clicked()
{
    try
    {
        Horizontal_Flip_Image("saved.jpg");
    }
    catch (invalid_argument)
    {
        Horizontal_Flip_Image(Gamal_Khatab_Mostafa_filename.toStdString());
    }
}


void MainWindow::on_btnVFlip_clicked()
{
    try
    {
        Vertical_Flip_Image("saved.jpg");
    }
    catch (invalid_argument)
    {
        Vertical_Flip_Image(Gamal_Khatab_Mostafa_filename.toStdString());
    }
}


void MainWindow::on_btnDarken_clicked()
{
    try
    {
        Gamal_Darken_and_Lighten_Image("saved.jpg" , 'b');
    }
    catch (invalid_argument)
    {
        Gamal_Darken_and_Lighten_Image(Gamal_Khatab_Mostafa_filename.toStdString() , 'b');
    }
}


void MainWindow::on_btnLighten_clicked()
{
    try
    {
        Gamal_Darken_and_Lighten_Image("saved.jpg" , 'a');
    }
    catch (invalid_argument)
    {
        Gamal_Darken_and_Lighten_Image(Gamal_Khatab_Mostafa_filename.toStdString() , 'a');
    }
}


void MainWindow::on_btnRotate90_clicked()
{
    try
    {
        Rotate_Image("saved.jpg" , 90);
    }
    catch (invalid_argument)
    {
        Rotate_Image(Gamal_Khatab_Mostafa_filename.toStdString() , 90);
    }
}


void MainWindow::on_brnRoatate180_clicked()
{
    try
    {
        Rotate_Image("saved.jpg" , 180);
    }
    catch (invalid_argument)
    {
        Rotate_Image(Gamal_Khatab_Mostafa_filename.toStdString() , 180);
    }
}


void MainWindow::on_btnRotate270_clicked()
{
    try
    {
        Rotate_Image("saved.jpg" , 270);
    }
    catch (invalid_argument)
    {
        Rotate_Image(Gamal_Khatab_Mostafa_filename.toStdString() , 270);
    }
}


void MainWindow::on_btnFrame1_clicked()
{
    try
    {
        Frame_image("saved.jpg" , 1);
    }
    catch (invalid_argument)
    {
        Frame_image(Gamal_Khatab_Mostafa_filename.toStdString() , 1);
    }
}


void MainWindow::on_btnFrame2_clicked()
{
    try
    {
        Frame_image("saved.jpg" , 2);
    }
    catch (invalid_argument)
    {
        Frame_image(Gamal_Khatab_Mostafa_filename.toStdString() , 2);
    }
}


void MainWindow::on_btnFrame3_clicked()
{
    try
    {
        Frame_image("saved.jpg" , 3);
    }
    catch (invalid_argument)
    {
        Frame_image(Gamal_Khatab_Mostafa_filename.toStdString() , 3);
    }
}


void MainWindow::on_btnDENormal_clicked()
{
    try
    {
        Gamal_detect_edges("saved.jpg" , 'b');
    }
    catch (invalid_argument)
    {
        Gamal_detect_edges(Gamal_Khatab_Mostafa_filename.toStdString() , 'b');
    }
}


void MainWindow::on_btnDEFire_clicked()
{
    try
    {
        Gamal_detect_edges("saved.jpg" , 'a');
    }
    catch (invalid_argument)
    {
        Gamal_detect_edges(Gamal_Khatab_Mostafa_filename.toStdString() , 'a');
    }
}


void MainWindow::on_btnSunlight_clicked()
{
    try
    {
        Gamal_sunlight("saved.jpg");
    }
    catch (invalid_argument)
    {
        Gamal_sunlight(Gamal_Khatab_Mostafa_filename.toStdString());
    }
}


void MainWindow::on_btnOld_TV_clicked()
{
    try
    {
        Old_TV("saved.jpg");
    }
    catch (invalid_argument)
    {
        Old_TV(Gamal_Khatab_Mostafa_filename.toStdString());
    }
}


void MainWindow::on_btnPurple_clicked()
{
    try
    {
        Purple_image("saved.jpg");
    }
    catch (invalid_argument)
    {
        Purple_image(Gamal_Khatab_Mostafa_filename.toStdString());
    }
}


void MainWindow::on_btnInfrared_clicked()
{
    try
    {
        Infrared_image("saved.jpg");
    }
    catch (invalid_argument)
    {
        Infrared_image(Gamal_Khatab_Mostafa_filename.toStdString());
    }
}


void MainWindow::on_btnPrison_clicked()
{
    try
    {
        Gamal_prison("saved.jpg");
    }
    catch (invalid_argument)
    {
        Gamal_prison(Gamal_Khatab_Mostafa_filename.toStdString());
    }
}


void MainWindow::on_pushButton_clicked()
{
    QString scnd_image = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Images (*.png *.bmp *.jpg)"));
    try
    {

        Gamal_Merge_Images("saved.jpg" , scnd_image.toStdString());
    }
    catch (invalid_argument)
    {
        Gamal_Merge_Images(Gamal_Khatab_Mostafa_filename.toStdString() , scnd_image.toStdString());
    }
}


void MainWindow::on_btnCrop_clicked()
{
    try
    {
        int width = ui->CropWidth->text().toInt();
        int height = ui->CropHieght->text().toInt();
        int x = ui->XD->text().toInt();
        int y = ui->YD->text().toInt();
        Crop_Images("saved.jpg" , width , height , x , y);
    }
    catch (invalid_argument)
    {
        int width = ui->CropWidth->text().toInt();
        int height = ui->CropHieght->text().toInt();
        int x = ui->XD->text().toInt();
        int y = ui->YD->text().toInt();
        Crop_Images(Gamal_Khatab_Mostafa_filename.toStdString() , width , height , x , y);
    }
}


void MainWindow::on_btnResize_clicked()
{
    try
    {
        int width = ui->ResizeWidth->text().toInt();
        int height = ui->RsizeHieght->text().toInt();
        Resizing_Images("saved.jpg" , width , height);
    }
    catch (invalid_argument)
    {
        int width = ui->ResizeWidth->text().toInt();
        int height = ui->RsizeHieght->text().toInt();
        Resizing_Images(Gamal_Khatab_Mostafa_filename.toStdString() , width , height);
    }
}


void MainWindow::on_btnBlur_clicked()
{
    try
    {
        int inten = ui->Intensity->text().toInt();
        Blure_image("saved.jpg" ,inten);
    }
    catch (invalid_argument)
    {
        int inten = ui->Intensity->text().toInt();
        Blure_image(Gamal_Khatab_Mostafa_filename.toStdString() ,inten);
    }
}


void MainWindow::on_btnOIL_clicked()
{
    try
    {
        int inten = ui->Intensity->text().toInt();
        Gamal_oil_painting("saved.jpg" ,inten);
    }
    catch (invalid_argument)
    {
        int inten = ui->Intensity->text().toInt();
        Gamal_oil_painting(Gamal_Khatab_Mostafa_filename.toStdString() ,inten);
    }
}


void MainWindow::on_btnSkew_clicked()
{
    try
    {
        double degree = ui->Degree->text().toDouble();
        skew_Images("saved.jpg" ,degree);
    }
    catch (invalid_argument)
    {
        double degree = ui->Degree->text().toDouble();
        skew_Images(Gamal_Khatab_Mostafa_filename.toStdString() ,degree);
    }
}


void MainWindow::on_btnChess_clicked()
{
    try
    {
        int tiles = ui->tiles->text().toInt();
        Gamal_Chess("saved.jpg" ,tiles);
    }
    catch (invalid_argument)
    {
        int tiles = ui->tiles->text().toInt();
        Gamal_Chess(Gamal_Khatab_Mostafa_filename.toStdString() ,tiles);
    }
}


void MainWindow::on_btnSave_clicked()
{
    string new_filename = Gamal_Khatab_Mostafa_filename.toStdString(), old_filename = "saved.jpg";
    remove(Gamal_Khatab_Mostafa_filename.toStdString().c_str());
    rename(old_filename.c_str(), new_filename.c_str());
    system(Gamal_Khatab_Mostafa_filename.toStdString().c_str());
}


void MainWindow::on_btnSave_2_clicked()
{
    string new_filename = ui->savedName->text().toStdString(), old_filename = "saved.jpg";
    rename(old_filename.c_str(), new_filename.c_str());
    system(new_filename.c_str());
}


void MainWindow::on_pushButton_4_clicked()
{
    remove("saved.jpg");
    Gamal_Khatab_Mostafa_filename = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Images (*.png *.bmp *.jpg)"));
}

