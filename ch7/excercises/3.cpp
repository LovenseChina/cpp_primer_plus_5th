#include<iostream>
using namespace std;
struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void show_msg(box b);
void caculate_volume(box *pb);

int main() {
    box b1 = {
        "Flowers2CE",
        2.4,
        3.5,
        4.1,
        0
    };
    box b2 = {
        "X is Twitter",
        1.0,
        1.0,
        1.0,
        0
    };
    caculate_volume(&b1);
    caculate_volume(&b2);
    show_msg(b1);
    show_msg(b2);
    return 0;
}

void show_msg(box b) {
    cout << "Messages of the box are below:\n";
    cout << "Maker: " << b.maker << endl;
    cout << "Height: " << b.height << endl;
    cout << "Width: " << b.width << endl;
    cout << "Length: " << b.length << endl;
    cout << "Volume: " << b.volume << endl;
}

void caculate_volume(box *pb) {
    pb->volume = pb->height * pb->length * pb->width;
}