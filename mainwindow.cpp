#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Write stylesheet
    this->setStyleSheet("background-color: white;");

    this->setLocale(QLocale(QLocale::French, QLocale::France));
    begin = localTime.currentDateTime().toTime_t();
    //qDebug() << localTime.currentDateTime().toTime_t();
    //qDebug() << localTime.currentDateTimeUtc().toTime_t();
    //qDebug() << localTime.currentSecsSinceEpoch();
    //qDebug() << localTime.currentDateTime().toLocalTime().toTime_t();
    //qDebug() << localTime.currentDateTime().toLocalTime().toString();

    ch0_array.reserve(10000);
    x0_array.reserve(10000);
    ch1_array.reserve(10000);
    x1_array.reserve(10000);
    ch2_array.reserve(10000);
    x2_array.reserve(10000);
    ch3_array.reserve(10000);
    x3_array.reserve(10000);
    ch4_array.reserve(10000);
    x4_array.reserve(10000);
    ch5_array.reserve(10000);
    x5_array.reserve(10000);
    ch6_array.reserve(10000);
    x6_array.reserve(10000);
    ch7_array.reserve(10000);
    x7_array.reserve(10000);
    current_ch0_data.reserve(5);
    current_ch1_data.reserve(5);
    current_ch2_data.reserve(5);
    current_ch3_data.reserve(5);
    current_ch4_data.reserve(5);
    current_ch5_data.reserve(5);
    current_ch6_data.reserve(5);
    current_ch7_data.reserve(5);

    serial.setPortName("ttyUSB1");
    serial.setBaudRate(QSerialPort::Baud115200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    if(serial.open(QIODevice::ReadOnly))
        qDebug() << "Opened the serial port";
    else
    {
        //error
        qDebug() << serial.errorString();
    }

    /*               *
     *  Graph setup  *
     *               *
    */
    ui->plot0->addGraph();
    ui->plot0->graph(0)->setPen(QPen(Qt::red));
    ui->plot0->graph(0)->setAntialiasedFill(false);
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeSpec(localTime.timeSpec());
    dateTicker->setDateTimeFormat("HH:mm:ss");
    ui->plot0->xAxis->setTicker(dateTicker);
    ui->plot0->xAxis->setTickLabelFont(QFont(QFont().family(),7));
    ui->plot0->yAxis->setTickLabelFont(QFont(QFont().family(),7));
    ui->plot0->xAxis->setLabel("Time");
    ui->plot0->yAxis->setLabel("Value");
    ui->plot0->xAxis2->setVisible(true);
    ui->plot0->yAxis->setVisible(true);
    ui->plot0->xAxis2->setTicks(false);
    ui->plot0->yAxis2->setTicks(false);
    ui->plot0->xAxis2->setTickLabels(false);
    ui->plot0->yAxis2->setTickLabels(false);

    ui->plot1->addGraph();
    ui->plot1->graph(0)->setPen(QPen(Qt::red));
    ui->plot1->graph(0)->setAntialiasedFill(false);
    ui->plot1->xAxis->setTicker(dateTicker);
    ui->plot1->xAxis->setTickLabelFont(QFont(QFont().family(),7));
    ui->plot1->yAxis->setTickLabelFont(QFont(QFont().family(),7));
    ui->plot1->xAxis->setLabel("Time");
    ui->plot1->yAxis->setLabel("Value");
    ui->plot1->xAxis2->setVisible(true);
    ui->plot1->yAxis->setVisible(true);
    ui->plot1->xAxis2->setTicks(false);
    ui->plot1->yAxis2->setTicks(false);
    ui->plot1->xAxis2->setTickLabels(false);
    ui->plot1->yAxis2->setTickLabels(false);


    ui->plot2->addGraph();
    ui->plot2->graph(0)->setPen(QPen(Qt::red));
    ui->plot2->graph(0)->setAntialiasedFill(false);
    ui->plot2->xAxis->setTicker(dateTicker);
    ui->plot2->xAxis->setTickLabelFont(QFont(QFont().family(),7));
    ui->plot2->yAxis->setTickLabelFont(QFont(QFont().family(),7));
    ui->plot2->xAxis->setLabel("Time");
    ui->plot2->yAxis->setLabel("Value");
    ui->plot2->xAxis2->setVisible(true);
    ui->plot2->yAxis->setVisible(true);
    ui->plot2->xAxis2->setTicks(false);
    ui->plot2->yAxis2->setTicks(false);
    ui->plot2->xAxis2->setTickLabels(false);
    ui->plot2->yAxis2->setTickLabels(false);


    ui->plot3->addGraph();
    ui->plot3->graph(0)->setPen(QPen(Qt::red));
    ui->plot3->graph(0)->setAntialiasedFill(false);
    ui->plot3->xAxis->setTicker(dateTicker);
    ui->plot3->xAxis->setTickLabelFont(QFont(QFont().family(),7));
    ui->plot3->yAxis->setTickLabelFont(QFont(QFont().family(),7));
    ui->plot3->xAxis->setLabel("Time");
    ui->plot3->yAxis->setLabel("Value");
    ui->plot3->xAxis2->setVisible(true);
    ui->plot3->yAxis->setVisible(true);
    ui->plot3->xAxis2->setTicks(false);
    ui->plot3->yAxis2->setTicks(false);
    ui->plot3->xAxis2->setTickLabels(false);
    ui->plot3->yAxis2->setTickLabels(false);


    ui->plot4->addGraph();
    ui->plot4->graph(0)->setPen(QPen(Qt::red));
    ui->plot4->graph(0)->setAntialiasedFill(false);
    ui->plot4->xAxis->setTicker(dateTicker);
    ui->plot4->xAxis->setTickLabelFont(QFont(QFont().family(),7));
    ui->plot4->yAxis->setTickLabelFont(QFont(QFont().family(),7));
    ui->plot4->xAxis->setLabel("Time");
    ui->plot4->yAxis->setLabel("Value");
    ui->plot4->xAxis2->setVisible(true);
    ui->plot4->yAxis->setVisible(true);
    ui->plot4->xAxis2->setTicks(false);
    ui->plot4->yAxis2->setTicks(false);
    ui->plot4->xAxis2->setTickLabels(false);
    ui->plot4->yAxis2->setTickLabels(false);


    ui->plot5->addGraph();
    ui->plot5->graph(0)->setPen(QPen(Qt::red));
    ui->plot5->graph(0)->setAntialiasedFill(false);
    ui->plot5->xAxis->setTicker(dateTicker);
    ui->plot5->xAxis->setTickLabelFont(QFont(QFont().family(),7));
    ui->plot5->yAxis->setTickLabelFont(QFont(QFont().family(),7));
    ui->plot5->xAxis->setLabel("Time");
    ui->plot5->yAxis->setLabel("Value");
    ui->plot5->xAxis2->setVisible(true);
    ui->plot5->yAxis->setVisible(true);
    ui->plot5->xAxis2->setTicks(false);
    ui->plot5->yAxis2->setTicks(false);
    ui->plot5->xAxis2->setTickLabels(false);
    ui->plot5->yAxis2->setTickLabels(false);


    ui->plot6->addGraph();
    ui->plot6->graph(0)->setPen(QPen(Qt::red));
    ui->plot6->graph(0)->setAntialiasedFill(false);
    ui->plot6->xAxis->setTicker(dateTicker);
    ui->plot6->xAxis->setTickLabelFont(QFont(QFont().family(),7));
    ui->plot6->yAxis->setTickLabelFont(QFont(QFont().family(),7));
    ui->plot6->xAxis->setLabel("Time");
    ui->plot6->yAxis->setLabel("Value");
    ui->plot6->xAxis2->setVisible(true);
    ui->plot6->yAxis->setVisible(true);
    ui->plot6->xAxis2->setTicks(false);
    ui->plot6->yAxis2->setTicks(false);
    ui->plot6->xAxis2->setTickLabels(false);
    ui->plot6->yAxis2->setTickLabels(false);


    ui->plot7->addGraph();
    ui->plot7->graph(0)->setPen(QPen(Qt::red));
    ui->plot7->graph(0)->setAntialiasedFill(false);
    ui->plot7->xAxis->setTicker(dateTicker);
    ui->plot7->xAxis->setTickLabelFont(QFont(QFont().family(),7));
    ui->plot7->yAxis->setTickLabelFont(QFont(QFont().family(),7));
    ui->plot7->xAxis->setLabel("Time");
    ui->plot7->yAxis->setLabel("Value");
    ui->plot7->xAxis2->setVisible(true);
    ui->plot7->yAxis->setVisible(true);
    ui->plot7->xAxis2->setTicks(false);
    ui->plot7->yAxis2->setTicks(false);
    ui->plot7->xAxis2->setTickLabels(false);
    ui->plot7->yAxis2->setTickLabels(false);

    connect(&serial, SIGNAL(readyRead()), this, SLOT(framesAvailable()));
    connect(this, SIGNAL(receivedCh0(unsigned long)), this, SLOT(plot0dataAvailable(unsigned long)));
    connect(this, SIGNAL(receivedCh1(unsigned long)), this, SLOT(plot1dataAvailable(unsigned long)));
    connect(this, SIGNAL(receivedCh2(unsigned long)), this, SLOT(plot2dataAvailable(unsigned long)));
    connect(this, SIGNAL(receivedCh3(unsigned long)), this, SLOT(plot3dataAvailable(unsigned long)));
    connect(this, SIGNAL(receivedCh4(unsigned long)), this, SLOT(plot4dataAvailable(unsigned long)));
    connect(this, SIGNAL(receivedCh5(unsigned long)), this, SLOT(plot5dataAvailable(unsigned long)));
    connect(this, SIGNAL(receivedCh6(unsigned long)), this, SLOT(plot6dataAvailable(unsigned long)));
    connect(this, SIGNAL(receivedCh7(unsigned long)), this, SLOT(plot7dataAvailable(unsigned long)));
}

MainWindow::~MainWindow()
{
    delete ui;
    serial.close();
    ch0_array.clear();
}

void MainWindow::framesAvailable()
{

    QStringList linedivider;
    QString data;
    unsigned long dataUint;
    QFile output_ch0("/home/lsce/Desktop/Qt_CH0_COV.txt"),
          output_ch1("/home/lsce/Desktop/Qt_CH1_COV.txt"),
          output_ch2("/home/lsce/Desktop/Qt_CH2_COV.txt"),
          output_ch3("/home/lsce/Desktop/Qt_CH3_COV.txt"),
          output_ch4("/home/lsce/Desktop/Qt_CH4_COV.txt"),
          output_ch5("/home/lsce/Desktop/Qt_CH5_COV.txt"),
          output_ch6("/home/lsce/Desktop/Qt_CH6_COV.txt"),
          output_ch7("/home/lsce/Desktop/Qt_CH7_COV.txt");

    //Character = serial.readLine();
    QByteArray byteArray = serial.readAll();

    if(QString(byteArray) != NULL)
    {
        Character = QString(byteArray);
    }
    //qDebug() << byteArray << Character;

    //qDebug() << "Character: " << Character;
    if(Character == "0\r")
        Character = Character.front();
    if(Character != "\r" && Character != "\n" && Character != "\r\n")
    {
        line.append(Character);
    }
    else if(Character == "\r" || Character == "\n" || Character == "\r\n")
    {
        if(line.isEmpty() == 0)
        {
            qDebug() << localTime.currentDateTime().toString("dd/MM/yy-HH:mm:ss") << "Line: " << line;
        }
        if(line.isEmpty() == 0 && line.size() < 15)
        {
            linedivider = line.split('x');
            //qDebug() << "Divided line: " << linedivider;

            if(linedivider.at(0).startsWith("CH0"))
            {
                data.append(linedivider.takeAt(1));
                data = data.left(8);
                //qDebug() << "data ch0: "<< data;
                dataUint = data.toUInt(&ok, 16);
                dataUint = dataUint & 0x0FFFFFFF;

                if(output_ch0.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                {
                    QTextStream stream(&output_ch0);
                    stream << localTime.currentDateTime().toString("dd/MM/yy-HH:mm:ss") << ",CH0:" << dataUint << endl;
                    output_ch0.close();
                }

                emit receivedCh0(dataUint);
            }
            else if(linedivider.at(0).startsWith("CH1"))
            {
                data.append(linedivider.takeAt(1));
                data = data.left(8);
                //qDebug() << "data ch1: "<< data;
                dataUint = data.toUInt(&ok, 16);
                dataUint = dataUint & 0x0FFFFFFF;

                if(output_ch1.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                {
                    QTextStream stream(&output_ch1);
                    stream << localTime.currentDateTime().toString("dd/MM/yy-HH:mm:ss") << ",CH1:" << dataUint << endl;
                    output_ch1.close();
                }

                emit receivedCh1(dataUint);
            }
            else if(linedivider.at(0).startsWith("CH2"))
            {
                data.append(linedivider.takeAt(1));
                data = data.left(8);
                //qDebug() << "data ch2: "<< data;
                dataUint = data.toUInt(&ok, 16);
                dataUint = dataUint & 0x0FFFFFFF;

                if(output_ch2.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                {
                    QTextStream stream(&output_ch2);
                    stream << localTime.currentDateTime().toString("dd/MM/yy-HH:mm:ss") << ",CH2:" << dataUint << endl;
                    output_ch2.close();
                }

                emit receivedCh2(dataUint);
            }
            else if(linedivider.at(0).startsWith("CH3"))
            {
                data.append(linedivider.takeAt(1));
                data = data.left(8);
                //qDebug() << "data ch3: "<< data;
                dataUint = data.toUInt(&ok, 16);
                dataUint = dataUint & 0x0FFFFFFF;

                if(output_ch3.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                {
                    QTextStream stream(&output_ch3);
                    stream << localTime.currentDateTime().toString("dd/MM/yy-HH:mm:ss") << ",CH3:" << dataUint << endl;
                    output_ch3.close();
                }

                emit receivedCh3(dataUint);
            }
            else if(linedivider.at(0).startsWith("CH4"))
            {
                data.append(linedivider.takeAt(1));
                data = data.left(8);
                //qDebug() << "data ch4: "<< data;
                dataUint = data.toUInt(&ok, 16);
                dataUint = dataUint & 0x0FFFFFFF;

                if(output_ch4.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                {
                    QTextStream stream(&output_ch4);
                    stream << localTime.currentDateTime().toString("dd/MM/yy-HH:mm:ss") << ",CH4:" << dataUint << endl;
                    output_ch4.close();
                }

                emit receivedCh4(dataUint);
            }
            else if(linedivider.at(0).startsWith("CH5"))
            {
                data.append(linedivider.takeAt(1));
                data = data.left(8);
                //qDebug() << "data ch5: "<< data;
                dataUint = data.toUInt(&ok, 16);
                dataUint = dataUint & 0x0FFFFFFF;

                if(output_ch5.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                {
                    QTextStream stream(&output_ch5);
                    stream << localTime.currentDateTime().toString("dd/MM/yy-HH:mm:ss") << ",CH5:" << dataUint << endl;
                    output_ch5.close();
                }

                emit receivedCh5(dataUint);
            }
            else if(linedivider.at(0).startsWith("CH6"))
            {
                data.append(linedivider.takeAt(1));
                data = data.left(8);
                //qDebug() << "data ch6: "<< data;
                dataUint = data.toUInt(&ok, 16);
                dataUint = dataUint & 0x0FFFFFFF;

                if(output_ch6.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                {
                    QTextStream stream(&output_ch6);
                    stream << localTime.currentDateTime().toString("dd/MM/yy-HH:mm:ss") << ",CH6:" << dataUint << endl;
                    output_ch6.close();
                }

                emit receivedCh6(dataUint);
            }
            else if(linedivider.at(0).startsWith("CH7"))
            {
                data.append(linedivider.takeAt(1));
                data = data.left(8);
                //qDebug() << "data ch7: "<< data;
                dataUint = data.toUInt(&ok, 16);
                dataUint = dataUint & 0x0FFFFFFF;

                if(output_ch7.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                {
                    QTextStream stream(&output_ch7);
                    stream << localTime.currentDateTime().toString("dd/MM/yy-HH:mm:ss") << ",CH7:" << dataUint << endl;
                    output_ch7.close();
                }

                emit receivedCh7(dataUint);
            }
        }
        line.clear();
    }

}

void MainWindow::plot0dataAvailable(unsigned long value)
{
    QString ch0_graphname = localTime.currentDateTime().toString("ddMMyy-HH:mm")+"_CH0_graph.jpg";
    QFile file(graphDir+"/"+ch0_graphname);
    //qDebug() << "CH0 graphname: " << ch0_graphname;
    //qDebug() << "Value CH0: " << value;
    if(current_ch0_data.size() < 5)
    {
        current_ch0_data.append(static_cast<double>(value));
    }
    else
    {
        for (auto& n : current_ch0_data)
        {
            sum0 += n;
        }
        avg0 = sum0 / 5;
        //qDebug() << "sum: " << sum << "avg ch0: " << avg;
        sum0 = 0;

        current_ch0_data.clear();
        ch0_array.append(avg0);
        now = localTime.currentDateTime().toTime_t();
        x0_array.append(now);
        //qDebug() << "ch0: " << ch0_array;
    }
    //qDebug() << "ch0 size: " << ch0_array.size;

    if(ch0_array.size() != 0 && ch0_array.size() < 10000 && ch0_array.size()%25 == 0)
    {
        ui->plot0->xAxis->setRange(begin, now);
        ui->plot0->graph(0)->addData(x0_array, ch0_array);
        ui->plot0->graph(0)->rescaleValueAxis();
        ui->plot0->replot();

        if(ch0_array.size()%100 == 0)
        {
            if (file.open(QIODevice::WriteOnly|QFile::WriteOnly))
            {
                //qDebug() << "Inside CH0 graph image saving ";
                ui->plot0->saveJpg(graphDir+"/"+ch0_graphname, 1280, 1024, 1.0, -1);
            }
        }
    }
    else if(ch0_array.size() == 10000)
    {
        ch0_array.clear();
        begin = localTime.currentDateTime().toTime_t();
        x0_array.clear();
    }


}

void MainWindow::plot1dataAvailable(unsigned long value)
{
    QString ch1_graphname = localTime.currentDateTime().toString("ddMMyy-HH:mm")+"_CH1_graph.jpg";
    QFile file(graphDir+"/"+ch1_graphname);
    //qDebug() << "Value CH1: " << value;
    if(current_ch1_data.size() < 5)
    {
        current_ch1_data.append(static_cast<double>(value));
    }
    else
    {
        for (auto& n : current_ch1_data)
        {
            sum1 += n;
        }
        avg1 = sum1 / 5;
        //qDebug() << "sum: " << sum << "avg ch1: " << avg;
        sum1 = 0;

        current_ch1_data.clear();
        ch1_array.append(avg1);
        now = localTime.currentDateTime().toTime_t();
        x1_array.append(now);
        //qDebug() << "ch1: " << ch1_array;
    }

    if(ch1_array.size() != 0 && ch1_array.size() < 10000 && ch1_array.size()%25 == 0)
    {
        ui->plot1->xAxis->setRange(begin, now);
        ui->plot1->graph(0)->addData(x1_array, ch1_array);
        ui->plot1->graph(0)->rescaleValueAxis();
        ui->plot1->replot();

        if(ch1_array.size()%100 == 0)
        {
            if (file.open(QIODevice::WriteOnly|QFile::WriteOnly))
            {
                //qDebug() << "Inside CH0 graph image saving ";
                ui->plot1->saveJpg(graphDir+"/"+ch1_graphname, 1280, 1024, 1.0, -1);
            }
        }
    }
    else if(ch1_array.size() == 10000)
    {
        ch1_array.clear();
        begin = localTime.currentDateTime().toTime_t();
        x1_array.clear();
    }
}

void MainWindow::plot2dataAvailable(unsigned long value)
{
    QString ch2_graphname = localTime.currentDateTime().toString("ddMMyy-HH:mm")+"_CH2_graph.jpg";
    QFile file(graphDir+"/"+ch2_graphname);
    //qDebug() << "Value CH2: " << value;
    if(current_ch2_data.size() < 5)
    {
        current_ch2_data.append(static_cast<double>(value));
    }
    else
    {
        for (auto& n : current_ch2_data)
        {
            sum2 += n;
        }
        avg2 = sum2 / 5;
        //qDebug() << "sum: " << sum << "avg ch2: " << avg;
        sum2 = 0;

        current_ch2_data.clear();
        ch2_array.append(avg2);
        now = localTime.currentDateTime().toTime_t();
        x2_array.append(now);
        //qDebug() << "ch2: " << ch2_array;
    }

    if(ch2_array.size() != 0 && ch2_array.size() < 10000 && ch2_array.size()%25 == 0)
    {
        ui->plot2->xAxis->setRange(begin, now);
        ui->plot2->graph(0)->addData(x2_array, ch2_array);
        ui->plot2->graph(0)->rescaleValueAxis();
        ui->plot2->replot();

        if(ch2_array.size()%100 == 0)
        {
            if (file.open(QIODevice::WriteOnly|QFile::WriteOnly))
            {
                //qDebug() << "Inside CH0 graph image saving ";
                ui->plot2->saveJpg(graphDir+"/"+ch2_graphname, 1280, 1024, 1.0, -1);
            }
        }
    }
    else if(ch2_array.size() == 10000)
    {
        ch2_array.clear();
        begin = localTime.currentDateTime().toTime_t();
        x2_array.clear();
    }    
}

void MainWindow::plot3dataAvailable(unsigned long value)
{
    QString ch3_graphname = localTime.currentDateTime().toString("ddMMyy-HH:mm")+"_CH3_graph.jpg";
    QFile file(graphDir+"/"+ch3_graphname);
    //qDebug() << "Value CH3: " << value;
    if(current_ch3_data.size() < 5)
    {
        current_ch3_data.append(static_cast<double>(value));
    }
    else
    {
        for (auto& n : current_ch3_data)
        {
            sum3 += n;
        }
        avg3 = sum3 / 5;
        //qDebug() << "sum: " << sum << "avg ch3: " << avg;
        sum3 = 0;

        current_ch3_data.clear();
        ch3_array.append(avg3);
        now = localTime.currentDateTime().toTime_t();
        x3_array.append(now);
        //qDebug() << "ch3: " << ch3_array;
    }

    if(ch3_array.size() != 0 && ch3_array.size() < 10000  && ch3_array.size()%25 == 0)
    {
        ui->plot3->xAxis->setRange(begin, now);
        ui->plot3->graph(0)->addData(x3_array, ch3_array);
        ui->plot3->graph(0)->rescaleValueAxis();
        ui->plot3->replot();

        if(ch3_array.size()%100 == 0)
        {
            if (file.open(QIODevice::WriteOnly|QFile::WriteOnly))
            {
                //qDebug() << "Inside CH0 graph image saving ";
                ui->plot3->saveJpg(graphDir+"/"+ch3_graphname, 1280, 1024, 1.0, -1);
            }
        }
    }
    else if(ch3_array.size() == 10000)
    {
        ch3_array.clear();
        begin = localTime.currentDateTime().toTime_t();
        x3_array.clear();
    }
}

void MainWindow::plot4dataAvailable(unsigned long value)
{
    QString ch4_graphname = localTime.currentDateTime().toString("ddMMyy-HH:mm")+"_CH4_graph.jpg";
    QFile file(graphDir+"/"+ch4_graphname);
    //qDebug() << "Value CH4: " << value;
    if(current_ch4_data.size() < 5)
    {
        current_ch4_data.append(static_cast<double>(value));
    }
    else
    {
        for (auto& n : current_ch4_data)
        {
            sum4 += n;
        }
        avg4 = sum4 / 5;
        //qDebug() << "sum: " << sum << "avg ch4: " << avg;
        sum4 = 0;

        current_ch4_data.clear();
        ch4_array.append(avg4);
        now = localTime.currentDateTime().toTime_t();
        x4_array.append(now);
        //qDebug() << "ch4: " << ch4_array;
    }

    if(ch4_array.size() != 0 && ch4_array.size() < 10000 && ch4_array.size()%25 == 0)
    {
        ui->plot4->xAxis->setRange(begin, now);
        ui->plot4->graph(0)->addData(x4_array, ch4_array);
        ui->plot4->graph(0)->rescaleValueAxis();
        ui->plot4->replot();

        if(ch4_array.size()%100 == 0)
        {
            if (file.open(QIODevice::WriteOnly|QFile::WriteOnly))
            {
                //qDebug() << "Inside CH0 graph image saving ";
                ui->plot4->saveJpg(graphDir+"/"+ch4_graphname, 1280, 1024, 1.0, -1);
            }
        }
    }
    else if(ch4_array.size() == 10000)
    {
        ch4_array.clear();
        begin = localTime.currentDateTime().toTime_t();
        x4_array.clear();
    }
}

void MainWindow::plot5dataAvailable(unsigned long value)
{
    QString ch5_graphname = localTime.currentDateTime().toString("ddMMyy-HH:mm")+"_CH5_graph.jpg";
    QFile file(graphDir+"/"+ch5_graphname);
    //qDebug() << "Value CH5: " << value;
    if(current_ch5_data.size() < 5)
    {
        current_ch5_data.append(static_cast<double>(value));
        //qDebug() << "Current CH5: " << current_ch5_data;
    }
    else
    {
        for (auto& n : current_ch5_data)
        {
            sum5 += n;
        }
        avg5 = sum5 / 5;
        //qDebug() << "sum: " << sum << "avg ch5: " << avg;
        sum5 = 0;

        current_ch5_data.clear();
        ch5_array.append(avg5);
        now = localTime.currentDateTime().toTime_t();
        x5_array.append(now);
        //qDebug() << "ch5: " << ch5_array;
    }

    if(ch5_array.size() != 0 && ch5_array.size() < 10000 && ch5_array.size()%25 == 0)
    {
        ui->plot5->xAxis->setRange(begin, now);
        ui->plot5->graph(0)->addData(x5_array, ch5_array);
        ui->plot5->graph(0)->rescaleValueAxis();
        ui->plot5->replot();

        if(ch5_array.size()%100 == 0)
        {
            if (file.open(QIODevice::WriteOnly|QFile::WriteOnly))
            {
                //qDebug() << "Inside CH0 graph image saving ";
                ui->plot5->saveJpg(graphDir+"/"+ch5_graphname, 1280, 1024, 1.0, -1);
            }
        }
    }
    else if(ch5_array.size() == 10000)
    {
        ch5_array.clear();
        begin = localTime.currentDateTime().toTime_t();
        x5_array.clear();
    }
}

void MainWindow::plot6dataAvailable(unsigned long value)
{
    QString ch6_graphname = localTime.currentDateTime().toString("ddMMyy-HH:mm")+"_CH6_graph.jpg";
    QFile file(graphDir+"/"+ch6_graphname);
    //qDebug() << "Value CH6: " << value;
    if(current_ch6_data.size() < 5)
    {
        current_ch6_data.append(static_cast<double>(value));
    }
    else
    {
        for (auto& n : current_ch6_data)
        {
            sum6 += n;
        }
        avg6 = sum6 / 5;
        //qDebug() << "sum: " << sum << "avg ch6: " << avg;
        sum6 = 0;

        current_ch6_data.clear();
        ch6_array.append(avg6);
        now = localTime.currentDateTime().toTime_t();
        x6_array.append(now);
        //qDebug() << "ch6: " << ch6_array;
    }

    if(ch6_array.size() != 0 && ch6_array.size() < 10000 && ch6_array.size()%25 == 0)
    {
        ui->plot6->xAxis->setRange(begin, now);
        ui->plot6->graph(0)->addData(x6_array, ch6_array);
        ui->plot6->graph(0)->rescaleValueAxis();
        ui->plot6->replot();

        if(ch6_array.size()%100 == 0)
        {
            if (file.open(QIODevice::WriteOnly|QFile::WriteOnly))
            {
                //qDebug() << "Inside CH0 graph image saving ";
                ui->plot6->saveJpg(graphDir+"/"+ch6_graphname, 1280, 1024, 1.0, -1);
            }
        }
    }
    else if(ch6_array.size() == 10000)
    {
        ch6_array.clear();
        begin = localTime.currentDateTime().toTime_t();
        x6_array.clear();
    }
}

void MainWindow::plot7dataAvailable(unsigned long value)
{
    QString ch7_graphname = localTime.currentDateTime().toString("ddMMyy-HH:mm")+"_CH7_graph.jpg";
    QFile file(graphDir+"/"+ch7_graphname);
    //qDebug() << "Value CH7: " << value;
    if(current_ch7_data.size() < 5)
    {
        current_ch7_data.append(static_cast<double>(value));
    }
    else
    {
        for (auto& n : current_ch7_data)
        {
            sum7 += n;
        }
        avg7 = sum7 / 5;
        //qDebug() << "sum: " << sum << "avg ch7: " << avg;
        sum7 = 0;

        current_ch7_data.clear();
        ch7_array.append(avg7);
        now = localTime.currentDateTime().toTime_t();
        x7_array.append(now);
        //qDebug() << "ch7: " << ch7_array;
    }

    if(ch7_array.size() != 0 && ch7_array.size() < 10000 && ch7_array.size()%25 == 0)
    {
        ui->plot7->xAxis->setRange(begin, now);
        ui->plot7->graph(0)->addData(x7_array, ch7_array);
        ui->plot7->graph(0)->rescaleValueAxis();
        ui->plot7->replot();

        if(ch7_array.size()%100 == 0)
        {
            if (file.open(QIODevice::WriteOnly|QFile::WriteOnly))
            {
                //qDebug() << "Inside CH0 graph image saving ";
                ui->plot7->saveJpg(graphDir+"/"+ch7_graphname, 1280, 1024, 1.0, -1);
            }
        }
    }
    else if(ch7_array.size() == 10000)
    {
        ch7_array.clear();
        begin = localTime.currentDateTime().toTime_t();
        x7_array.clear();
    }
}
