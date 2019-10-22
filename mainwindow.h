#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSerialPort serial;
    QVector<double> current_ch0_data, current_ch1_data, current_ch2_data, current_ch3_data,
                    current_ch4_data, current_ch5_data, current_ch6_data, current_ch7_data;
    QVector<double> ch0_array, ch1_array, ch2_array, ch3_array, ch4_array, ch5_array, ch6_array, ch7_array;
    QString Character, line;
    bool ok;
    double sum0, avg0, sum1, avg1, sum2, avg2, sum3, avg3, sum4, avg4, sum5, avg5, sum6, avg6, sum7, avg7;
    QVector<double> x0_array, x1_array, x2_array, x3_array, x4_array, x5_array, x6_array, x7_array;
    double begin, now;
    QDateTime time = QDateTime::fromString("01.03.90.15.25.01", "dd.MM.yy.HH.mm.ss");
    QDateTime localTime = time.toLocalTime();
    QString graphDir = "/home/lsce/Desktop/adcGraphs";

public slots:
    void framesAvailable();
    void plot0dataAvailable(unsigned long);
    void plot1dataAvailable(unsigned long);
    void plot2dataAvailable(unsigned long);
    void plot3dataAvailable(unsigned long);
    void plot4dataAvailable(unsigned long);
    void plot5dataAvailable(unsigned long);
    void plot6dataAvailable(unsigned long);
    void plot7dataAvailable(unsigned long);

signals:
    void receivedCh0(unsigned long);
    void receivedCh1(unsigned long);
    void receivedCh2(unsigned long);
    void receivedCh3(unsigned long);
    void receivedCh4(unsigned long);
    void receivedCh5(unsigned long);
    void receivedCh6(unsigned long);
    void receivedCh7(unsigned long);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
