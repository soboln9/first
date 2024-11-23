#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QVector<unsigned char> MainWindow::convertfromsource(QString &source_text)
{
    std::string str = source_text.toStdString();
    QVector<unsigned char> vec(str.size());
    for(int c = 0; c < str.size();c++)
    {
        vec[c] = static_cast<unsigned char>(str[c]);
    }  return vec;
}

unsigned char MainWindow::crc8(QVector<unsigned char>& uns)
{
    uns.push_back('\0');
    unsigned char crc = 0xFF;//все 1
    unsigned char G = 0xD5;//порождающий

    for(unsigned char byte:uns)
    {
        for(size_t bit = 0;bit < 8;++bit)
        {
            //старший бит до сдвига
            bool flag = (crc & 0x80) != 0;
            crc <<= 1;
            crc |= (byte >> (7 - bit)) & 0x01;

            if(flag)
                crc ^= G;
        }
    }
    crc ^= 0xFF;
    qDebug()<<crc;
    return crc;
}

QString MainWindow::converttohex(unsigned char crc8)
{
    stringstream stream;
    stream << setw(2) << setfill('0')<< hex << static_cast<unsigned int> (crc8);
    return QString::fromStdString(stream.str());
}

void MainWindow::on_sum_button_clicked()
{
    QString source =  ui->source_edit->toPlainText();
    QVector<unsigned char> un = convertfromsource(source);
    ui->sum_edit->setText(converttohex(crc8(un)));
}

