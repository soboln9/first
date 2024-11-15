#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QRandomGenerator>
#include <bitset>
#include <QFile>
#include <QVector>
#include <vector>
#include <string>
#include <QTextStream>
#include <QRegularExpression>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ////////////////////DES
    bitset<64> IP(bitset<64>& block);
    bitset<48> Expand(bitset<32>& halfblock);
    bitset<32> P(bitset<32>& input);
    bitset<32> S(bitset<48>& afterxor);
    QVector<bitset<48>> generate_round_keys(bitset<64>& key);
    bitset<64> IP_1(bitset<64>& block);
    QVector<bitset<64>> stringiinbinary(QString& input);
    QVector<std::bitset<64>> hexStringToVector(QString& hexString);
    bitset<64> keyiinbinary(QString& key);

    bitset<64> encdes(bitset<64>& sourcetxt, bitset<64>& key);
    bitset<64> decdes(bitset<64>& sourcetxt, bitset<64>& key);


    ///////////////////RSA
    unsigned long long generate_p_q();
    bool ferma(unsigned long long simple, int k = 7);
    unsigned long long mod(unsigned long long a, unsigned long long s, unsigned long long simple);
    unsigned long long gcd(unsigned long long a, unsigned long long simple);
    unsigned long long n(unsigned long long p, unsigned long long q);
    unsigned long long fi(unsigned long long p, unsigned long long q);
    unsigned long long e(unsigned long long fi);
    unsigned long long extended_gcd(unsigned long long a, unsigned long long b, long long &x, long long &y);
    unsigned long long d(unsigned long long e, unsigned long long fi);
    unsigned long long modularExponentiation(unsigned long long base, unsigned long long exponent, unsigned long long mod);
    vector<unsigned long long> stringToNumbers(const QString &input);
    QString numbersToString(const vector<unsigned long long> &numbers);

    //vector<unsigned int> stringinint(QString& input, unsigned int e, )

    ~MainWindow();
private slots:
    void generickey();
    void encdesslot();
    void decdesslot();

    void loadopslot();
    void loadclslot();
    void loadkeyslot();
    void unloadopslot();
    void unloadclslot();
    void unloadkeyslot();


    void on_des_box_clicked();
    void on_rsa_box_clicked();


    void on_encrsa_clicked();

    void on_decrsa_clicked();

    void on_myencrsa_clicked();

    void on_mydecrsa_clicked();

private:
    Ui::MainWindow *ui;
    QPushButton* genkey;
    QPushButton* encrip;
    QPushButton* decrip;


    QPushButton* loadop;
    QPushButton* loadcl;
    QPushButton* loadkey;
    QPushButton* unloadop;
    QPushButton* unloadcl;
    QPushButton* unloadkey;

    QVector<bitset<64>> ks;
    QVector<bitset<64>> o;
    int opendatasize = 0;

    vector<unsigned long long> cipher;

};
#endif // MAINWINDOW_H
