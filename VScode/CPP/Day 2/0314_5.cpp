 #include <iostream>
using namespace std;

class Tv {
private:
    bool on;
    int channel;
    int volume;

public:
    // 기본 생성자
    Tv(){
        on = false;
        channel = 0;
        volume = 5;
    }
    Tv(int c, int v){
        on = false;
        channel = c;
        volume = v;
    }

    // 복사 생성자
    Tv(const Tv &other) : on(other.on), channel(other.channel), volume(other.volume) {}

    // 멤버 초기화 리스트를 사용하여 생성자 정의

    // 필요한 경우 초기값을 받아와서 객체를 생성할 수 있도록 생성자 오버로딩 가능
    Tv(bool power, int initialChannel, int initialVolume) : on(power), channel(initialChannel), volume(initialVolume) {}

    void powerOn()
    {
        on = true;
    }

    void powerOff()
    {
        on = false;
    }

    void increaseChannel()
    {
        channel += 1;
    }

    void decreaseChannel()
    {
        channel -= 1;
    }

    void increaseVolume()
    {
        volume += 1;
    }

    void decreaseVolume()
    {
        volume -= 1;
    }

    // 접근자 함수
    void show () {
        cout << channel << "\n" << volume;
    }
};

int main() {
    Tv tv1(1,1);
    tv1.increaseChannel();
    tv1.show(); // 함수는 cout을 반환하도록 수정되었으므로 cout을 인수로 전달
}
