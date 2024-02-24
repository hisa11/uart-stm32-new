#include "mbed.h"

DigitalOut led(D4);

BufferedSerial pc(PB_6, PA_10, 15200); // パソコンとのシリアル通信

int main() {
    while(1) {
        char command[3]; // コマンドと数字の組み合わせを格納する配列
        pc.read(command, sizeof(command)); // パソコンからのデータを読み込む

        if (command[0] == 'a' && atoi(&command[1]) >= 200) { // 先頭が'a'かつ後ろの数字が200以上の場合
            led = 1; // LED 点灯
        } else if (command[0] == 'B' && command[1] == 'c') { // 先頭が'B'かつ後ろが'c'の場合
            led = 0; // LED 消灯
            //変更したよ
        }
    }
}
