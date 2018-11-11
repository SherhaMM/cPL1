//
//  main.cpp
//  lab1 bohd
//
//  Created by Makcim Mikhailov on 08.10.18.
//  Copyright © 2018 Makcim Mikhailov. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;

class Room
{
private:
    float lenght;
    float height;
    float width;
    string color;
    float vLitresToL;
    float vLitres;
    
public:
    void setRoom() {
        cout << "\nВведите ширину ";
        cin >> lenght;
        cout << "\nВведите длину ";
        cin >> width;
        cout << "\nВведите высоту ";
        cin >> height;
        cout << "\nВведите количество затраченной краски на кв.метр ";
        cin >> vLitresToL;
        cout << "\nВведите цвет комнат ";
        cin >> color;
        
    }
    
    int getLitres() {
        vLitres = vLitresToL * (lenght*height * 2 + width * height * 2);
        return vLitres;
    }
    
    void getRoom() {
        
        cout <<std::endl<< "Длина " << lenght << "\nВысота " << height << "\nШирина " << width
        << "\nЦвет " << color << "\nКоличество литров краски на кв.метр " << vLitresToL
        << "\nКоличество краски на всю комнату " << getLitres() << std::endl;
    }
    ~Room(){
        cout <<"Деструктор комнаты";
    }
    
};


class Flat
{
private:
    int roomsNumb;
    Room *room;
    int vLitres;
    
public:
    
    void setFlat() {
        cout << "\nВведите количество комнат в каждой квартире ";
        cin >> roomsNumb;
        room = new Room();
        room->setRoom();
    }
    void getFlat() {
        cout << "Количество комнат " << roomsNumb << std::endl;
        room->getRoom();
    }
    
    int getLitres() {
        vLitres = roomsNumb * room->getLitres();
        return vLitres;
    }
    ~Flat(){
        cout << "Деструктор этажа"<< std::endl;
    }
    
};

class House
{
private:
    
    int flatOnFloorNumb;
    int floorsNumb;
    int vLitres;
    Flat *flat;
    
public:
    
    void setHouse() {
        cout << "\nВведите количество этажей в доме ";
        cin >> floorsNumb;
        cout << "\nВведите количество квартир на одном этаже ";
        cin >> flatOnFloorNumb;
        flat = new Flat();
        flat->setFlat();
    }
    
    int getCountFlats() {
        return (flatOnFloorNumb * floorsNumb);
    }
    void getHouse() {
        cout << "Этажность домов " << floorsNumb << "\nКоличество квартир в каждом доме " << flatOnFloorNumb*floorsNumb << std::endl;
        flat->getFlat();
    }
    
    int getLitres() {
        vLitres = flatOnFloorNumb * floorsNumb * flat->getLitres();
        return vLitres;
    }
    ~House(){
        delete flat;
        cout << "Деструктор дома"<< std::endl;
    }
};


class Street
{
private:
    int housesNumber;
    int vLitres;
    House *house;
    
public:
    
    void setHouse() {
        cout << "\nВведите количество домов на этой улице ";
        cin >> housesNumber;
        house = new House();
        house->setHouse();
    }
    
    int getLitres() {
        vLitres = housesNumber * house->getLitres();
        return vLitres;
    }
    
    void getHouse() {
        cout <<std::endl;
        cout << "\nКоличество домов " << housesNumber << std::endl;
        cout << "Общее количество квартир " << (housesNumber)*(house->getCountFlats()) << std::endl;
        house->getHouse();
        cout << "Общее количество литров затраченной краски " << getLitres() << std::endl;
    }
    ~Street(){
        cout << "Деструктор улицы"<< std::endl;
    }
};


int main()
{
    
    Street x;
    x.setHouse();
    x.getHouse();
    
    return 0;
}
