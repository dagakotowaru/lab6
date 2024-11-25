#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    setlocale(LC_ALL, "ru");


    Mat image = imread("C:\\с++\\3\\3.jpg");

    if (image.empty()) {
        cout << "Error!" << endl;
        return -1;
    }

    string text;
    cout << "Text: ";
    getline(cin, text);

    if (text.length() > 22) {
        cout << "Too long message!" << endl;
        return -1;
    }

    
    for (int i = 0; i < text.length(); i++) {
        int ascii_code = static_cast<int>(text[i]);

        
        Vec3b& pixel = image.at<Vec3b>(100 + i, 100);  
        pixel[2] = ascii_code;
    }

    string out = "C:\\с++\\3\\output_image.png";
    imwrite(out, image); 
    cout << "Image saved as output_image.png" << endl;

    Mat image_msg = imread(out);
    
    string extracted_text = "";
    for (int i = 0; i < text.length(); i++) {
        Vec3b pixel = image_msg.at<Vec3b>(100 + i, 100);
        int ascii_code = pixel[2];  
        if (ascii_code >= 0 && ascii_code <= 127) {
            extracted_text += static_cast<char>(ascii_code);
        }
    }

    cout << "Extracted text: " << extracted_text << endl;

    return 0;
}
