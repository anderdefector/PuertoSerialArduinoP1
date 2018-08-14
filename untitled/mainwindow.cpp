#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    arduino_is_available = false;
    arduino_port_name = "";
    arduino = new QSerialPort;

    //Revisar Puertos

    qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
        if(serialPortInfo.hasVendorIdentifier()){
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
        }
        qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
        if(serialPortInfo.hasProductIdentifier()){
            qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
        }
       qDebug() << "Nombre del puerto: " << serialPortInfo.portName();
    }

    // open and configure the serialport
    arduino->setPortName("/dev/ttyACM0");
    arduino->open(QSerialPort::WriteOnly);
    arduino->setBaudRate(QSerialPort::Baud9600);
    arduino->setDataBits(QSerialPort::Data8);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);
    if(arduino->isOpen()){
        qDebug() << "Arduino Available";
    }else{
        qDebug() << "No se pudo establecer la conexión";
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BTN_encdender_clicked()
{
    if(arduino->isWritable()){
        arduino->write("1");
    }else{
        qDebug() << "No se pudo escribir";
    }
}

void MainWindow::on_Apagar_clicked()
{
    if(arduino->isWritable()){
        arduino->write("0");
    }else{
        qDebug() << "No se pudo escribir";
    }
}
