#include <iostream>
#include <cmath> // sqrt 함수를 사용하기 위해 추가
using namespace std;

class Character
{
protected:
    double x, y, hp, mp, arrows, shield, range, speed;

public:
    Character(double x, double y, double hp, double mp, double range, double speed)
        : x(x), y(y), hp(hp), mp(mp), arrows(0), shield(0), range(range), speed(speed) {}

    virtual void attack(Character *c) = 0;
    virtual bool hpFull() = 0;
    virtual bool mpFull() = 0;
    virtual bool arrowsFull() = 0;
    virtual bool shieldFull() = 0;
    virtual void hpMax() = 0;
    virtual void mpMax() = 0;
    virtual void arrowsMax() = 0;
    virtual void shieldMax() = 0;

    void move(double dstX, double dstY)
    {
        double mx, my;
        mx = my = speed;
        if (dstX < x)
            mx = -mx;
        for (; int(dstX * 10) != int(x * 10); x += mx)
            ;
        if (dstY < y)
            my = -my;
        for (; int(dstY * 10) != int(y * 10); y += my)
            ;
    }

    void punch(Character *c)
    {
        double dist = distance(this, c);
        if (c->hp > 0 && dist <= 1)
            c->hp -= 1;
        else
            cout << "범위 내 대상이 없습니다." << endl;
    }

    void info()
    {
        cout << "pos = (" << x << ", " << y << "), hp = " << hp << ", mp = " << mp << endl;
    }

    double distance(Character *c1, Character *c2)
    {
        double a = c1->x - c2->x;
        double b = c1->y - c2->y;
        double cSQ = a * a + b * b;
        return sqrt(cSQ);
    }

    friend class SwordsMan;
    friend class Priest;
    friend class Wizard;
    friend class Archer;
    friend class Tanker;
};

class SwordsMan : public Character
{
public:
    SwordsMan(double x = 0, double y = 0, double hp = 80, double range = 2, double speed = 0.1)
        : Character(x, y, hp, 0.0, range, speed) {}
    virtual bool hpFull() { return hp >= 80; }
    virtual bool mpFull() { return mp >= 0; }
    virtual void hpMax() { hp = 80; }
    virtual void mpMax() { mp = 0; }

    virtual void attack(Character *c)
    {
        double dist = distance(this, c);
        if (c->hp > 0 && dist <= range) // range는 정상접근 가능.
            c->hp -= 10;                // 현재위치는 c의 입장에서 외부임. friend 없이 사용불가
        else
            cout << "범위 내 대상이 없습니다." << endl;
    }
    void run(double dstX, double dstY)
    {
        if (hp > 20)
        {
            double temp = speed;
            speed = 0.5;
            move(dstX, dstY);
            speed = temp;
            hp -= 5;
        }
    }
};

class Priest : public Character
{
public:
    Priest(double x = 0, double y = 0, double hp = 60, double mp = 80, double range = 5, double speed = 0.1)
        : Character(x, y, hp, mp, range, speed) {}

    virtual bool hpFull() { return hp >= 60; }
    virtual bool mpFull() { return mp >= 80; }
    virtual void hpMax() { hp = 60; }
    virtual void mpMax() { mp = 80; }
    virtual void attack(Character *c)
    {
        punch(c);
    }
    void hpHeal(Character *c)
    {
        double dist = distance(this, c);
        if (!c->hpFull() && dist <= range && mp >= 5) // range는 정상접근 가능.
        {
            c->hp += 10; // 현재위치는 c의 입장에서 외부임. friend 없이 사용불가
            if (c->hpFull())
                c->hpMax();
            mp -= 5;
            if (mp < 0)
                mp = 0;
        }
        else
            cout << "범위 내 대상이 없습니다." << endl;
    }
    void mpHeal(Character *c)
    {
        double dist = distance(this, c);
        if (!c->mpFull() && dist <= range && mp >= 5) // range는 정상접근 가능.
        {
            mp -= 5;
            c->mp += 10; // 현재위치는 c의 입장에서 외부임. friend 없이 사용불가
            if (c->mpFull())
                c->mpMax();

            if (mp < 0)
                mp = 0;
        }
        else
            cout << "범위 내 대상이 없습니다." << endl;
    }
};

class Archer : public Character
{
public:
    Archer(double x = 0, double y = 0, double hp = 60, double arrows = 5, double range = 10, double speed = 0.2)
        : Character(x, y, hp, 0.0, range, speed), arrows(arrows) {}
    virtual bool hpFull() { return hp >= 60; }
    virtual bool arrowsFull() { return arrows >= 5; }
    virtual void hpMax() { hp = 60; }
    virtual void arrowsMax() { arrows = 5; }

    virtual void attack(Character *c)
    {
        double dist = distance(this, c);
        if (c->hp > 0 && dist <= 10 && arrows >= 1)
        {
            c->hp -= 5;
            arrows -= 1;
        }
        else
        {
            cout << "범위 내 대상이 없습니다." << endl;
        }
    }
    void reload()
    {
        if (arrows <= 3)
        {
            arrows += 2;
        }
        else if (arrows == 4)
        {
            arrows += 1;
        }
        else
        {
            cout << "화살을 추가할 수 없습니다" << endl;
        }
    }

private:
    double arrows;
};

class Tanker : public Character
{
public:
    Tanker(double x = 0, double y = 0, double hp = 200, double shield = 100, double range = 10, double speed = 0.2)
        : Character(x, y, hp, shield, range, speed) {}
    virtual bool hpFull() { return hp >= 200; }
    virtual bool shieldFull() { return shield >= 100; }
    virtual void hpMax() { hp = 200; }
    virtual void shieldMax() { shield = 100; }

    virtual void attack(Character *c)
    {
        double dist = distance(this, c);
        if (c->hp > 0 && dist <= 1 && shield >= 20)
        {
            c->hp -= 1;
            shield -= 20;
        }
        else
        {
            cout << "범위 내 대상이 없습니다." << endl;
        }
    }
    void addshield()
    {
        if (hp > 20)
        {
            if (shield <= 150)
            {
                shield += 50;
            }
            else if (shield > 150 && shield < 200)
            {
                shield = 200;
            }
            else
            {
                cout << "보호막을 충전 할 수 없습니다" << endl;
            }
        }
    }
    void run(double dstX, double dstY)
    {
        if (hp > 20)
        {
            double temp = speed;
            speed = 0.5;
            move(dstX, dstY);
            speed = temp;
            hp -= 5;
        }
    }
};

int main()
{
    Character *c[4];

    c[0] = new SwordsMan(2, 0);
    c[1] = new SwordsMan(5, 5);
    c[2] = new Priest(3, 2);
    c[3] = new Tanker(3, 3);

    ((SwordsMan *)c[1])->run(3, 1);
    c[1]->attack(c[0]);
    c[2]->attack(c[1]);
    c[3]->attack(c[2]);
    ((Priest *)c[2])->hpHeal(c[1]);
    ((Priest *)c[2])->mpHeal(c[2]);
    ((Tanker *)c[3])->addshield();
    for (int i = 0; i < 3; i++)
    {
        c[i]->info();
    }

    return 0;
}
