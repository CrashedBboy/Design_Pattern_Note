#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Image {
public:
    vector<uint8_t> data;
    string filename;
};

class ExposureProcessor {
public:
    static void process(Image* image, int amount) {
        cout << "Adjust exposure" << endl;
    }
};

class CropProcessor {
public:
    static void process(Image* image, int size) {
        cout << "Crop image" << endl;
    }
};

class SaturateProcessor {
public:
    static void process(Image* image, int amount) {
        cout << "Adjust saturate of image" << endl;
    }
};

// Facade class
class CameraJPEGProcessor {
public:
    static void convert(Image* raw) {

        // wire all components up
        CropProcessor::process(raw, 1920);
        SaturateProcessor::process(raw, 15);
        ExposureProcessor::process(raw, 5);
    }
};

// client code
int main() {

    // new created raw image
    Image* img = new Image();

    // process it using fascade class
    CameraJPEGProcessor::convert(img);

    return 0;
}