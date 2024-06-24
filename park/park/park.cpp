#include "Param.h"

class Vehicle {
public:
    static int curId;
    virtual string getLicensePlate() = 0;
    virtual int getVehicleId() = 0;
    virtual void info() = 0;
};

class Car : public Vehicle {
private:
    string licensePlate;
    int vehicleId;
public:
    Car(string licensePlate, string vehicleType) : licensePlate(licensePlate), vehicleId(++curId){}

    string getLicensePlate() {
        return licensePlate;
    }

    int getVehicleId() {
        return vehicleId;
    }

    void info() {
        cout << "Тип транспортного средства: легковой автомобиль" << endl;
        cout << "Номерной знак: " << licensePlate << endl;
        cout << "Id: " << vehicleId << endl;
    }
};

class Truck : public Vehicle {
private:
    string licensePlate;
    int vehicleId;
public:
    Truck(string licensePlate, string vehicleType) : licensePlate(licensePlate), vehicleId(++curId) {}
    string getLicensePlate() {
        return licensePlate;
    }

    int getVehicleId() {
        return vehicleId;
    }

    void info() {
        cout << "Тип транспортного средства: грузовик" << endl;
        cout << "Номерной знак: " << licensePlate << endl;
        cout << "Id: " << vehicleId << endl;
    }
};

class motorbike : public Vehicle {
private:
    string licensePlate;
    int vehicleId;
public:
    motorbike(string licensePlate, string vehicleType) : licensePlate(licensePlate), vehicleId(++curId) {}
    string getLicensePlate() {
        return licensePlate;
    }

    int getVehicleId() {
        return vehicleId;
    }

    void info() {
        cout << "Тип транспортного средства: мотоцикл" << endl;
        cout << "Номерной знак: " << licensePlate << endl;
        cout << "Id: " << vehicleId << endl;
    }
};

class ParkingSpot {
private:
    int spotId;
    bool isOccupied = 0;
    string spotType;
public:

};

class DefaultSpot : public ParkingSpot {

};

class VIPSpot : public ParkingSpot {

};

class ParkingTicket {
private:
    int ticketId;
    int vehicleId;
    static int spotId;
    time_t entryTime;
public:
    ParkingTicket(int vehicleId) {
        this->entryTime = time(nullptr);
    }

    double getTime() {
        return difftime(time(nullptr), entryTime);
    }

};

class ParkingLot {
private:
    vector<ParkingSpot> parkingSpots;
    vector<Vehicle> vehicles;
    vector<ParkingTicket> parkingTickets;
public:
    int quantityOfSpots() {
        return parkingSpots.size();
    }
    int quantityOfVehicles() {
        return vehicles.size();
    }
    int quantityOfTickets() {
        return parkingTickets.size();
    }
};

class ParkingFeeCalculator {
private:
    float hourlyRate;
    float dailyRate;
public:
    void setHourlyRate(float hourlyRate) {
        this->hourlyRate = hourlyRate;
    }

    void setDailyRate(float dailyRate) {
        this->dailyRate = dailyRate;
    }

    float getHourlyRate() {
        return hourlyRate;
    }

    float setDailyRate() {
        return dailyRate;
    }


};

class RunORExit {
private:
    ParkingLot parking;
public:
    void saveAndExit() {
        string vehicle = "";
        ofstream out;
        out.open("vehicles.txt");
        if (out.is_open()) {
            for (int i = 0; i < parking.quantityOfVehicles(); i++) {
                out << "rrr";
            }
        }
        out.close();
    }
    void runProgram() {
        //int Vehicle::curId = 0;
        ifstream in("vehicles.txt");
        string line = "";
        if (in.is_open()) {
            while (getline(in, line)) {
                
                cout << line << endl;
            }
        }
        in.close();
    }
};

class VehicleAdapter {
public:
    string qualifier(string line) {
        switch (line[0]) {
        case 99:
            carAdapter(line);
            break;
        case 116:
            truckAdapter(line);
            break;
        case 109:
            motorbikeAdapter(line);
            break;

        }
    }
    
    void carAdapter(string line) {
        string licensePlate = "";
        string vehicleId = "";
        int number = 4;
        while (line[number]!=char(";")) {
            licensePlate += line[number++];
        }
        while (line[number] != char(";")) {
            vehicleId += line[number++];
        }
        
    }

    void truckAdapter(string line) {

    }

    void motorbikeAdapter(string line) {

    }
};











int main()
{
    setlocale(LC_ALL, "");
    char task;
    bool flag = true;
    RunORExit runorexit;
    for (int i = 0; i < 255; i++) cout << i << " " << char(i) << endl;
    runorexit.runProgram();
    while (flag) {
        //system("cls");
        cout << "Въезд транспортного средства(1)" << endl;
        cout << "Выезд транспортного средства(2)" << endl;
        cout << "Текущее состояние парковки(3)" << endl;
        cout << "Отчет о заработанных средствах(4)" << endl;
        cout << "Завершить работы программы и сохраненить данные(5)" << endl;
        cin >> task;
        switch (task) {
        case 49:

            break;
        case 50:

            break;
        case 51:

            break;
        case 52:

            break;
        case 53:
            runorexit.saveAndExit();
            flag = false;
            break;
        default:
            cout << "Введенное значение (" << task << ") некорректно" << endl;
            Sleep(1000);
        }
    }
}
